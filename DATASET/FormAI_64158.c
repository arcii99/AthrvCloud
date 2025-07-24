//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // maximum length of a line in the file

// Structures
typedef struct candidate {
    char name[MAX_LENGTH];
    int age;
    char skills[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Candidate;

// Functions
void print_candidate(Candidate* c);
void parse_resume(FILE* fp, Candidate* c);

int main() {
    char* resume_file = "resume.txt";
    FILE* fp = fopen(resume_file, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", resume_file);
        exit(EXIT_FAILURE);
    }

    Candidate* c = (Candidate*) malloc(sizeof(Candidate));
    parse_resume(fp, c);

    print_candidate(c);

    fclose(fp);
    free(c);

    return 0;
}

void parse_resume(FILE* fp, Candidate* c) {
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        char temp[MAX_LENGTH];
        char* token = strtok(line, " ");

        while (token != NULL) {
            if (strcmp(token, "Name:") == 0) {
                token = strtok(NULL, " ");
                strcpy(c->name, token);
            }

            if (strcmp(token, "Age:") == 0) {
                token = strtok(NULL, " ");
                c->age = atoi(token);
            }

            if (strcmp(token, "Skills:") == 0) {
                token = strtok(NULL, " ");
                strcpy(c->skills, token);
            }

            if (strcmp(token, "Experience:") == 0) {
                token = strtok(NULL, " ");
                strcpy(c->experience, token);
            }

            token = strtok(NULL, " ");
        }
    }
}

void print_candidate(Candidate* c) {
    printf("Name: %s\n", c->name);
    printf("Age: %d\n", c->age);
    printf("Skills: %s\n", c->skills);
    printf("Experience: %s\n", c->experience);
}