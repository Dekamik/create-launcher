#include <argp.h>
#include <stdlib.h>
#include "strutils.h"
#include "args.h"

const char *argp_program_version = "argex 1.0";
const char *argp_program_bug_address = "<dennis@vonbargen.se>";

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
    {
        case 'i':
            arguments->icon = arg;
            break;
        case 'o':
            arguments->outfile = arg;
            break;
        case 't':
            arguments->is_terminal = 1;
            break;
        case 'c':
            arguments->categories = arg;
            break;
        case 'd':
            arguments->description = arg;
            break;
        case 's':
            arguments->is_stdout = 1;
            break;
        case ARGP_KEY_ARG:
            if (state->arg_num >= 2)
                argp_usage(state);
            arguments->args[state->arg_num] = arg;
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 2)
                argp_usage(state);
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static char args_doc[] = "NAME COMMAND";

static char doc[] = "create-launcher -- A program for creating launchers on gnome on Ubuntu.";

static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv) {
    struct arguments arguments;
    FILE *out_stream;
    char *file_path;

    arguments.icon = NULL;
    arguments.outfile = NULL;
    arguments.is_terminal = 0;
    arguments.categories = NULL;
    arguments.description = NULL;
    arguments.is_stdout = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.outfile)
        file_path = arguments.outfile;
    else
    {
        char *file_name = replace_char(to_lower(arguments.args[0]), ' ', '-');
        file_path = strcat("/usr/share/applications/", strcat(file_name, ".desktop"));
    }

    if (arguments.is_stdout)
    {
        out_stream = stdout;
    }
    else if ((out_stream = fopen(file_path, "w")) == NULL)
    {
        printf("Cannot access file at %s, do you have root permissions?", file_path);
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

    system(strcat("chmod +x ", file_path));

    return EXIT_SUCCESS;
}
