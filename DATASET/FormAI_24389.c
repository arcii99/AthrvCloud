//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>

// Define ASCII art array
char ascii[10][10] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

// Function to print ASCII art
void printAsciiArt(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}

int main() {

    //Dummy image array
    char img[50][50];

    //Loop to add random characters to image array
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            img[i][j] = rand() % 256;
        }
    }

    //Loop to convert image array to ASCII art
    for(int i=0; i<50; i+=5){
        for(int j=0; j<50; j+=5){

            //Calculate average pixel value in the block
            int avg = 0;
            for(int k=i; k<i+5; k++){
                for(int l=j; l<j+5; l++){
                    avg += img[k][l];
                }
            }
            avg /= 25;

            //Select ASCII character based on pixel value
            if(avg<50){
                ascii[i/5][j/5] = '#';
            }
            else if(avg<100){
                ascii[i/5][j/5] = '$';
            }
            else if(avg<150){
                ascii[i/5][j/5] = '%';
            }
            else if(avg<200){
                ascii[i/5][j/5] = '&';
            }
            else{
                ascii[i/5][j/5] = '@';
            }
        }
    }

    //Print ASCII art
    printf("Your image in ASCII art form:\n\n");
    printAsciiArt();

    //Done!
    printf("\nAll done! Hope your image looks better in ASCII art form!");
    return 0;
}