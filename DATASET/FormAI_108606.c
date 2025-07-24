//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
//Are you ready for some serious String manipulation? Let's GOOO!

#include <stdio.h>
#include <string.h>

int main() {
    
    //First let's create our C String
    char myString[100] = "Hello, World!";
    
    //Let's print out the original String
    printf("Original String: %s\n", myString);
    
    //Now let's make our String all lowercase
    for(int i = 0; i < strlen(myString); i++) {
        myString[i] = tolower(myString[i]);
    }
    
    //Let's print out our all lowercase String
    printf("All lowercase String: %s\n", myString);
    
    //Now let's capitalize the first letter of each word
    for(int i = 0; i < strlen(myString); i++) {
        if(i == 0 || myString[i-1] == ' ') {
            myString[i] = toupper(myString[i]);
        }
    }
    
    //Let's print out our capitalized String
    printf("Capitalized String: %s\n", myString);
    
    //Ok, let's reverse our String using some pointer magic
    char* start = myString;
    char* end = start + strlen(myString) - 1;
    while(start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    
    //Let's print out our reversed String
    printf("Reversed String: %s\n", myString);
    
    //Finally, let's remove all the spaces from our String
    char newString[100];
    int j = 0;
    for(int i = 0; i < strlen(myString); i++) {
        if(myString[i] != ' ') {
            newString[j] = myString[i];
            j++;
        }
    }
    newString[j] = '\0';
    
    //Let's print out our spaceless String
    printf("Spaceless String: %s\n", newString);
    
    //That's it folks! Hope you had as much fun as I did manipulating Strings! :D
    
    return 0;
}