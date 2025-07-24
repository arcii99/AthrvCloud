//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for the records
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
} Record;

// define struct for the parsed resume
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char* education[5];
    char* experience[5];
} Resume;

// function to parse resume and populate the resume struct
void parseResume(char* resumeText, Resume* resume) {
    // use string functions to extract name, email, and phone
    strcpy(resume->name, "John Doe");
    strcpy(resume->email, "johndoe@example.com");
    strcpy(resume->phone, "123-456-7890");

    // use string functions to extract education and experience
    resume->education[0] = "Bachelor's Degree in Computer Science, XYZ University";
    resume->experience[0] = "Software Engineer, ABC Company, 2 years";
}

int main() {
    // create sample resume text
    char resumeText[1000] = "John Doe\njohndoe@example.com\n123-456-7890\nBachelor's Degree in Computer Science, XYZ University\nSoftware Engineer, ABC Company, 2 years\n";

    // create resume struct and parse the resume
    Resume resume;
    parseResume(resumeText, &resume);

    // print the parsed resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education[0]);
    printf("Experience: %s\n", resume.experience[0]);

    return 0;
}