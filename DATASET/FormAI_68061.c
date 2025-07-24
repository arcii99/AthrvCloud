//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main(){

    char password[100];
    int length, lower_char_count=0, upper_char_count=0, digit_count=0, special_char_count=0, strength_score=0;

    printf("Enter Password: ");
    fgets(password, 100, stdin);
    length = strlen(password);

    for(int i=0; i<length; i++){
        char ch = password[i];

        if(ch >= 'a' && ch <= 'z'){ //checking if the character is a lowercase alphabet
            lower_char_count++;
        }
        else if(ch >= 'A' && ch <= 'Z'){//checking if the character is an uppercase alphabet
            upper_char_count++;
        }
        else if(ch >= '0' && ch <= '9'){//checking if the character is a digit
            digit_count++;
        }
        else{ //if the character is not an alphabet or a digit, it must be a special character
            special_char_count++;
        }
    }

    /* Calculating Password Strength Score */
    if(length < 8){ 
        strength_score = 0;
    }
    else if(length >= 8 && length <= 10){
        strength_score = 1;
    }
    else if(length > 10 && length <= 15){
        strength_score = 2;
    }
    else{
        strength_score = 3;
    }

    if(lower_char_count > 0 && upper_char_count > 0){ //adding 1 to strength score if both lower and uppercase alphabets are present
        strength_score++;
    }

    if(digit_count > 0){ //adding 1 to strength score if digits are present
        strength_score++;
    }

    if(special_char_count > 0){ //adding 1 to strength score if special characters are present
        strength_score++;
    }

    /* Printing Password Strength */
    if(strength_score == 0){
        printf("Weak Password!");
    }
    else if(strength_score <= 2){
        printf("Medium Strength Password.");
    }
    else if(strength_score == 3){
        printf("Strong Password!");
    }
    else{
        printf("Very Strong Password!");
    }

    return 0;
}