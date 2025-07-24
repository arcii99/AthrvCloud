//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function to read CSV file */
void read_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return;
    }
    char line[200];
    int count = 0;
    /* read and print all lines from the CSV file */
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == 1) { //skip header
            continue;
        }
        char *record;
        char *fields[10];
        int i = 0;
        record = strtok(line, ",");
        while (record != NULL) {
            fields[i++] = record;
            record = strtok(NULL, ",");
        }
        printf("---------------------\n");
        printf("Name: %s\n", fields[0]);
        printf("Age: %s\n", fields[1]);
        printf("Gender: %s\n", fields[2]);
        printf("Email: %s\n", fields[3]);
        printf("---------------------\n");
    }
    fclose(file);
}

int main() {
    read_csv("data.csv");
    return 0;
}