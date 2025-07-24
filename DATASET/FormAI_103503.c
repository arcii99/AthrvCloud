//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include<stdio.h>
#include<string.h>

struct resume {
    char name[50];
    char email[50];
    char qualification[50];
    char skills[1000];
};

int main()
{
    struct resume r;
    char input[1000];
    int i, j = 0;

    printf("Enter your name: ");
    scanf("%[^\n]%*c", r.name);

    printf("Enter your email: ");
    scanf("%[^\n]%*c", r.email);

    printf("Enter your qualification: ");
    scanf("%[^\n]%*c", r.qualification);

    printf("Enter your skills: ");
    scanf("%[^\n]%*c", input);

    // Parsing skills
    for(i=0; input[i]!='\0'; i++) {
        if(input[i]==' ') {
            r.skills[j++] = ',';
            r.skills[j++] = ' ';
        } else {
            r.skills[j++] = input[i];
        }
    }
    
    printf("\n\n");
    printf("===============================================\n");
    printf("|                RESUME DETAILS                |\n");
    printf("===============================================\n");
    printf("| Name           : %-28s|\n", r.name);
    printf("| Email          : %-28s|\n", r.email);
    printf("| Qualification  : %-28s|\n", r.qualification);
    printf("| Skills         : %-28s|\n", r.skills);
    printf("===============================================\n");

    return 0;
}