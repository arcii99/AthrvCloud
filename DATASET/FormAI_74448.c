//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store resume information
struct Resume {
    char name[50];
    char email[50];
    char phoneNumber[15];
    char education[50];
    char experience[100];
};

// Function to read resume data from file
void readResumeData(char *fileName, struct Resume *resume) {
    FILE *fp;
    char line[100];
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    // Read each line from file and store in struct
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(resume->name, line+6);
        }
        else if (strncmp(line, "Email:", 6) == 0) {
            strcpy(resume->email, line+7);
        }
        else if (strncmp(line, "Phone Number:", 13) == 0) {
            strcpy(resume->phoneNumber, line+14);
        }
        else if (strncmp(line, "Education:", 10) == 0) {
            strcpy(resume->education, line+11);
        }
        else if (strncmp(line, "Experience:", 11) == 0) {
            strcpy(resume->experience, line+12);
        }
    }
    fclose(fp);
}

// Function to print resume data
void printResumeData(struct Resume *resume) {
    printf("Name: %s", resume->name);
    printf("Email: %s", resume->email);
    printf("Phone Number: %s", resume->phoneNumber);
    printf("Education: %s", resume->education);
    printf("Experience: %s", resume->experience);
}

// Main function
int main() {
    struct Resume resume;
    readResumeData("resume.txt", &resume);
    printResumeData(&resume);
    return 0;
}