//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_SKILLS 20
#define MAX_EXPERIENCES 20
#define MAX_EDUCATION 20

typedef struct Skill {
    char name[50];
    int level;
} Skill;

typedef struct Experience {
    char company[50];
    char title[50];
    char description[100];
    int duration;
} Experience;

typedef struct Education {
    char institution[50];
    char degree[50];
    char field[50];
    int year;
} Education;

typedef struct Resume {
    char name[50];
    char email[50];
    Skill skills[MAX_SKILLS];
    Experience experiences[MAX_EXPERIENCES];
    Education education[MAX_EDUCATION];
} Resume;

int main() {
    Resume resumes[MAX_RESUMES];
    int num_resumes = 0;

    // simulate parsing resumes and adding them to the database
    char resume1[] = "John Smith\njohnsmith@gmail.com\nC++, Java, Python\nAmazon, Software Developer, Developed web applications, 2 years\nUCLA, BS in Computer Science, 2015";
    char resume2[] = "Mary Johnson\nmaryjohnson@gmail.com\nJava, SQL\nGoogle, Software Engineer, Worked on search algorithms, 3 years\nStanford, MS in Computer Science, 2013";
    char resume3[] = "David Lee\ndavidlee@gmail.com\nJava, Ruby, HTML, CSS\nFacebook, Front-end Developer, Built responsive web pages, 1 year\nUC Berkeley, BA in Computer Science, 2017";
    // add resume 1
    char* token = strtok(resume1, "\n");
    strcpy(resumes[num_resumes].name, token);
    token = strtok(NULL, "\n");
    strcpy(resumes[num_resumes].email, token);
    token = strtok(NULL, "\n");
    int i = 0;
    while (token != NULL && i < MAX_SKILLS) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strcpy(resumes[num_resumes].skills[i].name, token);
        resumes[num_resumes].skills[i].level = rand() % 11; // random level between 0-10
        token = comma + 2; // skip comma and space
        i++;
    }
    i = 0;
    while (token != NULL && i < MAX_EXPERIENCES) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].company, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].title, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].description, token, 100);
        token = comma + 2; // skip comma and space
        resumes[num_resumes].experiences[i].duration = atoi(token);
        token = strtok(NULL, "\n");
        i++;
    }
    i = 0;
    while (token != NULL && i < MAX_EDUCATION) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].institution, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].degree, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].field, token, 50);
        token = comma + 2; // skip comma and space
        resumes[num_resumes].education[i].year = atoi(token);
        token = strtok(NULL, "\n");
        i++;
    }
    num_resumes++;
    // add resume 2
    token = strtok(resume2, "\n");
    strcpy(resumes[num_resumes].name, token);
    token = strtok(NULL, "\n");
    strcpy(resumes[num_resumes].email, token);
    token = strtok(NULL, "\n");
    i = 0;
    while (token != NULL && i < MAX_SKILLS) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strcpy(resumes[num_resumes].skills[i].name, token);
        resumes[num_resumes].skills[i].level = rand() % 11;
        token = comma + 2; // skip comma and space
        i++;
    }
    i = 0;
    while (token != NULL && i < MAX_EXPERIENCES) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].company, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].title, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].description, token, 100);
        token = comma + 2; // skip comma and space
        resumes[num_resumes].experiences[i].duration = atoi(token);
        token = strtok(NULL, "\n");
        i++;
    }
    i = 0;
    while (token != NULL && i < MAX_EDUCATION) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].institution, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].degree, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].field, token, 50);
        token = comma + 2; // skip comma and space
        resumes[num_resumes].education[i].year = atoi(token);
        token = strtok(NULL, "\n");
        i++;
    }
    num_resumes++;
    // add resume 3
    token = strtok(resume3, "\n");
    strcpy(resumes[num_resumes].name, token);
    token = strtok(NULL, "\n");
    strcpy(resumes[num_resumes].email, token);
    token = strtok(NULL, "\n");
    i = 0;
    while (token != NULL && i < MAX_SKILLS) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strcpy(resumes[num_resumes].skills[i].name, token);
        resumes[num_resumes].skills[i].level = rand() % 11;
        token = comma + 2; // skip comma and space
        i++;
    }
    i = 0;
    while (token != NULL && i < MAX_EXPERIENCES) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].company, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].title, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].experiences[i].description, token, 100);
        token = comma + 2; // skip comma and space
        resumes[num_resumes].experiences[i].duration = atoi(token);
        token = strtok(NULL, "\n");
        i++;
    }
    i = 0;
    while (token != NULL && i < MAX_EDUCATION) {
        char* comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].institution, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].degree, token, 50);
        token = comma + 2; // skip comma and space
        comma = strchr(token, ',');
        *comma = '\0';
        strncpy(resumes[num_resumes].education[i].field, token, 50);
        token = comma + 2; // skip comma and space
        resumes[num_resumes].education[i].year = atoi(token);
        token = strtok(NULL, "\n");
        i++;
    }
    num_resumes++;

    // print all resumes in the database
    for (int i = 0; i < num_resumes; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Skills:\n");
        for (int j = 0; j < MAX_SKILLS; j++) {
            if (strlen(resumes[i].skills[j].name) == 0) break;
            printf("- %s: %d\n", resumes[i].skills[j].name, resumes[i].skills[j].level);
        }
        printf("Experiences:\n");
        for (int j = 0; j < MAX_EXPERIENCES; j++) {
            if (strlen(resumes[i].experiences[j].company) == 0) break;
            printf("- %s: %s, %d years\n", resumes[i].experiences[j].company, resumes[i].experiences[j].title, resumes[i].experiences[j].duration);
        }
        printf("Education:\n");
        for (int j = 0; j < MAX_EDUCATION; j++) {
            if (strlen(resumes[i].education[j].institution) == 0) break;
            printf("- %s: %s, %s\n", resumes[i].education[j].institution, resumes[i].education[j].degree, resumes[i].education[j].field);
        }
        printf("\n");
    }

    return 0;
}