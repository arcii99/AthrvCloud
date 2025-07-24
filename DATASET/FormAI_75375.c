//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume{
    char name[50];
    char email[50];
    char phone[20];
    char education[200];
    char skills[1000];
};

int main(){
    struct Resume resume;
    char *keywords[] = {"C", "C++", "Java", "Python", "JavaScript", "PHP", "Ruby", "Swift", "HTML", "CSS", ".NET" };
    
    printf("Enter your name: ");
    scanf("%[^\n]%*c", resume.name);
    
    printf("Enter your email: ");
    scanf("%s", resume.email);
    
    printf("Enter your phone number: ");
    scanf("%s", resume.phone);
    
    printf("Enter your educational background: ");
    scanf("%[^\n]%*c", resume.education);
    
    printf("Enter your skills: ");
    scanf("%[^\n]%*c", resume.skills);
    
    printf("\n\n--------------RESUME--------------\n\n");
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);
    printf("\n");
    
    printf("Matching keywords: ");
    for(int i=0; i<11; i++){
        if(strstr(resume.skills, keywords[i]) != NULL){
            printf("%s, ", keywords[i]);
        }
    }
    
    printf("\n\nThank you for using our Resume Parsing System!");
    return 0;
}