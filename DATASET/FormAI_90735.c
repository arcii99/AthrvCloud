//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char name[50];
    int age;
    char skills[500];
} Resume;

// Function to extract age from resume
int extractAge(char* res) {
    int age = 0;
    int i = 0;
    while(res[i] != '\0') {
        if(isdigit(res[i])) {
            age = age*10 + (res[i] - '0');
        }
        i++;
    }
    return age;
}

// Function to extract skills from resume
void extractSkills(char* res, char* skills) {
    int i = 0;
    int j = 0;
    int flag = 0;
    while(res[i] != '\0') {
        if(res[i] == '.') {
            flag = 0;
        }
        if(flag == 1) {
            skills[j++] = res[i];
        }
        if(res[i] == ':') {
            flag = 1;
        }
        i++;
    }
    skills[j] = '\0';
}

// Function to parse the resume
void parseResume(char* res, Resume* r) {
    int i = 0;
    int j = 0;
    int flag = 0;
    while(res[i] != '\0') {
        if(res[i] == ':') {
            flag++;
        }
        if(flag == 1 && res[i] != ':') {
            r->name[j++] = res[i];
        }
        if(flag == 2) {
            r->age = extractAge(res+i);
            break;
        }
        i++;
    }
    extractSkills(res, r->skills);
}

int main() {
    char resume[1000] = "Name: John Doe. Age: 25. Skills: C, C++, Java, Python.";
    Resume r;
    parseResume(resume, &r);
    printf("Name: %s\n", r.name);
    printf("Age: %d\n", r.age);
    printf("Skills: %s\n", r.skills);
    return 0;
}