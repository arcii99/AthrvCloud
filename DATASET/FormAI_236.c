//FormAI DATASET v1.0 Category: System administration ; Style: statistical
/* This program uses statistical analysis to analyze an input file that contains user information, including name, age, and salary. It performs various administrative tasks, such as sorting the data by different categories and calculating summary statistics.

Author: John Doe
Date: August 15, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold user information
typedef struct {
    char name[50];
    int age;
    double salary;
} UserInfo;

// Function to read input file and populate user array
void readInput(UserInfo* users, int size, FILE* inputFile) {
    char buffer[100];
    for (int i = 0; i < size; i++) {
        fgets(buffer, 100, inputFile);
        sscanf(buffer, "%s %d %lf", users[i].name, &users[i].age, &users[i].salary);
    }
}

// Function to sort users by name in ascending order
void sortByName(UserInfo* users, int size) {
    UserInfo temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(users[j].name, users[j + 1].name) > 0) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}

// Function to sort users by age in descending order
void sortByAge(UserInfo* users, int size) {
    UserInfo temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (users[j].age < users[j + 1].age) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}

// Function to sort users by salary in ascending order
void sortBySalary(UserInfo* users, int size) {
    UserInfo temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (users[j].salary > users[j + 1].salary) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}

// Function to calculate summary statistics such as average and standard deviation of user age and salary
void calculateStatistics(UserInfo* users, int size) {
    double ageSum = 0, salarySum = 0, ageAverage, salaryAverage, ageVariance = 0, salaryVariance = 0;
    for (int i = 0; i < size; i++) {
        ageSum += users[i].age;
        salarySum += users[i].salary;
    }
    ageAverage = ageSum / size;
    salaryAverage = salarySum / size;

    for (int i = 0; i < size; i++) {
        ageVariance += (users[i].age - ageAverage) * (users[i].age - ageAverage);
        salaryVariance += (users[i].salary - salaryAverage) * (users[i].salary - salaryAverage);
    }
    ageVariance /= size;
    salaryVariance /= size;

    double ageStdDeviation = sqrt(ageVariance);
    double salaryStdDeviation = sqrt(salaryVariance);

    printf("Average age: %.2lf\n", ageAverage);
    printf("Age standard deviation: %.2lf\n", ageStdDeviation);
    printf("Average salary: $%.2lf\n", salaryAverage);
    printf("Salary standard deviation: $%.2lf\n", salaryStdDeviation);
}

int main() {
    // Open input file and read data into array
    FILE* inputFile = fopen("users.txt", "r");
    if (inputFile == NULL) {
        printf("Error reading input file\n");
        return 1;
    }

    int userCount = 0;
    char buffer[100];
    while (fgets(buffer, 100, inputFile) != NULL) {
        userCount++;
    }
    UserInfo* users = malloc(userCount * sizeof(UserInfo));
    rewind(inputFile);
    readInput(users, userCount, inputFile);
    fclose(inputFile);

    // Perform administrative tasks
    sortByName(users, userCount);
    printf("Users sorted by name:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s %d $%.2lf\n", users[i].name, users[i].age, users[i].salary);
    }

    printf("\n");

    sortByAge(users, userCount);
    printf("Users sorted by age:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s %d $%.2lf\n", users[i].name, users[i].age, users[i].salary);
    }

    printf("\n");

    sortBySalary(users, userCount);
    printf("Users sorted by salary:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s %d $%.2lf\n", users[i].name, users[i].age, users[i].salary);
    }

    printf("\n");

    calculateStatistics(users, userCount);

    // Free memory and return success
    free(users);
    return 0;
}