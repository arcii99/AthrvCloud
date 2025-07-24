//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char file_name[100];
    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    FILE *file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("File not found");
        exit(1);
    }

    char line[500];
    int line_num = 0;

    while (fgets(line, 500, file_pointer) != NULL) {
        line_num++;

        char *token = strtok(line, " ");

        while (token != NULL) {

            if (strstr(token, "__attribute__") != NULL) {

                char *attribute = strtok(token, "(");
                attribute = strtok(NULL, ")");
                printf("Line %d - attribute: %s\n", line_num, attribute);
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file_pointer);
    return 0;
}