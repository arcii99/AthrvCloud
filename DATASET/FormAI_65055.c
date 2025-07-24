//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
// It was just after midnight when Sherlock Holmes began to pore over the code in his study. 
// The dim light of his oil lamp flickered as he typed away on his keyboard, his mind intent 
// on the task at hand.

#include <stdio.h>

// Suddenly, a sound broke the silence. It was a familiar sound - the tapping of a cane on the 
// cobblestones. Sherlock recognized the sound immediately and knew without a doubt who was 
// coming up the stairs.

int recursive_factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * recursive_factorial(n - 1);
    }
}

int main() {
    // "Ah, Watson," said Sherlock as his friend burst into the room. "I see you've brought 
    // your trusty sidekick with you." 

    printf("Enter a number to find its factorial: ");
    int num;
    scanf("%d", &num);
    int result = recursive_factorial(num);
    printf("The factorial of %d is %d\n", num, result);

    // Watson chuckled as he patted his dog on the head. "Always good to have Backup, don't you think?"

    return 0;
}

// And so, the two friends worked late into the night, solving yet another mystery of the 
// programming world.