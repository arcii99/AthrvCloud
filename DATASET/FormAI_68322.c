//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char name[50]; 
    char email[50]; 
    char phone[20]; 
    char education[100];
    char skills[200]; 
} Resume;

int main() {
    Resume r; 
    char resume_text[1000]; 
    printf("Please input your resume:\n"); 
    fgets(resume_text, 1000, stdin); 

    // Parse name
    char *print_ptr = resume_text; 
    char *name_ptr = r.name; 
    int length = 0; 
    while (*print_ptr != '\0' && *print_ptr != '\n') {
        *name_ptr = *print_ptr; 
        name_ptr++; 
        print_ptr++; 
        length++; 
        if (*print_ptr == '\t') { 
            print_ptr++; 
            break;
        }
    }
    *name_ptr = '\0'; 

    // Parse email
    char *email_ptr = r.email;
    while (*print_ptr != '\0' && *print_ptr != '\n') {
        *email_ptr = *print_ptr;
        email_ptr++;
        print_ptr++;
        if (*print_ptr == '\t') {
            print_ptr++;
            break;
        }
    }
    *email_ptr = '\0';

    // Parse phone number
    char *phone_ptr = r.phone;
    while (*print_ptr != '\0' && *print_ptr != '\n') {
        *phone_ptr = *print_ptr;
        phone_ptr++;
        print_ptr++;
        if (*print_ptr == '\t') {
            print_ptr++;
            break;
        }
    }
    *phone_ptr = '\0';

    //Parse education
    char *education_ptr = r.education;
    while (*print_ptr != '\0' && *print_ptr != '\n') {
        *education_ptr = *print_ptr;
        education_ptr++;
        print_ptr++;
        if (*print_ptr == '\t') {
            print_ptr++;
            break;
        }
    }
    *education_ptr = '\0';

    // Parse skills
    char *skills_ptr = r.skills;
    while (*print_ptr != '\0' && *print_ptr != '\n') {
        *skills_ptr = *print_ptr;
        skills_ptr++;
        print_ptr++;
        if (*print_ptr == '\t') {
            print_ptr++;
            break;
        }
    }
    *skills_ptr = '\0';

    //Print Results
    printf("NAME: %s\n", r.name);
    printf("EMAIL: %s\n", r.email);
    printf("PHONE: %s\n", r.phone);
    printf("EDUCATION: %s\n", r.education);
    printf("SKILLS: %s\n", r.skills);

    return 0;
}