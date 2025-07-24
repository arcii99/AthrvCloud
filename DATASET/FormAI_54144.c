//FormAI DATASET v1.0 Category: Data validation ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>

int main()
{
    char fname[20], lname[20], age[3], gender[7], email[30], phone[15];
    char input;

    do
    {
        // Getting user input
        printf("Enter your First Name: ");
        fgets(fname, 20, stdin);

        printf("Enter your Last Name: ");
        fgets(lname, 20, stdin);

        printf("Enter your Age: ");
        fgets(age, 3, stdin);

        printf("Enter your Gender: ");
        fgets(gender, 7, stdin);

        printf("Enter your Email: ");
        fgets(email, 30, stdin);

        printf("Enter your Phone: ");
        fgets(phone, 15, stdin);

        // Validating user input
        int valid = 1;
        for(int i = 0; i < 20 && valid; i++)
        {
            if(!isalpha(fname[i]) && fname[i] != '\n' && fname[i] != '\r' && fname[i] != ' ')
            {
                valid = 0;
                printf("Invalid First Name!\n");
            }
            if(!isalpha(lname[i]) && lname[i] != '\n' && lname[i] != '\r' && lname[i] != ' ')
            {
                valid = 0;
                printf("Invalid Last Name!\n");
            }
        }
        if(!isdigit(age[0]))
        {
            valid = 0;
            printf("Invalid Age!\n");
        }
        if(gender[0] != 'm' && gender[0] != 'f' && gender[0] != 'M' && gender[0] != 'F')
        {
            valid = 0;
            printf("Invalid Gender!\n");
        }
        if(email[0] == '\n' || !isalpha(email[0]))
        {
            valid = 0;
            printf("Invalid Email!\n");
        }
        if(!isdigit(phone[0]))
        {
            valid = 0;
            printf("Invalid Phone Number!\n");
        }

        // Outputting user input or error message
        if(valid)
        {
            printf("\n\nYour details:\n");
            printf("Name: %s %s", fname, lname);
            printf("Age: %s", age);
            printf("Gender: %s", gender);
            printf("Email: %s", email);
            printf("Phone: %s\n", phone);
        }
        else
        {
            printf("\n\nInvalid input!\n\n");
        }

        // Asking user if they want to enter another set of values
        printf("Do you want to enter another set of values? (y/n)\n");
        input = getchar();
        while(input != '\n' && input != EOF) input = getchar();
    } while(input == 'y' || input == 'Y');

    return 0;
}