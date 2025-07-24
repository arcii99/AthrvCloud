//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char skills[200];
    char experience[1000];
};

int main() {
    struct resume candidate;
    char resume_text[3000];
    char *token;
    
    printf("Upload your resume: ");
    fgets(resume_text, 3000, stdin);
    
    //Parse resume text
    token = strtok(resume_text, "\n");
    while (token != NULL) {
        if (strstr(token, "Name:") != NULL) {
            sscanf(token, "Name:%[^\n]", candidate.name);
        }
        if (strstr(token, "Email:") != NULL) {
            sscanf(token, "Email:%[^\n]", candidate.email);
        }
        if (strstr(token, "Phone:") != NULL) {
            sscanf(token, "Phone:%[^\n]", candidate.phone);
        }
        if (strstr(token, "Education:") != NULL) {
            sscanf(token, "Education:%[^\n]", candidate.education);
        }
        if (strstr(token, "Skills:") != NULL) {
            sscanf(token, "Skills:%[^\n]", candidate.skills);
        }
        if (strstr(token, "Experience:") != NULL) {
            sscanf(token, "Experience:%[^\n]", candidate.experience);
        }
        
        token = strtok(NULL, "\n");
    }
    
    //Print parsed resume information
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Education: %s\n", candidate.education);
    printf("Skills: %s\n", candidate.skills);
    printf("Experience: %s\n", candidate.experience);
    
    return 0;
}