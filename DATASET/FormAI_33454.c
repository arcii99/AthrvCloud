//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_me_a_sandwich()
{
    printf("What? Make it yourself.\n");
}

void open_the_pod_bay_doors()
{
    printf("I'm sorry, Dave. I'm afraid I can't do that.\n");
}

void list_files()
{
    printf("Hmm, let me think...\n");
    system("ls");
}

void change_directory(char *dir)
{
    int status;
    status = chdir(dir);
    if (status < 0)
    {
        perror("Error changing directory");
    }
}

void show_current_directory()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current directory: %s\n", cwd);
    } else {
        perror("Error getting current directory");
    }
}

void print_help()
{
    printf("Here are the available commands:\n");
    printf("- make_me_a_sandwich: makes a sandwich\n");
    printf("- open_the_pod_bay_doors: sorry, cannot comply\n");
    printf("- list_files: lists files in the current directory\n");
    printf("- change_directory: changes current directory to the specified one\n");
    printf("- show_current_directory: shows the current directory\n");
    printf("- quit: exits the shell\n");
    printf("- help: shows this help message\n");
}

int main()
{
    char input[100];
    char *arg;
    printf("Welcome to the fun Shell!\n");
    printf("Type 'help' to get started.\n");
    while(1)
    {
        printf(">>> ");
        fgets(input, 100, stdin);
        arg = strtok(input, " \n");
        if (arg == NULL) {
            continue;
        }
        if (strcmp(arg, "make_me_a_sandwich") == 0) {
            make_me_a_sandwich();
        } else if (strcmp(arg, "open_the_pod_bay_doors") == 0) {
            open_the_pod_bay_doors();
        } else if (strcmp(arg, "list_files") == 0) {
            list_files();
        } else if (strcmp(arg, "change_directory") == 0) {
            char *dir = strtok(NULL, " \n");
            if (dir == NULL) {
                printf("Missing argument for change_directory.\n");
            } else {
                change_directory(dir);
            }
        } else if (strcmp(arg, "show_current_directory") == 0) {
            show_current_directory();
        } else if (strcmp(arg, "help") == 0) {
            print_help();
        } else if (strcmp(arg, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Unknown command.\n");
            printf("Type 'help' for a list of available commands.\n");
        }
    }
    return 0;
}