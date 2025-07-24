//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_PHONE_NUM_LEN 13

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
} Applicant;

void parseResumeData(char* resume_data, Applicant* app) {
    char* token = strtok(resume_data, "\n");

    while(token != NULL) {
        if (strstr(token, "Name:")) {
            sscanf(token+strlen("Name:"), "%[^\n]", app->name);
        }
        else if (strstr(token, "Email:")) {
            sscanf(token+strlen("Email:"), "%[^\n]", app->email);
        }
        else if (strstr(token, "Phone:")) {
            sscanf(token+strlen("Phone:"), "%[^\n]", app->phone_num);
        }

        token = strtok(NULL, "\n");
    }
}

int main() {
    char resume_data[] = "Name: John Doe\nEmail: johndoe@email.com\nPhone: 123456789";
    Applicant app;

    parseResumeData(resume_data, &app);

    printf("Applicant Name: %s\n", app.name);
    printf("Applicant Email: %s\n", app.email);
    printf("Applicant Phone Number: %s\n", app.phone_num);

    return 0;
}