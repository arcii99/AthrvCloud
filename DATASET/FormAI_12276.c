//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Hello fellow coders, welcome to the world of C Encryption! \n");
    printf("Are you ready for some top-secret coded fun? Let's get started! \n");
    printf("First, let's generate a key, shall we? \n");

    int key = rand()%1000; //let's generate a random three-digit key

    printf("Your key is: %d \n", key); //print out the key so we don't forget it

    printf("Now, let's enter the message you want to encrypt: \n");

    char message[100]; //let's make a message array of size 100

    fgets(message, sizeof(message), stdin); //let's get the message from the user

    for(int i=0; message[i]!='\0'; i++){
        if(message[i]>='a' && message[i]<='z'){ //if the message is lowercase
            message[i] = (char)(((int)message[i]+key-97)%26 +97); //let's encrypt it using the key
        }
        else if(message[i]>='A' && message[i]<='Z'){ //if the message is uppercase
            message[i] = (char)(((int)message[i]+key-65)%26 +65); //let's encrypt it using the key
        }
    }

    printf("Your encrypted message is: %s \n", message); //let's print out the encrypted message

    printf("Want to decrypt it? Let's do it! \n");

    for(int i=0; message[i]!='\0'; i++){
        if(message[i]>='a' && message[i]<='z'){ //if the message is lowercase
            message[i] = (char)(((int)message[i]-key-97+26)%26 +97); //let's decrypt it using the key
        }
        else if(message[i]>='A' && message[i]<='Z'){ //if the message is uppercase
            message[i] = (char)(((int)message[i]-key-65+26)%26 +65); //let's decrypt it using the key
        }
    }

    printf("Your decrypted message is: %s \n", message); //let's print out the decrypted message

    printf("And that's it, folks! You are now a C Encryption expert. Have fun encrypting and decrypting all your messages! \n");

    return 0; //let's clean up and go home
}