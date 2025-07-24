//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include<stdio.h>
#include<string.h>

// Structure for storing information about a candidate's resume
struct resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[100];
    char experience[200];
};

// Function to parse the resume and extract information
void parseResume(char* fileName, struct resume* candidate) {
    // Open the file in read mode
    FILE* fp = fopen(fileName, "r");

    // Check if the file was opened successfully
    if(fp == NULL) {
        printf("File not found!\n");
        return;
    }

    // Buffer to store each line of the file
    char buffer[200];

    // Loop through each line of the file
    while(fgets(buffer, 200, fp)) {
        // Extract name
        if(strncmp(buffer, "Name:", 5) == 0) {
            strtok(buffer, ":");
            strcpy(candidate->name, strtok(NULL, "\n"));
        }
        // Extract email
        else if(strncmp(buffer, "Email:", 6) == 0) {
            strtok(buffer, ":");
            strcpy(candidate->email, strtok(NULL, "\n"));
        }
        // Extract phone number
        else if(strncmp(buffer, "Phone:", 6) == 0) {
            strtok(buffer, ":");
            strcpy(candidate->phone, strtok(NULL, "\n"));
        }
        // Extract skills
        else if(strncmp(buffer, "Skills:", 7) == 0) {
            strtok(buffer, ":");
            strcpy(candidate->skills, strtok(NULL, "\n"));
        }
        // Extract experience
        else if(strncmp(buffer, "Experience:", 11) == 0) {
            strtok(buffer, ":");
            strcpy(candidate->experience, strtok(NULL, "\n"));
        }
    }

    // Close the file
    fclose(fp);
}

int main() {
    struct resume candidate;

    // Call the parseResume function and pass the filename and candidate structure as arguments
    parseResume("resume.txt", &candidate);

    // Print the extracted information
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Skills: %s\n", candidate.skills);
    printf("Experience: %s\n", candidate.experience);

    return 0;
}