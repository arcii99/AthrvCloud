//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char name[MAX];
    char email[MAX];
    char phone[MAX];
    char skills[MAX][MAX];
    int num_skills;
} Resume;

typedef struct {
    char keyword[MAX];
    int count;
} Keyword;

void parse_resume(char *filename, Resume *resume);
void count_keywords(Resume *resume, Keyword keywords[], int num_keywords);
void print_top_keywords(Keyword keywords[], int num_keywords, int top);

int main(void) {
    char filename[MAX];
    Resume resume;
    Keyword keywords[] = {{"C", 0},
                          {"Java", 0},
                          {"Python", 0},
                          {"Databases", 0},
                          {"Algorithms", 0}};
    int num_keywords = 5;
    int top_keywords = 3;

    printf("Enter filename of resume: ");
    scanf("%s", filename);

    parse_resume(filename, &resume);
    count_keywords(&resume, keywords, num_keywords);
    print_top_keywords(keywords, num_keywords, top_keywords);

    return 0;
}

void parse_resume(char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    char line[MAX];

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX, file)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", resume->name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", resume->email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } else if (strstr(line, "Skills:")) {
            char *token = strtok(line, ",");
            while (token) {
                strcpy(resume->skills[resume->num_skills], token);
                resume->num_skills++;
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
}

void count_keywords(Resume *resume, Keyword keywords[], int num_keywords) {
    int i, j, k;
    char *token;

    for (i = 0; i < resume->num_skills; i++) {
        token = strtok(resume->skills[i], " ");
        while (token) {
            for (j = 0; j < num_keywords; j++) {
                if (strcmp(token, keywords[j].keyword) == 0) {
                    keywords[j].count++;
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

void print_top_keywords(Keyword keywords[], int num_keywords, int top) {
    int i, j, max, max_index;

    for (i = 0; i < top; i++) {
        max = 0;
        max_index = 0;
        for (j = 0; j < num_keywords; j++) {
            if (keywords[j].count > max) {
                max = keywords[j].count;
                max_index = j;
            }
        }
        printf("%s: %d\n", keywords[max_index].keyword, keywords[max_index].count);
        keywords[max_index].count = -1;
    }
}