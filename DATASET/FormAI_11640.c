//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int num_skills;
} Resume;

Resume parse_resume(char* resume_str);
void print_skill_set(char skills[][MAX_SKILL_LENGTH], int num_skills);

int main() {
    char resumes[MAX_RESUMES][1000];
    int num_resumes = 0;
    
    // mock data for resumes
    strcpy(resumes[num_resumes++], "Name: John Doe\nSkills: C, Python, Java");
    strcpy(resumes[num_resumes++], "Name: Jane Smith\nSkills: Ruby, JavaScript, SQL");
    strcpy(resumes[num_resumes++], "Name: Michael Scott\nSkills: Sales, Management, Public Speaking");
    
    Resume resume_list[MAX_RESUMES];
    int num_valid_resumes = 0;
    
    // parse all resumes and store them in an array of Resume structures
    for (int i = 0; i < num_resumes; i++) {
        Resume current_resume = parse_resume(resumes[i]);
        if (current_resume.num_skills > 0) {
            resume_list[num_valid_resumes++] = current_resume;
        }
    }
    
    // print out all the valid resumes and their associated skill sets
    for (int i = 0; i < num_valid_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("Name: %s\n", resume_list[i].name);
        printf("Skills: ");
        print_skill_set(resume_list[i].skills, resume_list[i].num_skills);
        printf("\n");
    }
    
    return 0;
}

Resume parse_resume(char* resume_str) {
    Resume resume;
    char* name_start = strstr(resume_str, "Name: ");
    if (name_start == NULL) {
        resume.num_skills = 0;
        return resume;
    }
    sscanf(name_start, "Name: %s\n", resume.name);
    
    char* skills_start = strstr(resume_str, "Skills: ");
    if (skills_start == NULL) {
        resume.num_skills = 0;
        return resume;
    }
    
    char* skills_end = strstr(skills_start, "\0");
    char skills_str[500];
    strncpy(skills_str, skills_start + strlen("Skills: "), skills_end - skills_start - strlen("Skills: "));
    
    char* skill = strtok(skills_str, ", ");
    int num_skills = 0;
    while (skill != NULL && num_skills < MAX_SKILLS) {
        strcpy(resume.skills[num_skills++], skill);
        skill = strtok(NULL, ", ");
    }
    resume.num_skills = num_skills;
    
    return resume;
}

void print_skill_set(char skills[][MAX_SKILL_LENGTH], int num_skills) {
    for (int i = 0; i < num_skills; i++) {
        printf("%s", skills[i]);
        if (i != num_skills-1) {
            printf(", ");
        }
    }
}