//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include<stdio.h>
#include<string.h>

struct resume{
    char name[100];
    char email[100];
    char phone[20];
    char skills[1000];
    char education[500];
};

int main(){
    struct resume r;
    printf("Enter your name: ");
    scanf("%[^\n]%*c", r.name);
    printf("Enter your email ID: ");
    scanf("%s", r.email);
    printf("Enter your phone number: ");
    scanf("%s", r.phone);
    printf("Enter your skills (separated by comma): ");
    scanf("%s", r.skills);
    printf("Enter your education: ");
    scanf("%s", r.education);
    printf("\n");
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);
    printf("Education: %s\n", r.education);

    char *token;
    printf("\nSkills:\n");
    token = strtok(r.skills, ",");
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}