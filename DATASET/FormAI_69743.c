//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
    int height, width, i, j;
    printf("Enter height and width of pattern (both should be even and greater than 4): ");
    scanf("%d %d", &height, &width);

    //check if height and width entered are even and greater than 4
    if(height % 2 != 0 || width % 2 != 0 || height <= 4 || width <= 4){
        printf("Invalid input! Height and width should be even and greater than 4.");
        return 0;
    }

    int midheight = height/2;
    int midwidth = width/2;

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            if(i==0 || i==height-1){ //print top and bottom border
                printf("*");
            }
            else if(j==0 || j==width-1){ //print left and right border
                printf("*");
            }
            else if(i==midheight-1 && j>0 && j<midwidth){ //print letter C in top left
                printf("C");
                j++;
            }
            else if(i==midheight && j>0 && j<midwidth){ //print letter C in bottom left
                printf("C");
                j++;
            }
            else if(i==midheight-1 && j>midwidth && j<width-1){ //print letter C in top right
                printf("C");
                j++;
            }
            else if(i==midheight && j>midwidth && j<width-1){ //print letter C in bottom right
                printf("C");
                j++;
            }
            else{
                printf(" "); //print space for empty spaces in pattern
            }
        }
        printf("\n"); //move to next row
    }
    return 0;
}