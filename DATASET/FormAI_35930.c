//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>

int main()
{
    FILE *fp;
    char name[50], email[50], address[100], phone[20];
    int age;
    
    //Opening the file for writing in append mode
    fp = fopen("personal_info.txt", "a");
    
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    //Taking input from user
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your address: ");
    scanf(" %[^\n]", address);
    printf("Enter your phone number: ");
    scanf("%s", phone);
    printf("Enter your age: ");
    scanf("%d", &age);

    //Writing data to the file
    fprintf(fp, "Name: %s\nEmail: %s\nAddress: %s\nPhone: %s\nAge: %d\n", name, email, address, phone, age);

    //Closing the file
    fclose(fp);

    printf("Data successfully written to file.\n");

    return 0;
}