//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining struct for each parsed element
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
} Resume;

// Parsing function to extract information from text file
void parseResume(char filename[], Resume* res) {
    FILE* fptr;
    fptr = fopen(filename, "r"); // Opening file in read mode

    // Checking if file exists or not
    if (fptr == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fptr)) { // Looping through each line
        char delimiters[] = ",\n"; // Separating at commas and new lines
        char* token;
        token = strtok(line, delimiters);

        while (token != NULL) { // Looping through each token
            if (strstr(token, "@") != NULL) { // Checking if token contains email
                strcpy(res->email, token);
            } else if (isdigit(token[0])) { // Checking if token starts with a digit (phone number)
                strcpy(res->phone, token);
            } else if (strlen(token) >= 5) { // Checking if token has length >= 5 (skill)
                strcat(res->skills, token);
                strcat(res->skills, " ");
            } else { // Assuming token as name
                strcat(res->name, token);
                strcat(res->name, " ");
            }

            token = strtok(NULL, delimiters);
        }
    }

    fclose(fptr);
}

int main() {
    Resume r;
    strcpy(r.name, "");
    strcpy(r.email, "");
    strcpy(r.phone, "");
    strcpy(r.skills, "");

    parseResume("resume.txt", &r); // Parsing resume from file

    // Printing parsed information
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);

    return 0;
}