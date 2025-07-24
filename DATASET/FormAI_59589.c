//FormAI DATASET v1.0 Category: Data mining ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

// Define function to find maximum value in an array
int max(int arr[], int n){
    int max_val = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max_val){
            max_val = arr[i];
        }
    }
    return max_val;
}

// Define function to find minimum value in an array
int min(int arr[], int n){
    int min_val = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min_val){
            min_val = arr[i];
        }
    }
    return min_val;
}

// Define function to find average of an array
float avg(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return (float) sum / n;
}

// Define main function
int main(){

    // Define array of player scores
    int player_scores[50] = {22, 38, 72, 55, 64, 12, 8, 45, 51, 29,
                          87, 42, 63, 5, 49, 35, 17, 91, 20, 74,
                          58, 76, 41, 95, 23, 67, 52, 30, 44, 88,
                          33, 79, 81, 68, 10, 48, 6, 16, 60, 70,
                          25, 99, 56, 93, 18, 43, 9, 15, 36, 77};

    // Define variables for data analysis
    int max_score, min_score;
    float avg_score;

    // Find maximum score and display it
    max_score = max(player_scores, 50);
    printf("Highest score: %d\n", max_score);

    // Find minimum score and display it
    min_score = min(player_scores, 50);
    printf("Lowest score: %d\n", min_score);

    // Find average score and display it
    avg_score = avg(player_scores, 50);
    printf("Average score: %.2f\n", avg_score);

    return 0;
}