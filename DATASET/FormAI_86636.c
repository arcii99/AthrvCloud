//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

void convertToMorse(char* input, int length) {
    char* morse[36] ={
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
        "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
        "-.--","--..","-----",".----","..---","...--","....-",".....","-....",
        "--...","---..","----."
    };

    char* alpha[36] ={
        "A","B","C","D","E","F","G","H","I","J","K","L",
        "M","N","O","P","Q","R","S","T","U","V","W","X",
        "Y","Z","0","1","2","3","4","5","6","7","8","9"
    };

    for (int i = 0; i < length; i++) {
        char* curr = &input[i];
        int index = -1;
        for (int j = 0; j < 36; j++) {
            if (strcmp(alpha[j], curr) == 0) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            printf(" ");
        } else {
            printf("%s ", morse[index]);
        }
    }
    printf("\n");
}

int main() {
    char* message = "HELLO WORLD";
    int length = strlen(message);

    printf("Message: %s\n", message);
    printf("Morse Code: ");
    convertToMorse(message, length);

    return 0;
}