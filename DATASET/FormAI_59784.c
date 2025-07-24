//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_password(char password[], int length, int index)
{
    // base case
    if (index == length) {
        password[index] = '\0';
        return;
    }
    
    // get a random character
    int ascii = rand() % 75 + 48;
    while ((ascii > 57 && ascii < 65) || (ascii > 90 && ascii < 97)) {
        ascii = rand() % 75 + 48;
    }
    char c = (char)ascii;
    
    // set the character in the password
    password[index] = c;
    
    // generate the rest of the password recursively
    generate_password(password, length, index+1);
}

int main()
{
    srand(time(NULL));
    int length;
    char password[101];
    
    printf("Enter length of password (maximum 100): ");
    scanf("%d", &length);
    
    // validate user input
    if (length < 1 || length > 100) {
        printf("Invalid length. Please enter a number between 1 and 100.\n");
        return 1;
    }
    
    generate_password(password, length, 0);
    
    printf("Your password is: %s\n", password);
    
    return 0;
}