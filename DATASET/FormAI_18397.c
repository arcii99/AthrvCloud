//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main() {

    char* data = "CyBearPunk"; //data to be used for checksum calculation
    int checksum = 0; //initializing checksum to 0

    //iterating through the data and calculating the checksum
    for(int i=0; i<strlen(data); i++) {
        if(isalpha(data[i])) { //if the character is an alphabet
            if(isupper(data[i])) { //if the alphabet is upper case
                checksum += (int)data[i] - 64; //add the ASCII value of the alphabet minus 64
            }
            else { //if the alphabet is lower case
                checksum += (int)data[i] - 96; //add the ASCII value of the alphabet minus 96
            }
        }
        else { //if the character is not an alphabet
            checksum += (int)data[i]; //add the ASCII value of the character
        }
    }

    printf("Checksum of \"%s\" is %d\n", data, checksum); //print the checksum value

    return 0; //end of program
}