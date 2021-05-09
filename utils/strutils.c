//
// Created by dennis on 2021-05-02.
//

#include "strutils.h"

char *replace_char(char *str, char find, char replace)
{
    char *current_pos = strchr(str, find);
    while (current_pos)
    {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}

char *to_lower(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

int count_char(char *str, char find)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        count += (str[i] == find);
    }
    return count;
}

char *split(char *buffer, char *str, char delimiter)
{
    int current = 0;
    char *token = strtok(str, &delimiter);

    while(token != NULL)
    {
        buffer[current++] = *token;
        token = strtok(NULL, &delimiter);
    }
}
