//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

char translate(char letter){
    switch(letter){
        case 'a':
            return '!';
        case 'b':
            return '*';
        case 'c':
            return '$';
        case 'd':
            return '#';
        default:
            return ' ';
    }
}

int main(){
    char message[100];
    printf("Enter your message in Alien Language: ");
    scanf("%[^\n]", message);
    
    printf("Translating...\n\n");
    int i;
    for(i=0; i<strlen(message); i++){
        printf("%c", translate(message[i]));
    }
    printf("\n\nTranslation complete.");
    return 0;
}