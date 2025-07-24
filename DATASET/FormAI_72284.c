//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

typedef struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

int main() {
    // Display Menu
    int choice;
    do {
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Record
                if (num_records >= MAX_RECORDS) {
                    printf("Database is full! Cannot add record.\n");
                    break;
                }

                Record new_record;
                printf("Enter name: ");
                scanf("%s", new_record.name);
                printf("Enter age: ");
                scanf("%d", &new_record.age);
                printf("Enter gender (M/F): ");
                scanf(" %c", &new_record.gender);

                records[num_records++] = new_record;

                printf("Record added successfully!\n");
                break;
            case 2:
                // Search Record
                char name_to_search[MAX_NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name_to_search);

                int i;
                for (i = 0; i < num_records; i++) {
                    if (strcmp(records[i].name, name_to_search) == 0) {
                        printf("Name: %s\n", records[i].name);
                        printf("Age: %d\n", records[i].age);
                        printf("Gender: %c\n", records[i].gender);
                        break;
                    }
                }
                if (i == num_records) {
                    printf("Record not found!\n");
                }
                break;
            case 3:
                // Delete Record
                char name_to_delete[MAX_NAME_LENGTH];
                printf("Enter name to delete: ");
                scanf("%s", name_to_delete);

                for (i = 0; i < num_records; i++) {
                    if (strcmp(records[i].name, name_to_delete) == 0) {
                        // Shift all records to the left
                        for (int j = i; j < num_records - 1; j++) {
                            records[j] = records[j + 1];
                        }
                        num_records--;
                        printf("Record deleted successfully!\n");
                        break;
                    }
                }
                if (i == num_records) {
                    printf("Record not found!\n");
                }
                break;
            case 4:
                // Display All Records
                if (num_records == 0) {
                    printf("Database is empty!\n");
                    break;
                }

                for (i = 0; i < num_records; i++) {
                    printf("Record #%d:\n", i + 1);
                    printf("Name: %s\n", records[i].name);
                    printf("Age: %d\n", records[i].age);
                    printf("Gender: %c\n", records[i].gender);
                    printf("\n");
                }
                break;
            case 5:
                // Exit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}