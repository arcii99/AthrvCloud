//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include<stdio.h>
#include<string.h>

int main(){

    printf("Surprise! Let's Encrypt in C!\n");

    char message[50];
    int i,shift;

    printf("Enter message to encrypt: ");
    fgets(message,50,stdin);

    printf("Enter shift value: ");
    scanf("%d",&shift);

    int length = strlen(message);

    for(i=0;i<length;i++){
        if(message[i]>='a' && message[i]<='z'){
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
        else if(message[i]>='A' && message[i]<='Z'){
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        }
    }

    printf("Encrypted Message: %s",message);

    return 0;
}