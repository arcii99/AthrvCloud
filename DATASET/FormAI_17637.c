//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_secure_password(char* password, int length);

int main() {
    int length;
    char password[20];
    
    printf("How long do you want the password to be? (between 8-20 characters)\n");
    scanf("%d", &length);
    
    if(length < 8 || length > 20) {
        printf("Invalid length!\n");
        return 0;
    }
    
    generate_secure_password(password, length);
    printf("Your secure password is: %s\n", password);
    
    return 0;
}

void generate_secure_password(char* password, int length) {
    // Define character sets
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#%^&*()_+-=[]{}|;':\"<>,.?/~`";
    
    // Concatenate all character sets into one string
    char charset[strlen(lowercase) + strlen(uppercase) + strlen(numbers) + strlen(symbols)];
    strcat(charset, lowercase);
    strcat(charset, uppercase);
    strcat(charset, numbers);
    strcat(charset, symbols);
    
    srand(time(NULL)); // Initialize random seed
    
    // Generate random password characters from the concatenated character set
    for(int i = 0; i < length; i++) {
        int random_index = rand() % strlen(charset);
        password[i] = charset[random_index];
    }
    
    password[length] = '\0'; // Add null terminator to end of password string
}