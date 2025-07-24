//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>

/* This program calculates the average score for a class of students. */

int main() {
    int numOfStudents, score, totalScore = 0;
    double averageScore;
    
    printf("Enter the number of students: ");
    scanf("%d", &numOfStudents);
    
    for (int i = 1; i <= numOfStudents; i++) {
        printf("Enter the score for student %d: ", i);
        scanf("%d", &score);
        totalScore += score;
    }
    
    averageScore = (double) totalScore / numOfStudents;
    
    printf("The average score for the class is %.2f\n", averageScore);
    
    if (averageScore > 80) {
        printf("Great job! The class performed exceptionally well.\n");
    } else if (averageScore > 60) {
        printf("Not bad! The class performed above average.\n");
    } else {
        printf("There is room for improvement. The class could do better.\n");
    }
    
    return 0;
}