//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: funny
#include<stdio.h>
#include<string.h>

int main() {

    char input[1000];
    printf("Welcome to the wackiest hashing function ever!\n");
    printf("Enter a string to hash: ");
    scanf("%s", input);

    int hash = 0;

    // loop over each character in string
    for(int i = 0; i < strlen(input); i++) {
        printf("Hashing %c...\n", input[i]);
        int char_value = input[i];

        // We do some calculations based on character value to get the unique hash
        int prime_value = 71; // arbitrary prime number
        if(char_value % 2 == 0) {
            hash += pow(char_value + prime_value, 2);
        } else {
            hash -= pow(char_value - prime_value, 2);
        }
    }

    printf("Your hash value is: %d\n", hash);

    printf("Don't worry about remembering this hash code. Just enter your "
           "string and I will generate a new one for you every time you use "
           "this function.\n");

    return 0;
}