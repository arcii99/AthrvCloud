//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <string.h>

// Define a struct for storing information about an individual's resume
typedef struct resume {
    char name[50];
    char email[50];
    char skills[500];
    char education[100];
} Resume;

// Define a function for parsing resume information
Resume parseResume(char *text) {
    Resume resume;
    
    // Find name
    char *nameStart = strstr(text, "Name:") + 6;
    char *nameEnd = strstr(nameStart, "\n");
    strncpy(resume.name, nameStart, nameEnd-nameStart);
    resume.name[nameEnd-nameStart] = '\0';
    
    // Find email
    char *emailStart = strstr(text, "Email:") + 7;
    char *emailEnd = strstr(emailStart, "\n");
    strncpy(resume.email, emailStart, emailEnd-emailStart);
    resume.email[emailEnd-emailStart] = '\0';
    
    // Find skills
    char *skillsStart = strstr(text, "Skills:") + 8;
    char *skillsEnd = strstr(skillsStart, "\n\n");
    strncpy(resume.skills, skillsStart, skillsEnd-skillsStart);
    resume.skills[skillsEnd-skillsStart] = '\0';
    
    // Find education
    char *eduStart = strstr(text, "Education:") + 10;
    char *eduEnd = strstr(eduStart, "\n\n");
    strncpy(resume.education, eduStart, eduEnd-eduStart);
    resume.education[eduEnd-eduStart] = '\0';
    
    return resume;
}

int main() {
    // Sample resume text
    char *text = "Name: John Doe\n"
                 "Email: johndoe@gmail.com\n"
                 "Skills: C, Python, Java, HTML\n"
                 "Education: B.S. in Computer Science from XYZ University\n";
    
    // Parse the resume
    Resume resume = parseResume(text);
    
    // Print the information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);
    
    return 0;
}