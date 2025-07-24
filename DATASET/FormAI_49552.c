//FormAI DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct student {
    int id;
    char name[20];
    int age;
};

void print_student(struct student s) {
    printf("%d %s %d\n", s.id, s.name, s.age);
}

int main() {
    struct student* students[MAX];
    int size = 0;
    int choice;
    
    while (1) {
        printf("1. Add student\n");
        printf("2. Print all students\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                if (size >= MAX) {
                    printf("Database is full!\n");
                    break;
                }
                
                struct student* new_student = malloc(sizeof(struct student));
                printf("Enter student id: ");
                scanf("%d", &new_student->id);
                printf("Enter student name: ");
                scanf("%s", new_student->name);
                printf("Enter student age: ");
                scanf("%d", &new_student->age);
                
                students[size] = new_student;
                size++;
                break;
            }
            case 2: {
                if (size == 0) {
                    printf("Database is empty!\n");
                    break;
                }
                
                for (int i = 0; i < size; i++) {
                    print_student(*students[i]);
                }
                
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }   
    }
    
    return 0;
}