//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume
{
    char name[30];
    char email[30];
    char phone[20];
    char skills[1000];
    char experience[1000];
};

int main()
{
    char resume_text[5000];
    struct resume candidate;
    
    printf("Enter the resume text:\n");
    fgets(resume_text, 5000, stdin);
    
    // Parsing the resume text for candidate information
    char* token = strtok(resume_text, "\n");
    while (token != NULL)
    {
        if (strstr(token, "Name: "))
        {
            strcpy(candidate.name, token + 6);
        }
        else if (strstr(token, "Email: "))
        {
            strcpy(candidate.email, token + 7);
        }
        else if (strstr(token, "Phone: "))
        {
            strcpy(candidate.phone, token + 7);
        }
        else if (strstr(token, "Skills: "))
        {
            strcpy(candidate.skills, token + 8);
        }
        else if (strstr(token, "Experience: "))
        {
            strcpy(candidate.experience, token + 12);
        }
        token = strtok(NULL, "\n");
    }
    
    // Printing the candidate information
    printf("Candidate name: %s\n", candidate.name);
    printf("Candidate email: %s\n", candidate.email);
    printf("Candidate phone: %s\n", candidate.phone);
    printf("Candidate skills: %s\n", candidate.skills);
    printf("Candidate experience: %s\n", candidate.experience);
    
    return 0;
}