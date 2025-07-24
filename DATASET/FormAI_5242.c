//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[50];
    char skills[100];
    char experience[100];
} Resume;

void parseResume(char* input, Resume* output) {
    char buffer[1000];
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;

    while (input[i] != '\n') {
        output->name[j++] = input[i++];
    }
    output->name[j] = '\0';

    i += 7; // skip "E-mail:"

    while (input[i] != '\n') {
        output->email[k++] = input[i++];
    }
    output->email[k] = '\0';

    i += 8; // skip "Phone: +"

    while (input[i] != '\n') {
        output->phone[l++] = input[i++];
    }
    output->phone[l] = '\0';

    i += 12; // skip "Education: "

    while (input[i] != '\n') {
        output->education[m++] = input[i++];
    }
    output->education[m] = '\0';

    i += 9; // skip "Skills: "

    while (input[i] != '\n') {
        output->skills[n++] = input[i++];
    }
    output->skills[n] = '\0';

    i += 13; // skip "Experience: "

    while (input[i] != '\0') {
        buffer[k++] = input[i++];
    }
    buffer[k] = '\0';

    char* token = strtok(buffer, "\n");

    while (token != NULL) {
        strcat(output->experience, token);
        strcat(output->experience, "\n");
        token = strtok(NULL, "\n");
    }
}

int main() {
    Resume r;
    char input[1000] = "John Doe\nE-mail: john.doe@gmail.com\nPhone: +1234567890\nEducation: Bachelor of Science\nSkills: C, Python, Java\nExperience: Worked as Software Developer for 3 years\nWorked as Project Manager for 1 year\n";

    parseResume(input, &r);

    printf("Name: %s\n", r.name);
    printf("E-mail: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);

    return 0;
}