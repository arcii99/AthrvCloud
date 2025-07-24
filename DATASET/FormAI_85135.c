//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <string.h>

struct Resume{
    char name[50];
    char education[50];
    char skills[200];
    char experience[200];
    int age;
    char email[50];
    char phone_number[20];
};

typedef struct Resume resume;

int main(){
    printf("Welcome to the Resume Parsing System!\n\n");

    // Initialization of a sample resume
    resume sample_resume;
    strcpy(sample_resume.name, "John Doe");
    strcpy(sample_resume.education, "Bachelor's Degree in Computer Science");
    strcpy(sample_resume.skills, "C++, Python, Java, SQL");
    strcpy(sample_resume.experience, "Software Engineering intern");
    sample_resume.age = 24;
    strcpy(sample_resume.email, "johndoe@gmail.com");
    strcpy(sample_resume.phone_number, "555-555-5555");

    // Displaying the sample resume
    printf("Name: %s\n", sample_resume.name);
    printf("Age: %d\n", sample_resume.age);
    printf("Education: %s\n", sample_resume.education);
    printf("Skills: %s\n", sample_resume.skills);
    printf("Experience: %s\n", sample_resume.experience);
    printf("Email: %s\n", sample_resume.email);
    printf("Phone Number: %s\n\n", sample_resume.phone_number);

    // Parsing the resume
    printf("Parsing the resume...\n\n");

    // Extracting the name from the resume
    char *name_ptr = strtok(sample_resume.name, " ");
    char name[50];
    while (name_ptr != NULL){
        strcpy(name, name_ptr);
        name_ptr = strtok(NULL, " ");
    }
    printf("Name: %s\n", name);

    // Extracting the age from the resume
    int age = sample_resume.age;
    printf("Age: %d\n", age);

    // Extracting the education from the resume
    char education[50];
    strcpy(education, sample_resume.education);
    printf("Education: %s\n", education);

    // Extracting the skills from the resume
    char skills[200];
    strcpy(skills, sample_resume.skills);
    printf("Skills: %s\n", skills);

    // Extracting the experience from the resume
    char experience[200];
    strcpy(experience, sample_resume.experience);
    printf("Experience: %s\n", experience);

    // Extracting the email from the resume
    char email[50];
    strcpy(email, sample_resume.email);
    printf("Email: %s\n", email);

    // Extracting the phone number from the resume
    char phone_number[20];
    strcpy(phone_number, sample_resume.phone_number);
    printf("Phone Number: %s\n", phone_number);

    return 0;
}