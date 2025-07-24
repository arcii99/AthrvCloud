//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char symbols[10] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    char uppercase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lowercase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char password[16];
    int count = 0, symbol_count = 0, upper_count = 0, lower_count = 0, digit_count = 0;
    
    srand(time(NULL));
    
    printf("Accessing system database...\n");
    printf("Authentication required.\n");
    printf("Generating secure password...\n");
    
    while(count < 16){
        int category = rand() % 4;
        if(category == 0 && symbol_count < 3){
            password[count] = symbols[rand() % 10];
            symbol_count++;
            count++;
        }
        else if(category == 1 && upper_count < 3){
            password[count] = uppercase[rand() % 26];
            upper_count++;
            count++;
        }
        else if(category == 2 && lower_count < 3){
            password[count] = lowercase[rand() % 26];
            lower_count++;
            count++;
        }
        else if(category == 3 && digit_count < 3){
            password[count] = digits[rand() % 10];
            digit_count++;
            count++;
        }
        else if(count >= 12){
            password[count] = symbols[rand() % 10];
            symbol_count++;
            count++;
        }
    }
    
    printf("Success! Your secure password is: %s\n\n", password);
    printf("Please copy and remember your password. Access granted.\n");
    printf("Exiting system database...\n");
    
    return 0;
}