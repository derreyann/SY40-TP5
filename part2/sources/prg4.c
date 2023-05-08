#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>


void erreur(const char* msg)      {perror(msg);exit(1);}

#define LGMSG 20

int main()
  {
    int tubef[2];

    if (pipe(tubef) == -1) erreur("pipe tubef");

    switch (fork())
    {
    case -1:
        erreur("fork");
        break;
    case 0:
        close(tubef[0]);
        dup2(tubef[1], STDOUT_FILENO);
        close(tubef[1]);
        if(execlp("ps", "ps", NULL) == -1){
            erreur("execlp");
        }
        break;
    default:
        wait(NULL);
        close(tubef[1]);
        dup2(tubef[0], STDIN_FILENO);
        close(tubef[0]);
        if(execlp("wc", "wc", "-l", NULL) == -1){
            erreur("execlp");
        }
        break;
    }
  }
              