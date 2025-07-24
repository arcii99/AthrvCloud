//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define structure to hold resume information */
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[500];
} Resume;

/* Function to parse resume and fill Resume structure */
void parseResume(char* text, Resume* res) {
    char* token;

    /* Parse name */
    token = strtok(text, "\n");
    strcpy(res->name, token);

    /* Parse email */
    token = strtok(NULL, "\n");
    strcpy(res->email, token);

    /* Parse phone */
    token = strtok(NULL, "\n");
    strcpy(res->phone, token);

    /* Parse skills */
    token = strtok(NULL, "\n");
    strcpy(res->skills, token);
}

int main() {
    char text[] = "John Doe\njohndoe@email.com\n123-456-7890\nC++, Java, Python";
    Resume res;

    /* Parse resume and fill structure */
    parseResume(text, &res);

    /* Print out resume information */
    printf("Name: %s\n", res.name);
    printf("Email: %s\n", res.email);
    printf("Phone: %s\n", res.phone);
    printf("Skills: %s\n", res.skills);

    return 0;
}