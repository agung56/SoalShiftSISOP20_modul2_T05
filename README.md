# SoalShiftSISOP20_modul2_T05
#### Anggota Kelompok:
1. I Gede Pradhana Indra W. (05311840000031)
2. Agung Mulyono (05311840000035)

## Soal 1
Kode Program: [soal1.c](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/soal1/soal1.c)
#### Soal
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:

**a.** Program menerima 4 argumen berupa:
  * Detik: 0-59 atau * (any value)
  * Menit: 0-59 atau * (any value)
  * Jam: 0-23 atau * (any value)
  * Path file .sh

**b.** Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai

**c.** Program hanya menerima 1 config cron

**d.** Program berjalan di background (daemon)

**e.** Tidak boleh mennggunakan fungsi system()

**Contoh:** `./program \* 34 7 /home/somi/test.sh`

#### Penjelasan Program
```c
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
```
Untuk membuat program c dibutuhkan beberapa library seperti diatas. library tersebut digunkan untuk memanggil beberapa fungsi yang nantinya akan digunkan pada kode program seperti printf(), if-else, while(), time_t, dan lain sebagainya.

```c
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
```
Setelah melakukan inputan library-library yang diperlukan, selanjutnya adalah mengecek argumen-argumen yang diinputkan oleh pengguna diterminal. Yang pertama dicek adalah jumlah argumen apakah jumlah argumen berjumlah 5 atau tidak dimana jumlah tersebut terdiri atas program C itu sendiri kemudian detik, menit, jam, dan file .sh yang akan dijalankan. Selanjutnya dilakukan pengecekan terhadap input waktunya, jika waktu yang dimasukkan sesuai dengan ketentuan diatas atau pada soal maka program akan langsung mengeluarkan error dan program tidak dapat dilanjutkan atau harus diulang. Disini kami menggunakan fungsi **atoi** yang berfungsi untuk mengubah tipe data string menjadi integer. Kemudian yang terakhir dicek adalah file .sh itu sendiri apakah file .sh yang akan dijalankan sudah ada dan siap untuk dijalankan. Untuk mengeceknya dengan menggunakan fungsi **access()** untuk melihat apakah file .sh sudah ada.

```c
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
```
Kode program diatas berfungsi sebagai daemon atau program yang berjalan dilatar belakang. Membuat variabel **pid** untuk menyimpan PID dari child proses dan dicek jika nilai PID<0 atau tidak ada child proses maka gagal kemudian memasukkan nilai **setsid()** kedalam variabel **sid**. SID ini digunakan agar child process dapat berjalan, jika tidak memiliki sid maka program daemon yang dikill akan menjadi orphan process. Dan yang terakhir menutup semua input, output, dan error karena proses daemon ini berjalan dilatar belakang oleh karena itu tidak boleh menampilkan apapun pada terminal

```c
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
```
Kemudian mengambil waktu dengan menggunakan struct tm yang menuju pointer jam dan mengambil waktu sekarang dan dimasukkan dalam variabel jam. Setelah itu jam yang telah didapatkan dicek satu persatu dari detik, menit, hingga jam file .sh akan dijalankan. Yang terakhir adalah apabila waktu telah sesuai maka file .sh dapat dijalankan menggunakan bash.

###output
* Daemon sukses\
![Program Daemon berhasil dijalankan](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/img/program%20berhasil.png)

* Isi file tes .sh\
![Isi file tes.sh](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/img/isi%20file%20shell.png)

* Contoh jika argumen yang dimasukkan tidak sama dengan algoritma\
![Argumen tidak sesuai](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/img/Argumen%20tidak%20sama%20dengan%20lima.png)

* Contoh jika waktu yang dimasukkan tidak sesuai\
![Argumen tidak sesuai](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/img/waktu%20yang%20diinputkan%20salah.png)

* Contoh jika file .sh tidak ditemukan\
![file .sh tidak ada](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/img/file%20shell%20tidak%20ada.png)

#### Kendala Selama Pengerjaan Soal 1
* Kesulitan dalam pembuatan proses daemon
* Kebingungan dalam memasukkan waktu dan mengecek waktu yang sudah ada dengan waktu yang diinputkan
*

## Soal 2
Kode Program: [soal2.c]()
#### Soal
Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program.

**a.** Pertama-tama, Kiwa membuat sebuah folder khusus, didalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].

**b.** Tiap-tiap folder lalu diisi dengan 20 gambar yang didownload dari *https://picsum.photos/*, dimana tiap gambar didownload setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].

**c.** Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan dizip dan folder akan didelete (sehingga menyisakan .zip).

**d.** Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut mengenerate sebuah program "killer" **yang siap dirun (executable)** untuk menterminasi semua operasi program tersebut. Setelah dirun, program yang menterminasi ini lalu akan mendelete dirinya sendiri.

