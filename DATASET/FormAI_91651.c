//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error reading file '%s'", filename);
        return 1;
    }

    char line[100];
    fgets(line, 100, file); // skip first line (header)

    while (fgets(line, 100, file)) {
        char *token;
        token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}