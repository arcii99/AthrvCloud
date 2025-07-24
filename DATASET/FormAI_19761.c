//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char caser(char m) { // The Caesar cipher function
    if(m>='a'&&m<='z'){
        m-=32;// change to uppercase
    }
    m-=3; // shift letter by 3
    if(m < 'A') {
        m+=26; // roll over to Z
    }
    return m;
}   
int main()  
{  
    int i, j;  
    char message[100], ch, choice;  
    printf("Enter a message to encrypt: ");  
    fgets(message, 100, stdin); // get the message
    for(i = 0; message[i] != '\0'; ++i) {
        ch = caser(message[i]); // encrypt each letter using caesar cipher
        message[i] = ch;
    }
    printf("The encrypted message: %s", message);  
    return 0;  
}