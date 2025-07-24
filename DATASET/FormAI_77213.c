//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct resume {
    char name[50];
    int age;
    char email[50];
    char skills[100];
};

void parseResume(struct resume* res) {
    printf("Welcome to the Resume Parsing System!\n");
    printf("Please enter your name: ");
    scanf("%49s", res->name);
    printf("Please enter your age: ");
    scanf("%d", &res->age);
    printf("Please enter your email address: ");
    scanf("%49s", res->email);
    printf("Please enter some skills you have (comma-separated list): ");
    scanf("%99s", res->skills);
}

int main() {
    struct resume r1;
    
    parseResume(&r1);
    
    printf("\nResume successfully parsed! Here are the details:\n");
    printf("Name: %s\n", r1.name);
    printf("Age: %d\n", r1.age);
    printf("Email: %s\n", r1.email);
    printf("Skills: %s\n", r1.skills);
    
    // Select a random skill
    char* skill = strtok(r1.skills, ",");
    srand(time(NULL));
    int len = strlen(skill);
    int randIndex = rand() % len;
    char randChar = skill[randIndex];
    
    // Print the surreal output
    printf("\nProcessing skills...please wait...\n");
    for (int i = 0; i < 5; i++) {
        printf("----> %c %c %c <----\n", randChar, randChar, randChar);
    }
    printf("\nSkills processed!");

    return 0;
}