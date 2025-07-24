//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for resume details
struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char education[100];
    char experience[200];
    char skills[300];
};

// Function to parse and fill the resume structure
void parseResume(struct Resume *resume, char *resumeText) {
    char *line;
    line = strtok(resumeText, "\n");
    while (line != NULL) {
        if (strstr(line, "Name:")) {
            strcpy(resume->name, line+5);
        } else if (strstr(line, "Email:")) {
            strcpy(resume->email, line+6);
        } else if (strstr(line, "Phone:")) {
            strcpy(resume->phone, line+6);
        } else if (strstr(line, "Address:")) {
            strcpy(resume->address, line+8);
        } else if (strstr(line, "Education:")) {
            strcpy(resume->education, line+10);
        } else if (strstr(line, "Experience:")) {
            strcpy(resume->experience, line+11);
        } else if (strstr(line, "Skills:")) {
            strcpy(resume->skills, line+7);
        }
        line = strtok(NULL, "\n");
    }
}

int main() {
    char resumeText[] = "Name: John Doe\nEmail: john.doe@email.com\nPhone: 123-456-7890\nAddress: 123 Main St.\n"
        "Education: Bachelor of Science in Computer Science\nExperience: Software Developer at ABC Inc.\n"
        "Skills: C, Java, Python, SQL";

    struct Resume resume;
    parseResume(&resume, resumeText);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}