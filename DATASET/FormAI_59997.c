//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; //declaring a character array to store input string
    printf("Enter a string: ");
    scanf("%[^\n]", str); //taking input string till end of line
    printf("Original string is: %s\n", str);

    int len = strlen(str); //finding length of the string

    //reversing the string
    for(int i=0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    printf("Reversed string is: %s\n", str);

    //converting all characters to uppercase
    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') { //checking if character is lowercase
            str[i] = str[i] - 32; //converting to uppercase by subtracting 32 from ASCII value
        }
    }
    printf("String in uppercase is: %s\n", str);

    //finding and replacing all occurrences of a particular character
    char old_char, new_char;
    printf("Enter the character to be replaced: ");
    scanf(" %c", &old_char);
    printf("Enter the new character: ");
    scanf(" %c", &new_char);
    for(int i=0; i<len; i++) {
        if(str[i] == old_char) { //checking if character matches with old character
            str[i] = new_char; //replacing with new character
        }
    }
    printf("Modified string is: %s\n", str);
    return 0;
}