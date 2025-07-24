//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold relevant information about a job applicant
struct Applicant {
    char name[50];
    char email[50];
    char address[100];
    char phone[20];
    char education[100];
    char previous_company[50];
    char position[100];
    char skills[500];
    char achievements[500];
};

// Define a function to parse a resume file and return an Applicant structure
struct Applicant parse_resume(FILE *resume_file) {
    struct Applicant applicant;
    char buffer[500];
    int current_line = 0;

    // Loop over each line in the file and extract relevant information
    while (fgets(buffer, sizeof(buffer), resume_file)) {
        current_line++;
        if (strstr(buffer, "Name")) {
            sscanf(buffer, "Name: %49[^\n]", applicant.name);
        } else if (strstr(buffer, "Email")) {
            sscanf(buffer, "Email: %49[^\n]", applicant.email);
        } else if (strstr(buffer, "Address")) {
            sscanf(buffer, "Address: %99[^\n]", applicant.address);
        } else if (strstr(buffer, "Phone")) {
            sscanf(buffer, "Phone: %19[^\n]", applicant.phone);
        } else if (strstr(buffer, "Education")) {
            sscanf(buffer, "Education: %99[^\n]", applicant.education);
        } else if (strstr(buffer, "Previous Company")) {
            sscanf(buffer, "Previous Company: %49[^\n]", applicant.previous_company);
        } else if (strstr(buffer, "Position")) {
            sscanf(buffer, "Position: %99[^\n]", applicant.position);
        } else if (strstr(buffer, "Skills")) {
            sscanf(buffer, "Skills: %499[^\n]", applicant.skills);
        } else if (strstr(buffer, "Achievements")) {
            sscanf(buffer, "Achievements: %499[^\n]", applicant.achievements);
        } else {
            printf("Warning: unrecognized line '%s' on line %d\n", buffer, current_line);
        }
    }

    return applicant;
}

int main() {
    FILE *resume_file = fopen("resume.txt", "r");
    if (!resume_file) {
        printf("Error: could not open resume file\n");
        return 1;
    }

    struct Applicant applicant = parse_resume(resume_file);

    // Print out the information we extracted
    printf("Name: %s\n", applicant.name);
    printf("Email: %s\n", applicant.email);
    printf("Address: %s\n", applicant.address);
    printf("Phone: %s\n", applicant.phone);
    printf("Education: %s\n", applicant.education);
    printf("Previous Company: %s\n", applicant.previous_company);
    printf("Position: %s\n", applicant.position);
    printf("Skills: %s\n", applicant.skills);
    printf("Achievements: %s\n", applicant.achievements);

    fclose(resume_file);
    return 0;
}