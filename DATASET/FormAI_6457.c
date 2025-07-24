//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: active
#include<stdio.h>
#include<string.h>

//Function prototype
void alienLangTranslator(char sentence[]);

int main(){

    //Define and initialize the sentence to be translated
    char sentence[] = "Klorco xabrin tronko baxt gellop skrek!";
    //Call the alienLangTranslator function to translate the sentence
    alienLangTranslator(sentence);
    return 0;
}

//Function to translate the alien language
void alienLangTranslator(char sentence[]){
    //Define and initialize the mapping of alien to english alphabets
    char alienCode[] = "klrcxbrntgpshfvmwqyzdjaeiou";
    char englishCode[] = "abcdefghijklmnopqrstuvwxyz";
    //Calculate the length of the sentence
    int sentenceLength = strlen(sentence);
    //Loop through each character in the sentence
    for(int i=0; i<sentenceLength; i++){
        //Check if the character is a space or special character
        if(sentence[i] == ' ' || sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ','){
            //Print the character as it is
            printf("%c", sentence[i]);
        }else{
            //Loop through the alienCode array to find the matching english alphabet
            for(int j=0; j<26; j++){
                //Check if the character matches with any alien alphabet
                if(sentence[i] == alienCode[j]){
                    //Print the matching english alphabet
                    printf("%c", englishCode[j]);
                }
            }
        }
    }
}