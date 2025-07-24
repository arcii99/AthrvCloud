//FormAI DATASET v1.0 Category: Text processing ; Style: modular
#include<stdio.h>
#include<string.h>

//Module that finds the number of vowels in a given string
int count_vowels(char *str){
    int count = 0;
    for(int i=0; i<strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count += 1;
        }
    }
    return count;
}

//Module that finds the number of consonants in a given string
int count_consonants(char *str){
    int count = 0;
    for(int i=0; i<strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
            if(!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')){
                count += 1;
            }
        }
    }
    return count;
}

//Module that finds the number of digits in a given string
int count_digits(char *str){
    int count = 0;
    for(int i=0; i<strlen(str); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            count += 1;
        }
    }
    return count;
}

int main(){
    char input_str[100];
    printf("Enter a string: ");
    fgets(input_str, sizeof(input_str), stdin); //Taking user input with fgets()
    input_str[strcspn(input_str, "\n")] = 0;  //Removing the trailing newline character

    printf("Number of vowels: %d\n", count_vowels(input_str));
    printf("Number of consonants: %d\n", count_consonants(input_str));
    printf("Number of digits: %d\n", count_digits(input_str));

    return 0;
}