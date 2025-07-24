//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(char* array, int size){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        int r = rand()%size;
        char temp = array[i];
        array[i] = array[r];
        array[r] = temp;
    }
}

int main(){
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    int length = sizeof(sentence)/sizeof(sentence[0])-1; //minus 1 to exclude the null character
    shuffle(sentence, length); //shuffle the sentence
    printf("Welcome to the Typing Speed Test!\n\nType the following sentence as fast as you can:\n\n%s\n\n", sentence);
    printf("Press ENTER when you are ready to start...");
    getchar(); //wait for user to press enter
    
    time_t start = time(NULL); //get current time
    char input[length]; 
    fgets(input, length, stdin); //get user input
    time_t end = time(NULL); //get current time again
    double time = difftime(end, start); //calculate time taken
    
    int errors = 0;
    for(int i=0; i<length; i++){
        if(sentence[i] != input[i]){
            errors++;
        }
    }
    int words_per_minute = ((length-errors)*60.0)/(5*time); //calculate the typing speed in words per minute
    
    printf("You completed the typing test in %.2f seconds.\n", time);
    if(errors == 0){
        printf("Congratulations! You made no mistakes.\n");
    }
    else{
        printf("You made %d mistake(s).\n", errors);
    }
    printf("Your typing speed: %d words per minute.\n", words_per_minute);
    
    return 0;
}