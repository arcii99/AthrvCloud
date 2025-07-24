//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); //to set the seed for random function

    char password[17] = ""; //initialize an empty string to store the password
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-="; //define the characters that can be used in the password
    const int length = 16; //set the length of the password

    for(int i=0; i<length; i++) 
    {
        int index = rand() % 72; //generate a random number between 0 and 71 (72 is the length of the charset array)
        password[i] = charset[index]; //add a random character from the charset to the password
    }
    password[16] = '\0'; //add the null terminator at the end of the password string to terminate the string

    printf("Secure Password : %s\n", password); //print the generated password

    return 0;
}