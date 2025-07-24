//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <string.h>

//define resume struct
typedef struct 
{
    char name[50];
    char email[50];
    char phone_number[20];
    char education[100];
    char work_experience[250];
} Resume;

//resume parsing function
void parseResume(Resume *resume)
{
    printf("Welcome to our romantic C Resume Parsing System!\n");
    printf("Please enter your name: ");
    fgets(resume->name, 50, stdin);
    printf("Please enter your email: ");
    fgets(resume->email, 50, stdin);
    printf("Please enter your phone number: ");
    fgets(resume->phone_number, 20, stdin);
    printf("Please enter your education history: ");
    fgets(resume->education, 100, stdin);
    printf("Please enter your work experience: ");
    fgets(resume->work_experience, 250, stdin);
}

int main()
{
    Resume myResume;
    parseResume(&myResume);

    printf("\nThank you for using our C Resume Parsing System! Here is your parsed resume information:\n\n");
    printf("Name: %s", myResume.name);
    printf("Email: %s", myResume.email);
    printf("Phone Number: %s", myResume.phone_number);
    printf("Education: %s", myResume.education);
    printf("Work Experience: %s", myResume.work_experience);

    printf("\n\nOur love for C programming is endless - just like our love for you!\n");
    return 0;
}