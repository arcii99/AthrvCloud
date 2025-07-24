//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char firstName[20];
    char lastName[20];
    int age;
    float salary;
};

int main() {
    printf("Loading CSV data...\n");
    FILE * csvFile = fopen("data.csv", "r");
    if (!csvFile) {
        printf("Error: could not open file.\n");
        return 1;
    }

    struct Record records[100];
    char line[100];
    int count = 0;
    while (fgets(line, 100, csvFile)) {
        char * token = strtok(line, ",");
        strcpy(records[count].firstName, token);

        token = strtok(NULL, ",");
        strcpy(records[count].lastName, token);

        token = strtok(NULL, ",");
        records[count].age = atoi(token);

        token = strtok(NULL, ",");
        records[count].salary = atof(token);

        count++;
    }

    fclose(csvFile);
    printf("CSV data loaded successfully.\n");

    printf("Printing records...\n");
    printf("First Name\tLast Name\tAge\tSalary\n");
    for (int i=0; i<count; i++) {
        printf("%s\t\t%s\t\t%d\t%.2f\n", records[i].firstName, records[i].lastName, records[i].age, records[i].salary);
    }

    return 0;
}