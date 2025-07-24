//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 100

int main(void)
{
    char resume[MAX_LINES][MAX_LINE_LEN];
    char *keywords[] = {"education", "experience", "skills", "projects", "certifications"};
    int keyword_count = sizeof(keywords)/sizeof(keywords[0]);
    int line_count = 0;

    printf("Enter the resume:\n");

    while(line_count < MAX_LINES && fgets(resume[line_count], MAX_LINE_LEN, stdin) != NULL) {
        line_count++;
    }

    int section_count[keyword_count];
    memset(section_count, 0, sizeof(section_count));

    for(int i = 0; i < line_count; i++) {
        for(int j = 0; j < keyword_count; j++) {
            if(strstr(resume[i], keywords[j])) {
                section_count[j]++;
            }
        }
    }

    printf("Resume Summary:\n");

    for(int i = 0; i < keyword_count; i++) {
        printf("%s: %d\n", keywords[i], section_count[i]);
    }

    return 0;
}