//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char email[30];
    char phone[15];
    char education[50];
} Resume;

void parseResume(char* file_name, Resume* resume) {
    FILE* fp;
    char buffer[100];

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "Name:")) {
            sscanf(buffer, "%*s %s", resume->name);
        } else if (strstr(buffer, "Email:")) {
            sscanf(buffer, "%*s %s", resume->email);
        } else if (strstr(buffer, "Phone:")) {
            sscanf(buffer, "%*s %s", resume->phone);
        } else if (strstr(buffer, "Education:")) {
            fgets(buffer, sizeof(buffer), fp);
            sscanf(buffer, "%[^\n]", resume->education);
        }
    }

    fclose(fp);
}

int main() {
    Resume my_resume;

    parseResume("resume.txt", &my_resume);

    printf("Name: %s\n", my_resume.name);
    printf("Email: %s\n", my_resume.email);
    printf("Phone: %s\n", my_resume.phone);
    printf("Education: %s\n", my_resume.education);

    return 0;
}