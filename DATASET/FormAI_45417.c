//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
int main() 
{ 
    char username[20], password[20]; 
    int is_hacker = 0; 
  
    // Get user input for username and password
    printf("Enter your username: "); 
    scanf("%s", username); 
  
    printf("Enter your password: "); 
    scanf("%s", password); 
  
    // Check if username and password are valid 
    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) 
    { 
        printf("\nWelcome, admin!\n"); 
    } 
    else 
    { 
        is_hacker = 1; 
    } 
  
    // If username or password are invalid, log attempt 
    if (is_hacker == 1) 
    { 
        FILE *fptr; 
        fptr = fopen("intrusion.log", "a"); 
        fprintf(fptr, "Invalid login attempt: Username - %s, Password - %s\n", username, password); 
        fclose(fptr); 
  
        printf("\nInvalid login attempt!\n"); 
        printf("Your attempt has been logged and will be investigated.\n"); 
    } 
  
    return 0; 
}