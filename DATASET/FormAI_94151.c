//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 100

bool is_file_infected(char* file_name);
void quarantine_file(char* file_name);

int main(int argc, char** argv) {
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    if(is_file_infected(file_name)) {
        printf("File infected!\n");
        quarantine_file(file_name);
    } else {
        printf("File is safe.\n");
    }

    return 0;
}

// mock function to check if file is infected
// always returns true for demonstration purposes
bool is_file_infected(char* file_name) {
    printf("Scanning %s for viruses...\n", file_name);
    return true;
}

// function to quarantine infected files
void quarantine_file(char* file_name) {
    printf("Quarantining %s...\n", file_name);
    // code to move infected file to quarantine folder goes here
}