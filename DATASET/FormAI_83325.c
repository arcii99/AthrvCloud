//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    int length, i, j, random_index;
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    char password[20];
    srand(time(NULL));

    printf("Enter the length of the password you want to generate (up to 20 characters): ");
    scanf("%d", &length);

    if(length <=0 || length > 20)
    {
        printf("Invalid length. Please enter a length up to 20 characters.\n");
        return 0;
    }

    for(i=0; i<length; i++)
    {
        random_index = rand() % strlen(characters);
        password[i] = characters[random_index];
    }

    password[length] = '\0';

    printf("Your generated password is: \n%s",password);
    return 0;
}