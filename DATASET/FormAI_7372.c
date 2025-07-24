//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    char user_input[100];
    int i, count = 0, flag = 0;

    printf("Welcome to the C Word Count Tool\n");
    printf("Please enter your sentence: ");
    fgets(user_input, 100, stdin);

    for(i=0; i<strlen(user_input); i++) {
        if(isalpha(user_input[i])) {
            if(flag == 0) {
                count++;
                flag = 1;
            }
        }
        else {
            flag = 0;
        }
    }

    printf("\nYour sentence contains %d words\n", count);

    if(count == 0) {
        printf("Seriously, not even a single word? C'mon dude!\n");
    }
    else if(count<5) {
        printf("Ha! You call that a sentence? That's just %d words\n", count);
    }
    else if(count>=5 && count<10) {
        printf("Not bad, you managed to write %d words\n", count);
    }
    else if(count>=10 && count<20){
        printf("Wow! You really put some effort into that. %d words and counting.\n", count);
    }
    else {
        printf("Slow down there, Shakespeare! %d words is quite the achievement!\n", count);
    }

    return 0;
}