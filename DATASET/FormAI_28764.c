//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000
#define MAX_WORD_SIZE 50
#define MAX_SKILLS 10

int main() {
    char resume[MAX_RESUME_SIZE];
    char skills[MAX_SKILLS][MAX_WORD_SIZE];
    int num_skills = 0;
    int skill_count[MAX_SKILLS] = {0};

    printf("Enter your resume:\n");
    fgets(resume, MAX_RESUME_SIZE, stdin);

    char *token = strtok(resume, " ,.-\n");
    while(token != NULL) {
        int found = 0;
        for(int i=0; i<num_skills; i++) {
            if(strcmp(token, skills[i]) == 0) {
                found = 1;
                skill_count[i]++;
                break;
            }
        }
        if(!found && num_skills < MAX_SKILLS) {
            strcpy(skills[num_skills], token);
            skill_count[num_skills]++;
            num_skills++;
        }
        token = strtok(NULL, " ,.-\n");
    }

    printf("Skills:\n");
    for(int i=0; i<num_skills; i++) {
        printf("%s: %d\n", skills[i], skill_count[i]);
    }

    return 0;
}