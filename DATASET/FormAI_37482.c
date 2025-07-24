//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char *name;
    char *email;
    char *address;
    char *phone;
    char *skills[10];
    char *experience[10];
    int exp_count;
};

struct Resume resume;

void parse_resume(char *filename) {
    FILE *fptr;
    char line[100];
    int i = 0;
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }
    
    while (fgets(line, sizeof(line), fptr)) {
        // Parse name
        if (i == 0) {
            resume.name = strdup(line);
        }
        // Parse email
        else if (strstr(line, "@")) {
            resume.email = strdup(line);
        }
        // Parse address
        else if (strstr(line, "Address:")) {
            char *temp = strstr(line, ":");
            resume.address = strdup(temp + 2);
        }
        // Parse phone
        else if (strstr(line, "Phone:")) {
            char *temp = strstr(line, ":");
            resume.phone = strdup(temp + 2);
        }
        // Parse skills
        else if (strstr(line, "Skills:")) {
            char *temp = strstr(line, ":");
            char *token = strtok(temp + 2, ", ");
            while (token != NULL) {
                resume.skills[i] = strdup(token);
                token = strtok(NULL, ", ");
                i++;
            }
        }
        // Parse experience
        else if (strstr(line, "Experience:")) {
            char *temp = strstr(line, ":");
            resume.exp_count = i;
            i = 0;
            char *token = strtok(temp + 2, ", ");
            while (token != NULL) {
                resume.experience[i] = strdup(token);
                token = strtok(NULL, ", ");
                i++;
            }
        }
    }
    
    fclose(fptr);
}

void print_resume() {
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Address: %s", resume.address);
    printf("Phone: %s", resume.phone);
    printf("Skills:\n");
    for (int i = 0; i < resume.exp_count; i++) {
        printf("- %s\n", resume.skills[i]);
    }
    printf("Experience:\n");
    for (int i = 0; i < resume.exp_count; i++) {
        printf("- %s\n", resume.experience[i]);
    }
}

int main() {
    parse_resume("resume.txt");
    print_resume();
    return 0;
}