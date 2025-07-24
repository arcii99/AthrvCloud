//FormAI DATASET v1.0 Category: Data mining ; Style: mind-bending
#include <stdio.h>

// define a struct to hold data
typedef struct {
    int age;
    float salary;
    char profession[50];
} Person;

int main() {
    // create an array of person data
    Person people[5] = {
        {35, 80000.0, "Software Developer"},
        {42, 120000.0, "Systems Analyst"},
        {28, 60000.0, "Graphic Designer"},
        {50, 150000.0, "CTO"},
        {38, 100000.0, "Product Manager"}
    };
    
    // loop through array and find the person with the highest salary
    float max_salary = 0.0;
    int max_salary_index = 0;
    for (int i = 0; i < 5; i++) {
        if (people[i].salary > max_salary) {
            max_salary = people[i].salary;
            max_salary_index = i;
        }
    }
    
    // print out the person with the highest salary
    printf("The person with the highest salary is:\n");
    printf("Age: %d\n", people[max_salary_index].age);
    printf("Salary: %.2f\n", people[max_salary_index].salary);
    printf("Profession: %s\n", people[max_salary_index].profession);

    return 0;
}