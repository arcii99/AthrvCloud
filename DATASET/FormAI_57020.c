//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define a structure to save parsed resume data
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
};

// define a function to parse the resume
void parseResume(char* resumeContent) {
    // create a new resume object
    struct Resume resume;
    
    // find the name
    char* nameStart = strstr(resumeContent, "NAME:");
    if(nameStart == NULL) {
        printf("Name not found in the resume.");
        return;
    }
    char* nameEnd = strchr(nameStart + 5, '\n');
    if(nameEnd == NULL) {
        printf("Invalid name format in the resume.");
        return;
    }
    int nameLen = nameEnd - nameStart - 5;
    strncpy(resume.name, nameStart + 5, nameLen);
    resume.name[nameLen] = '\0';
    
    // find the email
    char* emailStart = strstr(resumeContent, "EMAIL:");
    if(emailStart == NULL) {
        printf("Email not found in the resume.");
        return;
    }
    char* emailEnd = strchr(emailStart + 6, '\n');
    if(emailEnd == NULL) {
        printf("Invalid email format in the resume.");
        return;
    }
    int emailLen = emailEnd - emailStart - 6;
    strncpy(resume.email, emailStart + 6, emailLen);
    resume.email[emailLen] = '\0';
    
    // find the phone
    char* phoneStart = strstr(resumeContent, "PHONE:");
    if(phoneStart == NULL) {
        printf("Phone not found in the resume.");
        return;
    }
    char* phoneEnd = strchr(phoneStart + 6, '\n');
    if(phoneEnd == NULL) {
        printf("Invalid phone format in the resume.");
        return;
    }
    int phoneLen = phoneEnd - phoneStart - 6;
    strncpy(resume.phone, phoneStart + 6, phoneLen);
    resume.phone[phoneLen] = '\0';
    
    // find the skills
    char* skillsStart = strstr(resumeContent, "SKILLS:");
    if(skillsStart == NULL) {
        printf("Skills not found in the resume.");
        return;
    }
    char* skillsEnd = strchr(skillsStart + 7, '\n');
    if(skillsEnd == NULL) {
        printf("Invalid skills format in the resume.");
        return;
    }
    int skillsLen = skillsEnd - skillsStart - 7;
    strncpy(resume.skills, skillsStart + 7, skillsLen);
    resume.skills[skillsLen] = '\0';
    
    // print the parsed data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
}

int main() {
    // read the resume file
    FILE *fp;
    fp = fopen("resume.txt", "r");
    if(fp == NULL) {
        printf("Resume file not found.");
        return 1;
    }
    char resumeContent[500];
    fgets(resumeContent, 500, fp);
    fclose(fp);
    
    // parse the resume
    parseResume(resumeContent);
    
    return 0;
}