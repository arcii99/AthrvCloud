//FormAI DATASET v1.0 Category: Data validation ; Style: creative
#include<stdio.h>
#include<string.h>

int main()
{
    char name[20], email[50];
    int age;
    printf("Enter your name:\n");
    scanf("%s", name);
    if (strlen(name) < 3) //Checking if name length is less than 3
    {
        printf("Name should have at least 3 characters\n");
        return 0;
    }
    printf("Enter your email:\n");
    scanf("%s", email);
    if (strstr(email, "@") == NULL) //Checking if email has @ symbol
    {
        printf("Invalid email format\n");
        return 0;
    }
    printf("Enter your age:\n");
    scanf("%d", &age);
    if (age < 0 || age > 150) //Checking if age is within 0 and 150
    {
        printf("Age is out of range\n");
        return 0;
    }
    printf("Name: %s\nAge: %d\nEmail: %s\n", name, age, email);
    return 0;
}