//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char skillset1[20];
    char skillset2[20];
    char skillset3[20];
    char education[30];
    char experience[100];
};

int main() {
    struct resume employee;
    char input[500];
    char *token;

    printf("Enter employee details in the following format:\n{Name},{Email},{Skillset 1},{Skillset 2},{Skillset 3},{Education},{Experience}\n");
    fgets(input, 500, stdin);

    token = strtok(input, ",");
    strcpy(employee.name, token);

    token = strtok(NULL, ",");
    strcpy(employee.email, token);

    token = strtok(NULL, ",");
    strcpy(employee.skillset1, token);

    token = strtok(NULL, ",");
    strcpy(employee.skillset2, token);

    token = strtok(NULL, ",");
    strcpy(employee.skillset3, token);

    token = strtok(NULL, ",");
    strcpy(employee.education, token);

    token = strtok(NULL, ",");
    strcpy(employee.experience, token);

    printf("\nEmployee details: \n");
    printf("Name: %s\n", employee.name);
    printf("Email: %s\n", employee.email);
    printf("Skillset 1: %s\n", employee.skillset1);
    printf("Skillset 2: %s\n", employee.skillset2);
    printf("Skillset 3: %s\n", employee.skillset3);
    printf("Education: %s\n", employee.education);
    printf("Experience: %s\n", employee.experience);

    return 0;
}