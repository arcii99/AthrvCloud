//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of resumes to be parsed
#define MAX_RESUMES 1000

// Define the maximum length of strings
#define MAX_STR_LENGTH 256

// Define the Resume structure
typedef struct {
    char name[MAX_STR_LENGTH];
    char email[MAX_STR_LENGTH];
    char skills[MAX_STR_LENGTH];
    int years_of_experience;
} Resume;

// Define the Resume database structure
typedef struct {
    Resume resumes[MAX_RESUMES];
    int num_resumes;
} ResumeDatabase;

// Function to parse a single resume and add it to the database
void parse_resume(char* resume_text, ResumeDatabase* db) {
    // Allocate memory for the new resume
    Resume* new_resume = (Resume*)malloc(sizeof(Resume));
    if (new_resume == NULL) {
        printf("Error: Could not allocate memory for new resume.\n");
        return;
    }

    // Parse the resume text and populate the new resume structure
    // ...

    // Add the new resume to the database
    if (db->num_resumes >= MAX_RESUMES) {
        printf("Error: Database is full.\n");
        free(new_resume);
        return;
    }
    memcpy(&(db->resumes[db->num_resumes]), new_resume, sizeof(Resume));
    db->num_resumes++;

    // Free the memory allocated for the new resume
    free(new_resume);
}

// Function to parse a batch of resumes and add them to the database
void parse_batch(char* batch_text, ResumeDatabase* db) {
    char* resume_text = strtok(batch_text, "\n");
    while (resume_text != NULL) {
        parse_resume(resume_text, db);
        resume_text = strtok(NULL, "\n");
    }
}

// Function to print the database
void print_database(ResumeDatabase* db) {
    for (int i = 0; i < db->num_resumes; i++) {
        printf("Name: %s\n", db->resumes[i].name);
        printf("Email: %s\n", db->resumes[i].email);
        printf("Skills: %s\n", db->resumes[i].skills);
        printf("Years of experience: %d\n", db->resumes[i].years_of_experience);
        printf("\n");
    }
}

int main() {
    // Initialize the database
    ResumeDatabase db;
    db.num_resumes = 0;

    // Parse a batch of resumes
    char batch_text[] = "John\njohn@example.com\nC++,Java\n3\nLisa\nlisa@example.com\nPython,Ruby\n5";
    parse_batch(batch_text, &db);

    // Print the database
    print_database(&db);

    return 0;
}