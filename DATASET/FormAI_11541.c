//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS_LENGTH 100

struct Education {
    char degree[MAX_NAME_LENGTH];
    char school[MAX_NAME_LENGTH];
    int year;
};

struct Experience {
    char company[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
    int start_year;
    int end_year;
};

struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    struct Education education[3];
    struct Experience experience[3];
};

struct Resume resumes[MAX_RESUMES];
int num_resumes = 0;

void parse_resume(char *resume_str) {
    struct Resume new_resume;
    char *token;
    int i = 0;
    token = strtok(resume_str, "|");
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(new_resume.name, token);
                break;
            case 1:
                strcpy(new_resume.email, token);
                break;
            case 2:
                strcpy(new_resume.skills, token);
                break;
            case 3:
                strcpy(new_resume.education[0].degree, token);
                break;
            case 4:
                strcpy(new_resume.education[0].school, token);
                break;
            case 5:
                new_resume.education[0].year = atoi(token);
                break;
            case 6:
                strcpy(new_resume.education[1].degree, token);
                break;
            case 7:
                strcpy(new_resume.education[1].school, token);
                break;
            case 8:
                new_resume.education[1].year = atoi(token);
                break;
            case 9:
                strcpy(new_resume.education[2].degree, token);
                break;
            case 10:
                strcpy(new_resume.education[2].school, token);
                break;
            case 11:
                new_resume.education[2].year = atoi(token);
                break;
            case 12:
                strcpy(new_resume.experience[0].company, token);
                break;
            case 13:
                strcpy(new_resume.experience[0].position, token);
                break;
            case 14:
                new_resume.experience[0].start_year = atoi(token);
                break;
            case 15:
                new_resume.experience[0].end_year = atoi(token);
                break;
            case 16:
                strcpy(new_resume.experience[1].company, token);
                break;
            case 17:
                strcpy(new_resume.experience[1].position, token);
                break;
            case 18:
                new_resume.experience[1].start_year = atoi(token);
                break;
            case 19:
                new_resume.experience[1].end_year = atoi(token);
                break;
            case 20:
                strcpy(new_resume.experience[2].company, token);
                break;
            case 21:
                strcpy(new_resume.experience[2].position, token);
                break;
            case 22:
                new_resume.experience[2].start_year = atoi(token);
                break;
            case 23:
                new_resume.experience[2].end_year = atoi(token);
                break;
        }
        token = strtok(NULL, "|");
        i++;
    }
    resumes[num_resumes++] = new_resume;
}

int main() {
    char resumes_str[] = "John Doe|johndoe@email.com|"
                         "C++,Java,Ruby on Rails|"
                         "Bachelor of Computer Science|University of Toronto|2014|"
                         "Master of Business Administration|Rotman School of Management|2017|"
                         "|Google Inc.|Software Engineer|2014|2016|"
                         "|Facebook Inc.|Senior Software Engineer|2016|2019|"
                         "|Microsoft Corporation|Senior Software Engineer|2019|present|\n"
                         "Jane Smith|janesmith@email.com|"
                         "Python,SQL,JavaScript|"
                         "Bachelor of Science in Mathematics|MIT|2015|"
                         "Ph.D. in Statistics|Harvard University|2020|"
                         "|Amazon Web Services|Data Scientist|2015|2019|"
                         "|Uber Technologies Inc.|Senior Data Scientist|2019|present|\n";
    char *token;
    token = strtok(resumes_str, "\n");
    while (token != NULL) {
        parse_resume(token);
        token = strtok(NULL, "\n");
    }

    printf("Successfully parsed %d resumes.\n", num_resumes);
    return 0;
}