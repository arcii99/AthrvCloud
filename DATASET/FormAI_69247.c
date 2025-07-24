//FormAI DATASET v1.0 Category: Calculator ; Style: statistical
#include <stdio.h>
#include <math.h>

//Function Declarations
double average(double data[], int n);
double variance(double data[], int n);
double standard_deviation(double data[], int n);
double covariance(double x[], double y[], int n);
double correlation_coefficient(double x[], double y[], int n);
double slope(double x[], double y[], int n);
double y_intercept(double x[], double y[], int n);

int main()
{
    int n, i;
    double x[50], y[50], avg_x, avg_y, var_x, var_y, cov, cc, m, c;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    printf("Enter the data for x: ");
    for(i=0; i<n; i++)
    {
        scanf("%lf", &x[i]);
    }
    
    printf("Enter the data for y: ");
    for(i=0; i<n; i++)
    {
        scanf("%lf", &y[i]);
    }
    
    avg_x = average(x, n);
    avg_y = average(y, n);
    
    var_x = variance(x, n);
    var_y = variance(y, n);
    
    cov = covariance(x, y, n);
    
    cc = correlation_coefficient(x, y, n);
    
    m = slope(x, y, n);
    c = y_intercept(x, y, n);
    
    printf("\n\nThe Statistical Analysis of Data:\n\n");
    
    printf("Average of x = %lf\n", avg_x);
    printf("Average of y = %lf\n", avg_y);
    
    printf("Variance of x = %lf\n", var_x);
    printf("Variance of y = %lf\n", var_y);
    
    printf("Covariance of x and y = %lf\n", cov);
    printf("Correlation Coefficient of x and y = %lf\n", cc);
    
    printf("Regression Line:\n");
    printf("y = %lfx + %lf\n", m, c);
    
    return 0;
}

double average(double data[], int n)
{
    int i;
    double sum = 0;
    
    for(i=0; i<n; i++)
    {
        sum += data[i];
    }
    
    return (sum/n);
}

double variance(double data[], int n)
{
    int i;
    double mean, variance = 0;
    
    mean = average(data, n);
    
    for(i=0; i<n; i++)
    {
        variance += pow(data[i]-mean, 2);
    }
    
    return (variance/n);
}

double standard_deviation(double data[], int n)
{
    return (sqrt(variance(data, n)));
}

double covariance(double x[], double y[], int n)
{
    int i;
    double mean_x, mean_y, covariance = 0;
    
    mean_x = average(x, n);
    mean_y = average(y, n);
    
    for(i=0; i<n; i++)
    {
        covariance += ((x[i]-mean_x) * (y[i]-mean_y));
    }
    
    return (covariance/n);
}

double correlation_coefficient(double x[], double y[], int n)
{
    double cov = covariance(x, y, n);
    double sd_x = standard_deviation(x, n);
    double sd_y = standard_deviation(y, n);
    
    return (cov / (sd_x * sd_y));
}

double slope(double x[], double y[], int n)
{
    double cov = covariance(x, y, n);
    double var_x = variance(x, n);
    
    return (cov / var_x);
}

double y_intercept(double x[], double y[], int n)
{
    double m = slope(x, y, n);
    double mean_x = average(x, n);
    double mean_y = average(y, n);
    
    return (mean_y - (m*mean_x));
}