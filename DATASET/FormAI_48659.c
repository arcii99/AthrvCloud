//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing resume information
typedef struct {
    char name[50];
    int age;
    char email[50];
    char phone[20];
    char education[200];
    char skills[200];
} Resume;

// Function to parse resume and store information in the Resume structure
Resume parseResume(char content[]) {
    Resume resume;

    // Tokenize the content by newline and loop through each line
    char* line = strtok(content, "\n");
    while (line != NULL) {
        // Check for keywords and store relevant information
        if (strstr(line, "Name:")) {
            strcpy(resume.name, line + 5); // +5 to skip "Name: "
        }
        else if (strstr(line, "Age:")) {
            resume.age = atoi(line + 4); // +4 to skip "Age: "
        }
        else if (strstr(line, "Email:")) {
            strcpy(resume.email, line + 6); // +6 to skip "Email: "
        }
        else if (strstr(line, "Phone:")) {
            strcpy(resume.phone, line + 6); // +6 to skip "Phone: "
        }
        else if (strstr(line, "Education:")) {
            strcpy(resume.education, line + 10); // +10 to skip "Education: "
        }
        else if (strstr(line, "Skills:")) {
            strcpy(resume.skills, line + 7); // +7 to skip "Skills: "
        }

        // Move to the next line
        line = strtok(NULL, "\n");
    }

    return resume;
}

int main() {
    // Example content of a resume
    char content[] = "Name: John Doe\nAge: 25\nEmail: john.doe@email.com\nPhone: 555-1234\n"
                     "Education: Bachelor of Science in Computer Science\nSkills: C++, Java";

    // Parse the resume and store the information in a struct
    Resume resume = parseResume(content);

    // Print the information for verification
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    return 0;
}