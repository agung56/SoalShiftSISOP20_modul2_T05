# SoalShiftSISOP20_modul2_T05
#### Anggota Kelompok:
1. I Gede Pradhana Indra W. (05311840000031)
2. Agung Mulyono (05311840000035)

---
## Table of Contents
* [Soal 1](#soal-1)
* [Soal 2](#soal-2)
  * [Soal 2.a.](#soal-2a)
  * [Soal 2.b.](#soal-2b)
  * [Soal 2.c.](#soal-2c)
  * [Soal 2.d.](#soal-2d)
  * [Soal 2.e.](#soal-2e)
* [Soal 3](#soal-3)
  * [Soal 3.a.](#soal-3a)
  * [Soal 3.b.](#soal-3b)
  * [Soal 3.c.](#soal-3c)
  * [Soal 3.d.](#soal-3d)
---


## Soal 1
Kode Program: [soal1.c](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/soal1/soal1.c)
### Soal
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
#### Kendala Selama Pengerjaan Soal 1

## Soal 2
Kode Program: [soal2.c]()
### Soal
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

#### Kendala Selama Pengerjaan Soal 2

## Soal 3
Kode Program: [soal3.c](https://github.com/agung56/SoalShiftSISOP20_modul2_T05/blob/master/soal3/soal3.c)
### Soal
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

#### Kendala Selama Pengerjaan Soal 3
