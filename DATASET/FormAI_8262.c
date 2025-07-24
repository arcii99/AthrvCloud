//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int count = 0;
    int total_time = 0;
    char input;
    char words[10][20] = {"apple", "banana", "orange", "grape", "pineapple", "strawberry", "watermelon", "blueberry", "kiwi", "lemon"};
    int random_num = 0;
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the word exactly as it appears on the screen and press Enter.\n");
    printf("Type 'quit' to exit the program.\n");
    srand(time(NULL));
    
    while(1){
        random_num = rand() % 10;
        printf("%s\n",words[random_num]);
        clock_t start = clock();
        scanf("%s", &input);
        
        if(strcmp(&input,"quit") == 0){
            break;
        }
        
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        total_time += time_spent;
        count++;
        
        if(strcmp(&input, words[random_num]) == 0){
            printf("Correct! Time elapsed: %f seconds\n", time_spent);
        }else{
            printf("Incorrect! Time elapsed: %f seconds\n",time_spent);
        }
    }

    printf("Thank you for playing the Typing Speed Test!\n");
    printf("You typed %d word(s) with an average time of %f seconds.\n", count, total_time/count);
    return 0;
}