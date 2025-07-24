//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[500];
};

struct Resume parseResume(char* resumeText) {
    struct Resume resume;

    char* token = strtok(resumeText, "\n");

    while (token) {
        if (strstr(token, "Name: ")) {
            strcpy(resume.name, token + strlen("Name: "));
        }
        else if (strstr(token, "E-mail: ")) {
            strcpy(resume.email, token + strlen("E-mail: "));
        }
        else if (strstr(token, "Phone: ")) {
            strcpy(resume.phone, token + strlen("Phone: "));
        }
        else if (strstr(token, "Education: ")) {
            strcpy(resume.education, token + strlen("Education: "));
        }
        else if (strstr(token, "Experience: ")) {
            strcpy(resume.experience, token + strlen("Experience: "));
        }

        token = strtok(NULL, "\n");
    }

    return resume;
}


int main() {
    char resumeText[1000] = "Name: John Doe\nE-mail: john.doe@email.com\nPhone: 555-123-4567\n"
                            "Education: Bachelor's Degree in Computer Science\n"
                            "Experience: Software Developer at XYZ company for 3 years\n";

    struct Resume resume = parseResume(resumeText);

    printf("Name: %s\n", resume.name);
    printf("E-mail: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}