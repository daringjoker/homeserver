#include <stdio.h>
#include <arpa/inet.h>
#include"socketsetup.h"
#include <pthread.h>
#include <unistd.h>


void * broadcastserver()
    {
        struct ip ipaddr=getip();
        int                sock = broadcastsocket();
        struct sockaddr_in saddr;
        saddr.sin_family = AF_INET;
        inet_pton(AF_INET, ipaddr.broadcast, &saddr.sin_addr.s_addr);
        saddr.sin_port = htons(2070);
        while (1)
        {
            sendto(sock, ipaddr.local, sizeof(ipaddr.local), 0, (struct sockaddr *) &saddr, sizeof(saddr));
            sleep(1);
        }
    }


int main()
    {
        pthread_t id;
        pthread_create(&id,NULL,broadcastserver,NULL);
        pthread_join(id,NULL);
    }