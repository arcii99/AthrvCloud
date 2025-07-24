//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct to hold parsed resume data
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[1000];
    char education[100];
};

// Function to parse the resume and return a Resume struct
struct Resume parseResume(char* resumeText) {
    struct Resume resume;

    // Parse name
    char* nameStart = strstr(resumeText, "Name: ");
    if (nameStart != NULL) {
        nameStart += strlen("Name: ");
        char* nameEnd = strstr(nameStart, "\n");
        if (nameEnd != NULL) {
            strncpy(resume.name, nameStart, nameEnd - nameStart);
            resume.name[nameEnd - nameStart] = '\0';
        }
    }

    // Parse email
    char* emailStart = strstr(resumeText, "Email: ");
    if (emailStart != NULL) {
        emailStart += strlen("Email: ");
        char* emailEnd = strstr(emailStart, "\n");
        if (emailEnd != NULL) {
            strncpy(resume.email, emailStart, emailEnd - emailStart);
            resume.email[emailEnd - emailStart] = '\0';
        }
    }

    // Parse phone number
    char* phoneStart = strstr(resumeText, "Phone: ");
    if (phoneStart != NULL) {
        phoneStart += strlen("Phone: ");
        char* phoneEnd = strstr(phoneStart, "\n");
        if (phoneEnd != NULL) {
            strncpy(resume.phone, phoneStart, phoneEnd - phoneStart);
            resume.phone[phoneEnd - phoneStart] = '\0';
        }
    }

    // Parse skills
    char* skillsStart = strstr(resumeText, "Skills: ");
    if (skillsStart != NULL) {
        skillsStart += strlen("Skills: ");
        char* skillsEnd = strstr(skillsStart, "\n\n");
        if (skillsEnd != NULL) {
            strncpy(resume.skills, skillsStart, skillsEnd - skillsStart);
            resume.skills[skillsEnd - skillsStart] = '\0';
        }
    }

    // Parse education
    char* educationStart = strstr(resumeText, "Education: ");
    if (educationStart != NULL) {
        educationStart += strlen("Education: ");
        char* educationEnd = strstr(educationStart, "\n");
        if (educationEnd != NULL) {
            strncpy(resume.education, educationStart, educationEnd - educationStart);
            resume.education[educationEnd - educationStart] = '\0';
        }
    }

    return resume;
}

int main() {
    // Example resume text
    char* resumeText = "Name: John Smith\n"
                       "Email: john.smith@gmail.com\n"
                       "Phone: 555-555-5555\n"
                       "\n"
                       "Skills: C, Java, Python\n"
                       "\n"
                       "Education: BS in Computer Science, University of California, Berkeley\n";

    // Parse the resume
    struct Resume resume = parseResume(resumeText);

    // Print the parsed data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);

    return 0;
}