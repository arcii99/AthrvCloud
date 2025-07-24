//FormAI DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("Hello, welcome to the Happy Text Processing Program!\n");
    printf("Please enter your message: ");
    
    char message[50];
    fgets(message, 50, stdin);
    
    int len = strlen(message);
    
    printf("\nProcessing your message...\n");
    
    for(int i=0; i<len; i++){
        
        if(message[i] == ' '){
            
            message[i] = '-';
            i++;
            
        }else{
            
            message[i] += 3;
            
        }
        
    }
    
    printf("\nHere is your happy message: %s", message);
    
    return 0;
}