//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j;
    char text[100];

    printf("Enter the text: ");
    fgets(text,100,stdin); //Taking input from user

    char ascii[8][100]={  //Creating ASCII Art using 8x100 array
        {"  _____     _        _        _____           _         "},
        {" |  __ \\   | |      | |      / ____|         (_)        "},
        {" | |__) |__| |_ __ _| |__   | |     ___  _ __ _ _ __    "},
        {" |  _  / / _` | '__| | '_ \\  | |    / _ \\| '__| | '_ \\ "},
        {" | | \\ \\| (_| | |  | | |_) | | |___| (_) | |  | | |_) |"},
        {" |_|  \\_\\\\__,_|_|  |_|_.__/   \\_____\\___/|_|  |_| .__/ "},
        {"                                                 | |    "},
        {"                                                 |_|    "}
    };

    for(i=0;i<8;i++){      //Printing the ASCII Art with the entered text
        for(j=0;j<100;j++){
            if(ascii[i][j]=='#' && text[(j/8)]!='\n' && text[(j/8)]!='\0'){
                printf("%c",text[(j/8)]);    //Replaces # with the entered text character
            }
            else{
                printf("%c",ascii[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}