#include <argp.h>
#include <stdlib.h>

#include "args/args.h"
#include "args/argsint.h"
#include "utils/strutils.h"
#include "utils/fileutils.h"

static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv) {
    struct arguments arguments;
    char *file_path;

    arguments.icon = NULL;
    arguments.outfile = NULL;
    arguments.is_terminal = 0;
    arguments.categories = NULL;
    arguments.description = NULL;
    arguments.is_stdout = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.is_interactive) {
        get_arguments_interactively(&arguments);
    }

    if (arguments.outfile)
    {
        file_path = malloc(strlen(arguments.outfile));
        strcpy(file_path, arguments.outfile);
    }
    else
    {
        char *dir = "/usr/share/applications/";
        char *file_name = replace_char(to_lower(arguments.args[0]), ' ', '-');
        char *ext = ".desktop";
        file_path = malloc(strlen(dir) + strlen(file_name) + strlen(ext));
        strcpy(file_path, dir);
        strcat(file_path, file_name);
        strcat(file_path, ext);
    }

    if (!has_file_permission(file_path))
    {
        printf("Cannot access file at %s, do you have root permissions?", file_path);
        free(file_path);
        exit(EXIT_FAILURE);
    }

    if (write_file(file_path, arguments))
        printf("Launcher created.");
    else
        printf("Error when creating launcher.");

    free(file_path);

    return EXIT_SUCCESS;
}
