//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include<stdio.h>
#include<string.h>

int main(){
    char names[4][30] = {"John", "Sarah", "Michael", "Katie"};
    char buffer[30];

    // printing names before sorting
    printf("Names before sorting: \n");
    for(int i=0; i<4; i++){
        printf("%s\n", names[i]);
    }

    // sorting the names
    for(int i=0; i<3; i++){
        for (int j=i+1; j<4; j++){
            if(strcmp(names[i], names[j]) > 0){
                strcpy(buffer, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], buffer);
            }
        }
    }

    // printing names after sorting
    printf("Names after sorting: \n");
    for(int i=0; i<4; i++){
        printf("%s\n", names[i]);
    }

    //concatenating strings
    char string1[50] = "Hello";
    char string2[30] = " world";
    strcat(string1, string2);
    printf("%s\n", string1);

    //copying the string
    char source[50] = "This is a source string";
    char destination[50];
    strcpy(destination, source);
    printf("The destination string is: %s", destination);

    //finding the length of a string
    char message[100] = "This is a long message";
    int length = strlen(message);
    printf("The length of the message is: %d", length);

    return 0;
}