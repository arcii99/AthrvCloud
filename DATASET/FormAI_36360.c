//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello, I am your C Disk Space Analyzer!\n");
    printf("I will help you find what is taking up space on your computer!\n");
    printf("Please enter the directory you want me to analyze: \n");

    char directoryName[100];
    scanf("%s", directoryName);

    printf("Alright, let's check how much space is being used in %s...\n", directoryName);

    char command[1000];
    sprintf(command, "du -sh %s/*", directoryName);

    printf("Running the command: %s...\n", command);

    FILE* output = popen(command, "r");

    if (output == NULL) {
        printf("Oops, something went wrong while running the command. Please try again later.\n");
        exit(1);
    }

    printf("Here is the list of files and directories, sorted by size:\n");

    char line[1000];
    while (fgets(line, sizeof(line), output) != NULL) {
        printf("%s", line);
    }

    pclose(output);

    printf("Thanks for using the C Disk Space Analyzer!\n");
    printf("Would you like to analyze another directory? (y/n)\n");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y') {
        main();
    } else {
        printf("Goodbye!\n");
    }

    return 0;
}