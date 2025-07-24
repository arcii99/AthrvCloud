//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_STRING_LENGTH 256

typedef struct Resume {
    char name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
    char skills[MAX_STRING_LENGTH];
} Resume;

int main() {

    FILE *resume_file;
    Resume resume;
    char buffer[MAX_BUFFER_SIZE];
    char skill_buffer[MAX_STRING_LENGTH];
    int i, j, k, buffer_length, skill_buffer_length, found_skill;

    resume_file = fopen("resume.txt", "r");

    if(resume_file == NULL) {
        printf("Error: Could not open file.");
        exit(1);
    }

    while(fgets(buffer, MAX_BUFFER_SIZE, resume_file)) {

        buffer_length = strlen(buffer);

        // Parse name
        if(strncmp(buffer, "Name:", 5) == 0) {
            strncpy(resume.name, buffer+6, MAX_STRING_LENGTH);
        }

        // Parse email
        if(strncmp(buffer, "Email:", 6) == 0) {
            strncpy(resume.email, buffer+7, MAX_STRING_LENGTH);
        }

        // Parse phone number
        if(strncmp(buffer, "Phone:", 6) == 0) {
            strncpy(resume.phone, buffer+7, MAX_STRING_LENGTH);
        }

        // Parse skills
        if(strncmp(buffer, "Skills:", 7) == 0) {
            memset(resume.skills, 0, MAX_STRING_LENGTH);

            // Loop through each character in the line
            for(i=8; i<buffer_length; i++) {

                // If the character is a letter or a space
                if(isalpha(buffer[i]) || buffer[i] == ' ') {

                    // Add it to the skill buffer
                    skill_buffer[skill_buffer_length] = buffer[i];
                    skill_buffer_length++;

                // If the character is a comma or the end of the line
                } else if(buffer[i] == ',' || i == buffer_length-1) {

                    // Set the last character of the skill buffer to a null terminator
                    skill_buffer[skill_buffer_length] = '\0';

                    // Loop through the skills array to see if we've already added this skill
                    found_skill = 0;
                    for(j=0; j<MAX_STRING_LENGTH; j++) {
                        if(strcmp(resume.skills+j, skill_buffer) == 0) {
                            found_skill = 1;
                            break;
                        }
                        if(resume.skills[j] == '\0') {
                            break;
                        }
                    }

                    // If we haven't added this skill yet, add it to the skills array
                    if(!found_skill) {
                        strncpy(resume.skills+j, skill_buffer, MAX_STRING_LENGTH-j);
                    }

                    // Reset the skill buffer
                    memset(skill_buffer, 0, MAX_STRING_LENGTH);
                    skill_buffer_length = 0;
                }
            }
        }
    }

    // Print the resume contents
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Skills: %s\n", resume.skills);

    fclose(resume_file);

    return 0;
}