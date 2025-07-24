//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

/* Struct used for storing the resume information */
typedef struct Resume{
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phoneNumber[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Resume;

/* Function that parses the resume information and stores it in a Resume struct */
void parseResume(char* fileName, Resume* resume){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }

    /* Read each line of the file and parse the information */
    char line[MAX_LENGTH];
    while(fgets(line, sizeof(line), file)){
        if(strncmp(line, "Name", 4) == 0){
            strncpy(resume->name, line + 5, MAX_LENGTH);
        }
        else if(strncmp(line, "Email", 5) == 0){
            strncpy(resume->email, line + 6, MAX_LENGTH);
        }
        else if(strncmp(line, "Phone", 5) == 0){
            strncpy(resume->phoneNumber, line + 6, MAX_LENGTH);
        }
        else if(strncmp(line, "Education", 9) == 0){
            strncpy(resume->education, line + 10, MAX_LENGTH);
        }
        else if(strncmp(line, "Experience", 10) == 0){
            strncpy(resume->experience, line + 11, MAX_LENGTH);
        }
        else{
            continue;
        }
    }
    fclose(file);
}

/* Function that prints the information stored in the Resume struct */
void printResume(Resume resume){
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phoneNumber);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);
}

/* Main function that calls the parseResume and printResume functions */
int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s <resume file>\n", argv[0]);
        exit(1);
    }
    Resume resume;
    parseResume(argv[1], &resume);
    printResume(resume);
    return 0;
}