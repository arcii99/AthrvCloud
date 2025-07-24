//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MIN_MATCH_PERCENTAGE 60

typedef struct {
    char first_name[MAX_WORD_LENGTH];
    char last_name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char address[MAX_LINE_LENGTH];
    char education[MAX_LINE_LENGTH];
    char experience[MAX_LINE_LENGTH];
} Resume;

Resume parse_resume(FILE *file);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [resume_file]\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file '%s'\n", argv[1]);
        exit(1);
    }

    Resume resume = parse_resume(file);

    printf("First name: %s\n", resume.first_name);
    printf("Last name: %s\n", resume.last_name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    fclose(file);
    return 0;
}

Resume parse_resume(FILE *file) {
    Resume resume;
    strcpy(resume.first_name, "");
    strcpy(resume.last_name, "");
    strcpy(resume.email, "");
    strcpy(resume.phone, "");
    strcpy(resume.address, "");
    strcpy(resume.education, "");
    strcpy(resume.experience, "");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // First Name
        if (strlen(resume.first_name) == 0 && isupper(line[0])) {
            char *token = strtok(line, " \t\n");
            if (strlen(token) < MAX_WORD_LENGTH) {
                strcpy(resume.first_name, token);
            }
        }

        // Last Name
        if (strlen(resume.last_name) == 0 && isupper(line[0]) && strlen(resume.first_name) > 0) {
            char *token = strtok(line, " \t\n");
            if (strlen(token) < MAX_WORD_LENGTH) {
                strcpy(resume.last_name, token);
            }
        }

        // Email
        if (strlen(resume.email) == 0 && strstr(line, "@")) {
            char *token = strtok(line, " \t\n");
            if (strlen(token) < MAX_WORD_LENGTH && strstr(token, "@")) {
                strcpy(resume.email, token);
            }
        }

        // Phone
        if (strlen(resume.phone) == 0 && strstr(line, "phone")) {
            char *token = strtok(line, " \t\n");
            while (token != NULL) {
                if (strlen(token) < MAX_WORD_LENGTH && isdigit(token[0])) {
                    strcpy(resume.phone, token);
                    break;
                }
                token = strtok(NULL, " \t\n");
            }
        }

        // Address
        if (strlen(resume.address) == 0 && strstr(line, "address")) {
            int match_count = 0;
            char *token = strtok(line, " \t\n");
            while (token != NULL) {
                if (strlen(token) >= 4 && isupper(token[0])) {
                    match_count++;
                }
                token = strtok(NULL, " \t\n");
            }
            if (match_count > 2) {
                strcpy(resume.address, line);
            }
        }

        // Education
        if (strlen(resume.education) == 0 && strstr(line, "education")) {
            int match_count = 0;
            char *token = strtok(line, " \t\n");
            while (token != NULL) {
                if (strlen(token) >= 4 && isupper(token[0])) {
                    match_count++;
                }
                token = strtok(NULL, " \t\n");
            }
            if (match_count > 1) {
                strcpy(resume.education, line);
            }
        }

        // Experience
        if (strlen(resume.experience) == 0 && strstr(line, "experience")) {
            int match_count = 0;
            char *token = strtok(line, " \t\n");
            while (token != NULL) {
                if (strlen(token) >= 4 && isupper(token[0])) {
                    match_count++;
                }
                token = strtok(NULL, " \t\n");
            }
            if (match_count > 1) {
                strcpy(resume.experience, line);
            }
        }
    }

    // Check if first and last name are valid
    if (strlen(resume.first_name) == 0 || strlen(resume.last_name) == 0) {
        printf("Could not parse first and last name\n");
        exit(1);
    }

    // Check if email and phone are valid
    int valid_count = 0;
    if (strlen(resume.email) > 0) {
        valid_count++;
    }
    if (strlen(resume.phone) > 0) {
        valid_count++;
    }
    if (valid_count < 1) {
        printf("Could not parse email and phone\n");
        exit(1);
    }

    return resume;
}