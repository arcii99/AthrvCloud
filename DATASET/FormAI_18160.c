//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Define a Struct for storing resume details
typedef struct Resume {
    char name[25];
    char email[50];
    char phone[15];
    char skills[100];
} Resume;

int main() {
    char resumeData[200];
    Resume resume;

    // Initializing resume fields to empty string
    strcpy(resume.name, "");
    strcpy(resume.email, "");
    strcpy(resume.phone, "");
    strcpy(resume.skills, "");

    // Get input from user
    printf("Enter the Resume data: ");
    fgets(resumeData, 200, stdin);

    // Extract relevant data from input and store in struct fields
    char *token;
    token = strtok(resumeData, ","); // Extract name
    if(token != NULL) {
        strcpy(resume.name, token);
    }
    token = strtok(NULL, ","); // Extract email
    if(token != NULL) {
        strcpy(resume.email, token);
    }
    token = strtok(NULL, ","); // Extract phone
    if(token != NULL) {
        strcpy(resume.phone, token);
    }
    token = strtok(NULL, ","); // Extract skills
    if(token != NULL) {
        strcpy(resume.skills, token);
    }

    // Print the Resume data
    printf("\nName: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Skills: %s", resume.skills);

    return 0;
}