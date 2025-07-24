//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>

void generateAsciiArt(int fontWidth, int fontHeight, char* text){
    int charWidth = fontWidth + 1;
    int numChars = strlen(text);
    int ascii[numChars][fontHeight + 2];

    //initialize ascii array
    for(int i=0; i<numChars; i++){
        for(int j=0; j<fontHeight+2; j++){
            ascii[i][j] = 0;
        }
    }

    //convert text to ascii art
    for(int i=0; i<numChars; i++){
        int asciiVal = (int)text[i];
        char asciiChar = text[i];

        //handle whitespace
        if(asciiVal == 32){
            for(int j=0; j<fontHeight+2; j++){
                ascii[i][j] = 0;
            }
        }
        //handle letters and numbers
        else if((asciiVal >= 48 && asciiVal <= 57) || (asciiVal >= 65 && asciiVal <= 90) || (asciiVal >= 97 && asciiVal <= 122)){
            FILE *fptr;
            char fileName[15];
            sprintf(fileName, "%c.txt", asciiChar);
            fptr = fopen(fileName, "r");

            if(fptr == NULL){
                printf("Error opening file\n");
                exit(1);
            }

            char line[255];
            int lineNum = 0;

            while(fgets(line, sizeof(line), fptr)){
                int lineLength = strlen(line);
                for(int j=0; j<lineLength-1; j++){
                    if(line[j] == '#'){
                        ascii[i][(lineNum + 1)] |= (1 << j);
                    }
                }
                lineNum++;
            }

            fclose(fptr);
        }
        //handle all other characters
        else{
            for(int j=0; j<fontHeight+2; j++){
                ascii[i][j] = 0;
            }
        }
    }

    //print ascii art
    for(int j=0; j<fontHeight+2; j++){
        for(int i=0; i<numChars; i++){
            for(int k=fontWidth-1; k>=0; k--){
                if(ascii[i][j] & (1 << k)){
                    printf("#");
                }
                else{
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int fontWidth = 5;
    int fontHeight = 8;
    char* text = "Hello World!";

    generateAsciiArt(fontWidth, fontHeight, text);

    return 0;
}