//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include<stdio.h>

int main(){
    char input[100];
    printf("Enter a text: ");
    fgets(input, 100, stdin); // get input from user
    int vowels = 0; // initialize variable for counting vowels
    int consonants = 0; // initialize variable for counting consonants
    int spaces = 0; // initialize variable for counting spaces
    int digits = 0; // initialize variable for counting digits

    for(int i=0; input[i]!='\n'; i++){ // loop through input string
        if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u' || input[i]=='A' || input[i]=='E' || input[i]=='I' || input[i]=='O' || input[i]=='U'){
            vowels++; // increment vowel count
        }
        else if(input[i]>='a' && input[i]<='z' || input[i]>='A' && input[i]<='Z'){
            consonants++; // increment consonant count
        }
        else if(input[i]>='0' && input[i]<='9'){
            digits++; // increment digit count
        }
        else if(input[i]==' '){
            spaces++; // increment space count
        }
    }

    // output results:
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);

    return 0;
}