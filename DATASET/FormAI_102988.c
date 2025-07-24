//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000000

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

int main() {
    int option, i, j, count;
    float min_salary, max_salary;
    char search_name[50];
    Record records[MAX_RECORDS];

    srand(time(NULL)); // Initialize random number generator

    // Generate random records
    for (i = 0; i < MAX_RECORDS; i++) {
        records[i].id = i+1;
        sprintf(records[i].name, "Name%d", i+1);
        records[i].age = rand() % 50 + 20;
        records[i].salary = (float)(rand() % 5000 + 500) / 10.0;
    }

    printf("\nData Mining Example Program\n\n");
    printf("1. Display all records\n");
    printf("2. Search records by name\n");
    printf("3. Search records by salary range\n");
    printf("4. Search records by age range\n");
    printf("5. Exit\n\n");

    do {
        printf("Enter option (1-5): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nAll Records\n\n");
                printf("ID\tName\t\tAge\tSalary\n");
                printf("-----------------------------------------------------\n");
                for (i = 0; i < MAX_RECORDS; i++) {
                    printf("%d\t%s\t%d\t%.1f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
                }
                break;

            case 2:
                printf("\nEnter name to search: ");
                scanf("%s", search_name);
                count = 0;
                printf("\nSearch Results for \"%s\"\n\n", search_name);
                printf("ID\tName\t\tAge\tSalary\n");
                printf("-----------------------------------------------------\n");
                for (i = 0; i < MAX_RECORDS; i++) {
                    if (strcmp(records[i].name, search_name) == 0) {
                        printf("%d\t%s\t%d\t%.1f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No records found for \"%s\"\n", search_name);
                } else {
                    printf("\n%d records found for \"%s\"\n", count, search_name);
                }
                break;

            case 3:
                printf("\nEnter minimum salary: ");
                scanf("%f", &min_salary);
                printf("Enter maximum salary: ");
                scanf("%f", &max_salary);
                count = 0;
                printf("\nSearch Results for Salary Range [%.1f - %.1f]\n\n", min_salary, max_salary);
                printf("ID\tName\t\tAge\tSalary\n");
                printf("-----------------------------------------------------\n");
                for (i = 0; i < MAX_RECORDS; i++) {
                    if (records[i].salary >= min_salary && records[i].salary <= max_salary) {
                        printf("%d\t%s\t%d\t%.1f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No records found for Salary Range [%.1f - %.1f]\n", min_salary, max_salary);
                } else {
                    printf("\n%d records found for Salary Range [%.1f - %.1f]\n", count, min_salary, max_salary);
                }
                break;

            case 4:
                printf("\nEnter minimum age: ");
                scanf("%d", &i);
                printf("Enter maximum age: ");
                scanf("%d", &j);
                count = 0;
                printf("\nSearch Results for Age Range [%d - %d]\n\n", i, j);
                printf("ID\tName\t\tAge\tSalary\n");
                printf("-----------------------------------------------------\n");
                for (i = 0; i < MAX_RECORDS; i++) {
                    if (records[i].age >= i && records[i].age <= j) {
                        printf("%d\t%s\t%d\t%.1f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No records found for Age Range [%d - %d]\n", i, j);
                } else {
                    printf("\n%d records found for Age Range [%d - %d]\n", count, i, j);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option! Please enter a number between 1-5.\n");
                break;
        }

        printf("\n");

    } while (option != 5);

    return 0;
}