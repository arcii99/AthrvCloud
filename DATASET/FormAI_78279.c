//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define INDEX_NAME_SIZE 32

typedef struct {
    int id;
    char name[32];
    int age;
    float salary;
} Record;

typedef struct {
    char name[INDEX_NAME_SIZE];
    int* data;
    int size;
} Index;

int main() {
    Record records[MAX_RECORDS];
    Index ageIndex, salaryIndex;
    int numRecords = 0;
    int i, id, choice;
    float minSalary;

    // Initialize index arrays
    ageIndex.data = malloc(MAX_RECORDS * sizeof(int));
    salaryIndex.data = malloc(MAX_RECORDS * sizeof(int));
    ageIndex.size = 0;
    salaryIndex.size = 0;

    // Populate records array
    numRecords = 5;
    records[0].id = 1;
    strcpy(records[0].name, "John");
    records[0].age = 30;
    records[0].salary = 50000.0;

    records[1].id = 2;
    strcpy(records[1].name, "Jane");
    records[1].age = 25;
    records[1].salary = 60000.0;

    records[2].id = 3;
    strcpy(records[2].name, "Bob");
    records[2].age = 45;
    records[2].salary = 80000.0;

    records[3].id = 4;
    strcpy(records[3].name, "Alice");
    records[3].age = 35;
    records[3].salary = 75000.0;

    records[4].id = 5;
    strcpy(records[4].name, "Tom");
    records[4].age = 40;
    records[4].salary = 90000.0;

    // Populate index arrays
    for (i = 0; i < numRecords; i++) {
        if (records[i].age >= 30) {
            ageIndex.data[ageIndex.size] = i;
            ageIndex.size++;
        }

        if (records[i].salary >= 60000.0) {
            salaryIndex.data[salaryIndex.size] = i;
            salaryIndex.size++;
        }
    }

    // Print menu
    printf("Database indexing system\n");
    printf("1. Search record by ID\n");
    printf("2. Search records by minimum salary\n");
    printf("3. Search records by minimum age\n");
    printf("4. Exit\n");

    do {
        // Prompt user for choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Search record by ID
                printf("Enter ID: ");
                scanf("%d", &id);

                for (i = 0; i < numRecords; i++) {
                    if (records[i].id == id) {
                        printf("Record found:\n");
                        printf("ID: %d\n", records[i].id);
                        printf("Name: %s\n", records[i].name);
                        printf("Age: %d\n", records[i].age);
                        printf("Salary: %.2f\n", records[i].salary);
                        break;
                    }
                }

                if (i == numRecords) {
                    printf("Record not found\n");
                }

                break;

            case 2:
                // Search records by minimum salary
                printf("Enter minimum salary: ");
                scanf("%f", &minSalary);

                for (i = 0; i < salaryIndex.size; i++) {
                    int recordIndex = salaryIndex.data[i];

                    if (records[recordIndex].salary >= minSalary) {
                        printf("Record found:\n");
                        printf("ID: %d\n", records[recordIndex].id);
                        printf("Name: %s\n", records[recordIndex].name);
                        printf("Age: %d\n", records[recordIndex].age);
                        printf("Salary: %.2f\n", records[recordIndex].salary);
                    }
                }

                break;

            case 3:
                // Search records by minimum age
                printf("Enter minimum age: ");
                scanf("%d", &id);

                for (i = 0; i < ageIndex.size; i++) {
                    int recordIndex = ageIndex.data[i];

                    if (records[recordIndex].age >= id) {
                        printf("Record found:\n");
                        printf("ID: %d\n", records[recordIndex].id);
                        printf("Name: %s\n", records[recordIndex].name);
                        printf("Age: %d\n", records[recordIndex].age);
                        printf("Salary: %.2f\n", records[recordIndex].salary);
                    }
                }

                break;

            case 4:
                // Exit program
                printf("Exiting program...\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    // Free memory
    free(ageIndex.data);
    free(salaryIndex.data);

    return 0;
}