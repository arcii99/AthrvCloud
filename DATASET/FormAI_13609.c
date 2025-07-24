//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include<stdio.h>
#include<string.h>

struct resume {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char skills[100];
    char education[100];
    char experience[100];
} applicant; // Defining struct object

int main() {

    printf("Enter applicant name: ");
    fgets(applicant.name, 50, stdin); // Reading applicant name

    printf("Enter applicant email: ");
    fgets(applicant.email, 50, stdin); // Reading applicant email

    printf("Enter applicant phone: ");
    fgets(applicant.phone, 15, stdin); // Reading applicant phone

    printf("Enter applicant address: ");
    fgets(applicant.address, 100, stdin); // Reading applicant address

    printf("Enter applicant skills: ");
    fgets(applicant.skills, 100, stdin); // Reading applicant skills

    printf("Enter applicant education: ");
    fgets(applicant.education, 100, stdin); // Reading applicant education

    printf("Enter applicant experience: ");
    fgets(applicant.experience, 100, stdin); // Reading applicant experience

    // Removing trailing new-line characters from inputs
    applicant.name[strcspn(applicant.name, "\n")] = 0;
    applicant.email[strcspn(applicant.email, "\n")] = 0;
    applicant.phone[strcspn(applicant.phone, "\n")] = 0;
    applicant.address[strcspn(applicant.address, "\n")] = 0;
    applicant.skills[strcspn(applicant.skills, "\n")] = 0;
    applicant.education[strcspn(applicant.education, "\n")] = 0;
    applicant.experience[strcspn(applicant.experience, "\n")] = 0;

    // Printing out the resume fields
    printf("\n\nBelow is the parsed resume:\n");
    printf("Name:           %s\n", applicant.name);
    printf("Email:          %s\n", applicant.email);
    printf("Phone:          %s\n", applicant.phone);
    printf("Address:        %s\n", applicant.address);
    printf("Skills:         %s\n", applicant.skills);
    printf("Education:      %s\n", applicant.education);
    printf("Experience:     %s\n", applicant.experience);

    return 0;
}