//
// Created by dennis on 2021-05-02.
//

#ifndef CREATE_LAUNCHER_ARGS_H
#define CREATE_LAUNCHER_ARGS_H

#include <argp.h>

extern char const *argp_program_version;
extern char const *argp_program_bug_address;

struct arguments
{
    char *args[2];      // NAME and COMMAND
    char *icon;         // Argument for -i
    char *outfile;      // Argument for -o
    int is_terminal;    // Argument for -t
    char *categories;   // Argument for -c
    char *description;  // Argument for -d
    int is_stdout;      // Argument for --stdout
    int is_interactive; // Argument for no args
};

static struct argp_option options[6];

error_t parse_opt (int key, char *arg, struct argp_state *state);

extern char const args_doc[];

extern char const doc[];

#endif //CREATE_LAUNCHER_ARGS_H
