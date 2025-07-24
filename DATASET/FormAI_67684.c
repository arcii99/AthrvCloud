//FormAI DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of input string

void caesar_encrypt(char *input, int key){

    char ch;

    for(int i = 0; input[i] != '\0'; i++){
        ch = input[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z')
                ch = ch - 'z' + 'a' - 1;
            input[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;
            input[i] = ch;
        }
    }
}

int main()
{
    char str[MAX_SIZE];
    int key;

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    caesar_encrypt(str, key);
    printf("Encrypted string: %s", str);

    return 0;
}