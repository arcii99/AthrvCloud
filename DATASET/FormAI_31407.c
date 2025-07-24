//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include<stdio.h>
#include<string.h>

int main() 
{
    int len;
    
    char message[100];
    printf("Enter your message: "); //user inputs message
    fgets(message, 100, stdin);
    
    len = strlen(message); //gets length of message
    
    for(int i=0; i<len; i++) { //loops through each character
        if(message[i] != ' ') { //checks if character is not a space
            message[i] += 5; //adds 5 to each character to create watermark
        }
    }
    
    printf("Your watermarked message is: %s", message); //prints out watermarked message
    
    for(int i=0; i<len; i++) { //loops through each character
        if(message[i] != ' ') { //checks if character is not a space
            message[i] -= 5; //subtracts 5 from each character to remove watermark
        }
    }
    
    printf("Your original message is: %s", message); //prints out original message
    
    return 0;
}