//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_text[1000];
    char processed_text[1000];
    
    printf("Enter the text to be processed: ");
    fgets(input_text, sizeof(input_text), stdin); // read input from user
    
    for(int i=0; i<strlen(input_text); i++) {
        processed_text[i] = input_text[i] ^ 0xff; // paranoid style text processing
        if(i > 0) {
            if((processed_text[i-1] == '0' && processed_text[i] == 'x') || (processed_text[i-1] == 'x' && processed_text[i] == '0')) {
                printf("Potentially malicious input detected! Aborting...\n");
                exit(1);
            }
        }
    }
    
    printf("Processed text: %s", processed_text);
    
    return 0;
}