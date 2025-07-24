//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

int main(){
    char input[1000]; //Declare a character array with size 1000 to store the user input
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a phrase in the C Alien Language: ");
    fgets(input, 1000, stdin); //Use fgets to read in input from the user

    char output[1000]; //Declare a character array with size 1000 to store the translated output
    int i;
    for(i=0;i<strlen(input);i++){
        if(input[i]=='c' || input[i]=='C'){ //If the character is 'c' or 'C', replace it with 'Z'
            output[i]='Z';
        }
        else if(input[i]=='0'){ //If the character is '0', replace it with 'O'
            output[i]='O';
        }
        else if(input[i]=='1'){ //If the character is '1', replace it with 'I'
            output[i]='I';
        }
        else if(input[i]==' '){ //If the character is a space, leave it as is
            output[i]=' ';
        }
        else{ //For all other characters, replace them with a random special character
            int x = rand()%5;
            switch(x){
                case 0: output[i]='!';
                        break;
                case 1: output[i]='@';
                        break;
                case 2: output[i]='#';
                        break;
                case 3: output[i]='$';
                        break;
                case 4: output[i]='%';
                        break;              
            }
        }
    }
    printf("Your translated phrase in English is: %s",output); //Print out the translated output
    printf("\nThanks for using the Alien Language Translator. Goodbye!"); //Say goodbye to the user

    return 0;
}