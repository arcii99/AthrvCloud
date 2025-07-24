//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define constants for maximum length of input and output strings*/

#define MAX_INPUT_LEN 500
#define MAX_OUTPUT_LEN 1000

/* Define the resume data structure */

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* work_experience;
    char* education;
    char* skills;
} Resume;

/* Define a helper function that extracts data from a resume file */

void extract_resume_details(char* filename, Resume* resume) {

    /* Open the file for reading */

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {

        printf("Error: Could not open file %s!\n", filename);
        exit(1);
    }

    /* Allocate memory for data fields in the resume */

    resume->name = malloc(100 * sizeof(char));
    resume->email = malloc(100 * sizeof(char));
    resume->phone = malloc(20 * sizeof(char));
    resume->address = malloc(200 * sizeof(char));
    resume->work_experience = malloc(500 * sizeof(char));
    resume->education = malloc(200 * sizeof(char));
    resume->skills = malloc(200 * sizeof(char));

    /* Extract data from the file */

    char line[MAX_INPUT_LEN];
    int field = -1;

    while (fgets(line, MAX_INPUT_LEN, fp)) {

        /* Remove newline character */

        line[strcspn(line, "\n")] = 0;

        /* Check for field identifiers */

        if (strstr(line, "Name:") != NULL) {

            field = 0;
        }
        else if (strstr(line, "Email:") != NULL) {

            field = 1;
        }
        else if (strstr(line, "Phone:") != NULL) {

            field = 2;
        }
        else if (strstr(line, "Address:") != NULL) {

            field = 3;
        }
        else if (strstr(line, "Work Experience:") != NULL) {

            field = 4;
        }
        else if (strstr(line, "Education:") != NULL) {

            field = 5;
        }
        else if (strstr(line, "Skills:") != NULL) {

            field = 6;
        }
        else {

            /* Add data to the appropriate field */

            switch (field) {

                case 0:
                    strcpy(resume->name, line);
                    break;
                case 1:
                    strcpy(resume->email, line);
                    break;
                case 2:
                    strcpy(resume->phone, line);
                    break;
                case 3:
                    strcpy(resume->address, line);
                    break;
                case 4:
                    strcat(resume->work_experience, line);
                    strcat(resume->work_experience, "\n");
                    break;
                case 5:
                    strcat(resume->education, line);
                    strcat(resume->education, "\n");
                    break;
                case 6:
                    strcat(resume->skills, line);
                    strcat(resume->skills, "\n");
                    break;
                default:
                    break;
            }
        }
    }

    /* Close the file */

    fclose(fp);
}

/* Define a helper function that formats resume data for output */

void format_resume_details(Resume* resume, char* output) {

    /* Create output string */

    sprintf(output, "Name: %s\nEmail: %s\nPhone: %s\nAddress: %s\nWork Experience:\n%s\nEducation:\n%s\nSkills:\n%s\n", 
           resume->name, resume->email, resume->phone, resume->address, resume->work_experience, resume->education, resume->skills);
}

/* Define the main function */

int main() {

    /* Initialize resume data structure */

    Resume resume;
    memset(&resume, 0, sizeof(Resume));

    /* Extract resume details from file */

    extract_resume_details("resume.txt", &resume);

    /* Format details for output */

    char output[MAX_OUTPUT_LEN];
    format_resume_details(&resume, output);

    /* Print output */

    printf("%s", output);

    /* Free memory */

    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.address);
    free(resume.work_experience);
    free(resume.education);
    free(resume.skills);

    return 0;

}