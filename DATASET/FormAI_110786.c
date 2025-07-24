//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char education[MAX_WORDS][MAX_WORD_LENGTH];
    int num_education;
    char skills[MAX_WORDS][MAX_WORD_LENGTH];
    int num_skills;
    char experience[MAX_WORDS][MAX_WORD_LENGTH];
    int num_experience;
} resume;

int main() {
    resume resumes[MAX_RESUMES];

    FILE* file = fopen("resumes.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return -1;
    }

    // read in resumes
    int num_resumes = 0;
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        strcpy(resumes[num_resumes].name, line);

        fgets(line, MAX_WORD_LENGTH, file);
        strcpy(resumes[num_resumes].email, line);

        fgets(line, MAX_WORD_LENGTH, file);
        strcpy(resumes[num_resumes].phone, line);

        fgets(line, MAX_WORD_LENGTH, file);
        int num_education = atoi(line);
        resumes[num_resumes].num_education = num_education;
        for (int i = 0; i < num_education; i++) {
            fgets(line, MAX_WORD_LENGTH, file);
            strcpy(resumes[num_resumes].education[i], line);
        }

        fgets(line, MAX_WORD_LENGTH, file);
        int num_skills = atoi(line);
        resumes[num_resumes].num_skills = num_skills;
        for (int i = 0; i < num_skills; i++) {
            fgets(line, MAX_WORD_LENGTH, file);
            strcpy(resumes[num_resumes].skills[i], line);
        }

        fgets(line, MAX_WORD_LENGTH, file);
        int num_experience = atoi(line);
        resumes[num_resumes].num_experience = num_experience;
        for (int i = 0; i < num_experience; i++) {
            fgets(line, MAX_WORD_LENGTH, file);
            strcpy(resumes[num_resumes].experience[i], line);
        }

        num_resumes++;
    }

    fclose(file);

    // print out resumes
    for (int i = 0; i < num_resumes; i++) {
        printf("Name: %s", resumes[i].name);
        printf("Email: %s", resumes[i].email);
        printf("Phone: %s", resumes[i].phone);
        printf("Education:\n");
        for (int j = 0; j < resumes[i].num_education; j++) {
            printf("- %s", resumes[i].education[j]);
        }
        printf("Skills:\n");
        for (int j = 0; j < resumes[i].num_skills; j++) {
            printf("- %s", resumes[i].skills[j]);
        }
        printf("Experience:\n");
        for (int j = 0; j < resumes[i].num_experience; j++) {
            printf("- %s", resumes[i].experience[j]);
        }
        printf("\n");
    }

    return 0;
}