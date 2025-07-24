//FormAI DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char boot_sequence[100];
    int i, len, vowels=0, consonants=0, uppercase=0, lowercase=0;

    printf("Welcome to the Medieval C System Boot Optimizer\n");
    printf("Please enter the boot sequence:\n");
    scanf("%[^\n]s", boot_sequence);

    len = strlen(boot_sequence);

    printf("\nOptimizing the boot sequence...\n");

    for(i=0;i<len;i++){
        if(isalpha(boot_sequence[i])){
            if(boot_sequence[i] == 'A' || boot_sequence[i] == 'E' || boot_sequence[i] == 'I' || boot_sequence[i] == 'O' || boot_sequence[i] == 'U' || boot_sequence[i] == 'a' || boot_sequence[i] == 'e' || boot_sequence[i] == 'i' || boot_sequence[i] == 'o' || boot_sequence[i] == 'u'){
                vowels++;
            } else {
                consonants++;
            }
            if(isupper(boot_sequence[i])){
                uppercase++;
            } else if(islower(boot_sequence[i])){
                lowercase++;
            }
        }
    }

    printf("\nOptimization complete.\n");
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of uppercase characters: %d\n", uppercase);
    printf("Number of lowercase characters: %d\n", lowercase);

    printf("\nPress any key to continue...");
    getchar();
    return 0;
}