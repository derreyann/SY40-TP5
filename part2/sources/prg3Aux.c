/*-----------------------------------------------------------
-------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define LGMSG 20

int main(int argc,char* argv[])
  {
  char msg[LGMSG];
  int  E,S;
  if (argc-1 != 2) {
       fprintf(stderr,"Appel %s <desc E> <desc S>",argv[0]);
       exit(1);
       };
  E=atoi(argv[1]);
  S=atoi(argv[2]); 
  while (1) {
    int lg,i;
    read(E,msg,LGMSG);
    lg = strlen(msg);
    for (i=0;i<lg;i++) msg[i]=toupper(msg[i]);
    sleep(3);
    write(S,msg,LGMSG);
    }
  }
     
     