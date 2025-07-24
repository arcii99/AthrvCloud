//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct to store resume information
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[200];
};

// function to parse the resume and store the information in the struct
void parseResume(char *resumeString, struct Resume *resume) {

    // split the resume string by new line character
    char *split;
    split = strtok(resumeString, "\n");

    // keep track of which field we are currently parsing
    int field = 1;

    // iterate through each line of the resume and store the information
    while (split != NULL) {

        // parse the name field
        if (field == 1) {
            strcpy(resume->name, split);
        }

        // parse the email field
        else if (field == 2) {
            strcpy(resume->email, split);
        }

        // parse the phone field
        else if (field == 3) {
            strcpy(resume->phone, split);
        }

        // parse the education field
        else if (field == 4) {
            strcpy(resume->education, split);
        }

        // parse the experience field
        else if (field == 5) {
            strcpy(resume->experience, split);
        }

        // move to the next field
        field++;

        // get the next line of the resume
        split = strtok(NULL, "\n");
    }
}

// function to print the resume information
void printResume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// main function
int main() {

    // an example resume string
    char resumeString[] = "John Smith\njohn.smith@email.com\n555-555-5555\nBachelor of Science in Computer Science\nSoftware Developer at XYZ Corp";

    // create a new resume struct
    struct Resume myResume;

    // parse the resume information into the struct
    parseResume(resumeString, &myResume);

    // print out the resume information
    printf("Parsed Resume:\n");
    printResume(&myResume);

    return 0;
}