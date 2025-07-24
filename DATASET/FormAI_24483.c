//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LINES 5000
#define MAX_LENGTH 1000

// Struct to hold resume data
typedef struct Resume {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
    char skills[MAX_LENGTH];
} Resume;

// Struct to hold parsed data
typedef struct ParsedResume {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char education[MAX_LINES][MAX_LENGTH];
    int educationCount;
    char experience[MAX_LINES][MAX_LENGTH];
    int experienceCount;
    char skills[MAX_LINES][MAX_LENGTH];
    int skillsCount;
} ParsedResume;

// Function to parse each line of the resume
ParsedResume parseResume(Resume *resume) {
    ParsedResume parsedResume;
    strcpy(parsedResume.name, resume->name);
    strcpy(parsedResume.email, resume->email);
    strcpy(parsedResume.phone, resume->phone);
    parsedResume.educationCount = 0;
    parsedResume.experienceCount = 0;
    parsedResume.skillsCount = 0;
    char *token;
    token = strtok(resume->education, "\n");
    while (token != NULL) {
        strcpy(parsedResume.education[parsedResume.educationCount], token);
        parsedResume.educationCount++;
        token = strtok(NULL, "\n");
    }
    token = strtok(resume->experience, "\n");
    while (token != NULL) {
        strcpy(parsedResume.experience[parsedResume.experienceCount], token);
        parsedResume.experienceCount++;
        token = strtok(NULL, "\n");
    }
    token = strtok(resume->skills, "\n");
    while (token != NULL) {
        strcpy(parsedResume.skills[parsedResume.skillsCount], token);
        parsedResume.skillsCount++;
        token = strtok(NULL, "\n");
    }
    return parsedResume;
}

// Function to print parsed resume data
void printParsedResume(ParsedResume parsedResume) {
    printf("Name: %s\n", parsedResume.name);
    printf("Email: %s\n", parsedResume.email);
    printf("Phone: %s\n", parsedResume.phone);
    printf("Education:\n");
    for (int i = 0; i < parsedResume.educationCount; i++) {
        printf("- %s\n", parsedResume.education[i]);
    }
    printf("Experience:\n");
    for (int i = 0; i < parsedResume.experienceCount; i++) {
        printf("- %s\n", parsedResume.experience[i]);
    }
    printf("Skills:\n");
    for (int i = 0; i < parsedResume.skillsCount; i++) {
        printf("- %s\n", parsedResume.skills[i]);
    }
}

// Function to read a resume from a file
void readResumeFromFile(char filename[], Resume *resume) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LENGTH];
    int lineCount = 0;
    while (fgets(line, MAX_LENGTH, file) != NULL && lineCount < 6) {
        switch(lineCount) {
            case 0:
                strcpy(resume->name, line);
                break;
            case 1:
                strcpy(resume->email, line);
                break;
            case 2:
                strcpy(resume->phone, line);
                break;
            case 3:
                strcpy(resume->education, line);
                break;
            case 4:
                strcpy(resume->experience, line);
                break;
            case 5:
                strcpy(resume->skills, line);
                break;
        }
        lineCount++;
    }
    fclose(file);
}

// Function to write a resume to a file
void writeResumeToFile(char filename[], Resume *resume) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%s", resume->name);
    fprintf(file, "%s", resume->email);
    fprintf(file, "%s", resume->phone);
    fprintf(file, "%s", resume->education);
    fprintf(file, "%s", resume->experience);
    fprintf(file, "%s", resume->skills);
    fclose(file);
}

// Asynchronous function to read a resume from a file
void *readResume(void *filename) {
    Resume *resume = (Resume*) malloc(sizeof(Resume));
    readResumeFromFile((char*)filename, resume);
    pthread_exit((void*)resume);
}

// Asynchronous function to parse a resume
void *parseResumeAsync(void *resume) {
    ParsedResume *parsedResume = (ParsedResume*) malloc(sizeof(ParsedResume));
    *parsedResume = parseResume((Resume*)resume);
    pthread_exit((void*)parsedResume);
}

int main(int argc, char *argv[]) {

    // Parse command line arguments
    if (argc != 2) {
        printf("Usage: %s <filename1> <filename2> ...\n", argv[0]);
        exit(1);
    }

    // Allocate memory for threads and resumes
    pthread_t threads[MAX_LINES];
    Resume resumes[MAX_LINES];
    ParsedResume parsedResumes[MAX_LINES];

    // Read resumes from files
    int numResumes = argc - 1;
    for (int i = 0; i < numResumes; i++) {
        readResumeFromFile(argv[i+1], &resumes[i]);
    }

    // Parse resumes in parallel
    for (int i = 0; i < numResumes; i++) {
        pthread_create(&threads[i], NULL, parseResumeAsync, (void*)&resumes[i]);
    }
    for (int i = 0; i < numResumes; i++) {
        pthread_join(threads[i], (void**)&parsedResumes[i]);
    }

    // Print parsed resumes
    for (int i = 0; i < numResumes; i++) {
        printf("Resume %d:\n", i+1);
        printParsedResume(parsedResumes[i]);
    }

    return 0;
}