//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    
    printf("Welcome to the Resume Parsing System!\n");
    printf("Please input your resume:\n");
    
    char resume[1000];
    fgets(resume, 1000, stdin);
    
    printf("\nParsing...\n");
    
    int skills = 0;
    char experience[100];
    int experience_len = 0;
    int education = 0;
    
    for (int i = 0; i < strlen(resume); i++) {
        if (resume[i] == 's') {
            skills++;
        }
        else if (resume[i] == 'e') {
            experience[experience_len++] = 'e';
        }
        else if (resume[i] == 'd') {
            education = 1;
        }
    }
    
    printf("\nResults:\n");
    printf("Skills: %d\n", skills);
    printf("Experience: %s\n", experience_len == 0 ? "None" : experience);
    printf("Education: %s\n", education == 1 ? "Present" : "None");
    
    return 0;
}