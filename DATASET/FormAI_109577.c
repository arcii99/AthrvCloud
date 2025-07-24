//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>

#define MAX_RECORDS 100

// Define structure to hold record data
struct Record {
    int id;
    char name[20];
    float salary;
    int age;
};

// Define function to print record data
void printRecord(struct Record r) {
    printf("ID: %d\n", r.id);
    printf("Name: %s\n", r.name);
    printf("Salary: %.2f\n", r.salary);
    printf("Age: %d\n", r.age);
    printf("\n");
}

int main() {
    // Define array to hold record data
    struct Record records[MAX_RECORDS];

    // Initialize record data
    records[0].id = 1;
    strcpy(records[0].name, "John Doe");
    records[0].salary = 50000.00;
    records[0].age = 30;

    records[1].id = 2;
    strcpy(records[1].name, "Jane Doe");
    records[1].salary = 60000.00;
    records[1].age = 35;

    records[2].id = 3;
    strcpy(records[2].name, "Bob Smith");
    records[2].salary = 70000.00;
    records[2].age = 40;

    // Print all record data
    printf("All Records:\n");
    for(int i=0; i<3; i++) {
        printRecord(records[i]);
    }

    // Find and print record with highest salary
    printf("Record with Highest Salary:\n");
    struct Record highestSalaryRecord = records[0];
    for(int i=1; i<3; i++) {
        if(records[i].salary > highestSalaryRecord.salary) {
            highestSalaryRecord = records[i];
        }
    }
    printRecord(highestSalaryRecord);

    // Find and print record with oldest age
    printf("Record with Oldest Age:\n");
    struct Record oldestAgeRecord = records[0];
    for(int i=1; i<3; i++) {
        if(records[i].age > oldestAgeRecord.age) {
            oldestAgeRecord = records[i];
        }
    }
    printRecord(oldestAgeRecord);

    return 0;
}