//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include<stdio.h>
#include<string.h>

// A structure to store information about resumes
struct Resume {
    char name[50];
    char email[50];
    char mobile[15];
    char skills[100];
};

// A function to parse the resume and extract the relevant information
void parseResume(struct Resume *r, char *resumeContents) {
    // First, extract the name
    char *name = strtok(resumeContents, "\n");
    strcpy(r->name, name);
    
    // Extract the email
    char *email = strtok(NULL, "\n");
    strcpy(r->email, email);
    
    // Extract the mobile number
    char *mobile = strtok(NULL, "\n");
    strcpy(r->mobile, mobile);
    
    // Extract the skills
    char *skills = strtok(NULL, "\n");
    strcpy(r->skills, skills);
}

// A function to display the information stored in a Resume struct
void displayResume(struct Resume r) {
    printf("\nName: %s", r.name);
    printf("\nEmail: %s", r.email);
    printf("\nMobile: %s", r.mobile);
    printf("\nSkills: %s\n", r.skills);
}

int main() {
    char resumeContents[500];
    // Assume that resumeContents is filled with the contents of an actual resume in text format
    
    struct Resume r;
    parseResume(&r, resumeContents);
    displayResume(r);
    
    return 0;
}