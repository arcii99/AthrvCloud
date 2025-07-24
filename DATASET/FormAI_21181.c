//FormAI DATASET v1.0 Category: File handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[30];
    int age;
    char program[30];
}student;

int main(){
    student s;
    FILE *fp;

    // Writing to file on one server
    fp = fopen("students.dat", "wb");
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }
    strcpy(s.name, "John");
    s.age = 20;
    strcpy(s.program, "Computer Science");
    fwrite(&s, sizeof(student), 1, fp);
    fclose(fp);

    // Reading from file on another server
    fp = fopen("students.dat", "rb");
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }

    fread(&s, sizeof(student), 1, fp);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Program: %s\n", s.program);

    fclose(fp);

    return 0;
}