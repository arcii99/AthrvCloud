//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/* The Medieval Hash Function */

unsigned long long medieval_hash(char *msg){
    unsigned long long hash_value=0;
    int len_msg=strlen(msg);
    
    for(int i=0;i<len_msg;i++){
        hash_value=(hash_value*17)+msg[i];
    }
    
    return hash_value;
}

/* The Main Function */

int main(){
    char message[100];
    printf("Enter the message to be hashed in medieval style: ");
    scanf("%[^\n]",message);
    printf("\n\nThe hashed value of the message in medieval style is: %llu",medieval_hash(message));
    
    return 0;
}