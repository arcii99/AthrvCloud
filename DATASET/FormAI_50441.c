//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

// Struct to define information in a resume
typedef struct {
    char name[50];
    char email[50];
    int experience;
    char skills[100];
} Resume;

// Function to parse the resume and print the information
void parseResume(Resume res) {
    printf("Name: %s\n", res.name);
    printf("Email: %s\n", res.email);
    printf("Experience: %d years\n", res.experience);
    printf("Skills: %s\n", res.skills);
}

int main() {
    // Create a dummy resume object
    Resume resume = {"John Doe", "johndoe@email.com", 5, "C++, Java, Python"};
    
    // Parse the resume
    parseResume(resume);

    return 0;
}