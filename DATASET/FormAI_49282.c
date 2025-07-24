//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>

int main() {
    printf("Let's get energized with C!\n");

    // Count from 1 to 10 using a for loop
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Now let's go backwards from 10 to 1 using a while loop!\n");
    int j = 10;
    while (j >= 1) {
        printf("%d ", j);
        j--;
    }
    printf("\n");

    printf("How about we calculate the sum of the first 10 natural numbers using a do-while loop?\n");
    int sum = 0;
    int k = 1;
    do {
        sum += k;
        k++;
    } while (k <= 10);
    printf("The sum of the first 10 natural numbers is: %d\n", sum);

    printf("Let's take this up a notch and create an array of our favorite fruits.\n");
    char fruits[5][10] = {"banana", "apple", "orange", "strawberry", "watermelon"};
    for (int l = 0; l < 5; l++) {
        printf("%s\n", fruits[l]);
    }

    printf("Now, let's add a new fruit to the end of the array using a function.\n");
    char new_fruit[10] = "kiwi";
    addFruit(fruits, new_fruit);
    for (int m = 0; m < 6; m++) {
        printf("%s\n", fruits[m]);
    }

    printf("Wow, we're feeling so energized with this C programming!\n");

    return 0;
}

void addFruit(char arr[][10], char newFruit[]) {
    int len = sizeof(arr)/sizeof(arr[0]); // Get length of array
    for (int i = 0; i < 10; i++) {
        arr[len][i] = newFruit[i];
    }
}