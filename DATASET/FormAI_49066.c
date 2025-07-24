//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    FILE *file;

    printf("Enter a message: ");
    fgets(input, MAX_SIZE, stdin);

    file = fopen("message.txt", "w");

    if (file == NULL) {
        printf("Unable to open file...\n");
        return 1;
    }

    fprintf(file, "%s", input);
    fclose(file);

    printf("Message saved to file!\n");

    file = fopen("message.txt", "r");

    if (file == NULL) {
        printf("Unable to open file...\n");
        return 1;
    }

    printf("Contents of file:\n");

    while (fgets(input, MAX_SIZE, file) != NULL) {
        printf("%s", input);
    }

    fclose(file);

    return 0;
}