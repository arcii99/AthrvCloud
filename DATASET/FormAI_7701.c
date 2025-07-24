//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LEN 10000
#define MAX_SKILLS 50
#define MAX_EDUCATION 5

struct Education {
    char degree[50];
    char university[50];
    char year[10];
};

struct Skill {
    char name[50];
    int experience;
};

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    struct Education education[MAX_EDUCATION];
    struct Skill skills[MAX_SKILLS];
};

int main() {
    char resume[MAX_RESUME_LEN];
    struct Resume parsed_resume;

    printf("Enter your resume:\n");
    fgets(resume, MAX_RESUME_LEN, stdin);

    // Check for potential buffer overflow
    if (strlen(resume) == MAX_RESUME_LEN - 1 && resume[MAX_RESUME_LEN - 2] != '\n') {
        printf("Error: resume is too long\n");
        exit(EXIT_FAILURE);
    }

    // Parse name
    char *name_start = strstr(resume, "name:");
    if (name_start == NULL) {
        printf("Error: name not found\n");
        exit(EXIT_FAILURE);
    }
    char *name_end = strstr(name_start, "\n");
    if (name_end == NULL) {
        printf("Error: name end not found\n");
        exit(EXIT_FAILURE);
    }
    strncpy(parsed_resume.name, name_start + strlen("name:"), name_end - name_start - strlen("name:"));
    parsed_resume.name[name_end - name_start - strlen("name:")] = '\0';

    // Parse email
    char *email_start = strstr(resume, "email:");
    if (email_start == NULL) {
        printf("Error: email not found\n");
        exit(EXIT_FAILURE);
    }
    char *email_end = strstr(email_start, "\n");
    if (email_end == NULL) {
        printf("Error: email end not found\n");
        exit(EXIT_FAILURE);
    }
    strncpy(parsed_resume.email, email_start + strlen("email:"), email_end - email_start - strlen("email:"));
    parsed_resume.email[email_end - email_start - strlen("email:")] = '\0';

    // Parse phone
    char *phone_start = strstr(resume, "phone:");
    if (phone_start == NULL) {
        printf("Error: phone not found\n");
        exit(EXIT_FAILURE);
    }
    char *phone_end = strstr(phone_start, "\n");
    if (phone_end == NULL) {
        printf("Error: phone end not found\n");
        exit(EXIT_FAILURE);
    }
    strncpy(parsed_resume.phone, phone_start + strlen("phone:"), phone_end - phone_start - strlen("phone:"));
    parsed_resume.phone[phone_end - phone_start - strlen("phone:")] = '\0';

    // Parse education
    int num_education = 0;
    char *education_start = strstr(resume, "education:");
    while (education_start != NULL) {
        if (num_education >= MAX_EDUCATION) {
            printf("Error: too many education entries\n");
            exit(EXIT_FAILURE);
        }
        char *education_end = strstr(education_start, "\n");
        if (education_end == NULL) {
            printf("Error: education end not found\n");
            exit(EXIT_FAILURE);
        }
        char education_line[MAX_RESUME_LEN];
        strncpy(education_line, education_start + strlen("education:"), education_end - education_start - strlen("education:"));
        education_line[education_end - education_start - strlen("education:")] = '\0';
        char *degree_start = strstr(education_line, "degree:");
        if (degree_start == NULL) {
            printf("Error: degree not found\n");
            exit(EXIT_FAILURE);
        }
        char *degree_end = strstr(degree_start, ",");
        if (degree_end == NULL) {
            printf("Error: degree end not found\n");
            exit(EXIT_FAILURE);
        }
        strncpy(parsed_resume.education[num_education].degree, degree_start + strlen("degree:"), degree_end - degree_start - strlen("degree:"));
        parsed_resume.education[num_education].degree[degree_end - degree_start - strlen("degree:")] = '\0';
        char *university_start = strstr(degree_end, "university:");
        if (university_start == NULL) {
            printf("Error: university not found\n");
            exit(EXIT_FAILURE);
        }
        char *university_end = strstr(university_start, ",");
        if (university_end == NULL) {
            printf("Error: university end not found\n");
            exit(EXIT_FAILURE);
        }
        strncpy(parsed_resume.education[num_education].university, university_start + strlen("university:"), university_end - university_start - strlen("university:"));
        parsed_resume.education[num_education].university[university_end - university_start - strlen("university:")] = '\0';
        char *year_start = strstr(university_end, "year:");
        if (year_start == NULL) {
            printf("Error: year not found\n");
            exit(EXIT_FAILURE);
        }
        char *year_end = strstr(year_start, "\n");
        if (year_end == NULL) {
            printf("Error: year end not found\n");
            exit(EXIT_FAILURE);
        }
        strncpy(parsed_resume.education[num_education].year, year_start + strlen("year:"), year_end - year_start - strlen("year:"));
        parsed_resume.education[num_education].year[year_end - year_start - strlen("year:")] = '\0';
        num_education++;
        education_start = strstr(education_end, "education:");
    }

    // Parse skills
    int num_skills = 0;
    char *skills_start = strstr(resume, "skills:");
    while (skills_start != NULL) {
        if (num_skills >= MAX_SKILLS) {
            printf("Error: too many skills entries\n");
            exit(EXIT_FAILURE);
        }
        char *skills_end = strstr(skills_start, "\n");
        if (skills_end == NULL) {
            printf("Error: skills end not found\n");
            exit(EXIT_FAILURE);
        }
        char skill_line[MAX_RESUME_LEN];
        strncpy(skill_line, skills_start + strlen("skills:"), skills_end - skills_start - strlen("skills:"));
        skill_line[skills_end - skills_start - strlen("skills:")] = '\0';
        char *name_start = strstr(skill_line, "name:");
        if (name_start == NULL) {
            printf("Error: skill name not found\n");
            exit(EXIT_FAILURE);
        }
        char *name_end = strstr(name_start, ",");
        if (name_end == NULL) {
            printf("Error: skill name end not found\n");
            exit(EXIT_FAILURE);
        }
        strncpy(parsed_resume.skills[num_skills].name, name_start + strlen("name:"), name_end - name_start - strlen("name:"));
        parsed_resume.skills[num_skills].name[name_end - name_start - strlen("name:")] = '\0';
        char *experience_start = strstr(name_end, "experience:");
        if (experience_start == NULL) {
            printf("Error: skill experience not found\n");
            exit(EXIT_FAILURE);
        }
        char *experience_end = strstr(experience_start, "\n");
        if (experience_end == NULL) {
            printf("Error: skill experience end not found\n");
            exit(EXIT_FAILURE);
        }
        char experience_str[MAX_RESUME_LEN];
        strncpy(experience_str, experience_start + strlen("experience:"), experience_end - experience_start - strlen("experience:"));
        experience_str[experience_end - experience_start - strlen("experience:")] = '\0';
        parsed_resume.skills[num_skills].experience = atoi(experience_str);
        num_skills++;
        skills_start = strstr(skills_end, "skills:");
    }

    // Print parsed resume
    printf("Name: %s\n", parsed_resume.name);
    printf("Email: %s\n", parsed_resume.email);
    printf("Phone: %s\n", parsed_resume.phone);
    printf("Education:\n");
    for (int i = 0; i < num_education; i++) {
        printf("\tDegree: %s\n", parsed_resume.education[i].degree);
        printf("\tUniversity: %s\n", parsed_resume.education[i].university);
        printf("\tYear: %s\n", parsed_resume.education[i].year);
    }
    printf("Skills:\n");
    for (int i = 0; i < num_skills; i++) {
        printf("\tName: %s\n", parsed_resume.skills[i].name);
        printf("\tExperience: %d\n", parsed_resume.skills[i].experience);
    }

    return 0;
}