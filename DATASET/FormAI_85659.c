//FormAI DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int biosTime, osTime, bootTime, totalTime;
    srand(time(NULL));
    
    // simulate BIOS loading time
    biosTime = rand() % 5 + 1;
    printf("BIOS loading... (%d seconds)\n", biosTime);
    
    // simulate OS loading time
    osTime = rand() % 10 + 1;
    printf("OS loading... (%d seconds)\n", osTime);
    
    // simulate program loading time
    // here you can add your own program files to optimize
    int numPrograms = 3;
    int programTimes[numPrograms];
    char* programNames[numPrograms];
    programTimes[0] = rand() % 6 + 1;
    programNames[0] = "Chrome Browser";
    programTimes[1] = rand() % 8 + 1;
    programNames[1] = "Microsoft Word";
    programTimes[2] = rand() % 4 + 1;
    programNames[2] = "Notepad++";
    
    int totalProgramTime = 0;
    for (int i = 0; i < numPrograms; i++)
    {
        totalProgramTime += programTimes[i];
    }
    
    printf("Programs loading...\n");
    for (int i = 0; i < numPrograms; i++)
    {
        printf("%s... (%d seconds)\n", programNames[i], programTimes[i]);
    }
    
    // calculate total boot time
    bootTime = biosTime + osTime + totalProgramTime;
    totalTime = bootTime;
    
    printf("Total boot time: %d seconds\n", totalTime);
    
    // optimize boot time
    if (totalTime > 30)
    {
        printf("Optimizing boot time...\n");
        
        // close unnecessary programs
        int numToClose = 0;
        for (int i = 0; i < numPrograms; i++)
        {
            if (programTimes[i] > 3)
            {
                numToClose++;
            }
        }
        
        if (numToClose > 0)
        {
            printf("Closing %d programs...\n", numToClose);
            
            for (int i = 0; i < numPrograms; i++)
            {
                if (programTimes[i] > 3)
                {
                    printf("Closing %s\n", programNames[i]);
                    programTimes[i] = 0;
                    numToClose--;
                    
                    if (numToClose == 0)
                    {
                        break;
                    }
                }
            }
        }
        
        // recalculate total boot time
        totalProgramTime = 0;
        for (int i = 0; i < numPrograms; i++)
        {
            totalProgramTime += programTimes[i];
        }
        
        bootTime = biosTime + osTime + totalProgramTime;
        totalTime = bootTime;
    }
    
    printf("Optimized boot time: %d seconds\n", totalTime);
    
    return 0;
}