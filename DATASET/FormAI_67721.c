//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold resume information
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char experience[5000];
} Resume;

// Function to parse resume and fill out its details
void parse_resume(char* path, Resume* resume) {
    FILE* file = fopen(path, "r");

    // Check that the file exists
    if (file == NULL) {
        printf("Error: file does not exist\n");
        exit(1);
    }

    // Loop through each line of the resume
    char buffer[1000];
    while (fgets(buffer, 1000, file) != NULL) {
        // Check for keywords and fill in appropriate fields
        if (strstr(buffer, "Name:") != NULL) {
            strcpy(resume->name, buffer + 5);
        }
        else if (strstr(buffer, "Email:") != NULL) {
            strcpy(resume->email, buffer + 6);
        }
        else if (strstr(buffer, "Phone:") != NULL) {
            strcpy(resume->phone, buffer + 6);
        }
        else if (strstr(buffer, "Experience:") != NULL) {
            strcpy(resume->experience, buffer + 11);
        }
    }

    fclose(file);
}

int main() {
    // Create a new resume object
    Resume resume;
    memset(&resume, 0, sizeof(Resume));

    // Parse the resume
    parse_resume("resume.txt", &resume);

    // Print out its contents
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Experience: \n%s", resume.experience);

    return 0;
}