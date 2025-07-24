//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char name[100];
    int age;
    char gender[10];
    float gpa;
};

int main() {
    FILE *csv_file;
    csv_file = fopen("students.csv", "r");
    
    if(csv_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    printf("Students:\n");
    printf("Name, Age, Gender, GPA\n");
    
    char line[100];
    while(fgets(line, sizeof(line), csv_file)) {
        char *token = strtok(line, ",");
        struct Student student;
        
        strcpy(student.name, token);
        token = strtok(NULL, ",");
        student.age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(student.gender, token);
        token = strtok(NULL, ",");
        student.gpa = atof(token);
        
        printf("%s, %d, %s, %.2f\n", student.name, student.age, student.gender, student.gpa);
    }
    
    fclose(csv_file);
    return 0;
}