//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main(){
    char hex[7]; // hexadecimal string input
    int rgb[3]; // output RGB values
    int i, j; // iterator variables

    printf("Enter hexadecimal color code: #");
    scanf("%s", hex);

    for(i=0; i<3; i++){ // loop through each pair of hex digits
        char curHex[3] = {hex[i*2], hex[i*2+1], '\0'}; // extract current pair of hex digits
        int curDec; // current decimal value

        for(j=0; j<2; j++){ // convert each hex digit to decimal value
            char curChar = curHex[j];
            if(curChar >= '0' && curChar <= '9'){
                curDec += curChar - '0';
            }
            else if(curChar >= 'a' && curChar <= 'f'){
                curDec += curChar - 'a' + 10;
            }
            else if(curChar >= 'A' && curChar <= 'F'){
                curDec += curChar - 'A' + 10;
            }
            curDec *= 16;
        }
        curDec /= 16;

        rgb[i] = curDec; // add current decimal value to output RGB value array
    }

    printf("\nRGB values are: %d, %d, %d", rgb[0], rgb[1], rgb[2]);

    return 0;
}