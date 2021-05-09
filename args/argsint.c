//
// Created by dennis on 2021-05-05.
//

#include "argsint.h"

void flushin()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n' );
}

int get_string(char *buffer, char *prompt)
{
    printf("%s ", prompt);
    fgets(buffer, (int)(sizeof(buffer)), stdin);
    return 0;
}

int get_bool(char *prompt, int default_answer)
{
    char *buffer = malloc(1);
    printf("%s [Y/n] ", prompt);
    fgets(buffer, (int)(sizeof(buffer)), stdin);
    int answer = tolower(*buffer) == 'y' ? 1
            : tolower(*buffer) == 'n' ? 0
            : default_answer;
    free(buffer);
    return answer;
}

void get_arguments_interactively(struct arguments *arguments)
{
    char *name = malloc(255);
    char *command = malloc(255);
    char *icon = malloc(255);

    get_string(name, "Launcher display name (required):");
    get_string(command, "Command to run when clicking the launcher (required):");
    get_string(icon, "Path to launcher icon:");

    arguments->args[0] = name;
    arguments->args[1] = command;
    arguments->icon = icon;

    free(name);
    free(command);
    free(icon);

    if (!get_bool("Do you want to add advanced options?", 0))
        return;

    int is_terminal;
    char *categories = malloc(STR_DEFAULT_SIZE);
    char *comment = malloc(STR_DEFAULT_SIZE);

    is_terminal = get_bool("Should this command run in a terminal?", 0);
    get_string(categories, "Launcher categories (comma-separated):");
    get_string(comment, "Launcher description:");

    arguments->is_terminal = is_terminal;
    arguments->categories = categories;
    arguments->description = comment;

    free(categories);
    free(comment);
}
