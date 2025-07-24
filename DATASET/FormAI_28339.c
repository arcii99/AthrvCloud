//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include<stdio.h>
#include<string.h>

//function to check if a character is an alphabet or not
int isAlphabet(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}

//function to check if a word is spelled correctly or not
int spellCheck(char *word){
    char dictionary[][15] = {"programming", "language", "computer", "algorithm", "debug", "compiler", "syntax", "library", "array", "pointer"}; //dictionary
    int len = sizeof(dictionary)/sizeof(dictionary[0]); //number of words in dictionary
    
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right)/2;
        if(strcmp(dictionary[mid], word) == 0) //word found
            return 1;
        else if(strcmp(dictionary[mid], word) > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0; //word not found
}

int main(){
    char sentence[100], word[20] = "";
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); //input sentence
    
    int len = strlen(sentence);
    for(int i=0; i<len; i++){
        if(isAlphabet(sentence[i])){
            int j = 0;
            while(isAlphabet(sentence[i])){
                word[j++] = tolower(sentence[i++]);
            }
            word[j] = '\0';
            if(!spellCheck(word)){ //word not in dictionary
                printf("Did you mean:");
                for(int k=0; k<j; k++){ //random suggestion for word
                    char temp = word[k];
                    word[k] = (k%2 == 0)? tolower(temp) : toupper(temp);
                }
                printf("%s ", word);
            }
            i--;
            strcpy(word, "");
        }
    }
    return 0;
}