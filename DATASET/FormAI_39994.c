//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Funniest CSV Reader!\n");
    printf("Don't be shy, enter the name of your CSV file here: ");
    char filename[100];
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;
    FILE* csv_file = fopen(filename, "r");

    if (csv_file == NULL) {
        printf("We couldn't find the file you were looking for.\n");
        printf("Please try again with a different file: ");
        fgets(filename, 100, stdin);
        filename[strcspn(filename, "\n")] = 0;
        csv_file = fopen(filename, "r");
        if (csv_file == NULL) {
            printf("We're sorry, we couldn't find that file either.\n");
            return 1;
        }
        printf("Great, we found it this time! Let's continue...\n");
    }

    printf("Now let's get to the juicy stuff...taking a look at that CSV data!\n");
    printf("Here are the contents of your CSV file:\n");

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, csv_file)) != -1) {
        printf("%s", line);
    }

    printf("Wow, that was exciting! Thanks for using the Funniest CSV Reader. We guarantee you won't find anything funnier out there.\n");

    fclose(csv_file);
    if (line) {
        free(line);
    }
    return 0;
}