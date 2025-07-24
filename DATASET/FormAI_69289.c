//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <string.h>

struct ResumeInformation {
    char name[30];
    char email[50];
    char phone[20];
    char skills[100];
    char experience[200];
};

void parseResume(char* fileContent) {
    // Split fileContent into lines
    char* line = strtok(fileContent, "\n");
    
    // Initialize the ResumeInformation struct
    struct ResumeInformation resumeInfo;
    memset(&resumeInfo, 0, sizeof(resumeInfo));
    
    // Parse the lines
    while (line != NULL) {
        // Determine the type of data
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %s", resumeInfo.name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %s", resumeInfo.email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %s", resumeInfo.phone);
        } else if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %s", resumeInfo.skills);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %s", resumeInfo.experience);
        }
        line = strtok(NULL, "\n");
    }
    
    // Print the parsed information
    printf("Name: %s\n", resumeInfo.name);
    printf("Email: %s\n", resumeInfo.email);
    printf("Phone: %s\n", resumeInfo.phone);
    printf("Skills: %s\n", resumeInfo.skills);
    printf("Experience: %s\n", resumeInfo.experience);
}

int main() {
    char resumeFileContent[] = "Name: John Smith\nEmail: john.smith@gmail.com\nPhone: 555-5555\nSkills: C++, Java\nExperience: Software Developer";
    parseResume(resumeFileContent);
    return 0;
}