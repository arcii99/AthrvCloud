//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    int num_of_logs, base;
    printf("Enter the number of logs you want to analyze: ");
    scanf("%d", &num_of_logs);

    printf("Enter the base of the logs: ");
    scanf("%d", &base);

    double logs[num_of_logs];
    printf("Enter the logs: ");

    for(int i=0; i<num_of_logs; i++) {
        scanf("%lf", &logs[i]);
    }

    double sum_of_logs = 0.0;
    double log_sum;

    for(int i=0; i<num_of_logs; i++) {
        sum_of_logs += logs[i];
    }

    log_sum = sum_of_logs / num_of_logs;

    double standard_deviation = 0.0;
    double logarithmic_variance;

    for(int i=0; i<num_of_logs; i++) {
        standard_deviation += pow(logs[i] - log_sum, 2);
    }

    logarithmic_variance = standard_deviation / num_of_logs;

    double log_mean = log_sum / log10(base);
    double log_variance = logarithmic_variance / log10(base);

    printf("The log mean is %.3lf\n", log_mean);
    printf("The log variance is %.3lf\n", log_variance);
    return 0;
}