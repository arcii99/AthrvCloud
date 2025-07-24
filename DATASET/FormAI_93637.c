//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 20   // Maximum password length
#define MIN_LENGTH 8    // Minimum password length

char* generate_password(int length) {
    char* password = (char*) malloc(sizeof(char) * length);  // Allocate memory for password
    
    // Characters allowed in password
    char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+}{[]\\|';:,./?><`~";
    int charset_length = strlen(charset);

    srand(time(NULL));  // Seed random generator
    
    for(int i=0; i<length; i++) {
        password[i] = charset[rand() % charset_length]; // Append a random character to the password
    }
    
    return password;
}

int main() {
    int password_length;
    
    printf("Enter the length of the password you want to generate (minimum length is %d and maximum length is %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &password_length);
    
    while(!(password_length >= MIN_LENGTH && password_length <= MAX_LENGTH)) {
        printf("Invalid input! Please enter a length between %d and %d: ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &password_length);
    }
    
    char* password = generate_password(password_length);
    printf("Your secure password is: %s\n", password);
    
    free(password);  // Deallocate memory
    
    return 0;
}