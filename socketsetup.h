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
#include "ipgrab.h"
extern int createAndBind(int port, char protocal[]);
extern int broadcastsocket();

#endif //HOMESERVER_SOCKETSETUP_H
