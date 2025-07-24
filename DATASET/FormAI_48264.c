//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Here's a fun and unique application of bucket sort:
   We are going to simulate a lottery with it! */

/* The rules:
   1. There are 10 numbers in play, ranging from 1 to 100 inclusive.
   2. Players can choose any 5 numbers from 1 to 100.
   3. The winning numbers are randomly drawn from the same pool of 1 to 100.
   4. The more numbers a player correctly chooses, the higher the prize they win.
   5. If multiple players have the same number of correct choices, the prize is split between them.
   6. We want to print out a leaderboard of players and their prizes. */

/* First, we need a bucket sort implementation. */

void bucket_sort(int arr[], int size, int bucket_size) {
    int i, j;
    int min_val = arr[0], max_val = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int num_buckets = (max_val - min_val) / bucket_size + 1;
    int **buckets = malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = malloc(bucket_size * sizeof(int));
    }
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < bucket_size; j++) {
            buckets[i][j] = 0;
        }
    }
    for (i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min_val) / bucket_size;
        int j = 0;
        while (buckets[bucket_index][j] > 0 && buckets[bucket_index][j] < arr[i]) {
            j++;
        }
        int temp = arr[i];
        while (j < bucket_size) {
            int old_temp = buckets[bucket_index][j];
            buckets[bucket_index][j] = temp;
            temp = old_temp;
            j++;
        }
    }
    int k = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < bucket_size; j++) {
            if (buckets[i][j] > 0) {
                arr[k] = buckets[i][j];
                k++;
            }
        }
    }
    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

/* Now let's write a function to simulate a lottery with 5 players. */

void lottery() {
    int pool[100];
    int i, j;
    for (i = 0; i < 100; i++) {
        pool[i] = i + 1;
    }
    /* Shuffle the pool of numbers randomly. */
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        j = rand() % 100;
        int temp = pool[i];
        pool[i] = pool[j];
        pool[j] = temp;
    }
    int player_choices[5][5];
    int player_names[5] = { 1, 2, 3, 4, 5 };
    int player_prizes[5] = { 0, 0, 0, 0, 0 };
    printf("Welcome to the lottery! The winning numbers are:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", pool[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++) {
        printf("Player %d, choose your 5 numbers from 1 to 100: ", player_names[i]);
        for (j = 0; j < 5; j++) {
            scanf("%d", &player_choices[i][j]);
        }
    }
    printf("Checking results...\n");
    for (i = 0; i < 5; i++) {
        int correct_count = 0;
        for (j = 0; j < 5; j++) {
            int k;
            for (k = 0; k < 5; k++) {
                if (player_choices[i][j] == pool[k]) {
                    correct_count++;
                    break;
                }
            }
        }
        printf("Player %d had %d correct numbers.\n", player_names[i], correct_count);
        switch (correct_count) {
            case 5:
                player_prizes[i] = 100000;
                break;
            case 4:
                player_prizes[i] = 10000;
                break;
            case 3:
                player_prizes[i] = 1000;
                break;
            case 2:
                player_prizes[i] = 100;
                break;
            case 1:
                player_prizes[i] = 10;
                break;
        }
    }
    int sorted_prizes[5];
    for (i = 0; i < 5; i++) {
        sorted_prizes[i] = player_prizes[i];
    }
    bucket_sort(sorted_prizes, 5, 1);
    printf("Leaderboard:\n");
    for (i = 5; i >= 1; i--) {
        printf("%d. ", 6 - i);
        for (j = 0; j < 5; j++) {
            if (sorted_prizes[i - 1] == player_prizes[j]) {
                printf("Player %d wins %d dollars\n", player_names[j], player_prizes[j]);
            }
        }
    }
}

/* Finally, let's put it all together and run the lottery. */

int main() {
    lottery();
    return 0;
}