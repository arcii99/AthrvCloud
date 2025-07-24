//FormAI DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct firewall
{
    int allow_ports[10];
    int deny_ports[10];
    char* allow_ips[10];
    char* deny_ips[10];
};

typedef struct firewall Firewall;

bool check_allowed(Firewall fire, char* ip, int port)
{
    for (int i = 0; i < 10; i++)
    {
        if (fire.allow_ports[i] == port && strcmp(fire.allow_ips[i], ip) == 0)
        {
            return true;
        }
    }
    return false;
}

bool check_denied(Firewall fire, char* ip, int port)
{
    for (int i = 0; i < 10; i++)
    {
        if (fire.deny_ports[i] == port && strcmp(fire.deny_ips[i], ip) == 0)
        {
            return true;
        }
    }
    return false;
}

void add_allow_port(Firewall* fire, int port, char* ip)
{
    for (int i = 0; i < 10; i++)
    {
        if (!fire->allow_ports[i])
        {
            fire->allow_ports[i] = port;
            fire->allow_ips[i] = ip;
            break;
        }
    }
}

void add_deny_port(Firewall* fire, int port, char* ip)
{
    for (int i = 0; i < 10; i++)
    {
        if (!fire->deny_ports[i])
        {
            fire->deny_ports[i] = port;
            fire->deny_ips[i] = ip;
            break;
        }
    }
}

int main(void)
{
    Firewall fire = { .allow_ports = {0}, .deny_ports = {0}, .allow_ips = {0}, .deny_ips = {0} };

    char* ip1 = "192.168.1.1";
    char* ip2 = "10.0.0.1";
    add_allow_port(&fire, 80, ip1);
    add_deny_port(&fire, 22, ip2);

    bool allowed = check_allowed(fire, ip1, 80);
    bool denied = check_denied(fire, ip2, 22);

    printf("Port 80 from IP %s is allowed? %d\n", ip1, allowed);
    printf("Port 22 from IP %s is denied? %d\n", ip2, denied);

    return 0;
}