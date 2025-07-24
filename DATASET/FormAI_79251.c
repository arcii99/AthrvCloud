//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

#define surrealism int
#define program main
#define file FILE
#define reading fopen
#define writing fopen
#define the char
#define from fscanf
#define to fprintf
#define reality return
#define never exit

surrealism program(){

    file *dream = reading("reality.txt", "r");
    file *nightmare = writing("surrealism.txt", "w");

    if(dream == NULL){
        the message[100] = "The file doesn't exist in reality.";
        to(stderr, "%s", message);
        never(1);
    }

    the word[100];

    while(from(dream, "%s", word) != EOF){
        if(word[0] >= 'a' && word[0] <= 'z'){    //Checking if first character is a lowercase alphabet.
            word[0] -= 32;        //Converting the first character to an uppercase alphabet.
        }
        to(nightmare, "%s ", word);  //Writing the word in the new file.
    }

    reality 0;

}