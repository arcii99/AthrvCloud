//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the hilarious CSV Reader! Don't worry, we don't bite (much).\n");

    FILE *file_pointer;
    file_pointer = fopen("data.csv", "r");

    if (file_pointer == NULL) {
        printf("Uh oh, looks like we couldn't find your file. Did you name it data.csv?\n");
        return 1;
    }

    char line[200];
    int row_counter = 0;
    printf("Your CSV data:\n");

    while (fgets(line, sizeof(line), file_pointer)) {
        row_counter++;

        if (row_counter == 1) {
            printf("Header row: %s", line);
        } else {
            char *field;
            int column_counter = 1;
            printf("Row %d:", row_counter);

            field = strtok(line, ",");
            while (field != NULL) {
                printf(" Column %d: %s", column_counter, field);
                field = strtok(NULL, ",");
                column_counter++;
            }
            printf("\n");
        }
    }

    fclose(file_pointer);
    printf("Thanks for using our CSV Reader! Don't forget to always wash your hands before coding!\n");
    return 0;
}