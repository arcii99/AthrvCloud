//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include<stdio.h>
#include<string.h>

// Function to print ASCII art
void printAsciiArt(char *str){
    int len = strlen(str); // Calculate length of string
    int i;
    for(i=0; i<len; i++){ // Loop through each character in the string
        char ch = str[i];
        switch(ch){
            // Use specific ASCII art for each character
            case 'A':
                printf("     /\\    \n    /  \\   \n   /____\\  \n  /      \\ \n /        \\\n");
                break;
            case 'B':
                printf(" _______  \n|       \\ \n|_______\\\n|       /\n|_______/\n");
                break;
            case 'C':
                printf("   _____ \n  / ____|\n | |     \n | |     \n | |____ \n  \\_____|\n");
                break;
            // Add ASCII art for all the alphabets and numbers
            // ......
            
            default:
                printf("         \n         \n         \n         \n         \n");
                break;
        }
    }
}

int main(){
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Print the ASCII art for the string
    printAsciiArt(str);
    
    return 0;
}