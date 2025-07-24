//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("jokes.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Why don't scientists trust atoms? \n");
    fprintf(file, "Because they make up everything!\n");

    fclose(file);

    file = fopen("jokes.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[100];

    printf("Reading the jokes from file...\n\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    printf("\n");

    fclose(file);

    return 0;
}