//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* education;
    char* skills;
    char* experience;
} Resume;

Resume* parseResume(char* text) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    char* token;
    token = strtok(text, ":");
    while (token != NULL) {
        if (strstr(token, "name")) {
            resume->name = strtok(NULL, ":");
        } else if (strstr(token, "education")) {
            resume->education = strtok(NULL, ":");
        } else if (strstr(token, "skills")) {
            resume->skills = strtok(NULL, ":");
        } else if (strstr(token, "experience")) {
            resume->experience = strtok(NULL, ":");
        }
        token = strtok(NULL, ":");
    }
    return resume;
}

int main() {
    char* text = "name:John Doe:education:BS Computer Science:skills:C++,Java,Python:experience:2 years Software Developer";
    Resume* resume = parseResume(text);
    printf("Name: %s\n", resume->name);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    free(resume);
    return 0;
}