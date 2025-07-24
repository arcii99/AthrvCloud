//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include<stdio.h>
#include<stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int image[MAX_HEIGHT][MAX_WIDTH], height, width;

void readImage(char*);
void printASCIIArt();

int main(){
    char fileName[20];
    printf("Enter the name of the file: ");
    scanf("%s", fileName);
    readImage(fileName);
    printASCIIArt();
    return 0;
}

void readImage(char *fileName){
    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        printf("File not found!");
        exit(0);
    }
    fscanf(file, "%d %d", &width, &height);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fscanf(file, "%d", &image[i][j]);
        }
    }
    fclose(file);
}

void printASCIIArt(){
    char ASCIIChars[] = {'#', 'M', 'X', 'I', 'O', ';', ',', '.', ' '};
    int intensityRange = 255/10;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int index = image[i][j] / intensityRange;
            printf("%c", ASCIIChars[index]);
        }
        printf("\n");
    }
}