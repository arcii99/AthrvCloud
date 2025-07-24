//FormAI DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void apocalypse_mode(char c[]);  // function for converting color code in post-apocalyptic style

int main(){
    char c[7]; // Declare a character array to store the color code (for example, #FF5733)
    printf("Enter a color code (In the format of #RRGGBB): "); 
    fgets(c, 7, stdin);

    apocalypse_mode(c); // Call the function to convert color code in post-apocalyptic style
    printf("\nThe post-apocalyptic style code is: %s\n", c);
    return 0;
}

void apocalypse_mode(char c[]){
    // Convert the Red component to max value
    c[1] = 'F'; 
    c[2] = 'F';

    // Convert the Green component to max value
    c[3] = 'F'; 
    c[4] = 'F';

    // Convert the Blue component to a random value in the range of red and green values
    int r = strtol(&c[1], NULL, 16); // extract the Red component value
    int g = strtol(&c[3], NULL, 16); // extract the Green component value
    int b = (rand() % (g - r + 1)) + r; // generate a random value in the range of Red and Green values
    sprintf(&c[5], "%02X", b); // convert the integer value of Blue component to hexadecimal value and store to c[5] and c[6]
}