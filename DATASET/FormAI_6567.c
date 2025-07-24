//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include<stdio.h>

int main(){
    char sentence[1000];
    int count=1, i;

    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter your sentence:\n");

    fgets(sentence, 1000, stdin);

    for(i=0; sentence[i]!='\0'; i++){
        if(sentence[i]==' '){
            count++;
        }
    }

    printf("Your sentence has %d words!\n", count);

    printf("Would you like to count another sentence?(y/n): ");
    char choice=getchar();
    while(getchar()!='\n');

    if(choice=='y'){
        main();
    }
    else{
        printf("Thank you for using the C Word Count Tool!\n");
        return 0;
    }
}