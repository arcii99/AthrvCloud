//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

struct Student{
    char name[50];
    int roll;
    float marks;
};

int main(){

    struct Student s[100]; //creating an array of structures
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    printf("Enter the student details:\n");

    //taking input for each student
    for(int i=0;i<n;i++){
        printf("Student %d:\n",i+1);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("Roll no.: ");
        scanf("%d",&s[i].roll);
        printf("Marks: ");
        scanf("%f",&s[i].marks);
    }

    //printing all the details of each student
    printf("\nList of Students:\n");
    for(int i=0;i<n;i++){
        printf("\nStudent %d details:\n",i+1);
        printf("Name: %s\n",s[i].name);
        printf("Roll No: %d\n",s[i].roll);
        printf("Marks: %.2f\n",s[i].marks);
    }

    return 0;
}