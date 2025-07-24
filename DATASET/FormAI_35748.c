//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//This program will count the frequency of each unique word in an input file

int main() {

    //opening the input file
    FILE *input;
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("File not found!");
        return 0;
    }

    //opening the output file
    FILE *output;
    output = fopen("output.txt", "w");

    //initializing variables
    char word[100];
    char lower_word[100];
    int freq[1000];
    int i,j,k,count=0;

    //loop to initialize the frequency array to zero
    for(i=0;i<1000;i++){
        freq[i]=0;
    }

    //loop to read each word from the input file and count the frequency of each unique word
    while(!feof(input)){
        fscanf(input,"%s",word);
        for(i=0;i<strlen(word);i++){
            lower_word[i] = tolower(word[i]);
        }
        lower_word[i] = '\0';
        count++;
        for(j=0;j<count;j++){
            if(strcmp(lower_word,word[j])==0){
                break;
            }
        }
        if(j==count){
            freq[j]++;
        }
    }

    //loop to write the frequency of each unique word to the output file
    for(k=0;k<count;k++){
        fprintf(output,"%s: %d\n",word[k],freq[k]);
    }

    //closing the input and output files
    fclose(input);
    fclose(output);

    //printing a success message
    printf("Word frequency counted successfully!");

    return 0;
}