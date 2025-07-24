//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include<stdio.h> 
#include<ctype.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<time.h>
#define BUFFER_SIZE 1000

//Function to check whether a character is an alphabet or not
bool isAlphabet(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

//Function to check whether a string is a palindrome or not
bool isPalindrome(char *str) {
    int left = 0;       //Index of first character
    int right = strlen(str) - 1;        //Index of last character
    while(right > left) {
        if(!isAlphabet(str[left])) {
            left++;     //incrementing left index if it's not an alphabet
        } else if(!isAlphabet(str[right])) {
            right--;       //decrementing right index if it's not an alphabet
        } else if(tolower(str[left]) != tolower(str[right])) {      //comparing both the alphabets, if not equal, then it's not a palindrome
            return false;
        } else {
            left++;     //if chars are equal, then move inner char indices inwards
            right--;
        }
    }
    return true;
}

//Function to check whether a file is present or not
bool isFileExist(const char* fileName) {
    struct stat buffer;     
    return (stat(fileName, &buffer) == 0);       //If return value is 0, then file exists
}

//Main function
int main() {
    char input_buffer[BUFFER_SIZE];     //Buffer to store input string
    int bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);        //Reading input string from stdin
    input_buffer[bytes_read - 1] = '\0';        //Appending null character at the end of input string
    printf("Input string: %s\n", input_buffer);      //Printing input string
    if(isPalindrome(input_buffer)) {
        printf("The given input string is a palindrome.\n");      //If input string is a palindrome
    } else {
        printf("The given input string is not a palindrome.\n");      //If input string is not a palindrome
    }
    char fileName[50];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    if(!isFileExist(fileName)) {
        printf("File not found!\n");
    } else {
        char buffer[BUFFER_SIZE];       //Buffer to store contents of file
        FILE* file = fopen(fileName, "r");      //Opening file in read mode
        if(file == NULL) {
            printf("Unable to open the file!\n");        //If unable to open file
            exit(EXIT_FAILURE);
        }
        printf("File opened successfully! Contents of the file:\n");
        while(fgets(buffer, BUFFER_SIZE, file)) {
            printf("%s", buffer);       //Printing file contents line by line
        }
        fclose(file);
        if(isPalindrome(buffer)) {
            printf("The contents of the file is a palindrome.\n");      //If contents of file is a palindrome
        } else {
            printf("The contents of the file is not a palindrome.\n");      //If contents of file is not a palindrome
        }
    }
    return 0;
}