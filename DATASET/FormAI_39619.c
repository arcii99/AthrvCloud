//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the structure for holding resume information
struct Resume {
    char *name;
    int age;
    char *address;
    char *email;
    char *degree;
    char *university;
    char *skills;
};

// Define the function for parsing the resume
void parse_resume(struct Resume *resume, char *resume_str) {
    // Split the resume string into individual lines
    char *line = strtok(resume_str, "\n");
    while (line != NULL) {
        // Split each line into key-value pairs
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        // Remove any leading or trailing whitespace from the value
        int i = 0;
        while (value[i] == ' ') {
            i++;
        }
        value += i;
        i = strlen(value) - 1;
        while (i >= 0 && value[i] == ' ') {
            value[i] = '\0';
            i--;
        }

        // Save the key-value pairs to the resume
        if (strcmp(key, "Name") == 0) {
            resume->name = (char*) malloc(strlen(value) + 1);
            strcpy(resume->name, value);
        } else if (strcmp(key, "Age") == 0) {
            resume->age = atoi(value);
        } else if (strcmp(key, "Address") == 0) {
            resume->address = (char*) malloc(strlen(value) + 1);
            strcpy(resume->address, value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = (char*) malloc(strlen(value) + 1);
            strcpy(resume->email, value);
        } else if (strcmp(key, "Degree") == 0) {
            resume->degree = (char*) malloc(strlen(value) + 1);
            strcpy(resume->degree, value);
        } else if (strcmp(key, "University") == 0) {
            resume->university = (char*) malloc(strlen(value) + 1);
            strcpy(resume->university, value);
        } else if (strcmp(key, "Skills") == 0) {
            resume->skills = (char*) malloc(strlen(value) + 1);
            strcpy(resume->skills, value);
        }

        // Move on to the next line
        line = strtok(NULL, "\n");
    }
}

int main() {
    // Define the example resume string
    char resume_str[] = "Name: John Doe\nAge: 25\nAddress: 123 Main St\nEmail: john.doe@email.com\nDegree: Bachelor of Science\nUniversity: University of Example\nSkills: C++, Java, Python";

    // Parse the resume string into a resume struct
    struct Resume resume;
    parse_resume(&resume, resume_str);

    // Print out the parsed resume information
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Address: %s\n", resume.address);
    printf("Email: %s\n", resume.email);
    printf("Degree: %s\n", resume.degree);
    printf("University: %s\n", resume.university);
    printf("Skills: %s\n", resume.skills);

    // Free the memory allocated for the resume strings
    free(resume.name);
    free(resume.address);
    free(resume.email);
    free(resume.degree);
    free(resume.university);
    free(resume.skills);
    
    return 0;
}