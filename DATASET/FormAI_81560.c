//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

struct applicant {
    char name[50];
    int age;
    char email[50];
    char skills[100];
};

void parse_resume(struct applicant* new_applicant, char* filename) {
    FILE* file = fopen(filename, "r");
    char buffer[500];
    char* token;

    // read name
    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "Name: %s", new_applicant->name);

    // read age
    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "Age: %d", &(new_applicant->age));

    // read email
    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "Email: %s", new_applicant->email);

    // read skills
    fgets(buffer, sizeof(buffer), file);
    token = strtok(buffer, ":");
    token = strtok(NULL, "\n");
    strcpy(new_applicant->skills, token);

    fclose(file);
}

int main(int argc, char** argv) {
    struct applicant new_applicant;
    char* filename = argv[1];

    parse_resume(&new_applicant, filename);

    printf("Name: %s\n", new_applicant.name);
    printf("Age: %d\n", new_applicant.age);
    printf("Email: %s\n", new_applicant.email);
    printf("Skills: %s\n", new_applicant.skills);

    return 0;
}