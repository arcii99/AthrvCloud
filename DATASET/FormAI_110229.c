//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include<stdio.h>
#include<string.h>

//this program processes text input to extract certain information

int main(){

    char text[1000]; //define a character array to store input
    int vowels=0, consonants=0, spaces=0, digits=0; //initialize variables to count number of vowels, consonants, spaces, and digits in the text input
    
    printf("Enter some text: "); //prompt the user to enter some text
    fgets(text, 1000, stdin); //store the text input in the character array
    
    //loop through the text to count and extract useful information
    for(int i=0; i<strlen(text); i++){
        
        //count vowels if they are present in the input
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U'){
            vowels++;
        }
        
        //count consonants if they are present in the input
        else if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')){
            consonants++;
        }
        
        //count spaces if present in the input
        else if(text[i]==' '){
            spaces++;
        }
        
        //count digits if present in the input
        else if(text[i]>='0' && text[i]<='9'){
            digits++;
        }
    }
    
    //print the extracted information
    printf("\nNumber of vowels in the text: %d\n", vowels);
    printf("Number of consonants in the text: %d\n", consonants);
    printf("Number of spaces in the text: %d\n", spaces);
    printf("Number of digits in the text: %d\n", digits);
    
    //perform some text processing and manipulation tasks to extract useful information
    printf("\nWords in the text: ");
    int i=0;
    while(i<strlen(text)){

        //skip spaces until a letter is encountered
        while(i<strlen(text) && text[i]==' '){
            i++;
        }
        
        //keep track of the current word length        
        int word_len=0;

        //read and print the current word        
        while(i<strlen(text) && text[i]!=' '){
            printf("%c", text[i]);
            i++;
            word_len++;
        }

        //print the length of the current word
        printf("(%d) ", word_len);
    }
    printf("\n");

    //perform some text processing and manipulation tasks to extract useful information    
    printf("\nWords in the text with more than 4 characters: ");
    i=0;
    while(i<strlen(text)){

        //skip spaces until a letter is encountered
        while(i<strlen(text) && text[i]==' '){
            i++;
        }
        
        //keep track of the current word length
        int word_len=0;

        //read and print the current word
        while(i<strlen(text) && text[i]!=' '){
            printf("%c", text[i]);
            i++;
            word_len++;
        }

        //print the length of the current word if it is more than 4 characters
        if(word_len>4){
            printf("(%d) ", word_len);
        }
    }
    printf("\n");

    return 0;
}