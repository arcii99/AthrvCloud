//FormAI DATASET v1.0 Category: Online Examination System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int id;
    int age;
    float grade;
};

void addStudent();
void displayAllStudents();
void searchByStudentName();
void searchByStudentID();
void deleteStudent();
void updateStudentInfo();

int main()
{
    int choice;
    printf("\n\nWelcome to the Online Examination System\n\n");

    while(1)
    {
        printf("\nEnter your choice: \n\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search By Student Name\n");
        printf("4. Search By Student ID\n");
        printf("5. Delete Student\n");
        printf("6. Update Student Info\n");
        printf("7. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchByStudentName();
                break;
            case 4:
                searchByStudentID();
                break;  
            case 5:
                deleteStudent();
                break;
            case 6:
                updateStudentInfo();
                break;    
            case 7:
                exit(0);
                break;
            default:
                printf("\nInvalid choice, try again!\n");
        }
    }
    return 0;
}

void addStudent()
{
    struct student s;
    FILE *fp;
    fp = fopen("student.dat", "ab");

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    printf("\nEnter Student Name: ");
    scanf("%s", s.name);
    printf("\nEnter Student Age: ");
    scanf("%d", &s.age);
    printf("\nEnter Student Grade: ");
    scanf("%f", &s.grade);

    fwrite(&s, sizeof(s), 1, fp);

    printf("\n\nStudent Record Added Successfully\n\n");

    fclose(fp);
}

void displayAllStudents()
{
    struct student s;
    FILE *fp;
    fp = fopen("student.dat", "rb");

    printf("\n\nAll Student Records\n\n");

    while(fread(&s, sizeof(s), 1, fp)==1)
    {
        printf("Student ID: %d\n", s.id);
        printf("Student Name: %s\n", s.name);
        printf("Student Age: %d\n", s.age);
        printf("Student Grade: %.2f\n", s.grade);
        printf("--------------------------------------\n");
    }

    fclose(fp);
}

void searchByStudentName()
{
    struct student s;
    FILE *fp;
    fp = fopen("student.dat", "rb");

    char searchName[50];
    int found = 0;

    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);

    while(fread(&s, sizeof(s), 1, fp)==1)
    {
        if(strcmp(searchName, s.name) == 0)
        {

        printf("\n\nStudent Record Found\n\n");
        printf("Student ID: %d\n", s.id);
        printf("Student Name: %s\n", s.name);
        printf("Student Age: %d\n", s.age);
        printf("Student Grade: %.2f\n", s.grade);

        found = 1;
        break;

        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("\n\nRecord not found for name %s\n\n", searchName);
    }
}

void searchByStudentID()
{
    struct student s;
    FILE *fp;
    fp = fopen("student.dat", "rb");

    int searchID;
    int found = 0;

    printf("\nEnter the student ID to search: ");
    scanf("%d", &searchID);

    while(fread(&s, sizeof(s), 1, fp)==1)
    {
        if(searchID == s.id)
        {

        printf("\n\nStudent Record Found\n\n");
        printf("Student ID: %d\n", s.id);
        printf("Student Name: %s\n", s.name);
        printf("Student Age: %d\n", s.age);
        printf("Student Grade: %.2f\n", s.grade);

        found = 1;
        break;

        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("\n\nRecord not found for ID %d\n\n", searchID);
    }
}

void deleteStudent()
{
    struct student s;
    FILE *fp, *temp;
    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    int deleteID;
    int found = 0;

    printf("\nEnter the student ID to delete: ");
    scanf("%d", &deleteID);

    while(fread(&s, sizeof(s), 1, fp)==1)
    {
        if(deleteID == s.id)
        {

        found = 1;
        printf("\n\nStudent Record Deleted Successfully\n\n");

        }
        else
        {
        fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if(found == 0)
    {
        printf("\n\nRecord not found for ID %d\n\n", deleteID);
    }
    else
    {
        remove("student.dat");
        rename("temp.dat", "student.dat");
    }
}

void updateStudentInfo()
{
    struct student s1, s2;
    FILE *fp, *temp;
    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    int updateID;
    int found = 0;

    printf("\nEnter the student ID to update: ");
    scanf("%d", &updateID);

    while(fread(&s1, sizeof(s1), 1, fp)==1)
    {
        if(updateID == s1.id)
        {

            found = 1;

            printf("\nEnter new student ID: ");
            scanf("%d", &s2.id);
            printf("\nEnter new student Name: ");
            scanf("%s", s2.name);
            printf("\nEnter new student Age: ");
            scanf("%d", &s2.age);
            printf("\nEnter new student Grade: ");
            scanf("%f", &s2.grade);
        
            fwrite(&s2, sizeof(s2), 1, temp);

            printf("\n\nStudent Record Updated Successfully\n\n");

        }
        else
        {
            fwrite(&s1, sizeof(s1), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if(found == 0)
    {
        printf("\n\nRecord not found for ID %d\n\n", updateID);
    }
    else
    {
        remove("student.dat");
        rename("temp.dat", "student.dat");
    }
}