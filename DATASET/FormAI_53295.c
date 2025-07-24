//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
// Welcome to the most advanced C Resume Parsing System
// Get excited for a hassle-free and efficient resume analysis!
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Let's analyze some resumes!\n");
    printf("Enter the name of the resume file to analyze:\n");
    char resume_file[50];
    scanf("%s", resume_file);

    printf("Opening the resume file...\n");
    FILE *file = fopen(resume_file, "r");

    if (file == NULL) {
        printf("Error opening file. Please make sure the file name is correct and try again.\n");
        return 1;
    }

    char buffer[100];
    char name[50];
    char email[50];
    char phone_number[20];

    printf("Analyzing the file...\n");

    while (fgets(buffer, 100, file)) {
        if (strstr(buffer, "Name: ")) {
            sscanf(buffer, "Name: %[^\n]", name);
        } else if (strstr(buffer, "Email: ")) {
            sscanf(buffer, "Email: %[^\n]", email);
        } else if (strstr(buffer, "Phone Number: ")) {
            sscanf(buffer, "Phone Number: %[^\n]", phone_number);
        }
    }

    fclose(file);

    printf("Resume analysis complete!\n");
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone Number: %s\n", phone_number);

    return 0;
}