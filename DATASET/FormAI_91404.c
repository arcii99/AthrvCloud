//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Setting the stage
    printf("O resume, where art thou? \n");
    printf("To parse or not to parse, that is the question:\n");
    
    // Creating variables
    char resume[1000];
    char name[50];
    char email[50];
    char education[50];
    char experience[50];
    char skills[50];
    
    // Asking for input
    printf("Enter thy resume, fair maid or sir: ");
    fgets(resume, 1000, stdin);
    
    // Parsing the data
    strcpy(name, strtok(resume, ","));
    strcpy(email, strtok(NULL, ","));
    strcpy(education, strtok(NULL, ","));
    strcpy(experience, strtok(NULL, ","));
    strcpy(skills, strtok(NULL, ","));
    
    // Verifying the data
    printf("Fair %s, is thy email %s?\n", name, email);
    printf("Hast thou studied %s and had experience in %s?\n", education, experience);
    printf("Verily, thou art skilled in %s! \n", skills);
    
    // Ending the tale
    printf("Thus endeth our tale of parsing resumes. \n");
    return 0;
}