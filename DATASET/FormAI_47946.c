//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_RESUMES 20
#define MAX_LINE_LENGTH 100
#define MAX_FIELD_LENGTH 50

// Define a struct to store the parsed resume data
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
} Resume;

// Define a global array to store resumes
Resume resumes[MAX_RESUMES];

// Define a global variable to keep track of the number of resumes parsed
int num_resumes = 0;

// Define a function to parse a resume from a file
void *parse_resume(void *arg) {
    // Get the filename to parse
    char *filename = (char *) arg;

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume data
    Resume *resume = malloc(sizeof(Resume));
    resume->name = malloc(MAX_FIELD_LENGTH);
    resume->email = malloc(MAX_FIELD_LENGTH);
    resume->phone = malloc(MAX_FIELD_LENGTH);
    resume->address = malloc(MAX_FIELD_LENGTH);
    resume->skills = malloc(MAX_FIELD_LENGTH);

    // Read each line of the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Parse the line based on the field name
        char *field_name = strtok(line, ":");
        char *field_value = strtok(NULL, "");

        // Trim whitespace from the field value
        char *trimmed_value = field_value;
        while (*trimmed_value == ' ' || *trimmed_value == '\t' || *trimmed_value == '\n') {
            trimmed_value++;
        }
        char *end_trimmed_value = trimmed_value + strlen(trimmed_value) - 1;
        while (*end_trimmed_value == ' ' || *end_trimmed_value == '\t' || *end_trimmed_value == '\n') {
            end_trimmed_value--;
        }
        *(end_trimmed_value + 1) = '\0';

        // Store the field value in the appropriate resume field
        if (strcmp(field_name, "Name") == 0) {
            strcpy(resume->name, trimmed_value);
        } else if (strcmp(field_name, "Email") == 0) {
            strcpy(resume->email, trimmed_value);
        } else if (strcmp(field_name, "Phone") == 0) {
            strcpy(resume->phone, trimmed_value);
        } else if (strcmp(field_name, "Address") == 0) {
            strcpy(resume->address, trimmed_value);
        } else if (strcmp(field_name, "Skills") == 0) {
            strcpy(resume->skills, trimmed_value);
        }
    }

    // Close the file
    fclose(file);

    // Add the parsed resume data to the global array
    int index;
    for (index = 0; index < MAX_RESUMES; index++) {
        if (resumes[index].name == NULL) {
            resumes[index] = *resume;
            num_resumes++;
            printf("Parsed resume %s\n", filename);
            break;
        }
    }

    // Free the allocated memory
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume);

    return NULL;
}

int main(int argc, char *argv[]) {
    // Get the filenames to parse from the command line arguments
    int num_files = argc - 1;
    char **filenames = argv + 1;

    // Create a thread for each resume to parse
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    int file_index;
    for (file_index = 0; file_index < num_files; file_index++) {
        if (num_threads >= MAX_THREADS) {
            // Wait for all threads to finish before creating more
            int thread_index;
            for (thread_index = 0; thread_index < MAX_THREADS; thread_index++) {
                pthread_join(threads[thread_index], NULL);
            }
            num_threads = 0;
        }
        char *filename = filenames[file_index];
        pthread_create(&threads[num_threads], NULL, parse_resume, (void *) filename);
        num_threads++;
    }

    // Wait for all threads to finish
    int thread_index;
    for (thread_index = 0; thread_index < num_threads; thread_index++) {
        pthread_join(threads[thread_index], NULL);
    }

    // Print the parsed resume data
    int resume_index;
    for (resume_index = 0; resume_index < num_resumes; resume_index++) {
        Resume resume = resumes[resume_index];
        printf("Resume %d:\nName: %s\nEmail: %s\nPhone: %s\nAddress: %s\nSkills: %s\n", 
            resume_index + 1, resume.name, resume.email, resume.phone, resume.address, resume.skills);
    }

    return 0;
}