//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>

int main(){
    //Input String
    char str[1000];
    printf("Enter a string:\n");
    fgets(str, 1000, stdin);

    //Remove white spaces from the string
    char new_str[1000];
    int j = 0;
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';

    //Convert all characters to uppercase and store in another string
    char uppercase_str[1000];
    for(int i=0; new_str[i] != '\0'; i++){
        if(new_str[i] >= 'a' && new_str[i] <= 'z'){
            uppercase_str[i] = new_str[i] - 32; //convert lowercase to uppercase
        }
        else{
            uppercase_str[i] = new_str[i];
        }
    }
    uppercase_str[j] = '\0';

    //Find the length of the string
    int length = 0;
    for(int i=0; uppercase_str[i] != '\0'; i++){
        length++;
    }

    //Reverse the string and store in another string
    char reverse_str[1000];
    int k = length-1;
    for(int i=0; i<length; i++){
        reverse_str[i] = uppercase_str[k];
        k--;
    }
    reverse_str[length] = '\0';

    //Concatenate the original string and the reversed string and store in another string
    char concat_str[2000];
    int l = 0;
    for(int i=0; str[i] != '\0'; i++){
        concat_str[l] = str[i];
        l++;
    }
    for(int i=0; reverse_str[i] != '\0'; i++){
        concat_str[l] = reverse_str[i];
        l++;
    }
    concat_str[l] = '\0';

    printf("Original String: %s", str);
    printf("String without white spaces: %s\n", new_str);
    printf("Uppercase String: %s\n", uppercase_str);
    printf("Reversed String: %s\n", reverse_str);
    printf("Concatenated String: %s\n", concat_str);

    return 0;
}