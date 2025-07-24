//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sanitizeString(char *str) {
    int len = strlen(str);
    char *temp = (char*)calloc(len, sizeof(char));
    int j = 0;

    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') // convert lowercase to uppercase
            temp[j++] = str[i] - 32;
        else if(str[i] >= 'A' && str[i] <= 'Z') // no change needed for uppercase
            temp[j++] = str[i];
        else if(str[i] >= '0' && str[i] <= '9') // no change needed for numbers
            temp[j++] = str[i];
    }
    temp[j] = '\0';
    strcpy(str, temp);
    free(temp);
}

int main() {
    char name[50], address[100], contact[15];
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    sanitizeString(name);
    printf("Enter your address: ");
    fgets(address, 100, stdin);
    sanitizeString(address);
    printf("Enter your contact number: ");
    fgets(contact, 15, stdin);
    sanitizeString(contact);

    printf("Sanitized Input:\nName: %sAddress: %sContact: %s", name, address, contact);
    return 0;
}