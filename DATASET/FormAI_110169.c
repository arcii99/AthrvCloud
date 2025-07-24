//FormAI DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>

int main(void) {
    /* Initializing the firewall */
    printf("Initializing Firewall...\n");

    /* Creating a rule to block incoming traffic on port 22 */
    system("sudo iptables -A INPUT -p tcp --dport 22 -j DROP");
    printf("Rule added to block incoming traffic on port 22.\n");

    /* Creating a rule to block outgoing traffic to a specific IP address */
    system("sudo iptables -A OUTPUT -d 192.168.1.100 -j DROP");
    printf("Rule added to block outgoing traffic to IP address 192.168.1.100.\n");

    /* Creating a rule to allow incoming traffic on port 80 */
    system("sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT");
    printf("Rule added to allow incoming traffic on port 80.\n");

    /* Creating a rule to allow outgoing traffic to a specific IP address */
    system("sudo iptables -A OUTPUT -d 192.168.1.200 -j ACCEPT");
    printf("Rule added to allow outgoing traffic to IP address 192.168.1.200.\n");

    /* Creating a rule to limit the number of connections */
    system("sudo iptables -A INPUT -p tcp --syn --dport 80 -m connlimit --connlimit-above 10 -j DROP");
    printf("Rule added to limit the number of connections to port 80.\n");

    /* Creating a rule to log all dropped packets */
    system("sudo iptables -A INPUT -j LOG --log-prefix \"Dropped Packet: \"");
    printf("Rule added to log all dropped packets.\n");

    /* Creating a rule to block all incoming traffic by default */
    system("sudo iptables -P INPUT DROP");
    printf("Rule added to block all incoming traffic by default.\n");

    /* Creating a rule to block all outgoing traffic by default */
    system("sudo iptables -P OUTPUT DROP");
    printf("Rule added to block all outgoing traffic by default.\n");

    /* Displaying the final set of rules */
    printf("\nFinal set of rules:\n");
    system("sudo iptables -S");

    return 0;
}