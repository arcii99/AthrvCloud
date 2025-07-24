//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char skills[200];
};

int main() {
    struct Resume applicant;
    printf("Enter your name: ");
    fgets(applicant.name, 50, stdin);
    printf("Enter your email: ");
    fgets(applicant.email, 50, stdin);
    printf("Enter your phone number: ");
    fgets(applicant.phone, 15, stdin);
    printf("Enter your education: ");
    fgets(applicant.education, 100, stdin);
    printf("Enter your skills: ");
    fgets(applicant.skills, 200, stdin);
    
    char* keyword = "survivor";
    int count = 0;
    
    // Count the number of times the keyword appears in the applicant's education and skills.
    char* ptr = strstr(applicant.education, keyword);
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr+1, keyword);
    }
    
    ptr = strstr(applicant.skills, keyword);
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr+1, keyword);
    }
    
    // Determine the severity of the apocalypse based on the number of times the keyword appears.
    if(count >= 4)
        printf("Congratulations, you are a rare survivor in this post-apocalyptic world!\n");
    else if(count >= 2)
        printf("You've definitely got some survival skills, but you'll need to stay alert.\n");
    else
        printf("You may want to brush up on your survival knowledge.\n");
    
    return 0;
}