//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char love_note[1000];
    char processed_note[1000] = "";
    
    printf("My dearest, please leave me a love note: ");
    fgets(love_note, sizeof(love_note), stdin);
    
    int i;
    for(i = 0; i < strlen(love_note); i++) {
        if(love_note[i] == 'y') {
            processed_note[i] = 'o';
        } else if (love_note[i] == 'u') {
            processed_note[i] = 'm';
        } else if (love_note[i] == ' ') {
            processed_note[i] = ' ';
        } else {
            processed_note[i] = love_note[i];
        }
    }
    
    printf("\nMy love, I received your message and have processed it for you:\n%s", processed_note);

    return 0;
}