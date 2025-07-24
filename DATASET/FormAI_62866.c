//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store Resume Information
struct ResumeInfo {
    char name[50];
    char email[100];
    char phone[20];
    char skills[500];
    char experience[1000];
    char education[500];
};

// Function to parse the Resume
struct ResumeInfo parseResume(char resumeContent[]) {

    struct ResumeInfo resume;

    // Parsing Name
    char *token = strtok(resumeContent,"\n");
    strcpy(resume.name,token);

    // Parsing Email
    token = strtok(NULL,"\n");
    strcpy(resume.email,token);

    // Parsing Phone number
    token = strtok(NULL,"\n");
    strcpy(resume.phone,token);

    // Parsing Skills
    char skills[500]="";
    while(token = strtok(NULL,"\n")) {
        strcat(skills,token);
    }
    strcpy(resume.skills,skills);

    // Randomly Generating Experience Details
    char experience[1000]="";
    char temp[100];
    for(int i=0;i<(rand()%5+1);i++) {
        sprintf(temp,"\nExperience %d:\nCompany Name: ABC Inc.\nDesignation: Developer\nDuration: 2 Years\n",i+1);
        strcat(experience,temp);
    }
    strcpy(resume.experience,experience);

    // Parsing Education Details
    char education[500]="";
    sprintf(temp,"\nUniversity: XYZ University\nDegree: Masters in Computer Science\nDuration: 2 Years\n");
    strcat(education,temp);
    sprintf(temp,"\nUniversity: VGT University\nDegree: Bachelors in Information Technology\nDuration: 4 Years\n");
    strcat(education,temp);
    strcpy(resume.education,education);

    return resume;
}

int main() {
    char resumeContent[] = "John Doe\njohndoe@email.com\n999-999-9999\n\
                           C++, Java, Python, HTML, CSS, JavaScript\n";
      
    // Parsing the Resume Content
    struct ResumeInfo resume = parseResume(resumeContent);

    // Displaying the parsed resume information
    printf("Name: %s\n",resume.name);
    printf("Email: %s\n",resume.email);
    printf("Phone: %s\n",resume.phone);
    printf("Skills: %s\n",resume.skills);
    printf("Experience: %s\n",resume.experience);
    printf("Education: %s\n",resume.education);

    return 0;
}