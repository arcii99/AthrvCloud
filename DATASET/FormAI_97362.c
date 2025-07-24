//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char education[1000];
    char skills[1000];
    int experience_years;
} Resume;

// Count number of occurrences of a word in a string
int count_word(char *str, char *word) {
    int count = 0;
    char *pch = strstr(str, word);
    while (pch != NULL) {
        count++;
        pch = strstr(pch + 1, word);
    }
    return count;
}

// Parse the education section of the resume
char *parse_education(char *resume_str) {
    char *start = strstr(resume_str, "Education");
    if (start == NULL) {
        return "";
    }
    char *end = strstr(start, "Experience");
    if (end == NULL) {
        return "";
    }
    int len = end - start - 9; // 9 is the length of "Education"
    char *education = (char *) malloc(sizeof(char) * (len + 1));
    strncpy(education, start + 10, len);
    education[len] = '\0';
    return education;
}

// Parse the skills section of the resume
char *parse_skills(char *resume_str) {
    char *start = strstr(resume_str, "Skills");
    if (start == NULL) {
        return "";
    }
    char *end = strstr(start, "Experience");
    if (end == NULL) {
        return "";
    }
    int len = end - start - 6; // 6 is the length of "Skills"
    char *skills = (char *) malloc(sizeof(char) * (len + 1));
    strncpy(skills, start + 7, len);
    skills[len] = '\0';
    return skills;
}

// Parse the experience section of the resume
int parse_experience(char *resume_str) {
    char *start = strstr(resume_str, "Experience");
    if (start == NULL) {
        return 0;
    }
    char *end = strstr(start, "Education");
    if (end == NULL) {
        return 0;
    }
    int count = count_word(start, "Company");
    return count;
}

// Parse the resume into a Resume struct
Resume parse_resume(char *resume_str) {
    Resume resume;
    memset(&resume, 0, sizeof(resume));
    char *ptr = resume_str;
    char *line = strtok(ptr, "\n");
    while (line != NULL) {
        if (strstr(line, "Name: ")) {
            sscanf(line, "Name: %s", resume.name);
        } else if (strstr(line, "Email: ")) {
            sscanf(line, "Email: %s", resume.email);
        } else if (strstr(line, "Phone: ")) {
            sscanf(line, "Phone: %s", resume.phone);
        }
        line = strtok(NULL, "\n");
    }
    strncpy(resume.education, parse_education(resume_str), 999);
    strncpy(resume.skills, parse_skills(resume_str), 999);
    resume.experience_years = parse_experience(resume_str);
    return resume;
}

int main() {
    char resume_str[5000];
    printf("Enter resume text:\n");
    fgets(resume_str, 5000, stdin);
    Resume resume = parse_resume(resume_str);
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);
    printf("Experience Years: %d\n", resume.experience_years);
    return 0;
}