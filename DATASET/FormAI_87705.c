//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definition of the structure to store parsed information from resume
struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[500];
};

// Function to parse resume information
struct Resume parseResume(char* resume) {
    struct Resume newResume = {"", "", "", ""}; // Initial values
    
    // Parsing name
    char* temp = strtok(resume, ",");
    strcpy(newResume.name, temp);
    
    // Parsing email
    temp = strtok(NULL, ",");
    strcpy(newResume.email, temp);
    
    // Parsing phone
    temp = strtok(NULL, ",");
    strcpy(newResume.phone, temp);
    
    // Parsing skills
    temp = strtok(NULL, ",");
    strcpy(newResume.skills, temp);
    
    return newResume;
}

int main() {
    // Sample resumes to parse
    char resume1[] = "John Smith,johnsmith@email.com,123-456-7890,Coding,Python,Java";
    char resume2[] = "Jane Doe,janedoe@email.com,987-654-3210,Coding,C++,PHP";
    
    // Parsing resumes
    struct Resume parsedResume1 = parseResume(resume1);
    struct Resume parsedResume2 = parseResume(resume2);
    
    // Printing parsed information
    printf("Parsed information from resume 1:\n");
    printf("Name: %s\n", parsedResume1.name);
    printf("Email: %s\n", parsedResume1.email);
    printf("Phone: %s\n", parsedResume1.phone);
    printf("Skills: %s\n", parsedResume1.skills);
    
    printf("\nParsed information from resume 2:\n");
    printf("Name: %s\n", parsedResume2.name);
    printf("Email: %s\n", parsedResume2.email);
    printf("Phone: %s\n", parsedResume2.phone);
    printf("Skills: %s\n", parsedResume2.skills);
    
    return 0;
}