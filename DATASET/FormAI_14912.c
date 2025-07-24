//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a resume structure to hold all the necessary information
struct Resume {
    char name[50];
    char email[50];
    char phone_num[20];
    char address[100];
    char education[200];
    char skills[500];
    char exp[1000];
};

// Function to parse the resume and store the information in the resume structure
void parse_resume(char *filename, struct Resume *r) {
    // Open the resume file
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the file line by line and store the information in the resume structure
    char buff[200];
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        if (strstr(buff, "Name:")) {
            sscanf(buff, "Name: %s", r->name);
        }
        else if (strstr(buff, "Email:")) {
            sscanf(buff, "Email: %s", r->email);
        }
        else if (strstr(buff, "Phone:")) {
            sscanf(buff, "Phone: %s", r->phone_num);
        }
        else if (strstr(buff, "Address:")) {
            sscanf(buff, "Address: %[^\n]", r->address);
        }
        else if (strstr(buff, "Education:")) {
            sscanf(buff, "Education: %[^\n]", r->education);
        }
        else if (strstr(buff, "Skills:")) {
            sscanf(buff, "Skills: %[^\n]", r->skills);
        }
        else if (strstr(buff, "Experience:")) {
            sscanf(buff, "Experience: %[^\n]", r->exp);
        }
    }

    // Close the resume file
    fclose(fp);
}

// Main function to test the resume parser
int main() {
    struct Resume my_resume;
    memset(&my_resume, 0, sizeof(my_resume));

    // Parse the resume and store the information in the resume structure
    parse_resume("my_resume.txt", &my_resume);

    // Display the information stored in the resume structure
    printf("Name: %s\n", my_resume.name);
    printf("Email: %s\n", my_resume.email);
    printf("Phone Number: %s\n", my_resume.phone_num);
    printf("Address: %s\n", my_resume.address);
    printf("Education: %s\n", my_resume.education);
    printf("Skills: %s\n", my_resume.skills);
    printf("Experience: %s\n", my_resume.exp);

    return 0;
}