//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_SIZE 1024
#define MAX_RESUME_SIZE 5000

struct resume{
    char name[50];
    char email[50];
    char phone[50];
    char skills[MAX_BUF_SIZE];
    char experience[MAX_BUF_SIZE];
};

int parse_resume(const char* filename, struct resume* res){

    FILE* fp = fopen(filename,"r");
    if(fp==NULL){
        printf("ERROR: Unable to open file!\n");
        return 0;
    }

    char text[MAX_RESUME_SIZE];
    memset(text,0,sizeof(text));
    fread(text, sizeof(char), MAX_RESUME_SIZE, fp);

    //Search for Name
    int name_start = 0, name_end = 0;
    for(int i = 0; i < strlen(text); i++){
        if(strncmp(&text[i], "Name:",5) == 0){
            name_start = i + 5;
            name_end = name_start;
            while(text[name_end] != '\n') name_end++;
            strncpy(res->name, &text[name_start], name_end - name_start);
            res->name[name_end - name_start] = '\0';
            break;
        }
    }
    
    //Search for Email
    int email_start = 0, email_end = 0;
    for(int i = 0; i < strlen(text); i++){
        if(strncmp(&text[i], "Email:",6) == 0){
            email_start = i + 6;
            email_end = email_start;
            while(text[email_end] != '\n') email_end++;
            strncpy(res->email, &text[email_start], email_end - email_start);
            res->email[email_end - email_start] = '\0';
            break;
        }
    }
    
    //Search for Phone Number
    int phone_start = 0, phone_end = 0;
    for(int i = 0; i < strlen(text); i++){
        if(strncmp(&text[i], "Phone:",6) == 0){
            phone_start = i + 6;
            phone_end = phone_start;
            while(text[phone_end] != '\n') phone_end++;
            strncpy(res->phone, &text[phone_start], phone_end - phone_start);
            res->phone[phone_end - phone_start] = '\0';
            break;
        }
    }
    
    //Search for Skills
    int skills_start = 0, skills_end = 0;
    for(int i = 0; i < strlen(text); i++){
        if(strncmp(&text[i], "Skills:",7) == 0){
            skills_start = i + 7;
            skills_end = skills_start;
            while(text[skills_end] != '\n') skills_end++;
            strncpy(res->skills, &text[skills_start], skills_end - skills_start);
            res->skills[skills_end - skills_start] = '\0';
            break;
        }
    }
    
    //Search for Experience
    int exp_start = 0, exp_end = 0;
    for(int i = 0; i < strlen(text); i++){
        if(strncmp(&text[i], "Experience:",11) == 0){
            exp_start = i + 11;
            exp_end = exp_start;
            while(text[exp_end] != '\n') exp_end++;
            strncpy(res->experience, &text[exp_start], exp_end - exp_start);
            res->experience[exp_end - exp_start] = '\0';
            break;
        }
    }

    fclose(fp);

    return 1;
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct resume res;
    memset(&res, 0, sizeof(res));

    if(!parse_resume(argv[1], &res)){
        printf("ERROR: Parsing failed!\n");
        return 1;
    }

    printf("Name: %s\nEmail: %s\nPhone: %s\nSkills: %s\nExperience: %s\n",
           res.name,
           res.email,
           res.phone,
           res.skills,
           res.experience);

    return 0;
}