//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char *generate_password(int length);

int main()
{
    int length;
    printf("Enter the length of the password you need: ");
    scanf("%d", &length);
    char *password = generate_password(length);
    printf("Your secure password is: %s \n", password);
    free(password); //free memory allocation
    return 0;
}

char *generate_password(int length)
{
    srand(time(0)); //set random seed value for generating random characters
    char *password = malloc(length+1); //allocate memory for password
    
    for(int i = 0; i < length; i++)
    {
        int random_num = rand()%3;
        switch(random_num)
        {
            case 0:
                password[i] = rand()%10 + '0'; //random number between 0-9
                break;
            case 1:
                password[i] = rand()%26 + 'A'; //random uppercase letter
                break;
            case 2:
                password[i] = rand()%26 + 'a'; //random lowercase letter
                break;
            default:
                password[i] = rand()%26 + 'a'; // default lowercase letter
        }
    }
    password[length] = '\0'; //end password with null character
    return password;
}