//FormAI DATASET v1.0 Category: Data recovery tool ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This is a unique C data recovery tool that can recover your lost data but with a twist!

void main() {
    char *data = NULL;
    int size;
    
    printf("Welcome to the C Data Recovery Tool!\n");
    printf("Please enter the size of your lost data: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Invalid size! Please try again.\n");
    } else {
        data = (char*) malloc(size * sizeof(char));
        printf("Please enter your lost data: ");
        scanf("%s", data);
        
        //Here comes the twist!
        for (int i=0; i < strlen(data); i++) {
            data[i] = (char)(data[i] + 1);
        }
        
        printf("Congratulations! Here is your recovered data: %s\n", data);
        printf("But wait, there's more!\n");
        printf("Your data has been successfully recovered but it has been encrypted with a Caesar Cipher!\n");
        printf("The key to decrypt your data is 1 (since we added 1 to each character).\n");
        printf("Good luck decrypting it! Thank you for using our C Data Recovery Tool!\n");
        free(data);
    }
}