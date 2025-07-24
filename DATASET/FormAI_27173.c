//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int signal_strengths[10] = {-50, -60, -65, -72, -80, -85, -90, -92, -95, -100};
    double dbm, mw;
    int i;
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("Signal Strength\t|\tDBM\t|\tMilliwatts\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < 10; i++) {
        dbm = signal_strengths[i];
        mw = pow(10, (dbm - 30) / 10);
        printf("\t%d\t\t|\t%.1f\t|\t%.5f\n", signal_strengths[i], dbm, mw);
    }
    return 0;
}