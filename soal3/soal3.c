#include <sys/stats.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <time.h>


int main() {

//-------------------SOAL 3.A----------------------------//
  pid_t idchild = fork();
  if (idchild == 0) {
    char *valueargu[] = {"mkdir", "-p", "/home/lab/modul2/indomie", NULL};
    execv("/bin/mkdir", valueargu);
  }
  while(wait(NULL) != idchild);
  sleep(5)

  idchild = fork();
  if (idchild == 0) {
    char *valueargu[] = {"mkdir", "-p", "/home/lab/modul2/sedaap", NULL};
    execv("/bin/mkdir", valueargu);
  }

  //----------------------SOAL 3B --------------------//
  while(wait(NULL) != idchild);

  idchild = fork();
  if (idchild == 0) {
    char *valueargu[] = {"unzip", "-q", "jpg.zip", "-d", "/home/lab/modul2", NULL};
    execv("/usr/bin/unzip", valueargu);
  }

//---------------------------soal 3D---------------------//
      idchild = fork();
      if (idchild == 0) {
        sleep(3);
        sprintf(lokbaru, "/home/lab/modul2/indomie/%s/coba2.txt", token);
        char *valueargu[] = {"touch", lokbaru, NULL};
        execv("/usr/bin/touch",`` valueargu);
      }


  closedir(dr);

}.
