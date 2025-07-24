//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store the resume information
struct ResumeData {
    char name[50];
    char email[50];
    char phone[15];
    char education[50];
    char experience[100];
};

// Function to parse the resume
void parseResume(char *resumeText, struct ResumeData *resume) {
    // Split the resume text by newline
    char *line = strtok(resumeText, "\n");
    while (line != NULL) {
        // Check for each resume section and store the data accordingly
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", resume->name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", resume->email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } else if (strstr(line, "Education:")) {
            sscanf(line, "Education: %[^\n]", resume->education);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", resume->experience);
        }
        // Get the next line
        line = strtok(NULL, "\n");
    }
}

int main() {
    // Read the resume text from a file
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char resumeText[500];
    fgets(resumeText, 500, fp);
    fclose(fp);

    // Parse the resume using the parseResume function
    struct ResumeData resume;
    parseResume(resumeText, &resume);

    // Print the extracted information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}