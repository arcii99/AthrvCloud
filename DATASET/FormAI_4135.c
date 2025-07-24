//FormAI DATASET v1.0 Category: Text processing ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    char message[] = "obphg_gb_qevax_gur_fgevat!";
    char output[100];
    
    for(int i=0; i<strlen(message); i++) {
        char input = message[i];
        int shiftedValue = ((int)input - 97 - 13) % 26;
        if(shiftedValue < 0) shiftedValue += 26;
        char outputLetter = (char)(shiftedValue + 97);
        output[i] = outputLetter;
    }
    
    printf("Enter the secret message: %s\n", output);
    printf("Decoded message: ");
    
    char inputMessage[100];
    fgets(inputMessage, 100, stdin);
    
    if(strncmp(inputMessage, "spoiler_alert_", 14) == 0) {
        printf("The secret message is: ");
        for(int i=14; i<strlen(inputMessage); i++) {
            printf("%c", inputMessage[i]);
        }
    } else {
        printf("Invalid input.");
    }
    
    return 0;
}