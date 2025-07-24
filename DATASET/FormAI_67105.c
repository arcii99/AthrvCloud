//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_RESUME_SIZE 100000

char *parse_resume(char *resume_content);

int main() {
    char *resume_content = (char *)malloc(MAX_RESUME_SIZE * sizeof(char));
    printf("Welcome to the Mind-Bending C Resume Parsing System!\n");
    printf("Please input your resume content: ");
    fgets(resume_content, MAX_RESUME_SIZE, stdin);
    char *parsed_resume = parse_resume(resume_content);
    printf("Here is your parsed resume:\n\n%s", parsed_resume);
    free(resume_content);
    free(parsed_resume);
    return 0;
}

char *parse_resume(char *resume_content) {
    int i = 0;
    char *parsed_resume = (char *)malloc(MAX_RESUME_SIZE * sizeof(char));
    while (resume_content[i]) {
        if (resume_content[i] == 'C' || resume_content[i] == 'c') {
            parsed_resume[i] = 'C';
        } else if (resume_content[i] >= 'A' && resume_content[i] <= 'Z') {
            parsed_resume[i] = resume_content[i] + ('a' - 'A');
        } else if (resume_content[i] >= 'a' && resume_content[i] <= 'z') {
            parsed_resume[i] = resume_content[i] - ('a' - 'A');
        } else if (resume_content[i] == '\n' || resume_content[i] == '\t') {
            parsed_resume[i] = ' ';
        } else {
            parsed_resume[i] = resume_content[i];
        }
        i++;
    }
    parsed_resume[i] = '\0';
    return parsed_resume;
}