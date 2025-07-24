//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to parse resume and extract details
void parseResume(char* resumeContent){
    char* fullName = NULL;
    char* email = NULL;
    char* phoneNumber = NULL;
    char* education = NULL;
    char* experience = NULL;

    char* delimiter = "\n";

    // parsing full name
    fullName = strtok(resumeContent, delimiter);

    // parsing email
    email = strtok(NULL, delimiter);

    // parsing phone number
    phoneNumber = strtok(NULL, delimiter);

    // parsing education
    education = strtok(NULL, delimiter);

    // parsing experience
    experience = strtok(NULL, delimiter);

    // printing extracted details
    printf("Full Name: %s\n", fullName);
    printf("Email: %s\n", email);
    printf("Phone Number: %s\n", phoneNumber);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);
}

int main(){
    char* resumeContent = "John Doe\njohndoe@email.com\n312-555-5555\nB.S. in Computer Science\n5 years of experience";

    // parsing the resume and extracting details
    parseResume(resumeContent);

    return 0;
}