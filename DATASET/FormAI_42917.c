//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define DATASET_COUNT 100  // define the size of the dataset
#define MIN_AGE 18  // define the minimum age in the dataset
#define MAX_AGE 65  // define the maximum age in the dataset

/* structure of a person in the dataset */
typedef struct {
    char name[20];
    int age;
    float salary;
} Person;

void printPerson(Person p);

int main() {
    Person dataset[DATASET_COUNT];  // create an array to store the dataset
    
    // fill the dataset with randomly generated data
    for (int i = 0; i < DATASET_COUNT; i++) {
        // generate a random name
        char name[] = {'A' + rand() % 26, 'a' + rand() % 26, 'a' + rand() % 26, '\0'};
        // generate a random age between MIN_AGE and MAX_AGE
        int age = MIN_AGE + rand() % (MAX_AGE - MIN_AGE + 1);
        // generate a random salary between 20000 and 100000
        float salary = 20000.0 + (float)rand() / RAND_MAX * (100000.0 - 20000.0);
        dataset[i].age = age;
        dataset[i].salary = salary;
        sprintf(dataset[i].name, "%s%d", name, i+1);
    }
    
    /* mining starts here */
    
    // find the average salary of people above the age of 40
    float averageSalary = 0.0;
    int count = 0;
    for (int i = 0; i < DATASET_COUNT; i++) {
        if (dataset[i].age > 40) {
            averageSalary += dataset[i].salary;
            count++;
        }
    }
    averageSalary = averageSalary / count;
    printf("Average salary of people above the age of 40: %.2f\n", averageSalary);
    
    // find the highest salary among people below the age of 30
    float highestSalary = 0.0;
    for (int i = 0; i < DATASET_COUNT; i++) {
        if (dataset[i].age < 30 && dataset[i].salary > highestSalary) {
            highestSalary = dataset[i].salary;
        }
    }
    printf("Highest salary among people below the age of 30: %.2f\n", highestSalary);
    
    // print the details of people with salary above the average salary
    printf("Details of people with salary above the average salary:\n");
    for (int i = 0; i < DATASET_COUNT; i++) {
        if (dataset[i].salary > averageSalary) {
            printPerson(dataset[i]);
        }
    }
    
    return 0;
}

/* function to print the details of a person in a formatted manner */
void printPerson(Person p) {
    printf("%s\t%d\t%.2f\n", p.name, p.age, p.salary);
}