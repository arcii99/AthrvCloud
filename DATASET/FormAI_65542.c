//FormAI DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C System boot optimizer!\n\n");

    int numProcs, numApps, numServices;
    printf("Enter the number of processes running at boot: ");
    scanf("%d", &numProcs);
    printf("Enter the number of applications running at boot: ");
    scanf("%d", &numApps);
    printf("Enter the number of services running at boot: ");
    scanf("%d", &numServices);

    int totalProcs = numProcs + numApps + numServices;

    printf("\nTotal processes running at boot: %d\n", totalProcs);

    if (totalProcs <= 10) {
        printf("Your system is optimized for boot time! Good job.\n");
    } else if (totalProcs <= 15) {
        printf("Your system could use some optimization to reduce boot time.\n");
        printf("Consider disabling unnecessary services and applications to improve performance.\n");
    } else {
        printf("Your system is overloaded at boot time. It's time for some serious cleanup.\n");
        printf("Consider uninstalling some applications and disabling many services to improve performance.\n");
    }

    return 0;
}