//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main(){
    char message[100] = "Welcome to the future, user!";

    //Replace vowels with numbers
    for(int i=0; i<strlen(message); i++){
        if(message[i] == 'a'){
            message[i] = '4';
        }
        else if(message[i] == 'e'){
            message[i] = '3';
        }
        else if(message[i] == 'i'){
            message[i] = '1';
        }
        else if(message[i] == 'o'){
            message[i] = '0';
        }
        else if(message[i] == 'u'){
            message[i] = '2';
        }
    }

    printf("%s\n", message);

    //Reverse the string
    char reversed[100];
    int j = 0;
    for(int i=strlen(message)-1; i>=0; i--){
        reversed[j++] = message[i];
    }
    reversed[j] = '\0';

    printf("%s\n", reversed);

    //Create a new string with only the capital letters
    char uppercase[100];
    j = 0;
    for(int i=0; i<strlen(message); i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            uppercase[j++] = message[i];
        }
    }
    uppercase[j] = '\0';

    printf("%s\n", uppercase);

    return 0;
}