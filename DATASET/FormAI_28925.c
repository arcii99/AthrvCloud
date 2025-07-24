//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: detailed
// This is a basic C Resume Parsing System example program that uses string manipulation and file handling concepts.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "resume.txt"
#define MAX_LENGTH 1000

void read_resume(char *resume_data);
void parse_resume(char *resume_data);

int main()
{
    char resume_data[MAX_LENGTH];
    read_resume(resume_data);
    parse_resume(resume_data);

    return 0;
}

// Function to read the resume data from a text file
void read_resume(char *resume_data)
{
    FILE *fp;
    fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(resume_data, MAX_LENGTH, fp))
    {
        printf("%s", resume_data);
    }

    fclose(fp);
}

// Function to parse the resume data and extract relevant information
void parse_resume(char *resume_data)
{
    char *token;

    // Extract name
    token = strtok(resume_data, " ");
    printf("Name: %s\n", token);

    // Extract email
    token = strtok(NULL, " ");
    if (strstr(token, "@") != NULL)
    {
        printf("Email: %s\n", token);
    }

    // Extract phone number
    token = strtok(NULL, " ");
    if (isdigit(token[0]))
    {
        printf("Phone Number: %s\n", token);
    }

    // Extract skills
    printf("Skills: ");
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (strcmp(token, "Skills:") == 0)
        {
            break;
        }
    }

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (strcmp(token, "Education:") == 0)
        {
            break;
        }

        printf("%s ", token);
    }

    // Extract education
    printf("\nEducation: ");
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (strcmp(token, "Education:") == 0)
        {
            break;
        }
    }

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (strcmp(token, "Experience:") == 0)
        {
            break;
        }

        printf("%s ", token);
    }

    // Extract experience
    printf("\nExperience: ");
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (strcmp(token, "Experience:") == 0)
        {
            break;
        }
    }

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (strcmp(token, "Projects:") == 0)
        {
            break;
        }

        printf("%s ", token);
    }

    // Extract projects
    printf("\nProjects: ");
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        printf("%s ", token);
    }
}