//FormAI DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Record {
    int id;
    char name[20];
    int age;
    float salary;
};

int main() {
    int num_records = 0;
    printf("Enter the number of records to store: ");
    scanf("%d", &num_records);
    
    // Allocate memory for the records
    struct Record* records = malloc(num_records * sizeof(struct Record));
    
    // Randomly generate record information
    srand(time(NULL));
    for (int i = 0; i < num_records; i++) {
        records[i].id = i + 1;
        sprintf(records[i].name, "Worker%d", i + 1);
        records[i].age = rand() % 50 + 18;
        records[i].salary = ((float)(rand() % 5000 + 500)) + (((float)(rand() % 100)) / 100);
    }
    
    // Print all records
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Salary: $%.2f\n", records[i].salary);
    }
    
    // Free allocated memory
    free(records);
    
    return 0;
}