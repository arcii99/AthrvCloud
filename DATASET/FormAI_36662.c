//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rgb[3];
    char colorCode[7];
    printf("Enter the color code in RGB format: ");
    scanf("%s", colorCode);
    for(int i=0; i<6; i+=2){
        char temp[3];
        for(int j=0; j<2; j++){
            temp[j] = colorCode[i+j];
        }
        rgb[i/2] = strtol(temp, NULL, 16);
    }
    printf("The rgb values are: %d, %d, %d\n", rgb[0], rgb[1], rgb[2]);
    return 0;
}