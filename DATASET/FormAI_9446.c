//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_EMAIL_LEN 64
#define MAX_PHONE_LEN 16
#define MAX_SKILL_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
    char skills[MAX_SKILL_LEN][MAX_SKILL_LEN];
    int num_skills;
} Resume;

void parse_resume(char* filename, Resume* res) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    char buffer[MAX_SKILL_LEN+1];
    while (!feof(file)) {
        char line[MAX_EMAIL_LEN+MAX_PHONE_LEN+2];
        if (fgets(line, sizeof(line), file) == NULL) {
            break;
        }
        line[strcspn(line, "\r\n")] = '\0'; // remove newline at end
        if (strncmp(line, "Name: ", 6) == 0) {
            strncpy(res->name, line+6, MAX_NAME_LEN);
            res->name[MAX_NAME_LEN-1] = '\0'; // make sure it's null terminated
        } else if (strncmp(line, "Email: ", 7) == 0) {
            strncpy(res->email, line+7, MAX_EMAIL_LEN);
            res->email[MAX_EMAIL_LEN-1] = '\0';
        } else if (strncmp(line, "Phone: ", 7) == 0) {
            strncpy(res->phone, line+7, MAX_PHONE_LEN);
            res->phone[MAX_PHONE_LEN-1] = '\0';
        } else if (strncmp(line, "Skills: ", 8) == 0) {
            char* ptr = line+8;
            while (*ptr != '\0') {
                int len = strcspn(ptr, ",");
                if (len == 0 || len >= MAX_SKILL_LEN) {
                    ptr++; // skip separator or invalid skill
                    continue;
                }
                strncpy(buffer, ptr, len);
                buffer[len] = '\0'; // make sure it's null terminated
                if (res->num_skills < MAX_SKILL_LEN) {
                    strncpy(res->skills[res->num_skills], buffer, MAX_SKILL_LEN);
                    res->num_skills++;
                }
                ptr += len+1; // skip separator
            }
        }
    }
    fclose(file);
}

void print_resume(Resume* res) {
    printf("Name: %s\n", res->name);
    printf("Email: %s\n", res->email);
    printf("Phone: %s\n", res->phone);
    printf("Skills:");
    for (int i = 0; i < res->num_skills; i++) {
        printf(" %s", res->skills[i]);
    }
    printf("\n");
}

int main() {
    Resume res;
    memset(&res, 0, sizeof(Resume)); // initialize to zero
    parse_resume("resume.txt", &res);
    print_resume(&res);
    return 0;
}