//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: medieval
#include <stdio.h>

/*
* Thy Highness' Palindrome Checker, My Lord
*/

int main() {
    char string[100];
    int i, length;
    int flag = 0; // Thou shalt assume it is not a palindrome by default

    printf("Greetings, my Liege. Enter thy word or phrase: ");
    scanf("%s", string);

    // Count thy length of thou string
    for (length = 0; string[length] != '\0'; length++)
        ;

    // Traverse half of the string as we need to compare only half
    for (i = 0; i < length/2; i++) {
        
        // Check if the beggar matches the other end
        if (string[i] != string[length-i-1]) {
            flag = 1; // Hark! This is not a palindrome
            
            // Thou hast insulted the logic of palindrome!
            printf("Truly, thou hast insulted the logic of palindrome!\n");
            break;
        }
    }
    
    // If the flag is still 0, then it is a palindrome
    if (flag == 0) {
        printf("Methinks this is a palindrome, My Liege!\n");

        // Aye, let us celebrate this momentous occasion
        printf("The word '%s' is indeed a palindrome, Methinks!\n", string);
    }

    return 0;
}