/*-----------------------------------------------------------
               Les tubes ordinaires
               le pere lit, le fils ecrit
-------------------------------------------------------------*/

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h>

void erreur(const char* msg)      {perror(msg);exit(1);}

#define LGMAX 100
  
int main()
  {
  int pfd[2];
  char tampon[LGMAX];
  
  if (pipe(pfd) == -1) erreur("pipe");
  
  switch (fork()) {
         case -1 : erreur("fork");
         case 0   :                   /* fils */
               close(pfd[0]);
               strcpy(tampon,"salut a toi");
               write(pfd[1],tampon,strlen(tampon)+1);
               break;
        default  :                  /* pere */ 
               {
               char *p = tampon;                    
               close(pfd[1]);
               read(pfd[0],p,LGMAX) != 0;
               printf("chaine lue dans le tube : %s\n",tampon);
               break;
               }
     }
  }
               
               
