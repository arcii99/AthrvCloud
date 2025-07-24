//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct applicant {
        char name[30];
        int age;
        char phone[12];
        char email[50];
        char address[100];
        char education[100];
    };
    
    struct applicant applicant1;
    
    // Input section
    printf("Enter your name: ");
    fgets(applicant1.name, 30, stdin);

    printf("Enter your age: ");
    scanf("%d", &applicant1.age);
    getchar();  //To clear the input buffer

    printf("Enter your phone number: ");
    fgets(applicant1.phone, 12, stdin);

    printf("Enter your email: ");
    fgets(applicant1.email, 50, stdin);

    printf("Enter your address: ");
    fgets(applicant1.address, 100, stdin);

    printf("Enter your education: ");
    fgets(applicant1.education, 100, stdin);

    // Output section
    printf("\n======== Resume ========");
    printf("\nName: %s", applicant1.name);
    printf("Age: %d\n", applicant1.age);
    printf("Phone: %s", applicant1.phone);
    printf("Email: %s", applicant1.email);
    printf("Address: %s", applicant1.address);
    printf("Education: %s\n", applicant1.education);

    return 0;
}