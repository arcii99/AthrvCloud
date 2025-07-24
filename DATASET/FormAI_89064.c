//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of each field in the resume
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_EDUCATION_LENGTH 100
#define MAX_EXPERIENCE_LENGTH 200

// Define a struct to store information about a candidate
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} CandidateInfo;

// Define a function to parse a resume and extract relevant information
CandidateInfo parseResume(char* resumeData) {
    CandidateInfo candidate;
    int i, j;
    int resumeLength = strlen(resumeData);
    
    // Find the candidate's name
    i = 0;
    while (resumeData[i] != '\n') {
        candidate.name[i] = resumeData[i];
        i++;
    }
    candidate.name[i] = '\0';
    
    // Find the candidate's email address
    j = i + 1;
    while (resumeData[j] != '\n') {
        j++;
    }
    i++;
    strncpy(candidate.email, &resumeData[i], j-i);
    candidate.email[j-i] = '\0';
    
    // Find the candidate's education information
    i = j + 1;
    j = i;
    while (j < resumeLength && !(resumeData[j] == '\n' && resumeData[j+1] == '\n')) {
        j++;
    }
    strncpy(candidate.education, &resumeData[i], j-i);
    candidate.education[j-i] = '\0';
    
    // Find the candidate's experience information
    i = j + 2;
    j = i;
    while (j < resumeLength) {
        j++;
    }
    strncpy(candidate.experience, &resumeData[i], j-i);
    candidate.experience[j-i] = '\0';
    
    return candidate;
}

int main() {
    // Define a sample resume to parse
    char resumeData[] = "John Smith\njohnsmith@email.com\n"
                        "B.S. Computer Science, University of California, Los Angeles\n"
                        "Software Engineer, XYZ Company, 2018-present\n";
    
    // Parse the resume and print the results
    CandidateInfo candidate = parseResume(resumeData);
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Education: %s\n", candidate.education);
    printf("Experience: %s\n", candidate.experience);
    
    return 0;
}