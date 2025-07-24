//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char education[50];
    char experience[200];
    char skills[200];
};

int main() {
    FILE *inputFile;
    FILE *outputFile;
    char line[MAX_LINE_LENGTH];
    struct Resume applicant;
    
    // Open input file
    inputFile = fopen("resume.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    // Parse resume data
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %s", applicant.name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %s", applicant.email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %s", applicant.phone);
        } else if (strstr(line, "Education:")) {
            sscanf(line, "Education: %[^\n]", applicant.education);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", applicant.experience);
        } else if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %[^\n]", applicant.skills);
        }
    }
    
    // Close input file
    fclose(inputFile);
    
    // Open output file
    outputFile = fopen("parsedresume.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    
    // Write parsed resume data to output file
    fprintf(outputFile, "Name: %s\n", applicant.name);
    fprintf(outputFile, "Email: %s\n", applicant.email);
    fprintf(outputFile, "Phone: %s\n", applicant.phone);
    fprintf(outputFile, "Education: %s\n", applicant.education);
    fprintf(outputFile, "Experience: %s\n", applicant.experience);
    fprintf(outputFile, "Skills: %s\n", applicant.skills);
    
    // Close output file
    fclose(outputFile);
    
    return 0;
}