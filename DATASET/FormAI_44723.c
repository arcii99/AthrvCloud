//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
 
struct clue {
    int value;
    int location;
};
 
void search(int arr[], int n, int key) {
    struct clue clues[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            clues[count].value = arr[i];
            clues[count].location = i;
            count++;
        }
    }
    if (count == 0) {
        printf("Sorry, I have no information about the whereabouts of %d\n", key);
    } else {
        printf("I have uncovered %d clues about the location(s) of %d:\n", count, key);
        for (int i = 0; i < count; i++) {
            printf("Clue #%d: Location %d\n", i+1, clues[i].location);
        }
    }
}
 
int main() {
    printf("Welcome, Sherlock! What would you like to know?\n");
    int arr[10] = {2, 7, 4, 1, 6, 9, 7, 5, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
 
    printf("Please give me a number to search for: ");
    scanf("%d", &key);
 
    search(arr, n, key);
 
    return 0;
}