/*
*Author:-Pukar Giri
*Created On:-12Th September 2018 at 11:56
*File Name:-server.h
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/

#ifndef HOMESERVER_SERVER_H
#define HOMESERVER_SERVER_H

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include "ipgrab.h"
#include <errno.h>

void *broadcastserver();
int responseServer();
#endif //HOMESERVER_SERVER_H
