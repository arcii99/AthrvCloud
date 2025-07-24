//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 1000
#define MAX_SKILLS 20
#define SKILL_SIZE 50

typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[50];
    char experience[50];
    char skills[MAX_SKILLS][SKILL_SIZE];
    int skill_count;
} Resume;

int main() {
    Resume resumes[MAX_RESUMES];
    int resume_count = 0;

    // simulate input of 3 resumes
    Resume r1, r2, r3;
    strcpy(r1.name, "John Doe");
    strcpy(r1.email, "john.doe@email.com");
    strcpy(r1.phone, "555-1234");
    strcpy(r1.education, "Bachelor's degree in Computer Science");
    strcpy(r1.experience, "2 years of experience in Java development");
    strcpy(r1.skills[0], "Java");
    r1.skill_count = 1;

    strcpy(r2.name, "Jane Smith");
    strcpy(r2.email, "jane.smith@email.com");
    strcpy(r2.phone, "555-5678");
    strcpy(r2.education, "Master's degree in Data Science");
    strcpy(r2.experience, "3 years of experience in Python development");
    strcpy(r2.skills[0], "Python");
    strcpy(r2.skills[1], "Data Analysis");
    r2.skill_count = 2;

    strcpy(r3.name, "Bob Johnson");
    strcpy(r3.email, "bob.johnson@email.com");
    strcpy(r3.phone, "555-9876");
    strcpy(r3.education, "Bachelor's degree in Information Technology");
    strcpy(r3.experience, "1 year of experience in C# development");
    strcpy(r3.skills[0], "C#");
    r3.skill_count = 1;

    // add resumes to array
    resumes[resume_count++] = r1;
    resumes[resume_count++] = r2;
    resumes[resume_count++] = r3;

    // simulate input of a job description
    char job_description[1000] = "We are looking for a developer with experience in Java or Python, and knowledge of data analysis.";

    // parse job description for required skills
    char * skill1 = strstr(job_description, "Java");
    char * skill2 = strstr(job_description, "Python");
    char * skill3 = strstr(job_description, "Data Analysis");

    // search resumes for matching skills
    for (int i = 0; i < resume_count; i++) {
        Resume r = resumes[i];
        int match_count = 0;

        for (int j = 0; j < r.skill_count; j++) {
            char * skill = r.skills[j];

            if (skill1 != NULL && strstr(skill, "Java") != NULL) {
                match_count++;
            }

            if (skill2 != NULL && strstr(skill, "Python") != NULL) {
                match_count++;
            }

            if (skill3 != NULL && strstr(skill, "Data Analysis") != NULL) {
                match_count++;
            }
        }

        // display resume if it matches
        if (match_count == (skill1 != NULL) + (skill2 != NULL) + (skill3 != NULL)) {
            printf("====================\n");
            printf("Name: %s\n", r.name);
            printf("Email: %s\n", r.email);
            printf("Phone: %s\n", r.phone);
            printf("Education: %s\n", r.education);
            printf("Experience: %s\n", r.experience);
            printf("Skills: ");

            for (int k = 0; k < r.skill_count; k++) {
                printf("%s", r.skills[k]);

                if (k != r.skill_count - 1) {
                    printf(", ");
                }
            }

            printf("\n");
        }
    }

    return 0;
}