//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include<stdio.h>
#include<string.h>

void encrypt(char *str, int key);

int main() {
    char str[100];
    int key;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strlen(str)-1] = '\0';
    printf("Enter a key value: ");
    scanf("%d", &key);
    encrypt(str, key);
    printf("Encrypted message is: %s\n", str);
    return 0;
}
void encrypt(char *str, int key) {
    int i = 0;
    char temp;
    while(str[i] != '\0') {
        temp = str[i];
        if(temp != ' ') {
            temp = temp + key;
            if(temp > 'z')
                temp = temp - 26;
        }
        str[i] = temp;
        i++;
    }
}