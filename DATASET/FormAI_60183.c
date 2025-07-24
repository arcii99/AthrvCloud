//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SKILLS_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Employee;

Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

// function to parse employee details from resume
void parseResume(char* resume) {
    // first, extract name from resume
    char* nameStart = strstr(resume, "Name:");
    if (nameStart) {
        nameStart += strlen("Name:");
        char* nameEnd = strchr(nameStart, '\n');
        if (nameEnd) {
            int nameLength = nameEnd - nameStart + 1;
            strncpy(employees[numEmployees].name, nameStart, nameLength);
            employees[numEmployees].name[nameLength - 1] = '\0';
        }
    }

    // next, extract email address from resume
    char* emailStart = strstr(resume, "Email:");
    if (emailStart) {
        emailStart += strlen("Email:");
        char* emailEnd = strchr(emailStart, '\n');
        if (emailEnd) {
            int emailLength = emailEnd - emailStart + 1;
            strncpy(employees[numEmployees].email, emailStart, emailLength);
            employees[numEmployees].email[emailLength - 1] = '\0';
        }
    }

    // finally, extract skills from resume
    char* skillsStart = strstr(resume, "Skills:");
    if (skillsStart) {
        skillsStart += strlen("Skills:");
        char* skillsEnd = strchr(skillsStart, '\n');
        if (skillsEnd) {
            int skillsLength = skillsEnd - skillsStart + 1;
            strncpy(employees[numEmployees].skills, skillsStart, skillsLength);
            employees[numEmployees].skills[skillsLength - 1] = '\0';
        }
    }

    numEmployees++; // increment numEmployees counter after parsing employee details
}

int main() {
    // example resumes to parse
    char resume1[] = "Name: John Doe\nEmail: john.doe@email.com\nSkills: C, Python, SQL";
    char resume2[] = "Name: Jane Smith\nEmail: jane.smith@email.com\nSkills: Java, C++, Python";

    // parse resumes and store data in employees array
    parseResume(resume1);
    parseResume(resume2);

    // print employee details
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d:\n", i+1);
        printf("Name: %s\n", employees[i].name);
        printf("Email: %s\n", employees[i].email);
        printf("Skills: %s\n", employees[i].skills);
        printf("\n");
    }

    return 0;
}