//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MIN_LENGTH 8 //minimum length of password
#define MAX_LENGTH 20 //maximum length of password
#define MAX_TRIES 5 //maximum number of attempts to generate password
#define SPECIAL_CHAR "!@#$%^&*" //special characters for password
#define ALPHABETS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" //alphabets for password
#define DIGITS "0123456789" //digits for password
#define SPECIAL_LEN 8 //length of special characters for password
#define ALPHABETS_LEN 52 //length of alphabets for password
#define DIGITS_LEN 10 //length of digits for password

int generateRandom(int min, int max){
    static int flag = 0;
    if(flag == 0) {
        srand(time(NULL));
        flag = 1;
    }
    return (rand() % (max - min + 1)) + min;
}

int checkForCharacters(char c, char *str, int len){
    int i;
    for(i = 0; i < len; i++){
        if(str[i] == c) return 1;
    }
    return 0;
}

void addRandomCharacter(char *password, int len){
    char character;
    int index;
    while(1){
        index = generateRandom(0, len-1);
        character = generateRandom(33,126);
        if(checkForCharacters(character, SPECIAL_CHAR, SPECIAL_LEN) || checkForCharacters(character, ALPHABETS, ALPHABETS_LEN) || checkForCharacters(character, DIGITS, DIGITS_LEN)){
            password[index] = character;
            break;
        }
    }
}

int main(){
    int passwordLength, tries, i;
    char password[MAX_LENGTH+1];

    printf("Welcome to Paranoid Password Generator\n");
    printf("Password must be between %d and %d characters long\n", MIN_LENGTH, MAX_LENGTH);

    for(tries = 0; tries < MAX_TRIES; tries++){

        passwordLength = generateRandom(MIN_LENGTH, MAX_LENGTH);

        for(i = 0; i < passwordLength; i++){
            password[i] = generateRandom(33, 126);
            if(i == 0){
                while(!checkForCharacters(password[i], ALPHABETS, ALPHABETS_LEN)) password[i] = generateRandom(33,126);
            }
            else if(i == passwordLength - 1){
                while(!checkForCharacters(password[i], DIGITS, DIGITS_LEN)) password[i] = generateRandom(33, 126);
            }
            else {
                while(checkForCharacters(password[i], SPECIAL_CHAR, SPECIAL_LEN) || checkForCharacters(password[i], password, i)){
                    password[i] = generateRandom(33, 126);
                }
            }
        }

        printf("Password generated: %s\n", password);
        printf("Is the password secure enough? (y/n) ");

        char response[10];
        scanf("%s", response);

        if(strcmp(response, "y") == 0 || strcmp(response, "Y") == 0){
            printf("Awesome! Your password has been generated! Please store it safely and don't tell it to anyone.\n");
            return 0;
        }
        printf("Let's try again...\n");
    }

    printf("Sorry, Password could not be generated after %d tries. Please come back later for more attempts.\n", MAX_TRIES);
    return 0;
}