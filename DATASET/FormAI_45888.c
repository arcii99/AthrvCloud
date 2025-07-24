//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Romeo and Juliet
/* Romeo and Juliet: An Internet Speed Test Application */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int downloadSpeed()
{
    int speed, delay;
    srand(time(NULL));
    speed = rand() % 100 + 1;
    delay = rand() % 5 + 1;
    
    printf("My love, tis the hour of testing our download speed.\n");
    printf("Our love may be swift as the wind, but our downloads need speed.\n");
    printf("Let us see if the gods bless us with a score of good speed.\n");

    printf("Calculating...\n");
    sleep(delay);

    printf("Our download speed is %d Mbps, my dear Juliet.\n", speed);
    return speed;
}

int uploadSpeed()
{
    int speed, delay;
    srand(time(NULL));
    speed = rand() % 50 + 1;
    delay = rand() % 5 + 1;
    
    printf("My fair lady, the hour grows late, and we must test our upload speed.\n");
    printf("For without good upload speed, our love letters may never reach their destination.\n");
    printf("Let us pray that we receive a score of good speed from the heavens above.\n");

    printf("Calculating...\n");
    sleep(delay);

    printf("Our upload speed is %d Mbps, my lovely Romeo.\n", speed);
    return speed;
}

int main()
{
    int download, upload;

    download = downloadSpeed();
    upload = uploadSpeed();

    printf("My sweet Juliet, our final score is in!\n");
    printf("Our download speed is %d Mbps and our upload speed is %d Mbps.\n", download, upload);
    printf("Our love may be swift, but our internet speeds are not far behind.\n");

    return 0;
}