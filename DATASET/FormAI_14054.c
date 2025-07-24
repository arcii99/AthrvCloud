//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>

// Calculates the checksum of the given string
int checksum(char* string){
    int sum = 0;
    for(int i = 0; string[i] != '\0'; i++){
        sum += (int)string[i];
    }
    return sum % 256;
}

int main(){
    char* message = "Hello World";
    int check = checksum(message);
    printf("The checksum of the message '%s' is %d\n", message, check);   
    return 0;
}