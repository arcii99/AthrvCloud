//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Resume Parsing
typedef struct {
    char* name;
    char* email;
    char* phone;
    char* education;
    char* experience;
} Resume;

// Define function to read Resume file
Resume readFile(char* fileName) {
    Resume resume;
    FILE* fp;
    char line[256]; // buffer for reading lines from file
    
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Loop through file and parse data
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            char* start = strchr(line, ':') + 1;
            char* end = strchr(start, '\n');
            resume.name = (char*)malloc(end - start + 1); // allocate memory for name
            strncpy(resume.name, start, end - start);
            resume.name[end - start] = '\0'; // add null-terminator
        }
        if (strstr(line, "Email:")) {
            char* start = strchr(line, ':') + 1;
            char* end = strchr(start, '\n');
            resume.email = (char*)malloc(end - start + 1); // allocate memory for email
            strncpy(resume.email, start, end - start);
            resume.email[end - start] = '\0'; // add null-terminator
        }
        if (strstr(line, "Phone:")) {
            char* start = strchr(line, ':') + 1;
            char* end = strchr(start, '\n');
            resume.phone = (char*)malloc(end - start + 1); // allocate memory for phone
            strncpy(resume.phone, start, end - start);
            resume.phone[end - start] = '\0'; // add null-terminator
        }
        if (strstr(line, "Education:")) {
            char* start = strchr(line, ':') + 1;
            char* end = strchr(start, '\n');
            resume.education = (char*)malloc(end - start + 1); // allocate memory for education
            strncpy(resume.education, start, end - start);
            resume.education[end - start] = '\0'; // add null-terminator
        }
        if (strstr(line, "Experience:")) {
            char* start = strchr(line, ':') + 1;
            char* end = strchr(start, '\n');
            resume.experience = (char*)malloc(end - start + 1); // allocate memory for experience
            strncpy(resume.experience, start, end - start);
            resume.experience[end - start] = '\0'; // add null-terminator
        }
    }
    
    fclose(fp);
    
    return resume;
}

// Define main method
int main() {
    Resume resume;
    char* fileName = "resume.txt";
    
    resume = readFile(fileName); // call readFile function to parse resume
    
    // Print out parsed data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    
    // Free up memory used by struct fields
    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.education);
    free(resume.experience);
    
    return 0;
}