//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME 1000
#define MAX_SKILLS 10

struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char skills[MAX_SKILLS][50];
    int skill_count;
};

void parse_resume(struct Resume *resume, char *file_name) {
    FILE *fp;
    char line[MAX_RESUME];

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Could not open file '%s'\n", file_name);
        return;
    }

    while (fgets(line, MAX_RESUME, fp)) {
        if (strstr(line, "Name: ")) {
            strcpy(resume->name, line + strlen("Name: "));
        } else if (strstr(line, "Email: ")) {
            strcpy(resume->email, line + strlen("Email: "));
        } else if (strstr(line, "Phone: ")) {
            strcpy(resume->phone, line + strlen("Phone: "));
        } else if (strstr(line, "Address: ")) {
            strcpy(resume->address, line + strlen("Address: "));
        } else if (strstr(line, "Skills: ")) {
            char *token = strtok(line + strlen("Skills: "), ",");
            while (token != NULL) {
                strcpy(resume->skills[resume->skill_count++], token);
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(fp);
}

int main() {
    struct Resume resume;
    memset(&resume, 0, sizeof(struct Resume));

    parse_resume(&resume, "resume.txt");

    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Address: %s", resume.address);
    printf("Skills:\n");
    for (int i = 0; i < resume.skill_count; i++) {
        printf("\t%s\n", resume.skills[i]);
    }

    return 0;
}