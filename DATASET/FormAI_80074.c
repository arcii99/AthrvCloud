//FormAI DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input[1000];
    char search[50];
    int count = 0;

    if (argc > 1) {
        // Read input from file
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("Error opening file: %s\n", argv[1]);
            return 1;
        }
        while (fgets(input, 1000, file)) {
            char *token = strtok(input, " ");
            while (token != NULL) {
                if (strcmp(token, argv[2]) == 0) {
                    count++;
                }
                token = strtok(NULL, " ");
            }
        }
        fclose(file);
    } else {
        // Read input from command line
        printf("Enter text: ");
        fgets(input, 1000, stdin);
        printf("Enter word to search: ");
        fgets(search, 50, stdin);
        search[strcspn(search, "\n")] = 0;

        char *token = strtok(input, " ");
        while (token != NULL) {
            if (strcmp(token, search) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }

    printf("%s appears %d times.\n", search, count);

    return 0;
}