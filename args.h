//
// Created by dennis on 2021-05-02.
//

#ifndef CREATE_LAUNCHER_ARGS_H
#define CREATE_LAUNCHER_ARGS_H

struct arguments
{
    char *args[2];      // NAME and COMMAND
    char *icon;         // Argument for -i
    char *outfile;      // Argument for -o
    int is_terminal;    // Argument for -t
    char *categories;   // Argument for -c
    char *description;  // Argument for -d
    int is_stdout;      // Argument for --stdout
};

static struct argp_option options[] =
{
        {"icon", 'i', "ICON", 0, "Path to launcher icon."},
        {"output", 'o', "OUTFILE", 0, "Output to OUTFILE instead of to /usr/share/applications/<launcher-name>.desktop"},
        {"terminal", 't', 0, 0, "Run launcher command in terminal."},
        {"categories", 'c', "CAT1;CAT2", 0, "List of categories as a semicolon-separated string."},
        {"description", 'd', "DESC", 0, "Launcher description/comment."},
        {"stdout", 's', 0, 0, "Redirect to stdout."}
};

#endif //CREATE_LAUNCHER_ARGS_H
