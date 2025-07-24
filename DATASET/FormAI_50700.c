//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main(){
    char message[100];
    printf("Enter message to calculate the checksum: ");
    scanf("%[^\n]s", message);

    //adding the values of all characters in the message
    int sum = 0;
    for(int i=0; i<strlen(message); i++){
        sum += (int) message[i];
    }

    //subtracting the largest ASCII value in the message from the sum
    int largest = (int) message[0];
    for(int i=0; i<strlen(message); i++){
        if((int) message[i] > largest){
            largest = (int) message[i];
        }
    }
    sum -= largest;

    //calculating the checksum by taking the final sum modulo 256
    int checksum = sum % 256;

    //displaying the message and checksum in post-apocalyptic style
    printf("\n----------------------------------------\n");
    printf("MSG: ");
    for(int i=0; i<strlen(message); i++){
        printf("%c ", message[i]);
    }
    printf("\n");
    printf("CHK: ");
    for(int i=0; i<checksum; i++){
        printf("%c", 219); //displaying block symbols for checksum
    }
    printf("\n----------------------------------------\n");

    return 0;
}