//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing resume data
struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[500];
};

// Define the function to parse a resume and extract the data
void parse_resume(char *filename, struct resume *r) {
    char line[100];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strlen(line)-1] = '\0'; // remove newline character
        if (strstr(line, "Name:") != NULL) {
            strcpy(r->name, line + strlen("Name:"));
        } else if (strstr(line, "Email:") != NULL) {
            strcpy(r->email, line + strlen("Email:"));
        } else if (strstr(line, "Phone:") != NULL) {
            strcpy(r->phone, line + strlen("Phone:"));
        } else if (strstr(line, "Education:") != NULL) {
            strcpy(r->education, line + strlen("Education:"));
        } else if (strstr(line, "Experience:") != NULL) {
            strcpy(r->experience, line + strlen("Experience:"));
        }
    }
    fclose(fp);
}

int main() {
    struct resume r;
    parse_resume("resume.txt", &r);
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
    return 0;
}