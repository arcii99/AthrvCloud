//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char name[MAX_STR_LEN];
    char email[MAX_STR_LEN];
    int experience;
    char skills[MAX_STR_LEN];
} Resume;

typedef struct {
    char skill[MAX_STR_LEN];
    int required_experience;
} JobDescription;

Resume parse_resume(char* text) {
    Resume resume;
    char* cur_str = strtok(text, "\n");
    while (cur_str != NULL) {
        if (strstr(cur_str, "Name:") != NULL) {
            strcpy(resume.name, cur_str + strlen("Name: "));
        } else if (strstr(cur_str, "Email:") != NULL) {
            strcpy(resume.email, cur_str + strlen("Email: "));
        } else if (strstr(cur_str, "Experience:") != NULL) {
            resume.experience = atoi(cur_str + strlen("Experience: "));
        } else if (strstr(cur_str, "Skills:") != NULL) {
            strcpy(resume.skills, cur_str + strlen("Skills: "));
        }
        cur_str = strtok(NULL, "\n");
    }
    return resume;
}

int matches_job(Resume resume, JobDescription job) {
    if (strstr(resume.skills, job.skill) != NULL) {
        return resume.experience >= job.required_experience;
    }
    return 0;
}

int main() {
    char resume_text[MAX_STR_LEN] = "Name: John Smith\nEmail: jsmith@gmail.com\nExperience: 5\nSkills: C++, Java, Python\n";
    Resume resume = parse_resume(resume_text);
    JobDescription job = {"C++", 3};
    if (matches_job(resume, job)) {
        printf("Resume matches the job description!");
    } else {
        printf("Resume does not match the job description.");
    }
    return 0;
}