//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char experience[500];
};

void parseResume(struct Resume* r, char* resumeText) {
    char* token;
    token = strtok(resumeText, "\n");
    while (token != NULL) {
        if (strstr(token, "Name:") != NULL) {
            char* nameToken = strtok(token, ":");
            strcpy(r->name, strtok(NULL, ":"));
        } else if (strstr(token, "Email:") != NULL) {
            char* emailToken = strtok(token, ":");
            strcpy(r->email, strtok(NULL, ":"));
        } else if (strstr(token, "Experience:") != NULL) {
            char* experienceToken = strtok(token, ":");
            strcpy(r->experience, strtok(NULL, ":"));
        }
        token = strtok(NULL, "\n");
    }
}

int main() {
    char resumeText[] = "Name: John Smith\nEmail: john.smith@email.com\nExperience: Worked at ABC Company for 3 years\n";
    struct Resume r;
    parseResume(&r, resumeText);

    printf("Name: %s\nEmail: %s\nExperience: %s\n", r.name, r.email, r.experience);

    return 0;
}