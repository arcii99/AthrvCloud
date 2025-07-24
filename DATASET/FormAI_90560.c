//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>

char outputCharacters[150][150];

void createLetterH(int rowStart, int colStart){
    int row, col;
    for(row=rowStart;row<rowStart+6;row++){
        for(col=colStart;col<colStart+3;col++){
            outputCharacters[row][col] = '#';
        }
    }
    for(col=colStart+1;col<colStart+2;col++){
        for(row=rowStart+1;row<rowStart+5;row++){
            outputCharacters[row][col] = '#';
        }
    }
    return;
}

void createLetterE(int rowStart, int colStart){
    int row, col;
    for(row=rowStart;row<rowStart+6;row++){
        for(col=colStart;col<colStart+3;col++){
            outputCharacters[row][col] = '#';
        }
    }
    for(row = rowStart+1;row<rowStart+5;row++){
        for(col=colStart+1;col<colStart+2;col++){
            outputCharacters[row][col] = '#';
        }
    }
    return;
}

void createLetterL(int rowStart, int colStart){
    int row, col;
    for(row=rowStart;row<rowStart+6;row++){
        for(col=colStart;col<colStart+3;col++){
            outputCharacters[row][col] = '#';
        }
    }
    for(col=colStart+1;col<colStart+2;col++){
        for(row=rowStart+4;row<rowStart+5;row++){
            outputCharacters[row][col] = '#';
        }
    }
    return;
}

void createLetterO(int rowStart, int colStart){
    int row, col;
    for(row=rowStart;row<rowStart+6;row++){
        for(col=colStart;col<colStart+3;col++){
            outputCharacters[row][col] = '#';
        }
    }
    for(col=colStart+1;col<colStart+2;col++){
        for(row=rowStart+1;row<rowStart+5;row++){
            outputCharacters[row][col] = ' ';
        }
    }
    return;
}

void createText(char* inputString, int rowStart, int colStart){
    int currentIndex;
    for(currentIndex=0;currentIndex<strlen(inputString);currentIndex++){
        switch(inputString[currentIndex]){
            case 'h': createLetterH(rowStart, colStart); break;
            case 'e': createLetterE(rowStart, colStart); break;
            case 'l': createLetterL(rowStart, colStart); break;
            case 'o': createLetterO(rowStart, colStart); break;
            default: break;
        }
        colStart+=5;
    }
    return;
}

int main(void) {
    int currentIndex, rowIndex, colIndex;
    
    for(rowIndex=0;rowIndex<150;rowIndex++){
        for(colIndex=0;colIndex<150;colIndex++){
            outputCharacters[rowIndex][colIndex] = ' ';
        }
    }
    
    createText("hello", 5, 5);
    
    for(rowIndex=0;rowIndex<150;rowIndex++){
        for(colIndex=0;colIndex<150;colIndex++){
            printf("%c", outputCharacters[rowIndex][colIndex]);
        }
        printf("\n");
    }
    
    return 0;
}