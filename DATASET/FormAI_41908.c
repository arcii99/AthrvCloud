//FormAI DATASET v1.0 Category: Date and time ; Style: mathematical
#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *tm_now;
    char s_now_time[100];
    double d_pi = 3.14159265358979323846;
    int i_num1 = 10, i_num2 = 5, i_result = 0;

    // get current time
    time(&now);
    tm_now = localtime(&now);

    // format current time
    strftime(s_now_time, sizeof(s_now_time), "%Y-%m-%d %H:%M:%S", tm_now);

    printf("The current date and time is: %s\n", s_now_time);

    // calculate area of circle
    double d_radius = 5;
    double d_area = d_pi * d_radius * d_radius;

    printf("The area of a circle with radius %lf is: %lf\n", d_radius, d_area);

    // perform addition and subtraction of two numbers
    i_result = i_num1 + i_num2;
    printf("%d + %d = %d\n", i_num1, i_num2, i_result);

    i_result = i_num1 - i_num2;
    printf("%d - %d = %d\n", i_num1, i_num2, i_result);

    return 0;
}