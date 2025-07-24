//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include<stdio.h>
#include<string.h>
int main(){
    char message[100];
    int i, count = 0;
    printf("Enter the message to check for spam: ");
    fgets(message, 100, stdin); // Read the input from user
    // A list of spam keywords
    char* spam_list[5] = {"free", "offer", "danger", "call now", "limited time offer"};
    // Check if message contains any of the spam keywords
    for(i=0; i<5; i++){
       if(strstr(message, spam_list[i]) != NULL){
          count++;
       }
    }
    if(count == 0){
       printf("Message not identified as spam.\n");   
    }else{
       printf("Message identified as spam.\n"); 
    }
    return 0;
}