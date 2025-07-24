//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold relevant resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];    
    char skills[200];
} Resume;

// Function to parse resume and store relevant information in a Resume struct
void parseResume(char* resumeFile, Resume* resume) {
    // TODO: Implement code to read resume file and extract relevant information
}

// Function to print contents of Resume struct
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);
}

int main() {
    Resume resume;
    char resumeFile[50];
    
    // Prompt user to enter name of resume file
    printf("Enter name of resume file: ");
    scanf("%s", resumeFile);
    
    // Parse resume and populate Resume struct
    parseResume(resumeFile, &resume);
    
    // Print contents of Resume struct
    printResume(resume);
    
    return 0;
}