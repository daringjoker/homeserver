/*
*Author:-Pukar Giri
*Created On:-12Th September 2018 at 11:58
*File Name:-server.c
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/
#include "server.h"
void *broadcastserver()
    {
        struct ip          ipaddr = getip();
        int                sock   = broadcastsocket();
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


int responseServer()
    {
        char msg[1024];
        int sock = createAndBind(2071, "tcp");
        listen(sock, 1);
        while (1)
        {
            int clisock = accept(sock, (struct sockaddr * )NULL, 0);
            recv(clisock, msg, sizeof(msg), 0);
            //pthread_t id = create_thread()
        }
    }
