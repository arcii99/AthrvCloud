//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int rollnumber;
    char name[20];
    int age;
    float marks;
};

int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);

    struct student *s = (struct student*)malloc(n*sizeof(struct student));

    for(int i=0; i<n; i++){
        printf("\nEnter details of student %d\n",(i+1));
        printf("Roll number: ");
        scanf("%d",&s[i].rollnumber);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("Age: ");
        scanf("%d",&s[i].age);
        printf("Marks: ");
        scanf("%f",&s[i].marks);
    }

    printf("\n\nDetails of all students:\n\n");
    printf("Roll Number\tName\tAge\tMarks\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%s\t%d\t%.2f\n",s[i].rollnumber,s[i].name,s[i].age,s[i].marks);
    }

    free(s);
    return 0;
}