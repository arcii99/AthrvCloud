//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>

struct Resume 
{
    char name[50];
    int age;
    char contact[11];
    char email[50];
    char skills[100];
    char experience[300];
};

int main() 
{
    struct Resume r1;
    printf("Enter your name: ");
    scanf("%s", r1.name);
    printf("Enter your age: ");
    scanf("%d", &r1.age);
    printf("Enter your contact number: ");
    scanf("%s", r1.contact);
    printf("Enter your email address: ");
    scanf("%s", r1.email);
    printf("Enter your top skills (separated by commas): ");
    scanf("%s", r1.skills);
    printf("Enter your work experience (in years): ");
    scanf("%s", r1.experience);
    
    printf("\n------------------\n");
    printf("Name: %s\n", r1.name);
    printf("Age: %d\n", r1.age);
    printf("Contact Number: %s\n", r1.contact);
    printf("Email Address: %s\n", r1.email);
    printf("Skills: %s\n", r1.skills);
    printf("Experience: %s years\n", r1.experience);
    printf("------------------\n");
    
    return 0;
}