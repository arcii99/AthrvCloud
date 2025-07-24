//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LINES 1000
#define MAX_NUM_TITLES 10
#define MAX_NUM_EXPERIENCES 20

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char education[100];
    char work_experience[MAX_NUM_EXPERIENCES][100];
    int num_experiences;
} Resume;

typedef struct {
    char title[100];
    char company[100];
    char location[100];
    char start_date[20];
    char end_date[20];
    char description[256];
} Experience;

int is_email(char *str) {
    char *at_pos = strchr(str, '@');
    if (at_pos == NULL) return 0;
    if (strchr(at_pos+1, '.') == NULL) return 0;
    return 1;
}

int is_phone(char *str) {
    int i, num_digits = 0;
    for (i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) num_digits++;
    }
    if (num_digits == 10 || num_digits == 11) return 1;
    return 0;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *lines[MAX_NUM_LINES];
    int num_lines = 0;

    Resume resume;
    memset(&resume, 0, sizeof(resume));
    Experience experiences[MAX_NUM_EXPERIENCES];
    memset(&experiences, 0, sizeof(experiences));
    int num_experiences = 0;

    // read text file into array of lines
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        lines[num_lines] = strdup(line);
        num_lines++;
    }
    fclose(fp);

    // extract information from each line
    int i, j, k;
    for (i = 0; i < num_lines; i++) {
        char *line = lines[i];

        if (is_email(line)) {
            strcpy(resume.email, line);
        } else if (is_phone(line)) {
            strcpy(resume.phone, line);
        } else if (strstr(line, "EDUCATION") != NULL) {
            i++;
            if (i >= num_lines) break;
            strcpy(resume.education, lines[i]);
        } else if (strstr(line, "EXPERIENCE") != NULL) {
            i++;
            if (i >= num_lines) break;
            char *experience_lines[MAX_NUM_LINES];
            int num_experience_lines = 0;
            while (i < num_lines && strlen(lines[i]) > 1 && lines[i][0] != '*') {
                experience_lines[num_experience_lines] = strdup(lines[i]);
                num_experience_lines++;
                i++;
            }
            if (num_experience_lines == 0) continue;
            Experience exp;
            memset(&exp, 0, sizeof(exp));
            strcpy(exp.title, experience_lines[0]);
            for (j = 1; j < num_experience_lines; j++) {
                char *line = experience_lines[j];
                if (strstr(line, "COMPANY") != NULL) {
                    k = strlen("COMPANY: ");
                    strcpy(exp.company, line+k);
                } else if (strstr(line, "LOCATION") != NULL) {
                    k = strlen("LOCATION: ");
                    strcpy(exp.location, line+k);
                } else if (strstr(line, "START DATE") != NULL) {
                    k = strlen("START DATE: ");
                    strcpy(exp.start_date, line+k);
                } else if (strstr(line, "END DATE") != NULL) {
                    k = strlen("END DATE: ");
                    strcpy(exp.end_date, line+k);
                } else if (strstr(line, "DESCRIPTION") != NULL) {
                    k = strlen("DESCRIPTION: ");
                    strcpy(exp.description, line+k);
                }
            }
            experiences[num_experiences] = exp;
            num_experiences++;
        } else {
            // assume that anything else is the candidate's name
            if (resume.name[0] == '\0') {
                strcpy(resume.name, line);
                // remove any trailing whitespace
                for (j = strlen(resume.name)-1; j >= 0; j--) {
                    if (isspace(resume.name[j])) resume.name[j] = '\0';
                    else break;
                }
            }
        }
    }

    // print out the extracted information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Work Experience:\n");
    for (i = 0; i < num_experiences; i++) {
        printf("%s\n", experiences[i].title);
        printf("  Company: %s\n", experiences[i].company);
        printf("  Location: %s\n", experiences[i].location);
        printf("  Start Date: %s\n", experiences[i].start_date);
        printf("  End Date: %s\n", experiences[i].end_date);
        printf("  Description: %s\n", experiences[i].description);
    }

    // free dynamically allocated memory
    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    for (i = 0; i < num_experiences; i++) {
        for (j = 0; j < MAX_NUM_LINES; j++) {
            free(experiences[i].description[j]);
        }
    }

    return 0;
}