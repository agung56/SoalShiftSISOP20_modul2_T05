#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

int main(int checkargu, char *valueargu[]) {
  if (checkargu != 5) {
    printf("Argumen yang dimasukkan tidak sesuai\n");
    return 1;
  }

  if (access(valueargu[4], F_OK) == -1) {
    printf("File tidak ada\n");
    return 1;
  }
  if (!(*valueargu[1] == '*' || (atoi(valueargu[1]) >= 0 && atoi(valueargu[1]) < 60))) {
       printf("Argumen yang dimasukkan salah (detik=0-59, menit=0-59, jam=0-23)\n");
    return 1;}


  if (!(*valueargu[2] == '*' || (atoi(valueargu[2]) >= 0 && atoi(valueargu[2]) < 60))) {
       printf("Argumen yang dimasukkan salah (detik=0-59, menit=0-59, jam=0-23)\n");
    return 1;}

  if (!(*valueargu[3] == '*' || (atoi(valueargu[3]) >= 0 && atoi(valueargu[3]) < 24))) {

  printf("Argumen yang dimasukkan salah (detik=0-59, menit=0-59, jam=0-23)\n");
    return 1;
  }

  pid_t pid, sid;        // Variabel untuk menyimpan PID
  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }


  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

   while (1) {
   time_t now = time(NULL);
   struct tm *jam=localtime(&now);

    if (atoi(valueargu[1]) == jam->tm_sec || *valueargu[1] == '*') {
    if (atoi(valueargu[2]) == jam->tm_min || *valueargu[2] == '*') {
    if (atoi(valueargu[3]) == jam->tm_hour || *valueargu[3] == '*') {

          pid_t child_id;
          child_id = fork();

          if (child_id == 0) {

            char *childargu[] = {"bash", valueargu[4], NULL};
            execv("/bin/bash", childargu);

          }
          while(wait(NULL) > 0);
        }
      }
    }

    sleep(1);
  }
}
