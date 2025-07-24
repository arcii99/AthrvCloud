//FormAI DATASET v1.0 Category: Spell checking ; Style: active
#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

//Function to reverse a string
void reverseString(char str[]) {
    for(int i = 0; i < strlen(str)/2; i++) {
        char temp = str[i];
        str[i] = str[strlen(str)-1-i];
        str[strlen(str)-1-i] = temp;
    }
}

//Function to check if two strings are equal
int isEqual(char str1[], char str2[]) {
    if(strlen(str1) != strlen(str2)) {
        return 0;
    }
    for(int i = 0; i < strlen(str1); i++) {
        if(str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

//Function to print misspelled words
void printMisspelledWords(char misspelledWords[][MAX_LEN], int numMisspelled){
    printf("Misspelled words found:\n");
    for(int i = 0; i < numMisspelled; i++){
        printf("%s\n", misspelledWords[i]);
    }
}

int main(){
    char sentence[MAX_LEN];
    printf("Enter a sentence for spell checking: ");
    fgets(sentence, MAX_LEN, stdin);
    char wordArr[MAX_LEN][MAX_LEN];
    char misspelledWords[MAX_LEN][MAX_LEN];
    int numWords = 0;
    for(int i = 0; i < strlen(sentence); i++){
        //Ignoring whitespace and special characters
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '?' || sentence[i] == '!') {
            continue;
        }
        char temp[MAX_LEN];
        int j = 0;
        //While the character is not whitespace or special character, add to temp array
        while(sentence[i] != ' ' && sentence[i] != '\n' && sentence[i] != '\t' && sentence[i] != '.' && sentence[i] != ',' && sentence[i] != '?' && sentence[i] != '!') {
            temp[j] = sentence[i];
            j++;
            i++;
        }
        temp[j] = '\0'; //Adding string terminator to end of temp array
        strcpy(wordArr[numWords],temp); //Copying temp array to wordArr
        numWords++;
    }
    int numMisspelled = 0;
    for(int i=0; i<numWords; i++){
        //If the first letter of the word is uppercase, it is likely a proper noun and thus should not be checked for spelling
        if(wordArr[i][0] >= 'A' && wordArr[i][0] <= 'Z'){
            continue;
        }
        char reversedWord[MAX_LEN];
        strcpy(reversedWord,wordArr[i]);
        reverseString(reversedWord); //Reversing the word for easier comparison
        if(!isEqual(wordArr[i],reversedWord)){ //If the word is not a palindrome, it is likely misspelled
            strcpy(misspelledWords[numMisspelled],wordArr[i]); //Adding misspelled word to array
            numMisspelled++;
        }
    }
    if(numMisspelled == 0){
        printf("No misspelled words found!\n");
    } else{
        printMisspelledWords(misspelledWords,numMisspelled); //Printing misspelled words
    }
    return 0;
}