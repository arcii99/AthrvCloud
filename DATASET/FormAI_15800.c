//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char phone_number[15];
    char address[100];
    char education[100];
    char experience[100];
} resume;

void parseResume(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist!\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strcmp(line, "Name:") == 0) {
            fgets(resume.name, sizeof(resume.name), fp);
            removeNewLine(resume.name);
        }
        else if (strcmp(line, "Email:") == 0) {
            fgets(resume.email, sizeof(resume.email), fp);
            removeNewLine(resume.email);
        }
        else if (strcmp(line, "Phone Number:") == 0) {
            fgets(resume.phone_number, sizeof(resume.phone_number), fp);
            removeNewLine(resume.phone_number);
        }
        else if (strcmp(line, "Address:") == 0) {
            fgets(resume.address, sizeof(resume.address), fp);
            removeNewLine(resume.address);
        }
        else if (strcmp(line, "Education:") == 0) {
            fgets(resume.education, sizeof(resume.education), fp);
            removeNewLine(resume.education);
        }
        else if (strcmp(line, "Experience:") == 0) {
            fgets(resume.experience, sizeof(resume.experience), fp);
            removeNewLine(resume.experience);
        }
    }

    fclose(fp);
}

void removeNewLine(char* str) {
    int len = strlen(str) - 1;
    if (str[len] == '\n') {
        str[len] = '\0';
    }
}

void printResume() {
    printf("-------------------------------------------------------\n");
    printf("Name:          %s\n", resume.name);
    printf("Email:         %s\n", resume.email);
    printf("Phone Number:  %s\n", resume.phone_number);
    printf("Address:       %s\n", resume.address);
    printf("Education:     %s\n", resume.education);
    printf("Experience:    %s\n", resume.experience);
    printf("-------------------------------------------------------\n");
}

int main() {
    parseResume("resume.txt");
    printResume();
    return 0;
}