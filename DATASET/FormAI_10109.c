//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length);

int main(){
    int length;
    printf("How long do you want your password to be? ");
    scanf("%d", &length);
    generatePassword(length);
    return 0;
}

void generatePassword(int length){
    srand(time(NULL)); //Initialize random seed
    char password[length]; //Create array to store password
    int i;
    for(i=0; i<length; i++){
        int type = rand()%3; //Randomly choose between upper, lower, and number
        if(type == 0){
            password[i] = (char)(rand()%26 + 65); //Choose random uppercase letter
        }
        else if(type == 1){
            password[i] = (char)(rand()%26 + 97); //Choose random lowercase letter
        }
        else{
            password[i] = (char)(rand()%10 + 48); //Choose random number
        }
    }
    printf("Your new password is: %s", password); //Print generated password
}