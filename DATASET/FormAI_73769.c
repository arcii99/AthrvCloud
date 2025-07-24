//FormAI DATASET v1.0 Category: Data recovery tool ; Style: modular
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Student;

void printStudent(Student student) {
    printf("ID: %d\nName: %s\nAge: %d\n", student.id, student.name, student.age);
}

int recoverData(Student* ptr, int size) {
    FILE* fp = fopen("data.dat", "rb");
    if(fp == NULL) {
        printf("Error: Unable to open file!\n");
        return 0;
    }
    int readSize = fread(ptr, sizeof(Student), size, fp);
    fclose(fp);
    return readSize;
}

int main() {
    int size;
    printf("Enter number of students: ");
    scanf("%d", &size);
    Student* students = (Student*) malloc(size * sizeof(Student));
    int numRecovered = recoverData(students, size);
    printf("%d students recovered:\n", numRecovered);
    for(int i=0; i<numRecovered; i++) {
        printStudent(students[i]);
        printf("\n");
    }
    free(students);
    return 0;
}