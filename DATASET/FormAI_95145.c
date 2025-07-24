//FormAI DATASET v1.0 Category: Database querying ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int age;
    int marks;
};

void display(struct student s[], int n) {
    printf("Name\tAge\tMarks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", s[i].name, s[i].age, s[i].marks);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &s[i].age);
        printf("Enter the marks of student %d: ", i+1);
        scanf("%d", &s[i].marks);
    }
    display(s, n);
    char search_name[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].name, search_name) == 0) {
            printf("%s was found. Age: %d, Marks: %d\n", s[i].name, s[i].age, s[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%s was not found.\n", search_name);
    }
    return 0;
}