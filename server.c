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
        struct ip ipaddr          = getip();
        int       sock            = socket(AF_INET, SOCK_DGRAM, 0);
        int       enableBroadcast = 1;
        setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &enableBroadcast, sizeof(enableBroadcast));
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
        int                response_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in serverAddr;
        memset(&serverAddr, 0, sizeof(serverAddr));
        serverAddr.sin_family              = AF_INET;
        serverAddr.sin_addr.s_addr         = INADDR_ANY;
        serverAddr.sin_port                = htons(2071);
        int addrlen = sizeof(struct sockaddr_in);
        if (bind(response_socket, (struct sockaddr *) &serverAddr,addrlen) < 0)
        {
            printf("could not bind to the given port.... due to %s\n", strerror(errno));
//            close(response_socket);
//            return -1;
        }
        listen(response_socket, 3);
        int  clientsock;
        char msg[1024];
        memset(msg, 0, 1024);
        struct sockaddr_in clientaddr;
        memset(&clientaddr, 0, sizeof(clientaddr));
        while (1)
        {
            clientsock=accept(response_socket, (struct sockaddr *)&clientaddr,(socklen_t*)&addrlen);
            if (clientsock < 0)
            {
                printf("receiving socket failed dueto %s ... %d \n ", strerror(errno), errno);
                //                close(response_socket);
                //                return -1;
            }
            int len;
            if ((len = recv(clientsock, msg, 1024, 0)) > 0)
            {
                send(clientsock,msg,1024,0);
                puts(msg);
            }
            else
            {
                printf("could not receive due to ...%s \n", strerror(errno));
                //                close(response_socket);
                //                return -1;
            }
        }
    }
