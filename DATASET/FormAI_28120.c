//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char name[20];
    int age;
    double salary;
} Employee;

int main()
{
    srand(time(NULL));
    Employee employees[10];
    for (int i = 0; i < 10; i++) {
        employees[i].id = rand() % 1000 + 100;
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", employees[i].name);
        printf("Enter age for employee %d: ", i + 1);
        scanf("%d", &employees[i].age);
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%lf", &employees[i].salary);
    }
    printf("Employee database loaded. Enter an ID to search for: ");
    int searchId;
    scanf("%d", &searchId);
    Employee *searchResult = NULL;
    for (int i = 0; i < 10; i++) {
        if (employees[i].id == searchId) {
            searchResult = &employees[i];
            break;
        }
    }
    if (searchResult != NULL) {
        printf("ID: %d, Name: %s, Age: %d, Salary: %.2lf\n",
            searchResult->id, searchResult->name, searchResult->age, searchResult->salary);
    }
    else {
        printf("No employee found with ID %d.\n", searchId);
    }
    return 0;
}