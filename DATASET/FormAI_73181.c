//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// define the maximum length of the resume
#define MAX_RESUME_LENGTH 10000

// function to parse the resume and extract important information
void parse_resume(char resume[]) {
    // initialize the variables for important information
    char name[100];
    char email[100];
    char phone[20];
    char summary[200];
    char skills[500];

    // find and extract the name
    int i = 0;
    while (resume[i] != '\0') {
        if (resume[i] == '\n') {  // reached the end of the line
            break;
        } else {  // add the character to the name
            name[i] = resume[i];
        }
        i++;
    }
    name[i] = '\0';
    
    // find and extract the email
    i = 0;
    while (resume[i] != '\0') {
        if (resume[i] == '@') {  // found the '@' symbol
            int j = i;
            while (resume[j] != '\n') {  // find the end of the email
                j++;
            }
            strncpy(email, &resume[i], j-i);
            email[j-i] = '\0';
            break;
        }
        i++;
    }
    
    // find and extract the phone number
    i = 0;
    while (resume[i] != '\0') {
        if (resume[i] == '+' || resume[i] == '0' || resume[i] == '1' || resume[i] == '2' || resume[i] == '3' || resume[i] == '4' || resume[i] == '5' || resume[i] == '6' || resume[i] == '7' || resume[i] == '8' || resume[i] == '9') {
            int j = i;
            while (resume[j] != '\n' && resume[j] != ' ' && resume[j] != ',') {  // find the end of the phone number
                j++;
            }
            strncpy(phone, &resume[i], j-i);
            phone[j-i] = '\0';
            break;
        }
        i++;
    }
    
    // find and extract the summary
    i = 0;
    while (resume[i] != '\0') {
        if (resume[i] == '\n' && (strncmp(&resume[i+1], "Summary\n", 8) == 0 || strncmp(&resume[i+1], "SUMMARY\n", 8) == 0)) {  // found the summary section
            int j = i+9;
            int k = 0;
            while (resume[j] != '\n') {  // find the end of the summary
                summary[k] = resume[j];
                j++;
                k++;
            }
            summary[k] = '\0';
        }
        i++;
    }
    
    // find and extract the skills
    i = 0;
    while (resume[i] != '\0') {
        if (resume[i] == '\n' && (strncmp(&resume[i+1], "Skills\n", 7) == 0 || strncmp(&resume[i+1], "SKILLS\n", 7) == 0)) {  // found the skills section
            int j = i+8;
            int k = 0;
            while (resume[j] != '\n') {  // find the end of the skills
                skills[k] = resume[j];
                j++;
                k++;
            }
            skills[k] = '\0';
        }
        i++;
    }
    
    // print the extracted information
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Summary: %s\n", summary);
    printf("Skills: %s\n", skills);
}

int main() {
    char resume[MAX_RESUME_LENGTH];
    
    // read the resume from a file
    FILE *fp;
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open the resume file.\n");
        return 1;
    }
    fgets(resume, MAX_RESUME_LENGTH, fp);
    fclose(fp);
    
    // parse the resume and extract important information
    parse_resume(resume);
    
    return 0;
}