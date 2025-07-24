//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing candidate information
struct Candidate {
    char name[50];
    char email[50];
    char skills[100];
};

// Define a function to parse the resume file and extract candidate information
int parse_resume_file(char *filename, struct Candidate *candidate) {
    FILE *resume_file;
    char line[100];

    // Open the resume file
    resume_file = fopen(filename, "r");

    // Check if file exists
    if (resume_file == NULL) {
        printf("Resume file does not exist.\n");
        return 1;
    }

    // Iterate over each line in the resume file
    while (fgets(line, sizeof(line), resume_file)) {
        // Check if the line contains the candidate name
        if (strstr(line, "Name:")) {
            // Extract the candidate name from the line
            strcpy(candidate->name, strchr(line, ':') + 2);
        }

        // Check if the line contains the candidate email
        if (strstr(line, "Email:")) {
            // Extract the candidate email from the line
            strcpy(candidate->email, strchr(line, ':') + 2);
        }

        // Check if the line contains the candidate skills
        if (strstr(line, "Skills:")) {
            // Extract the candidate skills from the line
            strcpy(candidate->skills, strchr(line, ':') + 2);
        }
    }

    // Close the resume file
    fclose(resume_file);

    return 0;
}

// Define a function to print candidate information
void print_candidate_info(struct Candidate *candidate) {
    printf("Name: %s\nEmail: %s\nSkills: %s\n", candidate->name, candidate->email, candidate->skills);
}

int main() {
    struct Candidate candidate;
    char filename[50];

    // Prompt the user to enter the resume file name
    printf("Enter the resume file name: ");
    scanf("%s", filename);

    // Parse the resume file and extract candidate information
    if (parse_resume_file(filename, &candidate) == 0) {
        // Print the candidate information
        print_candidate_info(&candidate);
    }

    return 0;
}