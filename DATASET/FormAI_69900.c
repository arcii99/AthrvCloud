//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 256

typedef struct resume {
    char name[MAX_FIELD_LEN];
    char email[MAX_FIELD_LEN];
    char phone[MAX_FIELD_LEN];
    char skills[MAX_FIELD_LEN];
    char experience[MAX_FIELD_LEN];
    char education[MAX_FIELD_LEN];
} Resume;

void trim(char* str) {
    int len = strlen(str);
    while (len > 0 && (str[len-1] == '\n' || str[len-1] == '\r')) {
        str[--len] = '\0';
    }
}

void parseResume(char* filename, Resume* r) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (strstr(line, "Name:") == line) {
            strncpy(r->name, line+strlen("Name:"), MAX_FIELD_LEN);
            trim(r->name);
        } else if (strstr(line, "Email:") == line) {
            strncpy(r->email, line+strlen("Email:"), MAX_FIELD_LEN);
            trim(r->email);
        } else if (strstr(line, "Phone:") == line) {
            strncpy(r->phone, line+strlen("Phone:"), MAX_FIELD_LEN);
            trim(r->phone);
        } else if (strstr(line, "Skills:") == line) {
            strncpy(r->skills, line+strlen("Skills:"), MAX_FIELD_LEN);
            trim(r->skills);
        } else if (strstr(line, "Experience:") == line) {
            strncpy(r->experience, line+strlen("Experience:"), MAX_FIELD_LEN);
            trim(r->experience);
        } else if (strstr(line, "Education:") == line) {
            strncpy(r->education, line+strlen("Education:"), MAX_FIELD_LEN);
            trim(r->education);
        }
    }

    fclose(fp);
}

void printResume(Resume* r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: ./resumeparse <resume.txt>\n");
        exit(1);
    }

    Resume r;
    memset(&r, 0, sizeof(r));
    parseResume(argv[1], &r);
    printResume(&r);

    return 0;
}