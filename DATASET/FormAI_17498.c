//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining the structure for the resume
struct Resume {
    char name[30];
    char email[50];
    char phone[15];
    char address[100];
    char skills[100];
    char experience[200];
    char education[100];
    int age;
};

int main() {
    // declaring variables for parsing
    int i = 0, j = 0, k = 0, age = 18;
    char resume[300];
    char token[30];
    char delimiter[3] = ", ";
    struct Resume userResume;

    // taking input the resume in the form of a string
    printf("Enter the resume: ");
    fgets(resume, 300, stdin);

    // parsing the fields of the resume
    while(resume[i] != '\0') {
        if(resume[i] != delimiter[0] && resume[i] != delimiter[1]) {
            token[j++] = resume[i];
        }
        else {
            token[j] = '\0';
            switch(k) {
                case 0:
                    strcpy(userResume.name, token);
                    break;
                case 1:
                    strcpy(userResume.email, token);
                    break;
                case 2:
                    strcpy(userResume.phone, token);
                    break;
                case 3:
                    strcpy(userResume.address, token);
                    break;
                case 4:
                    strcpy(userResume.skills, token);
                    break;
                case 5:
                    strcpy(userResume.experience, token);
                    break;
                case 6:
                    strcpy(userResume.education, token);
                    break;
            }
            j = 0;
            k++;
        }
        i++;
    }

    // adding age to the resume
    userResume.age = age;

    // printing the parsed resume
    printf("\nName: %s\n", userResume.name);
    printf("Email: %s\n", userResume.email);
    printf("Phone: %s\n", userResume.phone);
    printf("Address: %s\n", userResume.address);
    printf("Skills: %s\n", userResume.skills);
    printf("Experience: %s\n", userResume.experience);
    printf("Education: %s\n", userResume.education);
    printf("Age: %d\n", userResume.age);

    return 0;
}