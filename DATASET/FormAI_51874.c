//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_RESUME_LENGTH 10000
#define MAX_SKILLS 100

typedef struct{
    char name[MAX_LINE_LENGTH];
    int years_of_exp;
} Skill;

typedef struct{
    char name[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
    char education[MAX_LINE_LENGTH];
    char experience[MAX_RESUME_LENGTH];
    Skill skills[MAX_SKILLS];
    int num_skills;
} Resume;

void parse_resume(char* filename, Resume* resume);
int count_years_exp(char* experience);
void count_skills(char* experience, Skill* skills, int* num_skills);

int main(int argc, char** argv){
    if(argc < 2){
        printf("Error: missing filename argument\n");
        exit(EXIT_FAILURE);
    }
    
    Resume my_resume;
    parse_resume(argv[1], &my_resume);
    
    printf("Name: %s\n", my_resume.name);
    printf("Email: %s\n", my_resume.email);
    printf("Education: %s\n", my_resume.education);
    
    int years_of_exp = count_years_exp(my_resume.experience);
    printf("Years of Experience: %d\n", years_of_exp);
    
    count_skills(my_resume.experience, my_resume.skills, &my_resume.num_skills);
    printf("Skills:\n");
    for(int i = 0; i < my_resume.num_skills; i++){
        printf("%s - %d years of experience\n", my_resume.skills[i].name, my_resume.skills[i].years_of_exp);
    }
    
    return 0;
}

void parse_resume(char* filename, Resume* resume){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL){
        if(strncmp(line, "Name:", 5) == 0){
            sscanf(line, "Name: %[^\n]", resume->name);
        }
        else if(strncmp(line, "Email:", 6) == 0){
            sscanf(line, "Email: %[^\n]", resume->email);
        }
        else if(strncmp(line, "Education:", 10) == 0){
            sscanf(line, "Education: %[^\n]", resume->education);
        }
        else if(strncmp(line, "Experience:", 11) == 0){
            fgets(line, MAX_LINE_LENGTH, fp); //skip line with dashes
            while(fgets(line, MAX_LINE_LENGTH, fp) != NULL && strncmp(line, "-", 1) == 0){
                strcat(resume->experience, line);
            }
        }
    }
    fclose(fp);
}

int count_years_exp(char* experience){
    int years_of_exp = 0;
    char* token = strtok(experience, "\n");
    while(token != NULL){
        int num_years = 0;
        if(sscanf(token, "%d years", &num_years) == 1){
            years_of_exp += num_years;
        }
        token = strtok(NULL, "\n");
    }
    return years_of_exp;
}

void count_skills(char* experience, Skill* skills, int* num_skills){
    int num = 0;
    char* token = strtok(experience, "\n");
    while(token != NULL){
        if(strncmp(token, "-", 1) == 0){
            char skill_name[MAX_LINE_LENGTH];
            int num_years = 0;
            sscanf(token, "- %[^,], %d years", skill_name, &num_years);
            strcpy(skills[num].name, skill_name);
            skills[num].years_of_exp = num_years;
            num++;
        }
        token = strtok(NULL, "\n");
    }
    *num_skills = num;
}