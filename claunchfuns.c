//
// Created by dennis on 2021-05-04.
//

#include "claunchfuns.h"

int has_file_permission(char *path)
{
    FILE *out_stream;
    if ((out_stream = fopen(path, "w")) == NULL)
    {
        return 0;
    }
    else
    {
        fclose(out_stream);
        return 1;
    }
}

int write_file(char *path, struct arguments arguments)
{
    FILE *out_stream;

    if (arguments.is_stdout)
    {
        out_stream = stdout;
    }
    else if ((out_stream = fopen(path, "w")) == NULL)
    {
        printf("Cannot access file at %s, do you have root permissions?", path);
        exit(EXIT_FAILURE);
    }

    fprintf(out_stream, "[Desktop entry]");
    fprintf(out_stream, "Name=%s", arguments.args[0]);
    if (arguments.description)
        fprintf(out_stream, "Comment=%s", arguments.description);
    else
        fprintf(out_stream, "Comment=%s", arguments.args[0]);
    fprintf(out_stream, "Exec=%s", arguments.args[1]);
    if (arguments.icon)
        fprintf(out_stream, "Icon=%s", arguments.icon);
    fprintf(out_stream, "Terminal=%s", arguments.is_terminal == 0 ? "false" : "true");
    fprintf(out_stream, "Type=Application");
    if (arguments.categories)
        fprintf(out_stream, "Categories=%s", arguments.categories);
    else
        fprintf(out_stream, "Categories=Utility");

    fclose(out_stream);

    system(strcat("chmod +x ", path));
}
