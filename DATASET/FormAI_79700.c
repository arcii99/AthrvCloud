//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 20

char * generatePassword(int len);

int main(){
    int len;
    
    printf("How many characters do you want in your password? (max 20): ");
    scanf("%d", &len);
    
    if(len > MAX_LEN){
        printf("The password cannot be longer than 20 characters!");
        exit(1);
    }
    
    char* password = generatePassword(len);
    
    printf("Your password is: %s", password);
    free(password);
    return 0;
}

char * generatePassword(int len){
    char* password = malloc(sizeof(char) * len + 1);
    
    const char alphanumeric[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const int size = strlen(alphanumeric);
    
    srand(time(0));
    
    for(int i = 0; i < len; i++){
        int randomIndex = rand() % size;
        password[i] = alphanumeric[randomIndex];
    }
    
    password[len] = '\0';
    
    return password;
}