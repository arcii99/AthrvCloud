//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function prototypes
void parseResume(char *resumeText);
int extractEducation(char *resumeText, char *educationLine[], int *numLines);
int extractExperience(char *resumeText, char *experienceLine[], int *numLines);

int main() {
    char resume[10000]; // assuming resume will not be longer than 10,000 characters
    printf("Enter your resume text:\n");
    fgets(resume, sizeof(resume), stdin); // read resume text from user

    parseResume(resume); // parse resume text and display extracted education and experience

    return 0;
}

// function to parse resume text and extract education and experience sections
void parseResume(char *resumeText) {
    char *educationLine[10]; // assuming maximum of 10 education lines
    int numEducationLines = extractEducation(resumeText, educationLine, &numEducationLines);
    printf("\nEDUCATION:\n");
    for (int i = 0; i < numEducationLines; i++) {
        printf("%s\n", educationLine[i]);
    }

    char *experienceLine[10]; // assuming maximum of 10 experience lines
    int numExperienceLines = extractExperience(resumeText, experienceLine, &numExperienceLines);
    printf("\nEXPERIENCE:\n");
    for (int i = 0; i < numExperienceLines; i++) {
        printf("%s\n", experienceLine[i]);
    }
}

// function to extract education section from resume text
int extractEducation(char *resumeText, char *educationLine[], int *numLines) {
    *numLines = 0;
    char *start = strstr(resumeText, "education");
    if (start == NULL) {
        return 0; // no education section found
    }

    start += strlen("education") + 1; // skip "education" and the following space
    char *end = strstr(start, "experience");
    if (end == NULL) {
        end = resumeText + strlen(resumeText); // if experience section not found, use end of resume text
    }

    // extract each line of education section
    int i = 0;
    while (start < end) {
        char *lineEnd = strstr(start, "\n");
        if (lineEnd == NULL || lineEnd > end) {
            lineEnd = end; // if end of line not found or crossed experience section, use end of education section
        }

        // trim leading and trailing spaces from line
        while (isspace(*start)) {
            start++;
        }
        while (isspace(*(lineEnd - 1))) {
            lineEnd--;
        }

        int len = lineEnd - start;
        educationLine[i] = malloc(len + 1); // allocate memory for line
        strncpy(educationLine[i], start, len);
        educationLine[i][len] = '\0'; // terminate string
        i++;

        *numLines = i;
        if (i >= 10) {
            break; // maximum of 10 lines extracted
        }

        start = lineEnd + 1;
    }

    return i;
}

// function to extract experience section from resume text
int extractExperience(char *resumeText, char *experienceLine[], int *numLines) {
    *numLines = 0;
    char *start = strstr(resumeText, "experience");
    if (start == NULL) {
        return 0; // no experience section found
    }

    start += strlen("experience") + 1; // skip "experience" and the following space

    // extract each line of experience section
    int i = 0;
    while (*start != '\0') {
        char *lineEnd = strstr(start, "\n");

        // trim leading and trailing spaces from line
        while (isspace(*start)) {
            start++;
        }
        while (isspace(*(lineEnd - 1))) {
            lineEnd--;
        }

        int len = lineEnd - start;
        experienceLine[i] = malloc(len + 1); // allocate memory for line
        strncpy(experienceLine[i], start, len);
        experienceLine[i][len] = '\0'; // terminate string
        i++;

        *numLines = i;
        if (i >= 10) {
            break; // maximum of 10 lines extracted
        }

        start = lineEnd + 1;
    }

    return i;
}