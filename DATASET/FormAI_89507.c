//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    char email[50];
    char phone[15];
    char skills[100];
    char experience[200];
    char education[100];
};

void parseResume(char *resumeFile, struct Candidate *candidate) {
    // function to parse the resume file and extract relevant information
    // code omitted for brevity
}

void saveCandidate(struct Candidate *candidate) {
    // function to save candidate information to a database
    // code omitted for brevity
}

int main() {
    char resumeFile[50];
    printf("Enter the name of the resume file: ");
    scanf("%s", resumeFile);

    struct Candidate candidate;
    parseResume(resumeFile, &candidate);

    saveCandidate(&candidate);

    printf("Candidate information saved successfully!");

    return 0;
}