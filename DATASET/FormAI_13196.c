//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

int main() {
    Resume myResume;

    char *resumeText = "Name: John Doe\nEmail: john.doe@email.com\nPhone: 123-456-7890\nSkills: C, Java, Python\nExperience: Software Engineer at ABC Inc.\nEducation: Bachelor's Degree in Computer Science";

    char *nameStart = strstr(resumeText, "Name: ") + strlen("Name: ");
    char *emailStart = strstr(resumeText, "Email: ") + strlen("Email: ");
    char *phoneStart = strstr(resumeText, "Phone: ") + strlen("Phone: ");
    char *skillsStart = strstr(resumeText, "Skills: ") + strlen("Skills: ");
    char *experienceStart = strstr(resumeText, "Experience: ") + strlen("Experience: ");
    char *educationStart = strstr(resumeText, "Education: ") + strlen("Education: ");

    char *nameEnd = strstr(nameStart, "\n");
    char *emailEnd = strstr(emailStart, "\n");
    char *phoneEnd = strstr(phoneStart, "\n");
    char *skillsEnd = strstr(skillsStart, "\n");
    char *experienceEnd = strstr(experienceStart, "\n");
    char *educationEnd = strstr(educationStart, "\n");

    int nameLength = nameEnd - nameStart;
    int emailLength = emailEnd - emailStart;
    int phoneLength = phoneEnd - phoneStart;
    int skillsLength = skillsEnd - skillsStart;
    int experienceLength = experienceEnd - experienceStart;
    int educationLength = educationEnd - educationStart;

    myResume.name = (char*)malloc(nameLength + 1);
    myResume.email = (char*)malloc(emailLength + 1);
    myResume.phone = (char*)malloc(phoneLength + 1);
    myResume.skills = (char*)malloc(skillsLength + 1);
    myResume.experience = (char*)malloc(experienceLength + 1);
    myResume.education = (char*)malloc(educationLength + 1);

    strncpy(myResume.name, nameStart, nameLength);
    strncpy(myResume.email, emailStart, emailLength);
    strncpy(myResume.phone, phoneStart, phoneLength);
    strncpy(myResume.skills, skillsStart, skillsLength);
    strncpy(myResume.experience, experienceStart, experienceLength);
    strncpy(myResume.education, educationStart, educationLength);

    myResume.name[nameLength] = '\0';
    myResume.email[emailLength] = '\0';
    myResume.phone[phoneLength] = '\0';
    myResume.skills[skillsLength] = '\0';
    myResume.experience[experienceLength] = '\0';
    myResume.education[educationLength] = '\0';

    printf("Name: %s\nEmail: %s\nPhone: %s\nSkills: %s\nExperience: %s\nEducation: %s\n",
            myResume.name, myResume.email, myResume.phone, myResume.skills, myResume.experience, myResume.education);

    free(myResume.name);
    free(myResume.email);
    free(myResume.phone);
    free(myResume.skills);
    free(myResume.experience);
    free(myResume.education);

    return 0;
}