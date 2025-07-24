//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char skills[100];
    char experience[200];
} Resume;

int main() {
    FILE *file;
    Resume resume;

    file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    memset(&resume, 0, sizeof(Resume));
    fscanf(file, "%[^@]@%s\n%[^\n]\n%[^\n]\n", resume.name, resume.email, resume.skills, resume.experience);

    fclose(file);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);

    return 0;
}