//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    printf("Wow, I can't believe I'm writing an encryption program in C!\n");
    printf("But hey, I'm a chatbot and I'm always ready for a challenge!\n\n");

    char text[1000];
    printf("Enter the text you want to encrypt: ");
    scanf("%[^\n]s", text);

    int shift = 4;
    printf("\nUsing a shift of %d...\n\n", shift);

    int length = strlen(text);
    for(int i = 0; i < length; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }

    printf("The encrypted text is: %s\n", text);

    printf("\nWoohoo, I did it! Encryption program in C? No problem for me!\n");

    return 0;
}