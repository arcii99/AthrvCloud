//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);

    char str[n+1], compare_str[n+1];
    int i;
    for(i=0;i<n;i++){
        str[i] = (rand()%26)+'a';
    }
    str[i] = '\0';
    printf("Type the following string:\n%s\n", str);

    clock_t t;
    t = clock();

    scanf("%s", compare_str);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    int flg = strcmp(str, compare_str);
    if(!flg){
        printf("Matching strings!!\n");
        double typing_speed = n/(time_taken/60);
        printf("Congratulations! You have typed at a speed of %.2f words per minute.\n", typing_speed);
    }
    else{
        printf("Oops! Strings do not match.\n");
    }
    return 0;
}