//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include<stdio.h>

// Medieval Checksum Calculator

int main(){
    printf("Welcome to the Medieval Checksum Calculator!\n");
    printf("Please enter your message:\n");

    char message[100];
    fgets(message, 100, stdin);

    int checksum = 0;

    for(int i=0; message[i]!='\0'; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            checksum += (int)message[i] - 'a' + 1; // adding value of character
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            checksum += (int)message[i] - 'A' + 1; // adding value of character
        }
        else if(message[i] >= '0' && message[i] <= '9'){
            checksum += (int)message[i] - '0'; // adding value of character
        }
    }

    // Print out the calculated checksum
    printf("\n\nYour checksum is: %d\n", checksum);
    printf("May the gods be pleased with your message.\n");
    printf("Farewell.\n");

    return 0;
}