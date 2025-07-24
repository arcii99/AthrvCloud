//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <string.h>

int main(){

    char str1[20] = "Hello, ";
    char str2[10] = "World!";
    char result[30];
    
    strcat(result, str1); // concatenating str1 and str2 into result
    strcat(result, str2);

    printf("Original string 1: %s\n", str1);
    printf("Original string 2: %s\n", str2);
    printf("Concatenated string: %s\n", result);

    // Finding the length of result string
    printf("Length of concatenated string: %d\n", strlen(result));

    // Reversing the result string
    char reverse[30];
    int i, j;
    
    j = 0;
    for(i=strlen(result)-1; i>=0; i--){
        reverse[j] = result[i];
        j++;
    }
    // Adding null terminator to the end of the reverse string
    reverse[j] = '\0';

    printf("Reversed string: %s\n", reverse);

    // Removing the comma from the result string
    char commaRemoved[30];
    int k = 0;
    for(i=0; i<strlen(result); i++){
        if(result[i] != ','){
            commaRemoved[k] = result[i];
            k++;
        }
    }
    // Adding null terminator to the end of the commaRemoved string
    commaRemoved[k] = '\0';

    printf("String without comma: %s\n", commaRemoved);

    // Changing the case of the result string
    char caseChanged[30];
    for(i=0; i<strlen(result); i++){
        if(result[i] >= 'a' && result[i] <= 'z'){
            caseChanged[i] = result[i] - 32; // converting lower case to upper case
        }
        else if(result[i] >= 'A' && result[i] <= 'Z'){
            caseChanged[i] = result[i] + 32; // converting upper case to lower case
        }
        else{
            caseChanged[i] = result[i];
        }
    }
    // Adding null terminator to the end of the caseChanged string
    caseChanged[i] = '\0';

    printf("String with case changed: %s\n", caseChanged);

    return 0;
}