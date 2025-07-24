//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct resume { 
    char name[50]; 
    char email[50]; 
    char phone[20]; 
    char address[100]; 
    char summary[500]; 
    char skills[500]; 
    char education[500]; 
    char experience[500]; 
}; 

void parse_resume(char file_name[]) {
    struct resume r; 
    FILE* fp = fopen(file_name, "r"); 
    if (fp == NULL) { 
        printf("Cannot open the file\n"); 
        return; 
    } 
    char buffer[500]; 

    while (fgets(buffer, 500, fp) != NULL) { 
        if (strstr(buffer, "Name:")) { 
            sscanf(buffer+5, "%s", r.name); 
        } else if(strstr(buffer, "Email:")) { 
            sscanf(buffer+6, "%s", r.email); 
        } else if(strstr(buffer, "Phone:")) { 
            sscanf(buffer+6, "%s", r.phone); 
        } else if(strstr(buffer, "Address:")) { 
            sscanf(buffer+8, "%s", r.address); 
        } else if(strstr(buffer, "Summary:")) { 
            fgets(r.summary, 500, fp); 
        } else if(strstr(buffer, "Skills:")) { 
            fgets(r.skills, 500, fp); 
        } else if(strstr(buffer, "Education:")) { 
            fgets(r.education, 500, fp); 
        } else if(strstr(buffer, "Experience:")) { 
            fgets(r.experience, 500, fp); 
        } 
    } 

    fclose(fp);

    printf("\nResume Parsed Successfully\n");
    printf("=========================\n");
    printf("Name: %s\n", r.name); 
    printf("Email: %s\n", r.email); 
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address); 
    printf("Summary: %s\n", r.summary); 
    printf("Skills: %s\n", r.skills); 
    printf("Education: %s\n", r.education); 
    printf("Experience: %s\n", r.experience); 
} 

int main() { 
    char file_name[50];
    printf("Enter the name of the Resume file (with extension): ");
    fgets(file_name, 50, stdin); 
    file_name[strcspn(file_name, "\n")] = 0;
    parse_resume(file_name); 

    return 0; 
}