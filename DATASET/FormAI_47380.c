//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char occupation[MAX_SIZE];
    float salary;
} Person;

int main() {
    // create an array of persons
    Person people[5] = {
        {"John Doe", 32, "Hacker", 90000.00},
        {"Jane Smith", 26, "Data Analyst", 75000.00},
        {"Jack Johnson", 40, "Cybersecurity Specialist", 115000.00},
        {"Samuel Lee", 47, "Network Engineer", 100000.00},
        {"Anna White", 29, "Software Developer", 85000.00}
    };

    // print the list of people before data mining
    printf("Before data mining:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s is a %d year old %s earning $%.2f per year.\n",
                people[i].name, people[i].age, people[i].occupation, people[i].salary);
    }

    // perform data mining
    for (int i = 0; i < 5; i++) {
        // increase salary by 10% if age is less than 30
        if (people[i].age < 30) {
            people[i].salary *= 1.1;
        }
        // change occupation to "Data Miner" if salary is greater than $100,000
        if (people[i].salary > 100000.00) {
            strcpy(people[i].occupation, "Data Miner");
        }
    }

    // print the list of people after data mining
    printf("\nAfter data mining:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s is a %d year old %s earning $%.2f per year.\n",
                people[i].name, people[i].age, people[i].occupation, people[i].salary);
    }

    return 0;
}