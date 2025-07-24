//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>

int main() {
    int n; //Number of data points
    printf("How many data points would you like to enter? ");
    scanf("%d", &n);
    int activity[n], happiness[n];
    //Prompt user to enter data points
    for(int i = 0; i < n; i++) {
        printf("Enter the activity and the corresponding happiness level (out of 10) for data point %d:\n", i+1);
        scanf("%d %d", &activity[i], &happiness[i]);
    }
    //Calculate mean activity and happiness level
    float mean_activity = 0.0, mean_happiness = 0.0;
    for(int i = 0; i < n; i++) {
        mean_activity += activity[i];
        mean_happiness += happiness[i];
    }
    mean_activity /= n;
    mean_happiness /= n;
    //Calculate standard deviation of activity and happiness level
    float std_dev_activity = 0.0, std_dev_happiness = 0.0;
    for(int i = 0; i < n; i++) {
        std_dev_activity += (activity[i] - mean_activity)*(activity[i] - mean_activity);
        std_dev_happiness += (happiness[i] - mean_happiness)*(happiness[i] - mean_happiness);
    }
    std_dev_activity /= n;
    std_dev_activity = sqrt(std_dev_activity);
    std_dev_happiness /= n;
    std_dev_happiness = sqrt(std_dev_happiness);
    //Calculate correlation coefficient between activity and happiness level
    float correlation_coefficient = 0.0;
    for(int i = 0; i < n; i++) {
        correlation_coefficient += ((activity[i] - mean_activity)/std_dev_activity)*((happiness[i] - mean_happiness)/std_dev_happiness);
    }
    correlation_coefficient /= n;
    //Use linear regression to predict happiness level for new set of activities
    int new_activity;
    printf("Enter the activity for which you'd like to predict the happiness level: ");
    scanf("%d", &new_activity);
    float prediction = (correlation_coefficient)*(new_activity - mean_activity)*(std_dev_activity/std_dev_happiness) + mean_happiness;
    printf("Based on the data you entered, the predicted happiness level for this activity is %.2f out of 10.", prediction);
    return 0;
}