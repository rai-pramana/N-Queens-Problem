# N-Queens Problem (Program C)

Program sederhana untuk menemukan satu solusi dari masalah N-Queens. Program ini ditulis dalam bahasa C dan menggunakan pendekatan backtracking untuk menempatkan N ratu pada papan N x N sehingga tidak ada pasangan ratu yang saling menyerang.

## Fitur

-   Mencari dan mencetak satu solusi untuk konfigurasi N-Queens.
-   Implementasi backtracking rekursif.

## File dalam repository

-   `nqueen.c` : Kode sumber program C yang meminta input N, menjalankan algoritma N-Queens, dan mencetak papan dengan penempatan ratu (1 = ratu, 0 = kosong).
-   `README.md` : (file ini) dokumentasi singkat cara compile dan menjalankan program.
-   `By Hand nqueen/` : folder berisi gambar ilustrasi (manual) tentang solusi.
-   `Flowchart/` : folder berisi flowchart yang menjelaskan alur program.

## Cara compile (Windows, cmd.exe)

1. Buka Command Prompt (cmd.exe).
2. Arahkan ke folder project, misalnya:

```cmd
cd "c:\Users\raipr\OneDrive\Documents\Github\N-Queens-Problem"
```

3. Compile menggunakan GCC (MinGW atau paket compiler C lainnya):

```cmd
gcc -o nqueen nqueen.c
```

4. Jalankan program:

```cmd
nqueen
```

Catatan: Jika Anda tidak memiliki GCC, instalasi MinGW-w64 atau gunakan WSL/Dev C++/MSVC (sesuaikan perintah compile untuk compiler yang digunakan).

## Contoh penggunaan

Saat dijalankan, program akan meminta input jumlah ratu (N). Contoh interaksi:

```
Masukkan jumlah ratu: 4

    0	1	0	0

    0	0	0	1

    1	0	0	0

    0	0	1	0

```

Format output: setiap baris papan dicetak sebagai angka 0 dan 1, di mana `1` menandakan posisi ratu.

## Penjelasan singkat algoritma

Program menggunakan teknik backtracking rekursif:

-   Fungsi `N_ratu(ratu, baris)` mencoba menempatkan ratu pada baris saat ini (`baris`). Jika semua ratu telah ditempatkan (`ratu == 0`), fungsi mengembalikan solusi.
-   Untuk setiap kolom pada baris tersebut, fungsi memeriksa apakah posisi aman (tidak ada ratu pada kolom yang sama atau diagonal) dengan `apakah_diserang(baris, kolom)`.
-   Jika aman, program menandai posisi tersebut dengan `1` dan memanggil rekursi untuk menempatkan ratu berikutnya pada baris selanjutnya. Jika rekursi gagal, posisi dikembalikan ke `0` (backtrack) dan mencoba kolom berikutnya.

Keterbatasan dan catatan:

-   Program hanya mencetak satu solusi pertama yang ditemukan.
-   Ukuran maksimum papan diimplementasikan sebagai array statis `papan[100][100]`. Pastikan memasukkan N <= 100.

## Lisensi

Lisensi tidak dispesifikasikan di repository; gunakan sesuai kebutuhan Anda atau tambahkan file LICENSE jika ingin menentukan lisensi.

## Pengembang

I Kadek Rai Pramana (2105551094)

# N-Queens-Problem

## Manual Solution

![1](./By%20Hand%20nqueen/1.jpg)
![2](./By%20Hand%20nqueen/2.jpg)
![3](./By%20Hand%20nqueen/3.jpg)

## Flowchart

### main

![1](./Flowchart/N%20queen-main.drawio.png)

### nqueen

![2](./Flowchart/N%20queen-N_ratu.drawio.png)

### is attack

![3](./Flowchart/N%20queen-apakah_diserang.drawio.png)

### print

![4](./Flowchart/N%20queen-print_papan.drawio.png)
