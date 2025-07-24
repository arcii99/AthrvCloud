//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    printf("Enter a sentence in C Alien language:\n");
    scanf("%[^\n]%*c", input);

    char output[100];
    int length = strlen(input);
    int index = 0;

    for(int i=0; i<length; i++){
        if(input[i] == 'C' && input[i+1] == 'A' && input[i+2] == 'L'){
            output[index] = 'H';
            output[index+1] = 'e';
            output[index+2] = 'l';
            output[index+3] = 'l';
            output[index+4] = 'o';
            index += 5;
            i += 2;
        }
        else if(input[i] == 'C' && input[i+1] == 'A' && input[i+2] == 'T'){
            output[index] = 'B';
            output[index+1] = 'y';
            output[index+2] = 'e';
            index += 3;
            i += 2;
        }
        else if(input[i] == 'C' && input[i+1] == 'A' && input[i+2] == 'K' && input[i+3] == 'E'){
            output[index] = 'G';
            output[index+1] = 'o';
            output[index+2] = 'o';
            output[index+3] = 'd';
            output[index+4] = 'b';
            output[index+5] = 'y';
            index += 6;
            i += 3;
        }
        else if(input[i] == 'C' && input[i+1] == 'A' && input[i+2] == 'T' && input[i+3] == 'S'){
            output[index] = 'F';
            output[index+1] = 'r';
            output[index+2] = 'i';
            output[index+3] = 'e';
            output[index+4] = 'n';
            output[index+5] = 'd';
            output[index+6] = 'l';
            output[index+7] = 'y';
            index += 8;
            i += 3;
        }
        else{
            output[index] = input[i];
            index++;
        }
    }

    printf("Translated sentence in English:\n%s", output);

    return 0;
}