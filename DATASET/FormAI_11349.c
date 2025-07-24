//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Resume {
    char name[20];
    char email[30];
    char experience[50];
    char education[50];
    int age;
};

struct Resume parse_resume(char *filename);
void print_resume(struct Resume resume);

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    struct Resume resume = parse_resume(filename);
    print_resume(resume);
    return 0;
}

struct Resume parse_resume(char *filename) {
    struct Resume resume = {"", "", "", "", 0};
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "name:", 5) == 0) {
            strncpy(resume.name, line+5, sizeof(resume.name)-1);
        } else if (strncmp(line, "email:", 6) == 0) {
            strncpy(resume.email, line+6, sizeof(resume.email)-1);
        } else if (strncmp(line, "experience:", 11) == 0) {
            strncpy(resume.experience, line+11, sizeof(resume.experience)-1);
        } else if (strncmp(line, "education:", 10) == 0) {
            strncpy(resume.education, line+10, sizeof(resume.education)-1);
        } else if (strncmp(line, "age:", 4) == 0) {
            resume.age = atoi(line+4);
        }
    }
    fclose(file);
    return resume;
}

void print_resume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
    printf("Age: %d\n", resume.age);
    printf("Amazing! Your resume has been parsed successfully. Now you can use this information to impress employers and land the job of your dreams! Happy job hunting!");
}