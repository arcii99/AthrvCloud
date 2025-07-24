//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int length, num_digits, num_special;
    char password[100];
    char chars[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                    'n','o','p','q','r','s','t','u','v','w','x','y','z',
                    'A','B','C','D','E','F','G','H','I','J','K','L','M',
                    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                    '0','1','2','3','4','5','6','7','8','9','!','@','#',
                    '$','%','^','&','*','(',')','-','_','=','+','?','<','>'};
    srand(time(NULL));
    
    printf("Enter password length: ");
    scanf("%d", &length);
    printf("Enter number of digits: ");
    scanf("%d", &num_digits);
    printf("Enter number of special characters: ");
    scanf("%d", &num_special);
    
    /* Ensure length is long enough to include digits/special chars */
    if(length < num_digits + num_special) {
        printf("Error: Password length must be longer than number of digits and special characters\n");
        return 1;
    }
    
    /* Generate password with random characters */
    for(int i=0; i<length; i++) {
        int random_num = rand() % sizeof(chars);
        password[i] = chars[random_num];
    }
    
    /* Set random digits in password */
    for(int i=0; i<num_digits; i++) {
        int random_index = rand() % length;
        while(isdigit(password[random_index])) {
            random_index = rand() % length;
        }
        password[random_index] = rand() % 10 + '0';
    }
    
    /* Set random special chars in password */
    for(int i=0; i<num_special; i++) {
        int random_index = rand() % length;
        while(!ispunct(password[random_index])) {
            random_index = rand() % length;
        }
        password[random_index] = chars[rand() % (sizeof(chars)-10) + 52];
    }
    
    /* Output password */
    printf("\nGenerated password: %s\n", password);
    
    return 0;
}