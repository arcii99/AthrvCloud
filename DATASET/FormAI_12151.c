//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <string.h>

// define the maximum length of the name and resume
#define MAX_NAME_LENGTH 100
#define MAX_RESUME_LENGTH 1000

// define the structure for the candidate
typedef struct {
    char name[MAX_NAME_LENGTH];
    char resume[MAX_RESUME_LENGTH];
} Candidate;

// define the function for parsing the resume
void parseResume(const char* resume, Candidate* candidate) {
    // find the name of the candidate
    const char* nameStart = strstr(resume, "Name: ");
    if (nameStart != NULL) {
        const char* nameEnd = strstr(nameStart, "\n");
        if (nameEnd != NULL) {
            int nameLength = nameEnd - nameStart - strlen("Name: ");
            if (nameLength > 0 && nameLength < MAX_NAME_LENGTH) {
                strncpy(candidate->name, nameStart + strlen("Name: "), nameLength);
                candidate->name[nameLength] = '\0';
            }
        }
    }

    // find the resume of the candidate
    const char* resumeStart = strstr(resume, "Resume: ");
    if (resumeStart != NULL) {
        const char* resumeEnd = strstr(resumeStart, "\n\n");
        if (resumeEnd != NULL) {
            int resumeLength = resumeEnd - resumeStart - strlen("Resume: ");
            if (resumeLength > 0 && resumeLength < MAX_RESUME_LENGTH) {
                strncpy(candidate->resume, resumeStart + strlen("Resume: "), resumeLength);
                candidate->resume[resumeLength] = '\0';
            }
        }
    }
}

// define the main function
int main() {
    // define the resume string
    const char* resume = "Name: John Smith\n"
                         "Resume: A talented software engineer with 5 years of experience working on mission-critical systems.\n"
                         "       Proficient in C, C++, Python, and Java. Excellent problem-solving skills and a passion for learning.\n\n";

    // create a candidate object
    Candidate candidate;
    memset(&candidate, 0, sizeof(candidate));

    // parse the resume
    parseResume(resume, &candidate);

    // print the candidate's name and resume
    printf("Candidate's Name: %s\n", candidate.name);
    printf("Candidate's Resume: %s\n", candidate.resume);

    return 0;
}