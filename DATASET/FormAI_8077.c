//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_SKILL_LENGTH 20

// Struct to store parsed resume data
struct Resume {
    char name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char skills[MAX_SKILL_LENGTH][MAX_WORD_LENGTH];
    int num_skills;
};
typedef struct Resume Resume;

// Function to parse resume data
Resume parse_resume(char *resume) {
    Resume result;
    char *token;
    char *str_ptr;
    char temp[MAX_RESUME_LENGTH];
    strcpy(temp, resume);

    // Parse name
    str_ptr = strtok(temp, "\n");
    strcpy(result.name, str_ptr);

    // Parse email
    str_ptr = strtok(NULL, "\n");
    strcpy(result.email, str_ptr);

    // Parse phone
    str_ptr = strtok(NULL, "\n");
    strcpy(result.phone, str_ptr);

    // Parse skills
    token = strtok(NULL, ",");
    result.num_skills = 0;
    while (token != NULL) {
        strcpy(result.skills[result.num_skills], token);
        result.num_skills++;
        token = strtok(NULL, ",");
    }

    return result;
}

int main() {
    char resume[MAX_RESUME_LENGTH] = "John Doe\njohn.doe@email.com\n555-555-5555\n";
    strcat(resume, "C++,Java,Python");

    Resume parsed_resume = parse_resume(resume);

    printf("Name: %s\n", parsed_resume.name);
    printf("Email: %s\n", parsed_resume.email);
    printf("Phone: %s\n", parsed_resume.phone);
    printf("Skills:\n");
    for (int i = 0; i < parsed_resume.num_skills; i++) {
        printf("\t- %s\n", parsed_resume.skills[i]);
    }

    return 0;
}