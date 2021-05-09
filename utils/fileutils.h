//
// Created by dennis on 2021-05-04.
//

#ifndef CREATE_LAUNCHER_FILEUTILS_H
#define CREATE_LAUNCHER_FILEUTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../args/args.h"

int has_file_permission(char *path);
int write_file(char *path, struct arguments args);

#endif //CREATE_LAUNCHER_FILEUTILS_H
