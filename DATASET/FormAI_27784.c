//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000
#define MAX_RES 100

typedef struct{
    char name[MAX_LEN];
    char email[MAX_LEN];
    char phone[MAX_LEN];
    char education[MAX_LEN];
    char skills[MAX_LEN];
    char experience[MAX_RES][MAX_LEN];
    int num_exp;
} Resume;

int parse_resume(char* file_name, Resume* res){
    FILE *file_p;
    char line[MAX_LEN];
    char *token, *field;

    file_p = fopen(file_name, "r");

    if(!file_p){
        return 0;
    }

    while(fgets(line, MAX_LEN, file_p)){
        strtok(line, "\n"); //remove new line character
        token = strtok(line, ":");
        field = strtok(NULL, "");

        if(strcmp(token, "Name") == 0){
            strcpy(res->name, field);
        }else if(strcmp(token, "Email") == 0){
            strcpy(res->email, field);
        }else if(strcmp(token, "Phone") == 0){
            strcpy(res->phone, field);
        }else if(strcmp(token, "Education") == 0){
            strcpy(res->education, field);
        }else if(strcmp(token, "Skills") == 0){
            strcpy(res->skills, field);
        }else if(strcmp(token, "Experience") == 0){
            strcpy(res->experience[res->num_exp++], field);
        }
    }

    fclose(file_p);
    return 1;
}

void print_resume(Resume res){
    int i;

    printf("Name: %s\n", res.name);
    printf("Email: %s\n", res.email);
    printf("Phone: %s\n", res.phone);
    printf("Education: %s\n", res.education);
    printf("Skills: %s\n", res.skills);
    printf("Experience:\n");
    for(i = 0; i < res.num_exp; i++){
        printf("\t%s\n", res.experience[i]);
    }
}

int main(){
    Resume res;
    int r;

    r = parse_resume("resume.txt", &res);

    if(r){
        print_resume(res);
    }else{
        printf("Error parsing resume.\n");
    }

    return 0;
}