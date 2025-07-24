//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    int password_length;
    char password[30],possible_characters[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int i;

    printf("Enter the length of password you want: ");
    scanf("%d",&password_length);

    srand(time(NULL));
    for(i=0;i<password_length;i++){
        password[i]=possible_characters[rand()%strlen(possible_characters)];
    }
    password[i]='\0';

    printf("Your password is: %s",password);

    return 0;
}