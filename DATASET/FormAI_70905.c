//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[50];
    char email[50];
    char address[100];
    char skills[250];
    char experience[500];

    printf("Enter your name: ");
    fgets(name, 50, stdin);
    printf("Enter your email: ");
    fgets(email, 50, stdin);
    printf("Enter your address: ");
    fgets(address, 100, stdin);
    printf("Enter your skills: ");
    fgets(skills, 250, stdin);
    printf("Enter your work experience: ");
    fgets(experience, 500, stdin);

    // Find name
    char *ptr = strtok(name, " ");
    printf("First Name: %s\n", ptr);
    ptr = strtok(NULL, " ");
    printf("Last Name: %s\n", ptr);

    // Find email domain
    ptr = strtok(email, "@");
    ptr = strtok(NULL, "@");
    printf("Email Domain: %s\n", ptr);

    // Remove trailing newline from address
    address[strcspn(address, "\n")] = 0;
    printf("Address: %s\n", address);

    // Split skills by comma and print individually
    char *skill = strtok(skills, ",");
    while (skill != NULL) {
        printf("Skill: %s\n", skill);
        skill = strtok(NULL, ",");
    }

    // Split experience by dash and print individually
    char *line = strtok(experience, "-");
    while (line != NULL) {
        printf("Experience: %s\n", line);
        line = strtok(NULL, "-");
    }

    printf("Parsed Successfully!");
    return 0;
}