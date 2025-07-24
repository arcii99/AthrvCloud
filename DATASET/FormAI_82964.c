//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>

// defining the structure for our database
struct student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    int option;
    int i;
    // initializing an array to store student records
    struct student records[10];
    int count = 0; // to keep track of number of records stored

    // main menu for database
    while(1) {
        printf("\n--Student Database--");
        printf("\n1. Add Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Record");
        printf("\n4. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        // perform action according to user input
        switch(option) {
            case 1: // Adding a new record
                printf("\nEnter student ID: ");
                scanf("%d", &records[count].id);

                printf("Enter student name: ");
                scanf("%s", records[count].name);

                printf("Enter student GPA: ");
                scanf("%f", &records[count].gpa);

                count++; // incrementing the count of records
                break;

            case 2: // Displaying all records
                if(count == 0) {
                    printf("\nNo records found.");
                } else {
                    printf("\nAll Records:");
                    printf("\nID\tName\tGPA");

                    for(i=0; i<count; i++) {
                        printf("\n%d\t%s\t%.2f", records[i].id, records[i].name, records[i].gpa);
                    }
                }
                break;

            case 3: // Searching a record by ID
                if(count == 0) {
                    printf("\nNo records found.");
                } else {
                    int search_id;
                    printf("\nEnter student ID to search: ");
                    scanf("%d", &search_id);

                    for(i=0; i<count; i++) {
                        if(records[i].id == search_id) {
                            printf("\nRecord Found:");
                            printf("\nID\tName\tGPA");
                            printf("\n%d\t%s\t%.2f", records[i].id, records[i].name, records[i].gpa);
                            break;
                        }
                    }
                    if(i == count) {
                        printf("\nRecord not found.");
                    }
                }
                break;

            case 4: // Exit
                return 0;

            default:
                printf("\nInvalid option.");
        }
     }
     return 0;
}