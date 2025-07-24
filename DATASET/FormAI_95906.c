//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

void generate_ascii(char* input_text, char output_ascii[MAX_HEIGHT][MAX_WIDTH]);

int main(){
    printf("Enter your text: ");
    char input_text[1000];
    fgets(input_text, 1000, stdin);

    char output_ascii[MAX_HEIGHT][MAX_WIDTH];
    generate_ascii(input_text, output_ascii);

    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            printf("%c", output_ascii[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void generate_ascii(char* input_text, char output_ascii[MAX_HEIGHT][MAX_WIDTH]){
    int text_len = strlen(input_text);

    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            output_ascii[i][j] = ' ';
        }
    }

    int row = 0;
    int col = 0;
    for(int i=0; i<text_len; i++){
        if(input_text[i] == '\n'){
            break;
        }
        if(input_text[i] == ' '){
            col++;
        }
        else{
            char ascii_char[10][10];
            if(input_text[i] == 'a'){
                strcpy(ascii_char[0], "    "); 
                strcpy(ascii_char[1], " __ "); 
                strcpy(ascii_char[2], "/  \\"); 
                strcpy(ascii_char[3], "|  |"); 
                strcpy(ascii_char[4], "\\__|"); 
            }
            else if(input_text[i] == 'b'){
                strcpy(ascii_char[0], " _  "); 
                strcpy(ascii_char[1], "| | "); 
                strcpy(ascii_char[2], "| | "); 
                strcpy(ascii_char[3], "| | "); 
                strcpy(ascii_char[4], "|_| "); 
            }
            // add more characters here

            for(int r=0; r<5; r++){
                for(int c=0; c<4; c++){
                    output_ascii[row+r][col+c] = ascii_char[r][c];
                }
            }

            col += 5;
        }
    }
}