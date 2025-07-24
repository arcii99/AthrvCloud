//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char* name;
} student;

student* create_student(int id, char* name) {
    student* new_student = malloc(sizeof(student));
    new_student->id = id;
    new_student->name = malloc(strlen(name) + 1);
    strcpy(new_student->name, name);
    return new_student;
}

void destroy_student(student* std) {
    free(std->name);
    free(std);
}

int main() {
    student* student1 = create_student(1, "John");
    student* student2 = create_student(2, "Jane");

    printf("Student 1: %s (ID %d)\n", student1->name, student1->id);
    printf("Student 2: %s (ID %d)\n", student2->name, student2->id);

    destroy_student(student1);
    destroy_student(student2);

    return 0;
}