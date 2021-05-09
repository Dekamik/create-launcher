//
// Created by dennis on 2021-05-05.
//

#ifndef CREATE_LAUNCHER_ARGSINT_H
#define CREATE_LAUNCHER_ARGSINT_H

#define STR_DEFAULT_SIZE 255 * sizeof(char)

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "args.h"

int get_string(char *buffer, char *prompt);
int get_bool(char *prompt, int default_answer);
void get_arguments_interactively(struct arguments *arguments);

#endif //CREATE_LAUNCHER_ARGSINT_H
