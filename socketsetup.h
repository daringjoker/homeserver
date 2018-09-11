/*
*Author:-Pukar Giri
*Created On:-10Th September 2018 at 21:11
*File Name:-socketsetup.h
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/

#ifndef HOMESERVER_SOCKETSETUP_H
#define HOMESERVER_SOCKETSETUP_H


#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>


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


extern int broadcastsocket(char address[], port)
    {
        int                sock  = socket(AF_INET, SOCK_DGRAM, 0);
        struct sockaddr_in sockaddr;
        memset(&sockaddr, 0, sizeof(sockaddr));
        sockaddr.sin_family      = AF_INET;
        sockaddr.sin_addr.s_addr = htonl(address);
        sockaddr.sin_port        = htons(port);
        int enableBroadcast=1;
        setsockopt(sock,SOL_SOCKET,SO_BROADCAST,&enableBroadcast,sizeof(enableBroadcast));

    }


#endif //HOMESERVER_SOCKETSETUP_H
