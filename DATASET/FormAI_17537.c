//FormAI DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100]; // input string
    char vowels[] = "aeiouAEIOU"; // vowels list
    int vowel_count = 0, consonant_count = 0, digit_count = 0;
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // check for vowels, consonants and digits in the input string
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (strchr(vowels, str[i]) != NULL) {
                vowel_count++;
            } else {
                consonant_count++;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (strchr(vowels, str[i]) != NULL) {
                vowel_count++;
            } else {
                consonant_count++;
            }
        } else if (str[i] >= '0' && str[i] <= '9') {
            digit_count++;
        }
    }
    
    printf("The input string contains:\n");
    printf("%d vowels\n", vowel_count);
    printf("%d consonants\n", consonant_count);
    printf("%d digits\n", digit_count);
    
    return 0;
}