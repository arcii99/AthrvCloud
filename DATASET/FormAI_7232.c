//FormAI DATASET v1.0 Category: Data mining ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct Student{
    char name[50];
    int age;
    float marks;
};

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    // Dynamic allocation of memory for array of students 
    struct Student *s = (struct Student*)malloc(n * sizeof(struct Student));
    
    // Reading student data
    for(int i=0;i<n;i++){
        printf("\nEnter details of student %d: \n", i+1);
        printf("Name: ");
        scanf("%s", (s+i)->name);
        printf("Age: ");
        scanf("%d", &(s+i)->age);
        printf("Marks: ");
        scanf("%f", &(s+i)->marks);
    }
    
    // Finding student with highest marks
    float max_marks = (s+0)->marks;
    int max_index = 0;
    for(int i=1;i<n;i++){
        if((s+i)->marks > max_marks){
            max_marks = (s+i)->marks;
            max_index = i;
        }
    }
    printf("\n\nStudent with highest marks:\n");
    printf("Name: %s\n", (s+max_index)->name);
    printf("Age: %d\n", (s+max_index)->age);
    printf("Marks: %f\n", (s+max_index)->marks);
    
    // Freeing the allocated memory
    free(s);
    return 0;
}