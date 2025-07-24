//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

int main() {
    char sentence[1000];
    int word_count = 0, i = 0;
    printf("Enter your sentence in Alien Language: ");
    fgets(sentence, sizeof(sentence), stdin); //takes input from user

    for(i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == ' ')  //checks if a space is encountered
            word_count++;  //if yes, word_count is increased by 1
    }

    //creating an array of strings to store different words
    char word_arr[word_count + 1][20]; 
    //each word can be of maximum length 20

    int word_no = 0, letter_no = 0;
    for(i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == ' ') { //checks if space is encountered
            word_arr[word_no][letter_no] = '\0';
            word_no++; //if yes, stores the word in array and updates word_no and letter_no
            letter_no = 0;
        }
        else {
            word_arr[word_no][letter_no] = sentence[i];
            letter_no++;
        }
    }
    word_arr[word_no][letter_no] = '\0'; //applying null terminator to the last word

    printf("Translation in English: ");
    for(i = 0; i <= word_count; i++) {
        if(strcmp(word_arr[i], "godafrin") == 0)
            printf("hello ");
        else if(strcmp(word_arr[i], "zadar") == 0)
            printf("goodbye ");
        else if(strcmp(word_arr[i], "klansek") == 0)
            printf("welcome ");
        else if(strcmp(word_arr[i], "zilbron") == 0)
            printf("thank you ");
        else if(strcmp(word_arr[i], "ploktar") == 0)
            printf("please ");
        else if(strcmp(word_arr[i], "frimdor") == 0)
            printf("sorry ");
        else if(strcmp(word_arr[i], "ulimtak") == 0)
            printf("yes ");
        else if(strcmp(word_arr[i], "uklant") == 0)
            printf("no ");
        else if(strcmp(word_arr[i], "meitric") == 0)
            printf("friend ");
        else if(strcmp(word_arr[i], "bleksark") == 0)
            printf("enemy ");
        else if(strcmp(word_arr[i], "flaket") == 0)
            printf("love ");
        else if(strcmp(word_arr[i], "orimnid") == 0)
            printf("hate ");
        else
            printf("%s ", word_arr[i]); //prints the word as it is if it's not an alien word
    }
    return 0;
}