**e.** Kiwa menambahkan bahwa program **utama** bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. Untuk mengaktifkan MODE_A program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses disetiap folder yang masih berjalan sampai selesai (semua folder terisi gambar, terzip lalu didelete).

Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi. Buatlah program dalam mimpi Kiwa jadi nyata!

**Catatan:**
* Tidak boleh memakai system().
* Program utama harus ter-detach dari terminal.

**Hint:**
* Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran tertentu.
* Epoch Unix bisa didapatkan dari time().


#### Penjelasan Program

#### Kendala Selama Pengerjaan Soal 2
* Kesulitan dalam memahami soal dan algoritma yang harus digunakan
* Tingkat kesulitan soal yang tinggi
* Bingung dalam mendownload gambar dan menentukan piksel gambar sesuai dengan soal
*

## Soal 3
Kode Program: [soal3.c](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/soal3/soal3.c)
#### Soal
Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan (multiprocessing).

**a.** Program buatan Jaya harus bisa membuat dua direktori di **"/home/[USER]/modul2/"**. Direktori yang pertama diberi nama **"indomie"**, lalu lima detik kemudian membuat direktori yang kedua bernama **"sedaap"**.

**b.** Kemudian program tersebut harus meng-ekstrak file **jpg.zip** di direktori **"/home/[USER]/modul2/"**. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.

**c.** Diberi tugas baru yaitu setelah diekstrak, hasil dari ekstrakan tersebut (di dalam direktori **"/home/[USER]/modul2/jpg/"**) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke **"/home/[USER]/modul2/sedaap/"** dan semua direktori harus dipindahkan ke **"/home/[USER]/modul2/indomie/"**.

**d.** Untuk setiap direktori yang dipindahkan ke **"/home/[USER]/modul2/indomie/"** harus membuat dua file kosong. File yang pertama diberi nama **"coba1.txt"**, lalu 3 detik kemudian membuat file bernama **"coba2.txt"**.\
(Contoh:**"/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt"**).

Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat program tersebut.

**Catatan:**
* Tidak boleh memakai system().
* Tidak boleh menggunakan function C mkdir() ataupun rename().
* Gunakan exec dan fork.
* Direktori "." dan ".." tidak termasuk.


#### Penjelasan Program
Berikut adalah library-library yang digunakan untuk mengerjakan soal no 3.
```c
#include <sys/stats.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <time.h>
```


* Soal 3.a
```c
pid_t idchild = fork();
if (idchild == 0) {
  char *valueargu[] = {"mkdir", "-p", "/home/Documents/sisop20/modul2/indomie", NULL};
  execv("/bin/mkdir", valueargu);
}
while(wait(NULL) != idchild);
sleep(5)

idchild = fork();
if (idchild == 0) {
  char *valueargu[] = {"mkdir", "-p", "/home/Documents/sisop20/modul2/sedaap", NULL};
  execv("/bin/mkdir", valueargu);
}
```
Untuk soal 3.a pertama-tama memasukkan id child dari fungsi `fork()` kedalam variabel idchild, setelah itu dilakukan pengecekan jika nilai idchild sama dengan nol maka menjalankan argumen `mkdir` beserta parent-nya ke direktori yang telah ditentukan pada soal. Direktori pertama yang dibuat adalah indomie lalu lima detik kemudian membuat direktori sedaap pada lokasi yang sama

* Soal 3.b
```c
while(wait(NULL) != idchild);

  idchild = fork();
  if (idchild == 0) {
    char *valueargu[] = {"unzip", "-q", "jpg.zip", "-d", "/home/Documents/sisop20/modul2", NULL};
    execv("/usr/bin/unzip", valueargu);
  }
```
Kemudian setelah direktori terbentuk, tugas selanjutnya adalah mengekstrak file yang bernama **jpg.zip** dengan menggunakan command `unzip` pada lokasi yang sudah ditentukan

* Soal 3.c

Untuk soal 3.c kelompok kami tidak dapat menyelesaikannya karena kami kesulitan harus menggunakan cara yang seperti apa

* Soal 3.d
```c
while(wait(NULL) != idchild);

char new_location[80];
idchild = fork();
if (idchild == 0) {
  sprintf(new_location, "/home/Documents/sisop20/modul2/indomie/%s/coba1.txt", token);
  char *valueargu[] = {"touch", new_location, NULL};
  execv("/usr/bin/touch", valueargu);
}

idchild = fork();
if (idchild == 0) {
  sleep(3);
  sprintf(new_location, "/home/Documents/sisop20/modul2/indomie/%s/coba2.txt", token);
  char *valueargu[] = {"touch", new_location, NULL};
  execv("/usr/bin/touch", valueargu);
}

while(wait(NULL) != idchild);

}
```
Kemudian untuk soal 3.d diminta membuat file coba1.txt dan coba2.txt pada setiap direktori yang ada pada direktori indomie dengan selang waktu tiga detik.  

#### Kendala Selama Pengerjaan Soal 3
* Kesulitan dalam menentukan mana direktori dan mana File dan harus menggunakan metode yang bagaimana
*
