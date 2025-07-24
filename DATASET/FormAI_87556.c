//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>

// function to count the number of vowels in a given string
int count_vowels(char *str) {
    int num_vowels = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
           || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            num_vowels++;
        }
        i++;
    }
    
    return num_vowels;
}

int main() {
    char str[100];
    
    // get user input for string
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // count the number of vowels in the string
    int num_vowels = count_vowels(str);
    
    // print out the number of vowels
    printf("There are %d vowels in the string", num_vowels);
    
    return 0;
}