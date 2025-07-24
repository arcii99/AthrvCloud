//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>

struct Applicant {
    char name[50];
    char email[50];
    char education[100];
    char experience[500];
};

int main() {
    struct Applicant applicant1;
    char buffer[1024];
    int i = 0;
    char c;

    // Read resume text from file
    FILE* fp;
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            buffer[i] = ' ';
            i++;
        } else {
            buffer[i] = c;
            i++;
        }
    }
    buffer[i] = '\0';
    fclose(fp);

    // Parse resume text
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        if (strstr(token, "Name:")) {
            sscanf(token, "Name:%s", applicant1.name);
        } else if (strstr(token, "Email:")) {
            sscanf(token, "Email:%s", applicant1.email);
        } else if (strstr(token, "Education:")) {
            strcat(applicant1.education, token);
            strcat(applicant1.education, " ");
            token = strtok(NULL, " ");
            while (!strstr(token, "Experience:")) {
                strcat(applicant1.education, token);
                strcat(applicant1.education, " ");
                token = strtok(NULL, " ");
            }
        } else if (strstr(token, "Experience:")) {
            strcat(applicant1.experience, token);
            strcat(applicant1.experience, " ");
            token = strtok(NULL, " ");
            while (token != NULL) {
                strcat(applicant1.experience, token);
                strcat(applicant1.experience, " ");
                token = strtok(NULL, " ");
            }
        }
        token = strtok(NULL, " ");
    }

    // Print parsed data
    printf("Name: %s\n", applicant1.name);
    printf("Email: %s\n", applicant1.email);
    printf("Education: %s\n", applicant1.education);
    printf("Experience: %s\n", applicant1.experience);

    return 0;
}