//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUME_LENGTH 10000
#define MAX_KEYWORD_LENGTH 50
#define MAX_SKILL_LENGTH 50

char* parse_resume(char* resume);

int main()
{
    char resume[MAX_RESUME_LENGTH];
    printf("Please enter your resume:\n");
    fgets(resume, MAX_RESUME_LENGTH, stdin);
    char* parsed_resume = parse_resume(resume);
    printf("Parsed resume:\n%s\n", parsed_resume);
    free(parsed_resume);
    return 0;
}

char* parse_resume(char* resume)
{
    // Define keywords and skills to search for
    char keywords[][MAX_KEYWORD_LENGTH] = {"education", "experience", "skills", "projects", "achievements"};
    char skills[][MAX_SKILL_LENGTH] = {"C", "Java", "Python", "HTML", "CSS", "JavaScript"};

    // Allocate memory for parsed resume string
    char* parsed_resume = (char*)malloc(MAX_RESUME_LENGTH * sizeof(char));
    if (parsed_resume == NULL)
    {
        printf("Error allocating memory for parsed resume!\n");
        exit(1);
    }

    // Parse resume by searching for keywords and skills
    char* ptr = resume;
    while (*ptr != '\0')
    {
        // Search for keywords
        for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
        {
            if (strstr(ptr, keywords[i]) != NULL)
            {
                // Add keyword to parsed resume
                strcat(parsed_resume, keywords[i]);
                strcat(parsed_resume, ":\n");
                ptr = strstr(ptr, keywords[i]) + strlen(keywords[i]);
                while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
                {
                    ptr++;
                }
                break;
            }
        }

        // Search for skills
        for (int i = 0; i < sizeof(skills) / sizeof(skills[0]); i++)
        {
            if (strstr(ptr, skills[i]) != NULL)
            {
                // Add skill to parsed resume
                char skill_line[MAX_SKILL_LENGTH + 20];
                snprintf(skill_line, sizeof(skill_line), "- %s\n", skills[i]);
                strcat(parsed_resume, skill_line);
                ptr = strstr(ptr, skills[i]) + strlen(skills[i]);
                while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || ispunct(*ptr))
                {
                    ptr++;
                }
                if (*ptr != '\0' && !isdigit(*ptr))
                {
                    strcat(parsed_resume, "\n");
                }
                break;
            }
        }

        // Copy remaining lines of text to parsed resume
        while (*ptr != '\n' && *ptr != '\0')
        {
            char c = *ptr;
            strncat(parsed_resume, &c, 1);
            ptr++;
        }
        if (*ptr == '\n')
        {
            strcat(parsed_resume, "\n");
            ptr++;
        }
    }

    return parsed_resume;
}