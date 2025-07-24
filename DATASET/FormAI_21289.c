//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char email[100];
    char skills[1000];
} Resume;

Resume* parseResume(char* text) {
    Resume* res = (Resume*) malloc(sizeof(Resume));
    char* field = strtok(text, "\n");
    while (field != NULL) {
        if (strstr(field, "Name: ")) {
            strcpy(res->name, field + 6);
        } else if (strstr(field, "Email: ")) {
            strcpy(res->email, field + 7);
        } else if (strstr(field, "Skills: ")) {
            strcpy(res->skills, field + 8);
        }
        field = strtok(NULL, "\n");
    }
    return res;
}

int main() {
    char text[1000] = "Name: John Doe\nEmail: john@doe.com\nSkills: C, Java, Python";
    Resume* res = parseResume(text);
    printf("Name: %s\nEmail: %s\nSkills: %s\n", res->name, res->email, res->skills);
    free(res);
    return 0;
}