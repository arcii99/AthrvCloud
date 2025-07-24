//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w;

    printf("Enter the size of the Remote Control Vehicle (RCV): ");
    scanf("%d %d", &x, &y);

    printf(" RC Vehicle - Simulation \n\n");

    for (i = 0; i <= y + 1; i++)
    {
        for (j = 0; j <= x + 1; j++)
        {
            if (i == 0 || i == y + 1)
            {
                printf("-");
            }
            else if (j == 0 || j == x + 1)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Enter the initial position of the RC vehicle (row column direction): ");
    scanf("%d %d %d", &k, &l, &m);

    while (1)
    {
        printf("Enter the direction of movement (1 - Forward, 2 - Backward, 3 - Left, 4 - Right, 5 - Stop): ");
        scanf("%d", &n);

        if (n == 5)
        {
            break;
        }

        switch (m)
        {
            case 1:
                if (n == 1)
                {
                    if (k == 1)
                    {
                        printf("The RC Vehicle has reached the North end. Cannot move forward.");
                        m = 1;
                    }
                    else
                    {
                        k--;
                    }
                }
                else if (n == 2)
                {
                    if (k == y)
                    {
                        printf("The RC Vehicle has reached the South end. Cannot move forward.");
                        m = 1;
                    }
                    else
                    {
                        k++;
                    }
                }
                else if (n == 3)
                {
                    if (l == 1)
                    {
                        printf("The RC Vehicle has reached the West end. Cannot move left.");
                        m = 1;
                    }
                    else
                    {
                        l--;
                        m = 3;
                    }
                }
                else if (n == 4)
                {
                    if (l == x)
                    {
                        printf("The RC Vehicle has reached the East end. Cannot move right.");
                        m = 1;
                    }
                    else
                    {
                        l++;
                        m = 4;
                    }
                }
                break;

            case 2:
                if (n == 1)
                {
                    if (k == y)
                    {
                        printf("The RC Vehicle has reached the South end. Cannot move forward.");
                        m = 2;
                    }
                    else
                    {
                        k++;
                    }
                }
                else if (n == 2)
                {
                    if (k == 1)
                    {
                        printf("The RC Vehicle has reached the North end. Cannot move forward.");
                        m = 2;
                    }
                    else
                    {
                        k--;
                    }
                }
                else if (n == 3)
                {
                    if (l == x)
                    {
                        printf("The RC Vehicle has reached the East end. Cannot move left.");
                        m = 2;
                    }
                    else
                    {
                        l++;
                        m = 4;
                    }
                }
                else if (n == 4)
                {
                    if (l == 1)
                    {
                        printf("The RC Vehicle has reached the West end. Cannot move right.");
                        m = 2;
                    }
                    else
                    {
                        l--;
                        m = 3;
                    }
                }
                break;

            case 3:
                if (n == 1)
                {
                    if (k == 1)
                    {
                        printf("The RC Vehicle has reached the North end. Cannot move forward.");
                        m = 3;
                    }
                    else
                    {
                        k--;
                    }
                }
                else if (n == 2)
                {
                    if (k == y)
                    {
                        printf("The RC Vehicle has reached the South end. Cannot move forward.");
                        m = 3;
                    }
                    else
                    {
                        k++;
                    }
                }
                else if (n == 3)
                {
                    if (l == x)
                    {
                        printf("The RC Vehicle has reached the East end. Cannot move left.");
                        m = 3;
                    }
                    else
                    {
                        l++;
                    }
                }
                else if (n == 4)
                {
                    if (l == 1)
                    {
                        printf("The RC Vehicle has reached the West end. Cannot move right.");
                        m = 3;
                    }
                    else
                    {
                        l--;
                        m = 1;
                    }
                }
                break;

            case 4:
                if (n == 1)
                {
                    if (k == y)
                    {
                        printf("The RC Vehicle has reached the South end. Cannot move forward.");
                        m = 4;
                    }
                    else
                    {
                        k++;
                    }
                }
                else if (n == 2)
                {
                    if (k == 1)
                    {
                        printf("The RC Vehicle has reached the North end. Cannot move forward.");
                        m = 4;
                    }
                    else
                    {
                        k--;
                    }
                }
                else if (n == 3)
                {
                    if (l == 1)
                    {
                        printf("The RC Vehicle has reached the West end. Cannot move left.");
                        m = 4;
                    }
                    else
                    {
                        l--;
                        m = 1;
                    }
                }
                else if (n == 4)
                {
                    if (l == x)
                    {
                        printf("The RC Vehicle has reached the East end. Cannot move right.");
                        m = 4;
                    }
                    else
                    {
                        l++;
                        m = 3;
                    }
                }
                break;
        }

        for (o = 0; o <= y + 1; o++)
        {
            for (p = 0; p <= x + 1; p++)
            {
                if (o == 0 || o == y + 1)
                {
                    printf("-");
                }
                else if (p == 0 || p == x + 1)
                {
                    printf("|");
                }
                else if (o == k && p == l)
                {
                    switch (m)
                    {
                        case 1:
                            printf("^");
                            break;
                        case 2:
                            printf("v");
                            break;
                        case 3:
                            printf("<");
                            break;
                        case 4:
                            printf(">");
                            break;
                    }
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}