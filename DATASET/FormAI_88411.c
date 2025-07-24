//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[500];
    char experiences[500];
};

void parse_resume(struct Resume *res, char *resume_text) {
    char *token;
    const char delimiters[] = ",\n";
    int count = 0;

    token = strtok(resume_text, delimiters);
    while(token != NULL) {
        switch(count) {
            case 0:
                strncpy(res->name, token, 49);
                break;
            case 1:
                strncpy(res->email, token, 49);
                break;
            case 2:
                strncpy(res->phone, token, 14);
                break;
            case 3:
                strncpy(res->skills, token, 499);
                break;
            case 4:
                strncpy(res->experiences, token, 499);
                break;
        }
        count++;
        token = strtok(NULL, delimiters);
    }
}

int main() {
    char resume_text[] = "John Doe,john.doe@email.com,555-555-5555,C++,Python,Java,3 years of experience as a software engineer";
    struct Resume *res = malloc(sizeof(struct Resume));
    parse_resume(res, resume_text);
    printf("Name: %s\nEmail: %s\nPhone: %s\nSkills: %s\nExperiences: %s\n", res->name, res->email, res->phone, res->skills, res->experiences);
    free(res);
    return 0;
}