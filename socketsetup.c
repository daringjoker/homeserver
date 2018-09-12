/*
*Author:-Pukar Giri
*Created On:-12Th September 2018 at 11:50
*File Name:-socketsetup.c
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/
#include "socketsetup.h"

extern int createAndBind(int port, char protocal[])
    {
        //converting the protocol name to protocol using predefined macros
        int proto;
        if (strstr(protocal, "udp"))
        {
            proto = SOCK_DGRAM;
        }
        else if (strstr(protocal, "tcp"))
        {
            proto = SOCK_STREAM;
        }
        else
        {
            return -1;
        }
        //creating the server socket that will listen to the connection from clients.
        int                serversocket = socket(AF_INET, proto, 0);
        //deckaring and defining a structure to contain the server address message
        struct sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family      = AF_INET;
        sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        sockAddr.sin_port        = htons(port);
        //Binding the socket to the designated port where it can listen to the connections.
        bind(serversocket, (struct sockaddr *) &sockAddr, sizeof(sockAddr));
        return serversocket;
    }


extern int broadcastsocket()
    {
        int sock            = socket(AF_INET, SOCK_DGRAM, 0);
        int enableBroadcast = 1;
        setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &enableBroadcast, sizeof(enableBroadcast));
        return sock;
    }


