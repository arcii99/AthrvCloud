//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    // Let's generate some random data
    srand(time(0));
    int dataset[100];
    for(int i=0;i<100;i++) {
        dataset[i] = rand()%100 + 1;
    }

    // Let's print the dataset for giggles
    printf("The dataset is:\n");
    for(int i=0;i<100;i++) {
        printf("%d ",dataset[i]);
    }
    printf("\n\n");

    // Time to mine some data!
    int max = dataset[0];
    int min = dataset[0];
    float sum = 0.0;
    for(int i=0;i<100;i++) {
        if(dataset[i] > max) {
            max = dataset[i];
        }
        if(dataset[i] < min) {
            min = dataset[i];
        }
        sum += dataset[i];
    }

    // Let's display the results... in a funny way
    printf("The results are in!\n");
    printf("The highest number we found is %d... not as high as you right now though!\n",max);
    printf("The lowest number we found is %d... unlike your standards!\n",min);
    printf("The average of the dataset is %f... but you're above average!\n",sum/100);
    printf("\n");

    // The end of the program... for now!
    printf("That was fun! Let's do it again soon!\n");

    return 0;
}