//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_FIELDS 10

// A structure to hold information about each field in a resume
typedef struct Field {
    char name[BUFFER_SIZE];
    char value[BUFFER_SIZE];
} Field;

// A structure to hold information about a parsed resume
typedef struct Resume {
    Field fields[MAX_FIELDS];
    int num_fields;
} Resume;

// Function to split a string into an array of fields
void split_string(char* str, Field* fields, int* num_fields) {
    int i = 0;
    char* ptr = str;
    char* end = str;
    *num_fields = 0;

    // Loop through the string, splitting it into fields
    while (*end != '\0') {
        if (*end == ':') {
            // End the current field and start a new one
            *end = '\0';
            strcpy(fields[i].value, ptr);
            i++;
            ptr = end + 1;
        } else if (*end == '\n') {
            // End the current field and stop parsing
            *end = '\0';
            strcpy(fields[i].value, ptr);
            i++;
            break;
        }
        end++;
    }

    // Set the name of each field by capitalizing the first letter of each word
    for (int j = 0; j < i; j++) {
        char* name = fields[j].name;
        char* value = fields[j].value;
        int k = 0;
        while (*value != '\0') {
            if (k == 0 || *(value - 1) == ' ') {
                *name = toupper(*value);
                name++;
                k++;
            } else {
                *name = *value;
                name++;
            }
            value++;
        }
        *name = '\0';
    }

    *num_fields = i;
}

// Function to parse a resume from a file
Resume parse_resume(char* filename) {
    FILE* file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    Field fields[MAX_FIELDS];
    int num_fields = 0;

    // Read the contents of the file into a buffer
    fread(buffer, 1, BUFFER_SIZE, file);
    fclose(file);

    // Split the buffer into fields
    split_string(buffer, fields, &num_fields);

    // Create the resume object and set its fields
    Resume resume;
    resume.num_fields = num_fields;
    for (int i = 0; i < num_fields; i++) {
        strcpy(resume.fields[i].name, fields[i].name);
        strcpy(resume.fields[i].value, fields[i].value);
    }

    return resume;
}

// Function to print a resume
void print_resume(Resume resume) {
    for (int i = 0; i < resume.num_fields; i++) {
        printf("%s: %s\n", resume.fields[i].name, resume.fields[i].value);
    }
}

int main(int argc, char* argv[]) {
    Resume resume;

    // Check that a filename was provided
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Parse the resume and print it
    resume = parse_resume(argv[1]);
    print_resume(resume);

    return 0;
}