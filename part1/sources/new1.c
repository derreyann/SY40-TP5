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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void erreur(const char *msg)
{
       perror(msg);
       exit(1);
}

#define LGMAX 100

int main()
{
       int f;
       char tampon[LGMAX];
       switch (fork())
       {
       case -1:
              erreur("fork");
       case 0:

              f = open("../joe", O_WRONLY, 0666);
              strcpy(tampon, "salut a toi");
              write(f, tampon, strlen(tampon) + 1);
              break;
       default:
              wait(NULL);
              f = open("../joe", O_RDONLY, 0666);
              read(f, tampon, LGMAX);
              printf("chaine lue dans le tube : %s\n", tampon);
       }
}
