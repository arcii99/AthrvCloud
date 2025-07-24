//FormAI DATASET v1.0 Category: Online Examination System ; Style: protected
#include<stdio.h>
#include<string.h>

struct student{
    char name[50];
    int rollno;
    int marks;
};

int main(){
    int n,i;
    printf("Enter the number of students: ");
    scanf("%d",&n);

    struct student s[n];

    for(i=0;i<n;i++){
        printf("\nEnter the details of student %d:\n",i+1);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("Roll No: ");
        scanf("%d",&s[i].rollno);
        printf("Marks: ");
        scanf("%d",&s[i].marks);
    }

    printf("\n\nStudents who passed the examination:\n");
    printf("Name \t Roll No \t Marks\n");
    for(i=0;i<n;i++){
        if(s[i].marks>=40){
            printf("%s \t %d \t\t %d\n",s[i].name,s[i].rollno,s[i].marks);
        }
    }

    printf("\n\nStudents who failed the examination:\n");
    printf("Name \t Roll No \t Marks\n");
    for(i=0;i<n;i++){
        if(s[i].marks<40){
            printf("%s \t %d \t\t %d\n",s[i].name,s[i].rollno,s[i].marks);
        }
    }

    return 0;
}