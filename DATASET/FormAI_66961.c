//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int main(){
    char secret_message[MAX_SIZE];
    char watermark[MAX_SIZE];
    char final_message[MAX_SIZE*2];
    int i, j;

    // Get secret message from user
    printf("Enter secret message: ");
    fgets(secret_message, sizeof(secret_message), stdin);
    
    // Get watermark from user
    printf("Enter watermark: ");
    fgets(watermark, sizeof(watermark), stdin);
    
    // Embed watermark in secret message
    j = 0;
    for(i=0; i<strlen(secret_message); i++){
        if(j < strlen(watermark)){
            final_message[j] = watermark[j];
            j++;
        }
        final_message[j] = secret_message[i];
        j++;
    }
    
    // Display final message with watermark
    printf("Watermarked message: %s", final_message);
    
    return 0;
}