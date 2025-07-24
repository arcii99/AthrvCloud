//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int age;
    float gpa;
};

int main(){
    FILE *fp;
    struct student s;

    // Create database file
    fp = fopen("students.dat", "wb"); 
    if(fp == NULL){
        printf("Error creating database file.");
        exit(1);
    }

    // Add records
    s.id = 101;
    strcpy(s.name, "John Smith");
    s.age = 20;
    s.gpa = 3.5;
    
    fwrite(&s, sizeof(struct student), 1, fp);

    s.id = 102;
    strcpy(s.name, "Jane Doe");
    s.age = 19;
    s.gpa = 3.9;
    
    fwrite(&s, sizeof(struct student), 1, fp);

    // Close file
    fclose(fp);

    // Read records
    fp = fopen("students.dat", "rb");
    if(fp == NULL){
        printf("Error opening database file.");
        exit(1);
    }

    while(fread(&s, sizeof(struct student), 1, fp)){
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("GPA: %.2f\n\n", s.gpa);
    }

    // Close file
    fclose(fp);

    return 0;
}