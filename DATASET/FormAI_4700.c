//FormAI DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int id;
    char name[50];
    float cgpa;
};

int main(){
    struct Student s1 = {1, "John", 3.5};
    struct Student s2 = {2, "Jane", 3.2};
    struct Student s3 = {3, "David", 2.9};
    struct Student s4 = {4, "Emily", 3.8};
    struct Student s5 = {5, "Sam", 2.7};
    struct Student students[5] = {s1, s2, s3, s4, s5};
    float avg_cgpa = 0;
    
    printf("All students:\n");
    for(int i = 0; i < 5; i++){
        printf("Name: %s, ID: %d, CGPA: %.2f\n", students[i].name, students[i].id, students[i].cgpa);
        avg_cgpa += students[i].cgpa;
    }
    avg_cgpa /= 5;
    printf("Average CGPA: %.2f\n\n", avg_cgpa);
    
    printf("Students with CGPA above average:\n");
    for(int i = 0; i < 5; i++){
        if(students[i].cgpa > avg_cgpa){
            printf("Name: %s, ID: %d, CGPA: %.2f\n", students[i].name, students[i].id, students[i].cgpa);
        }
    }
    
    return 0;
}