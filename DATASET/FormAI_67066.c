//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume{
    char* name;
    char* email;
    char* phone;
    char* summary;
    char* education;
    char* skills;
    char* experience;
} Resume;

void parseResume(char* filename, Resume* r){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }
    char buffer[256];
    while(fgets(buffer, 256, fp)){
        if(strstr(buffer, "Name:")){
            r->name = strdup(buffer+5);
            r->name[strlen(r->name)-1] = '\0';
        } else if(strstr(buffer, "Email:")){
            r->email = strdup(buffer+6);
            r->email[strlen(r->email)-1] = '\0';
        } else if(strstr(buffer, "Phone:")){
            r->phone = strdup(buffer+6);
            r->phone[strlen(r->phone)-1] = '\0';
        } else if(strstr(buffer, "Summary:")){
            r->summary = strdup(buffer+8);
            r->summary[strlen(r->summary)-1] = '\0';
        } else if(strstr(buffer, "Education:")){
            r->education = strdup(buffer+10);
            r->education[strlen(r->education)-1] = '\0';
        } else if(strstr(buffer, "Skills:")){
            r->skills = strdup(buffer+7);
            r->skills[strlen(r->skills)-1] = '\0';
        } else if(strstr(buffer, "Experience:")){
            r->experience = strdup(buffer+11);
            r->experience[strlen(r->experience)-1] = '\0';
        }
    }
    fclose(fp);
}

int main(){
    Resume r;
    memset(&r, 0, sizeof(Resume));
    parseResume("resume.txt", &r);
    
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Summary: %s\n", r.summary);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
    
    free(r.name);
    free(r.email);
    free(r.phone);
    free(r.summary);
    free(r.education);
    free(r.skills);
    free(r.experience);
    
    return 0;
}