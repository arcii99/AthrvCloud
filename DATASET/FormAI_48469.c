//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to parse the CSV file
void read_csv(FILE *fp) {
    char buffer[1024];
    char *field;
    int row = 1;
    
    // print a header for our data
    printf("___________________________________\n");
    printf("|    NAME     |    AGE    | STATUS |\n");
    printf("|-------------|-----------|--------|\n");
    
    // loop through each line in the file
    while (fgets(buffer, 1024, fp)) {
        int column = 1;
        printf("|");
        
        // parse the fields in the line
        field = strtok(buffer, ",");
        while (field) {
            printf(" %s", field);
            if (column == 1) {
                for (int i = strlen(field); i < 13; i++) {
                    printf(" ");
                }
            } else if (column == 2) {
                for (int i = strlen(field); i < 9; i++) {
                    printf(" ");
                }
            } else {
                for (int i = strlen(field); i < 8; i++) {
                    printf(" ");
                }
            }
            printf("|");
            field = strtok(NULL, ",");
            column++;
        }
        printf("\n");
        row++;
    }
    printf("___________________________________\n");
}

int main() {
    FILE *fp;
    char filename[] = "medieval_data.csv";
    
    // attempt to open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // read the data from the file
    read_csv(fp);
    
    // close the file
    fclose(fp);
    return 0;
}