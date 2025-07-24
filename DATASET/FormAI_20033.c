//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>

// Recursive function to count the number of vowels in a string
int count_vowels(char* str, int index, int count){
    // Base Case: end of string
    if(str[index] == '\0'){
        return count;
    }
    // Recursive Case
    else{
        char c = str[index];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count++;
        }
        return count_vowels(str, index+1, count);
    }
}

int main(){
    char input[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", input);
    int num_vowels = count_vowels(input, 0, 0);
    printf("The number of vowels in the string is: %d", num_vowels);
    return 0;
}