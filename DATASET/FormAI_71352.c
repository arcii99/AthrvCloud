//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    char email[50];
    char phone[15];
    char skills[100];
} Candidate;

int main() {
    Candidate c;
    char resume[500];
    
    printf("Please paste your resume:\n");
    fgets(resume, 500, stdin);
    
    // Parse name
    int i = 0;
    while (resume[i] != '\n') {
        if (resume[i] == ' ') {
            strncpy(c.name, resume, i);
            c.name[i] = '\0';
            break;
        }
        i++;
    }
    
    // Parse email
    i = 0;
    while (resume[i] != '\n') {
        if (resume[i] == '@') {
            int j = i;
            while (resume[j] != '\n') {
                if (resume[j] == ' ') {
                    strncpy(c.email, resume + i, j - i);
                    c.email[j - i] = '\0';
                    break;
                }
                j++;
            }
            break;
        }
        i++;
    }
    
    // Parse phone number
    i = 0;
    while (resume[i] != '\n')  {
        if (isdigit(resume[i])) {
            int j = i;
            while (isdigit(resume[j])) {
                if (j == i + 9) {
                    strncpy(c.phone, resume + i, 10);
                    c.phone[10] = '\0';
                    break;
                }
                j++;
            }
            break;
        }
        i++;
    }
    
    // Parse skills
    i = 0;
    while (resume[i] != '\n') {
        if (resume[i] == 'S' && strncmp(resume + i, "Skills", 6) == 0) {
            int j = i + 7;
            while (resume[j] != '\n') {
                if (resume[j] == ',') {
                    strncat(c.skills, ", ", 2);
                    j++;
                } else if (resume[j] != ' ') {
                    strncat(c.skills, resume + j, 1);
                    j++;
                } else {
                    j++;
                }
            }
            break;
        }
        i++;
    }
    
    // Print results
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
    printf("Phone: %s\n", c.phone);
    printf("Skills: %s\n", c.skills);
    
    return 0;
}