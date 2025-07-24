//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mind-bending cryptography implementation
void mind_bending(void)
{
    char str[100], key[100];
    int i, j = 0;
    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);

    int len_str = strlen(str)-1;
    int len_key = strlen(key)-1;
    char new_str[len_str];

    for(i=0; i<len_str; i++)
    {
        new_str[i] = (str[i] + key[j]) % 128;
        j++;
        if(j == len_key) j = 0;
    }

    printf("Encrypted string: ");
    for(i=0; i<len_str; i++)
        printf("%c", new_str[i]);
    printf("\n");
}

int main()
{
    mind_bending();
    return 0;
}