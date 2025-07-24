//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
    char name[50];
    int age;
    int id;
    char skills[100];
};

void parse_resume(struct employee *e, char *resume_text) {
    // Extract name
    char *name_start = strstr(resume_text, "Name:");
    name_start += 6; // skip over "Name: "
    char *name_end = strstr(name_start, "\n");
    *name_end = '\0'; // replace newline with null terminator
    strcpy(e->name, name_start);

    // Extract age
    char *age_start = strstr(resume_text, "Age:");
    age_start += 5; // skip over "Age: "
    e->age = atoi(age_start);

    // Extract ID
    char *id_start = strstr(resume_text, "ID:");
    id_start += 4; // skip over "ID: "
    e->id = atoi(id_start);

    // Extract skills
    char *skills_start = strstr(resume_text, "Skills:");
    skills_start += 8; // skip over "Skills: "
    char *skills_end = strstr(skills_start, "\n");
    *skills_end = '\0'; // replace newline with null terminator
    strcpy(e->skills, skills_start);
}

int main() {
    char resume[] = "Name: John Smith\nAge: 30\nID: 12345\nSkills: Java, C++, Python\n";
    struct employee john;
    parse_resume(&john, resume);

    printf("Name: %s\n", john.name);
    printf("Age: %d\n", john.age);
    printf("ID: %d\n", john.id);
    printf("Skills: %s\n", john.skills);

    return 0;
}