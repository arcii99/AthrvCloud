//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
char *alphabet = "abcdefghijklmnopqrstuvwxyz ";

void textToMorse(char *message, int currentIndex){
    if(currentIndex == strlen(message)){
        return;
    }
    else{
        for(int i = 0; i < strlen(alphabet); i++){
            if(alphabet[i] == message[currentIndex]){
                printf("%s ", morseCode[i]);
                break;
            }
        }
        textToMorse(message, currentIndex + 1);
    }
}

int main(){
    char message[100];
    printf("Enter the text to convert to Morse code: ");
    scanf("%[^\n]", message);
    printf("The Morse code of the given text is:\n");
    textToMorse(message, 0);
    printf("\n");
    return 0;
}