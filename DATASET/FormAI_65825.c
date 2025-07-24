//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to check if a given string is a valid phone number */
int isPhoneNumber(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            count++;
            if (count == 10) {
                return 1;
            }
        }
    }
    return 0;
}

/* function to check if a given string is a valid email address */
int isEmail(char* str) {
    char* atSign = strchr(str, '@');
    if (!atSign || atSign == str) {
        return 0;
    }
    char* dot = strchr(atSign, '.');
    if (!dot || dot == atSign + 1) {
        return 0;
    }
    char* space = strchr(str, ' ');
    if (space) {
        return 0;
    }
    return 1;
}

/* function to parse the resume and extract information */
void parseResume(char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (!fp) {
        printf("Unable to open file %s\n", fileName);
        return;
    }

    char line[1000];
    char* delim = "\t\n ";

    char* name = NULL;
    char* phone = NULL;
    char* email = NULL;
    char skill1[50], skill2[50], skill3[50];

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            name = strtok(line, delim);
            name = strtok(NULL, delim);
        }
        else if (strstr(line, "Phone:")) {
            phone = strtok(line, delim);
            phone = strtok(NULL, delim);
            if (!isPhoneNumber(phone)) {
                printf("Invalid phone number: %s\n", phone);
                phone = NULL;
            }
        }
        else if (strstr(line, "Email:")) {
            email = strtok(line, delim);
            email = strtok(NULL, delim);
            if (!isEmail(email)) {
                printf("Invalid email address: %s\n", email);
                email = NULL;
            }
        }
        else if (strstr(line, "Skills:")) {
            char* skill = strtok(line, delim);
            skill = strtok(NULL, delim);
            if (skill) {
                strcpy(skill1, skill);
                skill = strtok(NULL, delim);
                if (skill) {
                    strcpy(skill2, skill);
                    skill = strtok(NULL, delim);
                    if (skill) {
                        strcpy(skill3, skill);
                    }
                }
            }
        }
    }

    fclose(fp);

    /* print the extracted information */
    printf("Name: %s\n", name ? name : "Not Found");
    printf("Phone: %s\n", phone ? phone : "Not Found");
    printf("Email: %s\n", email ? email : "Not Found");
    printf("Skills: %s%s%s\n", skill1, skill2[0] ? ", " : "", skill2);
    if (skill3[0]) {
        printf("%s%s%s\n", skill3, skill2[0] ? ", " : "", skill2);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please enter the filename as argument\n");
        return 1;
    }

    char* fileName = argv[1];

    parseResume(fileName);

    return 0;
}