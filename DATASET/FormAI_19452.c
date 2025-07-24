//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[30];
    char email[50];
    char phone[20];
    char education[100];
    char experience[500];
};

int main() {
    struct Resume myResume;
    char resumeText[1000];

    printf("Enter your resume text: ");
    fgets(resumeText, 1000, stdin);

    char *token = strtok(resumeText, "|");

    while (token != NULL) {
        if (strstr(token, "Name:")) {
            strcpy(myResume.name, token + 5);
        } else if (strstr(token, "Email:")) {
            strcpy(myResume.email, token + 6);
        } else if (strstr(token, "Phone:")) {
            strcpy(myResume.phone, token + 6);
        } else if (strstr(token, "Education:")) {
            strcpy(myResume.education, token + 10);
        } else if (strstr(token, "Experience:")) {
            strcpy(myResume.experience, token + 12);
        }
        token = strtok(NULL, "|");
    }

    printf("\nResume Information: \n");
    printf("Name: %s", myResume.name);
    printf("Email: %s", myResume.email);
    printf("Phone: %s", myResume.phone);
    printf("Education: %s", myResume.education);
    printf("Experience: %s", myResume.experience);

    return 0;
}