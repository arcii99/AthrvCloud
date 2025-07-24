//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX 100
#define SEC_PER_MIN 60

char words[MAX][MAX] = {"apple", "banana", "cherry", "dandelion", "eggplant", "fruits", "grapes", "happiness", "indigo", "jazz", "kiwi", "laptop", "mountain", "notebook", "ocean", "pencil", "quartz", "rainbow", "snowball", "triangle", "umbrella", "volcano", "watermelon", "xylophone", "yellow", "zebra"};
int n = 26;

int main()
{
    int i;
    int n_words = sizeof(words)/sizeof(words[0]);
    int max_chars = strlen(words[0]);
    int min_chars = strlen(words[0]);
    float total_time = 0;
    float avg_time = 0;
    float typing_speed = 0;

    srand(time(NULL));

    printf("Welcome to Typing Speed Test!\n");
    printf("You will have to type the given words correctly within 1 minute\n");
    printf("Press Enter to start the test\n");
    getchar();

    for(i=0; i<10; i++)
    {
        int random_word_index = rand()%n_words;
        printf("%d. %s\n", i+1, words[random_word_index]);
        clock_t start = clock();

        char input[MAX];
        fgets(input, MAX, stdin);

        clock_t end = clock();
        float time_taken = ((float) (end - start))/CLOCKS_PER_SEC;
        total_time += time_taken;

        if(strlen(input) > max_chars)
            max_chars = strlen(input);

        if(strlen(input) < min_chars)
            min_chars = strlen(input);

        if(strncmp(input, words[random_word_index], strlen(words[random_word_index])-1) == 0)
            printf("Correct\n");
        else
        {
            printf("Incorrect\n");
            break;
        }
    }

    avg_time = total_time/10;
    typing_speed = (max_chars*SEC_PER_MIN)/total_time;

    printf("\nResults\n");
    printf("Total time taken: %.2f seconds\n", total_time);
    printf("Average time taken: %.2f seconds\n", avg_time);
    printf("Max characters typed in a word: %d\n", max_chars-1);
    printf("Min characters typed in a word: %d\n", min_chars-1);
    printf("Typing Speed: %.0f WPM\n", typing_speed);

    return 0;
}