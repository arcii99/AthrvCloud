//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define CHAR_SET "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

int main(){
    int length, i, j, random_index;
    char password[MAX_LENGTH+1];
    time_t t;
    srand((unsigned) time(&t)); // initialize random seed

    printf("Enter the length of your password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if(length < MIN_LENGTH || length > MAX_LENGTH){
        printf("Invalid length.\n");
        return 1;
    }

    for(i=0; i<length; i++){
        random_index = rand() % strlen(CHAR_SET); // generate random index within the length of the character set
        password[i] = CHAR_SET[random_index];
    }
    password[length] = '\0'; // add null terminator at the end of the string

    // shuffle the characters in the password
    for(i=length-1; i>0; i--){
        j = rand() % (i+1); // generate random index within the unshuffled portion of the string
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("Your password is: %s\n", password);
    return 0;
}