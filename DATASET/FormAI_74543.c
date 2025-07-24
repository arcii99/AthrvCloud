//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void){
    srand(time(0));
    char password[16];
    int length = 0;
    int upper = 0, lower = 0, digit = 0, special = 0;

    //Ask user for desired length of password
    do{
        printf("Enter desired length of password (8-16): ");
        scanf("%d", &length);
    } while (length < 8 || length > 16);

    //Generate random password with desired length
    for (int i = 0; i < length; i++){
        int random = rand() % 4;
        if (random == 0 && upper < 2){
            password[i] = rand() % 26 + 65; //Generate random uppercase letter
            upper++;
        } else if (random == 1 && lower < 2){
            password[i] = rand() % 26 + 97; //Generate random lowercase letter
            lower++;
        } else if (random == 2 && digit < 2){
            password[i] = rand() % 10 + 48; //Generate random digit
            digit++;
        } else if (special < 2){
            int specialChar = rand() % 15;
            password[i] = specialChar + 33; //Generate random special character
            special++;
        } else {
            i--; //If cannot generate desired character, loop again
        }
    }
    password[length] = '\0'; //Null terminate string

    //Print password
    printf("Generated password: %s\n", password);

    return 0;
}