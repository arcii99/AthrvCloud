//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

typedef struct {
    char name[MAX_LINE_LEN];
    char email[MAX_LINE_LEN];
    char phone[MAX_LINE_LEN];
    char university[MAX_LINE_LEN];
    char major[MAX_LINE_LEN];
    char degree[MAX_LINE_LEN];
    char skills[MAX_LINE_LEN];
} Resume;

void parse_resume(char* filename, Resume* resume) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %s", resume->name);
        }
        else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %s", resume->email);
        }
        else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %s", resume->phone);
        }
        else if (strstr(line, "University:")) {
            sscanf(line, "University: %[^\n]", resume->university);
        }
        else if (strstr(line, "Major:")) {
            sscanf(line, "Major: %[^\n]", resume->major);
        }
        else if (strstr(line, "Degree:")) {
            sscanf(line, "Degree: %[^\n]", resume->degree);
        }
        else if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %[^\n]", resume->skills);
        }
    }

    fclose(fp);
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("University: %s\n", resume->university);
    printf("Major: %s\n", resume->major);
    printf("Degree: %s\n", resume->degree);
    printf("Skills: %s\n", resume->skills);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    Resume resume;
    memset(&resume, 0, sizeof(resume));

    parse_resume(argv[1], &resume);

    print_resume(&resume);

    return 0;
}