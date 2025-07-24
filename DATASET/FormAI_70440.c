//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// function to get CPU usage percentage
float get_cpu_usage()
{
    FILE *fp;
    char path[1035];

    fp = popen("ps aux | awk 'NR > 0 { s +=$3 }; END {print s}'", "r");
    if (fp == NULL) {
        printf("Failed to execute command\n");
        exit(1);
    }

    fgets(path, sizeof(path)-1, fp);

    pclose(fp);

    return atof(path);
}

int main()
{
    int counter = 0;
    bool is_cheerful = true;

    printf("Welcome to CPU Usage Monitor!\n\n");

    while (is_cheerful && counter < 10) {
        float usage = get_cpu_usage();

        printf("Current CPU usage: %.2f %%\n\n", usage);

        if (usage > 90.0) {
            printf("CPU usage is too high! Let's take a break and do some dancing!\n\n");
            printf("    (o^^)o     (o^^o)     (o^^o)     (o^^o)     (o^^o)\n");
            printf("    (@^^)/     (-^^-)==$  (-^^-)      (-^^-)     (-^^-)\n");
            printf("     ^^        ^^   ^^   ^^   ^^     ^^   ^^    ^^   ^^ \n\n");

            printf("Okay, we're back! Let's get back to work!\n\n");
            usleep(1000000);
        } else {
            printf("Things are looking good! Let's keep going!\n\n");
            usleep(500000);
        }

        counter++;
    }

    printf("Thanks for using CPU Usage Monitor! Have a great day!\n");

    return 0;
}