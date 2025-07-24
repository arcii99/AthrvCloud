//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000

void parse_resume(char* resume);

int main()
{
    char resume[MAX_RESUME_LENGTH];

    printf("Enter the resume:\n");
    fgets(resume, MAX_RESUME_LENGTH, stdin);
    
    printf("Parsing the resume...\n");
    parse_resume(resume);

    return 0;
}

void parse_resume(char* resume)
{
    char* token = strtok(resume, " ");
    
    while (token != NULL)
    {
        if (strcmp(token, "name") == 0)
        {
            printf("Name: ");
            token = strtok(NULL, " ");
            while (strcmp(token, "email") != 0)
            {
                printf("%s ", token);
                token = strtok(NULL, " ");
            }
            printf("\n");
        }
        else if (strcmp(token, "email") == 0)
        {
            printf("Email: ");
            token = strtok(NULL, " ");
            printf("%s\n", token);
        }
        else if (strcmp(token, "phone") == 0)
        {
            printf("Phone: ");
            token = strtok(NULL, " ");
            printf("%s\n", token);
        }
        else if (strcmp(token, "work") == 0)
        {
            printf("Work experience: \n");
            token = strtok(NULL, " ");
            while (token != NULL)
            {
                if (strcmp(token, "title") == 0)
                {
                    printf("Title: ");
                    token = strtok(NULL, " ");
                    while (strcmp(token, "company") != 0)
                    {
                        printf("%s ", token);
                        token = strtok(NULL, " ");
                    }
                    printf("\n");
                }
                else if (strcmp(token, "company") == 0)
                {
                    printf("Company: ");
                    token = strtok(NULL, " ");
                    printf("%s\n", token);
                }
                else if (strcmp(token, "duration") == 0)
                {
                    printf("Duration: ");
                    token = strtok(NULL, " ");
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                    printf("%s\n", token);
                }
                token = strtok(NULL, " ");
            }
        }
        token = strtok(NULL, " ");
    }
}