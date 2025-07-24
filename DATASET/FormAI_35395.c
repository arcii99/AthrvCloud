//FormAI DATASET v1.0 Category: Database querying ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Student {
    char name[20];
    int age;
    float gpa;
};

int main() {
    struct Student students[5] = {
        {"John", 21, 3.5},
        {"Emily", 20, 3.8},
        {"Jacob", 22, 3.2},
        {"Samantha", 23, 3.9},
        {"Alex", 19, 3.6}
    };
    
    char query[20];
    printf("Enter name to search: ");
    scanf("%s", query);
    
    bool found = false;
    float lowest_gpa = 4.0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(students[i].name, query) == 0) {
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("GPA: %0.1f\n", students[i].gpa);
            found = true;
        } else {
            if (students[i].gpa < lowest_gpa) {
                lowest_gpa = students[i].gpa;
            }
        }
    }
    
    if (!found) {
        printf("Sorry, unable to find student.\n");
    }
    
    printf("Lowest GPA: %0.1f\n", lowest_gpa);
    
    return 0;
}