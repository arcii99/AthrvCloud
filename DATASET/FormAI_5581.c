//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RESUMES 1000
#define MAX_KEYWORDS 50
#define MAX_LINES 5000
#define MAX_LINE_LENGTH 200

int main()
{
    char resumes[MAX_RESUMES][MAX_LINES][MAX_LINE_LENGTH];
    char keywords[MAX_KEYWORDS][MAX_LINE_LENGTH];
    int score[MAX_RESUMES] = {0};
    int num_resumes = 0, num_keywords = 0;

    printf("Welcome to the C Resume Parsing System!\n");

    // Read in resumes
    printf("Please enter resumes, one at a time. Enter a blank line to finish.\n");
    for (int i = 0; i < MAX_RESUMES; i++)
    {
        printf("Resume %d:\n", i+1);
        int num_lines = 0;
        while (fgets(resumes[i][num_lines], MAX_LINE_LENGTH, stdin) != NULL && strlen(resumes[i][num_lines]) > 1)
        {
            num_lines++;
        }
        if (num_lines == 0)
        {
            break;
        }
        num_resumes++;
    }

    // Read in keywords
    printf("Please enter keywords, one per line. Enter a blank line to finish.\n");
    for (int i = 0; i < MAX_KEYWORDS; i++)
    {
        printf("Keyword %d:", i+1);
        if (fgets(keywords[i], MAX_LINE_LENGTH, stdin) == NULL || strlen(keywords[i]) <= 1)
        {
            break;
        }
        num_keywords++;
    }

    // Parse resumes
    for (int i = 0; i < num_resumes; i++)
    {
        for (int j = 0; j < MAX_LINES; j++)
        {
            if (strlen(resumes[i][j]) == 0)
            {
                break;
            }
            for (int k = 0; k < num_keywords; k++)
            {
                if (strstr(resumes[i][j], keywords[k]) != NULL)
                {
                    score[i]++;
                }
            }
        }
    }

    // Find best match
    int best_match_index = -1;
    int best_match_score = 0;
    for (int i = 0; i < num_resumes; i++)
    {
        if (score[i] > best_match_score)
        {
            best_match_index = i;
            best_match_score = score[i];
        }
    }

    // Display best match
    if (best_match_index == -1)
    {
        printf("No match found.\n");
    }
    else
    {
        printf("Best match found in resume %d with a score of %d.\n", best_match_index+1, best_match_score);
        for (int i = 0; i < MAX_LINES; i++)
        {
            if (strlen(resumes[best_match_index][i]) == 0)
            {
                break;
            }
            printf("%s", resumes[best_match_index][i]);
        }
    }

    return 0;
}