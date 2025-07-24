//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    char file_name[50];
    char line[100];
    int num_lines = 0;

    printf("Hello there! I'm a file handling program that loves to have some fun. What's the name of the file you want to read? ");
    scanf("%s", file_name);

    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Oopsies! I can't find the file :( \n");
        exit(1);
    }

    printf("Yay! I found the file. Let's see what's inside...\n");
    while (fgets(line, sizeof(line), file_pointer) != NULL) {
        printf("Line number %d: %s", num_lines+1, line);
        num_lines++;
    }

    printf("Haha, wasn't that fun? Now let's count the number of lines in the file!\n");
    printf("Drumrolls please...\n");

    printf("The file contains %d lines. Amazing, right?\n", num_lines);

    printf("Thanks for playing with me. See ya next time!");

    fclose(file_pointer);

    return 0;
}