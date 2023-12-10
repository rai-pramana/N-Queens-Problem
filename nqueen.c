/* Judul        : Program Menemukan_Solusi_Masalah_N_Queen              */
/* Deskripsi    : Program untuk mencetak solusi untuk masalah n-queens  */
/*                berupa ratu yang sudah ditempatkan pada papan catur   */
/* Developer    : I Kadek Rai Pramana (2105551094)                      */
/* Tanggal      : 08 November 2021                                      */
/* Versi        : 1.0                                                   */

#include <stdio.h>

// deklarasi variabel global untuk jumlah ratu dan luas papan catur
int n;

// deklarasi array untuk papan catur
int papan[100][100];

void print_papan(){/* fungsi untuk mencetak ratu yang sudah ditempatkan pada papan catur */
    // deklarasi variabel lokal
    int baris, kolom;

    printf("\n");
    for(baris = 0; baris < n; baris++){
        printf("\n");
        for(kolom = 0; kolom < n; kolom++){
            printf("\t%d",papan[baris][kolom]);// mencetak nilai tiap baris dan kolom dari array papan
        }
        printf("\n\n");
    }
}

int apakah_diserang(int baris, int kolom){/* fungsi untuk mengecek apakah ratu saling serang */
    // deklarasi variabel lokal
    int k,l;

    // memeriksa kolom, apakah sudah ditempati ratu
    for(k = 0; k < n; k++){
        if(papan[k][kolom] == 1){
            return 1;// mengembalikan nilai true (1) jika sudah ditempati ratu
        }
    }

    // memeriksa diagonal, apakah sudah ditempati ratu
    for(k = 0; k < n; k++){
        for(l = 0; l < n; l++){
            if((k + l) == (baris + kolom) || (k - l) == (baris - kolom)){
                if(papan[k][l] == 1){
                    return 1;// mengembalikan nilai true (1) jika sudah ditempati ratu
                }
            }
        }
    }
    return 0;// mengembalikan nilai false (0) jika belum ditempati ratu (aman)
}

int N_ratu(int ratu, int baris){/* fungsi untuk mencari solusi N-Queens */
    // deklarasi variabel lokal
    int kolom;

    // base case fungsi rekursif
    if(ratu == 0){  // cek apakah ratu sudah habis (ratu == 0)
        return 1;   // mengembalikan nilai true (1) ke fungsi rekursi jika semua ratu telah berhasil ditempatkan
    }               // jika semua ratu sudah ditempatkan, solusi ditemukan

    for(kolom = 0; kolom < n; kolom++){
        /*  cek apakah kita dapat menempatkan seorang ratu di sini (papan[baris,kolom]), */
        /*  ratu tidak akan ditempatkan jika tempat itu diserang atau sudah diduduki     */
        if(apakah_diserang(baris, kolom) != 1){// memanggil fungsi apakah_diserang
            papan[baris][kolom] = 1;// menempatkan ratu di posisi papan saat ini

            /* cek apakah kita bisa menempatkan ratu berikutnya dengan pengaturan ini atau tidak */
            if(N_ratu(ratu - 1, baris + 1) == 1){   // fungsi rekursif akan mengurangi jumlah ratu,
                                                    // kemudian pindah baris jika ada ratu yang ditempatkan
                return 1;// mengembalikan nilai true (1) ke program utama jika dengan penempatan  saat ini ditemukan solusi
            }else{
            /* hapus posisi ratu jika penempatan  ini tidak menemukan solusi */
                papan[baris][kolom] = 0;
            }
        }
    }
    return 0;// mengembalikan nilai false (0) jika semua baris dan kolom telah diperiksa, tetapi tidak menemukan solusi
}// jika baris > 0, backtracking ke posisi papan sebelumnya
 // jika baris == 0, kembali ke program utama
/*  fungsi rekursif akan mengembalikan jumlah ratu kembali seperti semula saat solusi sudah ditemukan   */
/*  (sebelum kembali ke program utama untuk mencetak output ke layar)                                   */

int main(){/* program utama */
    // meminta input untuk nilai n
    printf("Masukkan jumlah ratu: ");
    scanf("%d",&n);

    if(N_ratu(n, 0) == 1){// memanggil fungsi N_ratu, kemudian cek apakah berhasil menemukan solusi
        print_papan();// memanggil fungsi print_papan jika berhasil menemukan solusi
    }else{
        printf("\n\tSolusi tidak ditemukan\n\n");// aksi yang dilakukan jika tidak berhasil menemukan solusi
    }
    return 0;
}
