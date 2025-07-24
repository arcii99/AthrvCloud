//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume
{
    char name[50];
    char email[50];
    int age;
    char education[100];
    char experience[200];
    char skills[200];
};

void parseResume(struct Resume *resume, char *resumeText)
{
    char *token;
    const char delimiter[] = "\n";

    token = strtok(resumeText, delimiter);
    
    while(token != NULL)
    {
        if(strstr(token, "Name"))
        {
            sscanf(token, "Name: %[^\n]s", resume->name);
        }
        else if(strstr(token, "Email"))
        {
            sscanf(token, "Email: %[^\n]s", resume->email);
        }
        else if(strstr(token, "Age"))
        {
            sscanf(token, "Age: %d", &resume->age);
        }
        else if(strstr(token, "Education"))
        {
            sscanf(token, "Education: %[^\n]s", resume->education);
        }
        else if(strstr(token, "Experience"))
        {
            sscanf(token, "Experience: %[^\n]s", resume->experience);
        }
        else if(strstr(token, "Skills"))
        {
            sscanf(token, "Skills: %[^\n]s", resume->skills);
        }
        
        token = strtok(NULL, delimiter);
    }
}

int main()
{
    printf("Welcome to the Resume Parsing System!\n");
    printf("Please enter your resume text:\n");

    char resumeText[500];
    fgets(resumeText, 500, stdin);

    struct Resume resume;
    parseResume(&resume, resumeText);

    printf("\nParsed Resume:\n");
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Age: %d\n", resume.age);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}