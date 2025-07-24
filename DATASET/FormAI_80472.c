//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Candidate {
    char name[50];
    char education[50];
    int experience;
    char skills[100];
};

void parseResume(char *filename, struct Candidate *candidate);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: resumeParser [filename]");
        return 0;
    }

    struct Candidate candidate;

    parseResume(argv[1], &candidate);

    printf("Name: %s\n", candidate.name);
    printf("Education: %s\n", candidate.education);
    printf("Experience: %d years\n", candidate.experience);
    printf("Skills: %s\n", candidate.skills);

    return 0;
}

void parseResume(char *filename, struct Candidate *candidate) {
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    char line[100];
    int count = 0;
    int section = 0;

    while (fgets(line, sizeof(line), f)) {
        if (strcmp(line, "Experience\n") == 0) {
            section = 1;
            continue;
        } else if (strcmp(line, "Skills\n") == 0) {
            section = 2;
            continue;
        }

        switch (section) {
            case 0:
                if (count == 0) {
                    strcpy(candidate->name, line);
                } else {
                    strcpy(candidate->education, line);
                }

                count++;
                break;
            case 1:
                candidate->experience = atoi(line);
                break;
            case 2:
                strcat(candidate->skills, line);
                break;
        }
    }

    fclose(f);
}