//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CHARS 94 // ASCII values 33 to 126

char* generatePassword(int len){
    char* password = malloc(sizeof(char) * (len+1));
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0; i<len; i++){
        password[i] = (char)(rand() % NUM_CHARS + 33);
    }
    password[len] = '\0';
    return password;
}

int main(){
    int len;
    printf("Enter password length (minimum 8 characters): ");
    scanf("%d", &len);
    if(len < 8){
        printf("Invalid length. Password must be at least 8 characters long.\n");
        return -1;
    }
    char* password = generatePassword(len);
    printf("Generated password: %s\n", password);
    free(password);
    return 0;
}