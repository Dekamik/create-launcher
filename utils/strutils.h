//
// Created by dennis on 2021-05-02.
//

#ifndef CREATE_LAUNCHER_STRUTILS_H
#define CREATE_LAUNCHER_STRUTILS_H

#include <string.h>
#include <ctype.h>

char *replace_char(char *str, char find, char replace);
char *to_lower(char *str);
int count_char(char *str, char find);
char *split(char *buffer, char *str, char delimiter);

#endif //CREATE_LAUNCHER_STRUTILS_H
