//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <string.h>

// Structure for storing the parsed information
struct resume {
    char name[50];
    char email[50];
    int experience;
    char skills[200];
};

// Function to parse the resume and store the information in the structure
void parseResume(char* resumeText, struct resume* res) {
    char* token;

    // Parsing name
    token = strtok(resumeText, "\n");
    strcpy(res->name, token);

    // Parsing email
    token = strtok(NULL, "\n");
    strcpy(res->email, token);

    // Parsing experience
    token = strtok(NULL, "\n");
    res->experience = atoi(token);

    // Parsing skills
    token = strtok(NULL, "\n");
    strcpy(res->skills, token);
}

int main() {
    // Example text for parsing
    char resumeText[] = "John Smith\njohnsmith@gmail.com\n5\nC++, Java, Python, SQL";

    // Creating structure for storing parsed information
    struct resume res;

    // Parsing the resume text
    parseResume(resumeText, &res);

    // Printing the parsed information
    printf("Name: %s\n", res.name);
    printf("Email: %s\n", res.email);
    printf("Experience: %d years\n", res.experience);
    printf("Skills: %s\n", res.skills);

    return 0;
}