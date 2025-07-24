//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(void){
    srand(time(NULL)); //initialize random value based on current time

    char charset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:<>?-=[]\;',./"; // Character set to generate password from
    
    int password_length=0; //Variable to store the length of password

    printf("Enter the length of password: ");
    scanf("%d",&password_length); //User input for length of password

    char password[password_length+1]; //password array with size equal to the length of password entered by user

    for(int i=0; i<password_length; i++){
        int random_index=rand()%strlen(charset); //generate random index value
        password[i]=charset[random_index]; //store random character in password array
    }
    password[password_length]='\0'; // add null character at the end of password string
   
    printf("\nYour secure password is: %s\n", password); //Output generated password
    
    return 0;
}