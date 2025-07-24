//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include<stdio.h>

//declaring a structure to hold information about a student
struct student{
    char name[20];
    int age;
    char gender[10];
    float marks;
};

//function to display information about a student
void display(struct student s){
    printf("\nName: %s", s.name);
    printf("\nAge: %d", s.age);
    printf("\nGender: %s", s.gender);
    printf("\nMarks: %.2f", s.marks);
}

int main(){
    int i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    //declaring an array of structures to hold information about multiple students
    struct student stu[n];
    
    //getting information about each student
    for(i=0; i<n; i++){
        printf("\nEnter the name of student %d: ", i+1);
        scanf("%s", stu[i].name);
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &stu[i].age);
        printf("Enter the gender of student %d: ", i+1);
        scanf("%s", stu[i].gender);
        printf("Enter the marks of student %d: ", i+1);
        scanf("%f", &stu[i].marks);
    }
    
    //displaying information about each student
    for(i=0; i<n; i++){
        printf("\n\nInformation about student %d:\n", i+1);
        display(stu[i]);
    }
    
    return 0;
}