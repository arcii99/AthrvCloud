//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the resume and relevant info for parsing
typedef struct Resume {
    char* name;
    char* email;
    char* education;
    char* experience;
    char* skills;
} Resume;

// A function to parse the resume and store the information
void parseResume(char* fileName, Resume* resume) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    char line[256];
    char* token;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name")) {
            token = strtok(line, ":");
            resume->name = strdup(strtok(NULL, ":"));
        } else if (strstr(line, "Email")) {
            token = strtok(line, ":");
            resume->email = strdup(strtok(NULL, ":"));
        } else if (strstr(line, "Education")) {
            token = strtok(line, ":");
            resume->education = strdup(strtok(NULL, ":"));
        } else if (strstr(line, "Experience")) {
            token = strtok(line, ":");
            resume->experience = strdup(strtok(NULL, ":"));
        } else if (strstr(line, "Skills")) {
            token = strtok(line, ":");
            resume->skills = strdup(strtok(NULL, ":"));
        }
    }
    fclose(file);
}

// A function to print the parsed resume information
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
}

// Main function to process_resume and print the parsed information
int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    // Initialize an empty resume to store parsed information
    Resume resume = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    };
    // Parse the resume and store information in the resume struct
    parseResume(argv[1], &resume);
    // Print the parsed resume information
    printResume(&resume);
    // Free the memory
    free(resume.name);
    free(resume.email);
    free(resume.education);
    free(resume.experience);
    free(resume.skills);
    return 0;
}