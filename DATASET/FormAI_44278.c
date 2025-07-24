//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int typing_speed(int accu, int total_count, int time){

    int curr_count = rand()%10+1;
    int curr_time = rand()%10+1;

    total_count += curr_count;
    time += curr_time;

    printf("Type the following sentence:\n");

    char sentence[100] = "The quick brown fox jumps over the lazy dog";
    for(int i=0; i<100; i++){
        printf("%c", sentence[i]);
    }

    printf("\nType the sentence: ");

    char user_input[100];
    fgets(user_input, 100, stdin);

    user_input[strcspn(user_input, "\n")] = 0;

    int i=0;
    int correct = 0;
    while(user_input[i]!='\0' && sentence[i]!='\0'){

        if(user_input[i]==sentence[i]){
            correct++;
        }
        i++;
    }

    printf("Accuracy: %d%%\n", (correct*100)/i);

    accu += (correct*100)/i;

    if(time>60){
        printf("\nYour typing speed is: %d wpm\n", (total_count*60)/(5*time));
        printf("Your average accuracy is: %d%%\n", accu/5);
        return 0;
    }
    else{
        return typing_speed(accu, total_count, time);
    }
}

int main(){

    srand(time(0));
    printf("Welcome to the Recursive Typing Speed Test!\n");

    int accu = 0;
    int total_count = 0;
    int time = 0;

    typing_speed(accu, total_count, time);

    return 0;
}