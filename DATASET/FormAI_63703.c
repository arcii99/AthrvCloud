//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>

void remove_vowels(char str[]) {
    int i, j=0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='A' && str[i]!='E' && str[i]!='I' && str[i]!='O' && str[i]!='U') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main() {
    char text[1000];
    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    // Remove vowels from text
    remove_vowels(text);

    printf("Text without vowels: %s\n", text);
    return 0;
}