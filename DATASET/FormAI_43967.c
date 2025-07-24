//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[500];
} Resume;

// Function to parse the resume and extract relevant information
void parse_resume(char* filename, Resume* resume) {
    FILE* file = fopen(filename, "r"); // open the resume file
    if (file == NULL) { // if file does not exist or cannot be opened
        printf("Error: file '%s' not found.\n", filename);
        exit(1); // exit with error code 1
    }

    char line[200]; // buffer to store each line of the resume

    while (fgets(line, sizeof(line), file)) { // read each line of the resume
        // Extract name
        if (strstr(line, "Name:")) {
            char* name_ptr = strstr(line, "Name:") + strlen("Name:");
            strcpy(resume->name, name_ptr);
        }
        // Extract email
        if (strstr(line, "Email:")) {
            char* email_ptr = strstr(line, "Email:") + strlen("Email:");
            strcpy(resume->email, email_ptr);
        }
        // Extract phone number
        if (strstr(line, "Phone:")) {
            char* phone_ptr = strstr(line, "Phone:") + strlen("Phone:");
            strcpy(resume->phone, phone_ptr);
        }
        // Extract education
        if (strstr(line, "Education:")) {
            char* education_ptr = strstr(line, "Education:") + strlen("Education:");
            strcpy(resume->education, education_ptr);
        }
        // Extract work experience
        if (strstr(line, "Experience:")) {
            char* experience_ptr = strstr(line, "Experience:") + strlen("Experience:");
            strcpy(resume->experience, experience_ptr);
        }
    }

    fclose(file); // close the resume file
}

// Function to print the parsed resume information
void print_resume(Resume resume) {
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);
}

int main() {
    Resume my_resume;

    parse_resume("resume.txt", &my_resume);

    print_resume(my_resume);

    return 0;
}