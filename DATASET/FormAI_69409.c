//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input_string[100], message[500];
    int i,j, ascii, height=5, width=6;

    printf("Enter a message: ");
    fgets(input_string, 100, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    int len = strlen(input_string);

    for(i=0; i<height; i++){
        for(j=0; j<len*(width-1); j++){
            message[i*(len*(width-1))+j] = ' ';
        }
        message[i*(len*(width-1))+(len*(width-1))] = '\n';
    }
    message[height*(len*(width-1))] = '\0';

    for(i=0; i<len; i++){
        ascii = (int) input_string[i];
        for(j=0; j<5; j++){
            switch(ascii){
                case 32:
                    message[(j*len*(width-1))+(i*(width-1))+1] = ' ';
                    message[(j*len*(width-1))+(i*(width-1))+2] = ' ';
                    message[(j*len*(width-1))+(i*(width-1))+3] = ' ';
                    break;
                case 33:
                    message[(j*len*(width-1))+(i*(width-1))+1] = ' ';
                    message[(j*len*(width-1))+(i*(width-1))+2] = '|';
                    message[(j*len*(width-1))+(i*(width-1))+3] = '|';
                    break;

                //more cases for more characters...

                default:
                    printf("Invalid character!\n");
                    return 1;
            }
            message[(j*len*(width-1))+(i*(width-1))] = '/';
            message[(j*len*(width-1))+(i*(width-1))+4] = '\\';
        }
    }

    printf("\n%s\n", message);
    return 0;
}