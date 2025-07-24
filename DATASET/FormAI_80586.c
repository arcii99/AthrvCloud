//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct to represent an applicant's resume information
struct Resume {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char education[MAX_SIZE];
    char experience[MAX_SIZE];
};

struct Resume parseResume(char *resumeText);

int parseSection(char *sectionText, char *title, char *content);

int main() {
    char resumeText[] = "Name: John Doe\nEmail: john.doe@email.com\n"
                        "Education: Degree in Computer Science\n"
                        "Experience: 5 years as a software engineer\n";
    struct Resume resume = parseResume(resumeText);
    printf("Name: %s\nEmail: %s\nEducation: %s\nExperience: %s\n",
           resume.name, resume.email, resume.education, resume.experience);
    return 0;
}

// Recursive function to parse a resume given as a string
struct Resume parseResume(char *resumeText) {
    struct Resume resume = { "", "", "", "" };
    char sectionTitle[MAX_SIZE], sectionContent[MAX_SIZE];
    int index = 0, sectionIndex;

    // Parse each section of the resume
    while (resumeText[index] != '\0') {
        memset(sectionTitle, '\0', MAX_SIZE);
        memset(sectionContent, '\0', MAX_SIZE);

        // Parse the section title
        sectionIndex = parseSection(&resumeText[index], sectionTitle, sectionContent);
        index += sectionIndex;

        // Assign the section content to the appropriate field in the resume struct
        if (strcmp(sectionTitle, "Name") == 0) {
            strcpy(resume.name, sectionContent);
        } else if (strcmp(sectionTitle, "Email") == 0) {
            strcpy(resume.email, sectionContent);
        } else if (strcmp(sectionTitle, "Education") == 0) {
            strcpy(resume.education, sectionContent);
        } else if (strcmp(sectionTitle, "Experience") == 0) {
            strcpy(resume.experience, sectionContent);
        }

        // Move to the next section
        index += 1;
    }

    return resume;
}

// Recursive function to parse a section title and content from a resume string
int parseSection(char *sectionText, char *title, char *content) {
    int index = 0, contentIndex = 0;

    // Parse the section title
    while (sectionText[index] != ':' && sectionText[index] != '\n' && index < MAX_SIZE) {
        title[index] = sectionText[index];
        index += 1;
    }

    // Move past the ':' character
    index += 1;

    // Parse the section content
    while (sectionText[index] != '\n' && sectionText[index] != '\0' && contentIndex < MAX_SIZE) {
        content[contentIndex] = sectionText[index];
        index += 1;
        contentIndex += 1;
    }

    // Terminate the strings
    title[index] = '\0';
    content[contentIndex] = '\0';

    // Return the index of the next section in the resume string
    return index;
}