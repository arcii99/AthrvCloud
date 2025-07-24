//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <string.h>

char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", 
    "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *alphabets = "abcdefghijklmnopqrstuvwxyz";

int main() {
    char message[100];
    printf("Enter your message in lowercase: \n");
    scanf("%s", message);

    int len = strlen(message);

    printf("Your message in Morse code is: ");

    for(int i = 0; i < len; i++) {
        char c = message[i];
        //check if it is a space
        if(c == ' ') {
            printf("   ");
        } else {
            //find the index of the character in the alphabets string
            int index = strchr(alphabets, c) - alphabets;
            printf("%s ", morse[index]);
        }
    }
    printf("\n");
    return 0;
}