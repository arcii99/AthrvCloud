//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    int age;
    char major[50];
};

int main() {

    struct student students[5];

    //taking input from user
    for(int i=0; i<5; i++) {
        printf("Enter name for student %d: ", i+1);
        fgets(students[i].name, 50, stdin);
        
        printf("Enter ID for student %d: ", i+1);
        scanf("%d", &students[i].id);

        printf("Enter age for student %d: ", i+1);
        scanf("%d", &students[i].age);
        getchar(); //to remove the '\n' character from the buffer
        
        printf("Enter major for student %d: ", i+1);
        fgets(students[i].major, 50, stdin);
    }

    //searching for students based on their major
    char query[50];
    printf("\nEnter the major you want to search for: ");
    fgets(query, 50, stdin);
    printf("\nStudents in the %s major:\n", query);
    for(int i=0; i<5; i++) {
        if(strcmp(students[i].major, query)==0) {
            printf("Name: %sID: %d\nAge: %d\nMajor: %s\n\n", students[i].name, students[i].id, students[i].age, students[i].major);
        }
    }

    return 0;
}