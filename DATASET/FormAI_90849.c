//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateChar(int min, int max){
    int range = max - min + 1;
    return (char)(rand() % range + min);
}

char* generatePassword(int length){
    char* password = malloc(length * sizeof(char));
    srand(time(NULL));
    for(int i=0; i<length; i++){
        if(i < (length/3)){
            //generate a random lowercase letter
            password[i] = generateChar('a', 'z');
        }else if(i < (2*length/3)){
            //generate a random uppercase letter
            password[i] = generateChar('A', 'Z');
        }else{
            //generate a random digit
            password[i] = generateChar('0', '9');
        }
    }
    //shuffle the password
    for(int i=(length-1); i>0; i--){
        int j = rand() % (i+1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    return password;
}

int main(){
    int length;
    printf("Welcome to Genius Password Generator!\n");
    printf("Enter the password length: ");
    scanf("%d", &length);
    char* password = generatePassword(length);
    printf("Password generated: %s\n", password);
    free(password);
    return 0;
}