/*
*Author:-Pukar Giri
*Created On:-12Th September 2018 at 11:49
*File Name:-ipgrab.c
*Project Name:-Homeserver
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/
#include "ipgrab.h"
char *match(char *pattern, char *text)
    {
        char       *result;
        regex_t    reg;
        regmatch_t match;
        regcomp(&reg, pattern, REG_EXTENDED);
        if ((regexec(&reg, text, 1, &match, 0)) == 0)
        {
            int start = match.rm_so;
            int end   = match.rm_eo;
            int len   = end - start;
            result   = realloc(result, (size_t) len + 5);
            int i, w = 0;
            for (i    = start; i < end; i++
                    )
            {
                result[w] = text[i];
                w++;
            }
            result[w] = 0;
        }
        return result;
    }


struct ip getip()
    {
        struct ip ipAddresses;
        system("ifconfig|grep broadcast > temp.tmp");
        FILE *infile = fopen("temp.tmp", "r");
        fseek(infile, 0, SEEK_END);
        long size = ftell(infile);
        fseek(infile, 0, SEEK_SET);
        char *file = malloc((size_t) size + 1);
        fread(file, (size_t) size, 1, infile);
        char *ipinet    = match("inet [0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}", file);
        char *ipinet_ip = match("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}", ipinet);
        strcpy(ipAddresses.local, ipinet_ip);
        char *ipbroad    = match("broadcast [0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}", file);
        char *ipbroad_ip = match("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}", ipbroad);
        strcpy(ipAddresses.broadcast, ipbroad_ip);
        free(ipinet);
        free(ipinet_ip);
        free(ipbroad);
        free(ipbroad_ip);
        return ipAddresses;
    }


