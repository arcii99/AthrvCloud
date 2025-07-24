//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000
#define MAX_NAME_LENGTH 30
#define MAX_SKILLS_COUNT 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_COUNT][MAX_NAME_LENGTH];
    int skills_count;
} Resume;

Resume* parse_resume(char* resume_text) {
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    char* token = strtok(resume_text, "\n");
    while (token != NULL) {
        char* key = strtok(token, ":");
        char* value = strtok(NULL, ":");
        if (key == NULL || value == NULL) {
            printf("Error parsing resume\n");
            return NULL;
        }
        if (strcmp(key, "name") == 0) {
            strncpy(resume->name, value, MAX_NAME_LENGTH);
        } else if (strcmp(key, "email") == 0) {
            strncpy(resume->email, value, MAX_NAME_LENGTH);
        } else if (strcmp(key, "phone") == 0) {
            strncpy(resume->phone, value, MAX_NAME_LENGTH);
        } else if (strcmp(key, "skills") == 0) {
            char* skill = strtok(value, ",");
            while (skill != NULL) {
                strncpy(resume->skills[resume->skills_count], skill, MAX_NAME_LENGTH);
                resume->skills_count++;
                skill = strtok(NULL, ",");
            }
        }
        token = strtok(NULL, "\n");
    }
    return resume;
}

int main() {
    char resume_text[MAX_RESUME_LENGTH] = "name: John Doe\nemail: john.doe@gmail.com\nphone: 555-123-4567\nskills: C++, Java, Python";
    Resume* resume = parse_resume(resume_text);
    printf("Name: %s\nEmail: %s\nPhone: %s\nSkills:\n", resume->name, resume->email, resume->phone);
    int i;
    for (i = 0; i < resume->skills_count; i++) {
        printf("- %s\n", resume->skills[i]);
    }
    return 0;
}