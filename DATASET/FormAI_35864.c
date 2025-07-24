//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Define a global variable to store each line of the CSV file
char csv_content[100][100];

// Function to split each line of the CSV file by comma and store it in the global variable
void read_csv_file(FILE *fp) {
    char line[100];
    int row_count = 0;

    while (fgets(line, 100, fp)) {
        char *temp = strtok(line, ",");
        int column_count = 0;
        while (temp != NULL) {
            strcpy(csv_content[row_count*10 + column_count], temp);
            temp = strtok(NULL, ",");
            column_count++;
        }
        row_count++;
    }
}

int main() {
    FILE *fp = fopen("users.csv", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    read_csv_file(fp);

    fclose(fp);

    // Print the contents of the CSV file after splitting
    for (int i=0; i<10; i++) {
        for (int j=0; j<5; j++) {
            printf("%s\t", csv_content[i*10 + j]);
        }
        printf("\n");
    }

    return 0;
}