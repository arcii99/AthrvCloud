//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int age;
    int roll_no;
    float marks;
};

int main(){

    struct student stu1,stu2,stu3;
    
    //adding values to student 1
    strcpy(stu1.name,"John");
    stu1.age= 18;
    stu1.roll_no= 1;
    stu1.marks= 92.5;

    //adding values to student 2
    strcpy(stu2.name,"Jane");
    stu2.age= 19;
    stu2.roll_no= 2;
    stu2.marks= 89.6;

    //adding values to student 3
    strcpy(stu3.name,"Robert");
    stu3.age= 18;
    stu3.roll_no= 3;
    stu3.marks= 95.2;

    //creating database using an array of structures
    struct student database[3];
    database[0]=stu1;
    database[1]=stu2;
    database[2]=stu3;

    //displaying the database
    printf("Student Name\tAge\tRoll Number\tMarks\n");
    for(int i=0;i<3;i++){
        printf("%s\t\t%d\t%d\t\t%.2f\n",database[i].name,database[i].age,database[i].roll_no,database[i].marks);
    }

    return 0;
}