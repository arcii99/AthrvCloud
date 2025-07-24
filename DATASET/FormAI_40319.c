//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h> 

int main() {
    FILE *fp;
    char name[50], email[50], phone[20], address[100];
    int age;

    fp = fopen("contact.txt", "a+"); // open text file in append mode

    if (fp == NULL) {
        printf("Error in opening file");
        exit(1);
    }

    // Take input from user
    printf("Enter your name: ");
    fgets(name, 50, stdin);

    printf("Enter your email: ");
    fgets(email, 50, stdin);

    printf("Enter your phone number: ");
    fgets(phone, 20, stdin);

    printf("Enter your address: ");
    fgets(address, 100, stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    // Write contact details to file
    fprintf(fp, "Name: %sEmail: %sPhone: %sAddress: %sAge: %d\n", name, email, phone, address, age);

    // Close file
    fclose(fp);

    printf("Contact details saved to file.");

    return 0;
}