//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures to store resume data
typedef struct Education {
    char degree[50];
    char institution[50];
    int graduation_year;
    struct Education* next;
} Education;

typedef struct Experience {
    char company[50];
    char position[50];
    int start_year;
    int end_year;
    struct Experience* next;
} Experience;

typedef struct Resume {
    char name[50];
    char email[50];
    Education* education;
    Experience* experience;
} Resume;

// Function to parse education data from a line of text
void parse_education(char* line, Education* education) {
    sscanf(line, "%[^,],%[^,],%d\n", education->degree, education->institution, &(education->graduation_year));
}

// Function to parse experience data from a line of text
void parse_experience(char* line, Experience* experience) {
    sscanf(line, "%[^,],%[^,],%d,%d\n", experience->company, experience->position, &(experience->start_year), &(experience->end_year));
}

// Function to add education data to a resume
void add_education(Resume* resume, char* line) {
    Education* education = (Education*) malloc(sizeof(Education));
    parse_education(line, education);
    education->next = resume->education;
    resume->education = education;
}

// Function to add experience data to a resume
void add_experience(Resume* resume, char* line) {
    Experience* experience = (Experience*) malloc(sizeof(Experience));
    parse_experience(line, experience);
    experience->next = resume->experience;
    resume->experience = experience;
}

// Function to parse a resume file and populate a Resume structure
void parse_resume(Resume* resume, char* file_name) {
    FILE* file = fopen(file_name, "r");

    if (file != NULL) {
        char line[100];
        while (fgets(line, 100, file) != NULL) {
            if (strstr(line, "NAME:")) {
                sscanf(line, "NAME:%[^\n]\n", resume->name);
            } else if (strstr(line, "EMAIL:")) {
                sscanf(line, "EMAIL:%[^\n]\n", resume->email);
            } else if (strstr(line, "EDUCATION:")) {
                add_education(resume, line + strlen("EDUCATION:"));
            } else if (strstr(line, "EXPERIENCE:")) {
                add_experience(resume, line + strlen("EXPERIENCE:"));
            }
        }
        fclose(file);
    } else {
        printf("Error opening file %s\n", file_name);
    }
}

// Function to print out a resume
void print_resume(Resume* resume) {
    printf("NAME: %s\n", resume->name);
    printf("EMAIL: %s\n\n", resume->email);

    printf("EDUCATION:\n");
    Education* education = resume->education;
    while (education != NULL) {
        printf("%s, %s, %d\n", education->degree, education->institution, education->graduation_year);
        education = education->next;
    }

    printf("\nEXPERIENCE:\n");
    Experience* experience = resume->experience;
    while (experience != NULL) {
        printf("%s, %s, %d-%d\n", experience->company, experience->position, experience->start_year, experience->end_year);
        experience = experience->next;
    }
}

// Main function to test the program
int main() {
    Resume resume;
    memset(&resume, 0, sizeof(Resume));
    parse_resume(&resume, "resume.txt");
    print_resume(&resume);
    return 0;
}