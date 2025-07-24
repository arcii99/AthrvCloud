//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to hold resume information
struct Resume {
    char name[50];
    int age;
    char address[100];
    char email[50];
    char phone[15];
    char education[50];
    char experience[100];
};

// Function to parse a resume and return a Resume struct
struct Resume parseResume(char* filename) {
    // Open file
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Parse resume
    struct Resume resume;
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        // Get name
        if (strstr(line, "Name:") != NULL) {
            char* name = strchr(line, ':') + 2; // Add 2 to skip ": "
            strcpy(resume.name, name);
        }
        // Get age
        if (strstr(line, "Age:") != NULL) {
            char* age = strchr(line, ':') + 2;
            resume.age = atoi(age);
        }
        // Get address
        if (strstr(line, "Address:") != NULL) {
            char* address = strchr(line, ':') + 2;
            strcpy(resume.address, address);
        }
        // Get email
        if (strstr(line, "Email:") != NULL) {
            char* email = strchr(line, ':') + 2;
            strcpy(resume.email, email);
        }
        // Get phone
        if (strstr(line, "Phone:") != NULL) {
            char* phone = strchr(line, ':') + 2;
            strcpy(resume.phone, phone);
        }
        // Get education
        if (strstr(line, "Education:") != NULL) {
            char* education = strchr(line, ':') + 2;
            strcpy(resume.education, education);
        }
        // Get experience
        if (strstr(line, "Experience:") != NULL) {
            char* experience = strchr(line, ':') + 2;
            strcpy(resume.experience, experience);
        }
    }

    // Close file
    fclose(fp);

    // Return resume struct
    return resume;
}

// Function to print a Resume struct
void printResume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Address: %s\n", resume.address);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    // Parse resume
    struct Resume myResume = parseResume("my_resume.txt");

    // Print resume
    printResume(myResume);

    return 0;
}