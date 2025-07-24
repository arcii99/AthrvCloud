//FormAI DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for storing the data
struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

int main() {
    // Create database file "employees.dat"
    FILE *fp;
    fp = fopen("employees.dat", "wb"); // Open file for writing in binary mode
    
    // Define data to populate database with
    struct Employee employees[5] = {
        {1, "John Doe", 25, 2000},
        {2, "Jane Smith", 30, 3000},
        {3, "Bob Johnson", 40, 4000},
        {4, "Karen Williams", 35, 3500},
        {5, "Tom Davis", 45, 4500}
    };
    
    // Write data to database
    for (int i = 0; i < 5; i++) {
        fwrite(&employees[i], sizeof(struct Employee), 1, fp);
    }
    
    // Close database file
    fclose(fp);
    
    // Reopen database file for reading
    fp = fopen("employees.dat", "rb"); // Open file for reading in binary mode
    
    // Query the database for employees over the age of 35
    printf("Employees over the age of 35:\n");
    for (int i = 0; i < 5; i++) {
        struct Employee emp;
        fread(&emp, sizeof(struct Employee), 1, fp);
        if (emp.age > 35) {
            printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", emp.id, emp.name, emp.age, emp.salary);
        }
    }
    
    // Close database file
    fclose(fp);
    
    return 0;
}