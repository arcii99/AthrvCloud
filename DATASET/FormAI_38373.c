//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_RESUME_LENGTH 5000

struct Resume {
    char name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char phone_number[MAX_STRING_LENGTH];
    char work_experience[MAX_RESUME_LENGTH];
    char education[MAX_RESUME_LENGTH];
    char skills[MAX_RESUME_LENGTH];
};

int main() {
    char resume_input[MAX_RESUME_LENGTH];
    struct Resume resume_output;
    
    printf("Enter your resume:\n");
    fgets(resume_input, MAX_RESUME_LENGTH, stdin);
    
    // Parsing name
    char* namePtr = strstr(resume_input, "Name:");
    if (namePtr == NULL) {
        printf("Error: Name not found\n");
        return 0;
    }
    sscanf(namePtr, "Name: %99[^\n]", resume_output.name);
    
    // Parsing email
    char* emailPtr = strstr(resume_input, "Email:");
    if (emailPtr == NULL) {
        printf("Error: Email not found\n");
        return 0;
    }
    sscanf(emailPtr, "Email: %99[^\n]", resume_output.email);
    
    // Parsing phone number
    char* phonePtr = strstr(resume_input, "Phone:");
    if (phonePtr == NULL) {
        printf("Error: Phone number not found\n");
        return 0;
    }
    sscanf(phonePtr, "Phone: %99[^\n]", resume_output.phone_number);
    
    // Parsing work experience
    char* workPtr = strstr(resume_input, "Work Experience:");
    if (workPtr == NULL) {
        printf("Error: Work experience not found\n");
        return 0;
    }
    sscanf(workPtr, "Work Experience: %4999[^\n]", resume_output.work_experience);
    
    // Parsing education
    char* educationPtr = strstr(resume_input, "Education:");
    if (educationPtr == NULL) {
        printf("Error: Education not found\n");
        return 0;
    }
    sscanf(educationPtr, "Education: %4999[^\n]", resume_output.education);
    
    // Parsing skills
    char* skillsPtr = strstr(resume_input, "Skills:");
    if (skillsPtr == NULL) {
        printf("Error: Skills not found\n");
        return 0;
    }
    sscanf(skillsPtr, "Skills: %4999[^\n]", resume_output.skills);
    
    // Outputting parsed resume data
    printf("\nName: %s\n", resume_output.name);
    printf("Email: %s\n", resume_output.email);
    printf("Phone: %s\n", resume_output.phone_number);
    printf("Work Experience: %s\n", resume_output.work_experience);
    printf("Education: %s\n", resume_output.education);
    printf("Skills: %s\n", resume_output.skills);
    
    return 0;
}