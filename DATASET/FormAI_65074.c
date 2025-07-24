//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>

int main() {
    char filename[50];
    printf("Hello! Let's read a CSV file!\n");
    printf("Please enter the name of the file: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Oops! Something went wrong. Cannot open file.\n");
        return 1;
    }

    printf("Reading contents of %s\n", filename);
    char buffer[1024];
    int row_count = 0;
    int field_count = 0;
    while (fgets(buffer, 1024, fp)) {
        printf("%s", buffer);
        row_count++;

        if (row_count == 1) { // Header row
            char *field = strtok(buffer, ",");
            while (field) {
                printf("Header field %d: %s\n", field_count, field);
                field = strtok(NULL, ",");
                field_count++;
            }
        } else { // Data row
            char *field = strtok(buffer, ",");
            field_count = 0;
            while (field) {
                printf("Field %d: %s\n", field_count, field);
                field = strtok(NULL, ",");
                field_count++;
            }
        }
    }

    printf("Number of rows: %d\n", row_count);
    printf("Number of fields: %d\n", field_count);

    fclose(fp);
    printf("All done! We successfully read the CSV file.\n");

    return 0;
}