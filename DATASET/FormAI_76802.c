//FormAI DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[20];
    int age;
    float marks;
};

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);

    struct student *ptr;
    ptr = (struct student*)malloc(n*sizeof(struct student));
    if(ptr==NULL){
        printf("Memory allocation failed!");
        exit(0);
    }

    for(int i=0;i<n;i++){
        printf("Enter details of student %d: \n",i+1);
        printf("Name: ");
        scanf("%s",(ptr+i)->name);
        printf("Age: ");
        scanf("%d",&(ptr+i)->age);
        printf("Marks: ");
        scanf("%f",&(ptr+i)->marks);
    }

    printf("\nDetails of students: \n");
    for(int i=0;i<n;i++){
        printf("Name: %s, Age: %d, Marks: %.2f\n",(ptr+i)->name,(ptr+i)->age,(ptr+i)->marks);
    }

    free(ptr); //freeing the allocated memory

    return 0;
}