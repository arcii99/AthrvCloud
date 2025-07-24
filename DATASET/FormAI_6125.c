//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>

struct Resume {
    char name[50];
    char email[50];
    char phone_num[15];
    char city[30];
    char skills[100];
};

int main() {
    struct Resume r1;
    
    printf("Enter name: ");
    scanf("%s", r1.name);
    printf("Enter email: ");
    scanf("%s", r1.email);
    printf("Enter phone number: ");
    scanf("%s", r1.phone_num);
    printf("Enter city: ");
    scanf("%s", r1.city);
    printf("Enter skills: ");
    getchar();
    fgets(r1.skills, sizeof(r1.skills), stdin);

    printf("\n\nName: %s\n", r1.name);
    printf("Email: %s\n", r1.email);
    printf("Phone number: %s\n", r1.phone_num);
    printf("City: %s\n", r1.city);
    printf("Skills:\n%s", r1.skills);

    return 0;
}