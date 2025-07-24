//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[200];
} Resume;

void parse_resume(char *filename) {
    FILE *fp;
    char line[100];
    Resume resume;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(-1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %49s", resume.name);
        }
        else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %49s", resume.email);
        }
        else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %19s", resume.phone);
        }
        else if (strstr(line, "Education:")) {
            fgets(line, sizeof(line), fp);
            sscanf(line, "%99[^\n]", resume.education);
        }
        else if (strstr(line, "Experience:")) {
            fgets(line, sizeof(line), fp);
            sscanf(line, "%199[^\n]", resume.experience);
        }
    }

    fclose(fp);

    // Print out the parsed resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    parse_resume("resume.txt");
    return 0;
}