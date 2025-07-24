//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <string.h>

struct Resume {
    char name[50];
    char education[100];
    char experience[500];
    char skills[500];
};

void parseResume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    
    // Split skills into individual words
    char* token = strtok(resume.skills, ", ");
    printf("Skills: ");
    while (token != NULL) {
        printf("%s ", token);
        token = strtok(NULL, ", ");
    }
}

int main() {
    struct Resume john;
    strcpy(john.name, "John Smith");
    strcpy(john.education, "Bachelor of Science in Computer Engineering");
    strcpy(john.experience, "5 years of experience in software development");
    strcpy(john.skills, "C, C++, Java, Python, SQL");
    
    parseResume(john);
    
    return 0;
}