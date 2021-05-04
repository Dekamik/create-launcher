//
// Created by dennis on 2021-05-04.
//

#include "args.h"

char const *argp_program_version = "create-launcher 1.0";
char const *argp_program_bug_address = "<dennis@vonbargen.se>";

static struct argp_option options[] =
{
        {"icon", 'i', "ICON", 0, "Path to launcher icon."},
        {"output", 'o', "OUTFILE", 0, "Output to OUTFILE instead of to /usr/share/applications/<launcher-name>.desktop"},
        {"terminal", 't', 0, 0, "Run launcher command in terminal."},
        {"categories", 'c', "CAT1;CAT2", 0, "List of categories as a semicolon-separated string."},
        {"description", 'd', "DESC", 0, "Launcher description/comment."},
        {"stdout", 's', 0, 0, "Redirect to stdout."}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
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
            if (state->arg_num == 0)
                arguments->is_interactive = 1;
            else if (state->arg_num == 1)
                argp_usage(state);
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

char const args_doc[] = "NAME COMMAND";

char const doc[] = "create-launcher -- A program for creating launchers on gnome on Ubuntu.";
