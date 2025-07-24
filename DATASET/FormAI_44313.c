//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to our unique C Resume Parsing System! Let's get started!\n\n");

    // Pretend we have a resume file
    FILE *resume;
    char *file_name = "resume.txt";
    int resume_lines = 0;

    // Let's open the file
    printf("Opening resume file...\n");
    resume = fopen(file_name, "r");

    // Check if we were able to open the file
    if (resume == NULL) {
        printf("Oh no! The file could not be opened. Check the file path.\n");
        return 0;
    } else {
        printf("File opened successfully!\n\n");
    }

    // Let's read the file line by line
    char line[500];
    while (fgets(line, sizeof(line), resume)) {
        printf("Parsing line: %s\n", line);
        resume_lines++;

        // Check if the line contains a keyword we're interested in
        if (strstr(line, "experience") || strstr(line, "work history")) {
            printf("Ah! We've found the experience section!\n");
            printf("Now let's extract the relevant information...\n\n");

            // Pretend we have a struct to store experience information
            struct Experience {
                char *company_name;
                char *position;
                int years_worked;
            } experience;

            // Let's extract company and position information
            fgets(line, sizeof(line), resume);
            experience.company_name = line;

            fgets(line, sizeof(line), resume);
            experience.position = line;

            printf("Experience:\n");
            printf("\t%s", experience.position);
            printf("\t\t%s\n\n", experience.company_name);

            // Let's extract years worked information
            fgets(line, sizeof(line), resume);
            fgets(line, sizeof(line), resume);
            sscanf(line, "%d", &experience.years_worked);

            printf("Years Worked: %d\n\n", experience.years_worked);
        }
    }

    printf("\nResume Parsing Complete! Parsed %d lines.\n", resume_lines);

    // Close the file
    fclose(resume);

    return 0;
}