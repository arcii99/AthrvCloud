//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <string.h>

int checkWord(char *word) {
    char dict[100][20] = {"apple", "banana", "cat", "dog", "elephant", "fox", "giraffe", "horse", "insect", "jaguar",
                          "kangaroo", "lion", "monkey", "napkin", "orange", "parrot", "queen", "rabbit", "strawberry", "tiger",
                          "umbrella", "violet", "whale", "xylophone", "yak", "zebra"}; //pre-defined dictionary
    int lenDict = sizeof(dict)/sizeof(dict[0]); //calculate dictionary size
    int lenWord = strlen(word); //calculate length of the word to be checked
    int points = 0; //score counter
    int maxPoints = 0; //maximum score achievable
    
    for(int i=0; i<lenDict; i++) { //iterate through the dictionary
        int lenCurrent = strlen(dict[i]); //calculate length of current word
        if(lenCurrent == lenWord) { //if the lengths match
            int tempPoints = 0; //temporary score counter
            for(int j=0; j<lenWord; j++) { //iterate through each character in the word
                if(dict[i][j] == word[j]) //if the characters match
                    tempPoints++; //increment the temporary score counter
            }
            if(tempPoints > points) //if the temporary score is higher than the current score
                points = tempPoints; //update the score counter
        }
        if(points == lenWord) //if the score equals the word length (i.e., all characters match)
            return 1; //return true
    }
    return 0; //return false
}

void spellCheck(char *text) {
    int lenText = strlen(text); //calculate length of input text
    char word[20] = ""; //initialize buffer for word
    for(int i=0; i<lenText; i++) { //iterate through each character in the text
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t' || text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == ':') { //if the character is a word delimiter
            if(checkWord(word)) { //check if the word is spelled correctly
                printf("%s", word); //if it is, print the word
            }
            else { //if it is not
                printf("*%s*", word); //print the word with asterisks indicating it is misspelled
            }
            printf("%c", text[i]); //print the delimiter character
            word[0] = '\0'; //reset the buffer
        }
        else { //if the character is not a delimiter
            int lenWord = strlen(word); //calculate length of current word
            word[lenWord] = text[i]; //add the character to the end of the word
            word[lenWord+1] = '\0'; //append null character to create string
        }
    }
}

int main() {
    char text[1000] = "The quick brown fox jumpped over the lazy dog. The cat in the had was very furry."; //input text
    spellCheck(text); //spell check the text
    return 0;
}