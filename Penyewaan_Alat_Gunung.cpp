#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
using namespace std;

string list_nama[2];
int list_tlp[2];
int list_antrian[2];
string list_pinjam[2];
string list_kembali[2];

void menu_awal(){
    cout << " ===================================" << endl;
    cout << " |\t   SAFETY ADVANTURE        |" << endl;
    cout << " ===================================" << endl;
    cout << " |\t1. Kelengkapan Data        |" << endl;
    cout << " |\t2. List Peminjaman Barang  |" << endl;
    cout << " |\t3. List Sewa Peralatan     |" << endl;
    cout << " |\t4. Data Penyewaan          |" << endl;
    cout << " |\t5. Selesai                 |" << endl;
    cout << " ===================================" << endl;
}
void menu_satu(){
    string nama;
    string pinjam, kembali;
    int tlp;
    int antrian;

    for (int i=0; i<2; i++){
        cout << "==========================================\n";
        cout << "|         Kelengkapan Administrasi       |\n";
        cout << "==========================================\n";
        cout << "| Nama Lengkap           : ";
        cin.ignore();
        getline(cin, nama);
        list_nama[i]=nama;
        cout << "| No.Telpon/HP           : ";
        cin >> tlp;
        list_tlp[i]=tlp;
        cout << "| Tanggal Peminjaman     : ";
        cin >> pinjam;
        list_pinjam[i]=pinjam;
        cout << "| Tanggal Pengembalian   : ";
        cin >> kembali;
        list_kembali[i]=kembali;
        cout << "| Nomor Antrian          : ";
        cin >> antrian;
        list_antrian[i]=antrian;
        cout << "==========================================\n\n";
    }
}
void menu_dua (){
        cout << "\n~~~~~~~~ LIST PEMINJAMAN BARANG ~~~~~~~~\n";

    for (int i=0;i<2;i++){
        cout << "==========================================\n";
        cout << "|            Kelengkapan Data            |\n";
        cout << "==========================================\n";
        cout << "| Nama                 : " << list_nama[i] << endl;
        cout << "| No ltp               : " << list_tlp[i] << endl;
        cout << "| Tanggal Peminjaman   : " << list_pinjam[i] << endl;
        cout << "| Tanggal Kembalil     : " << list_kembali [i] << endl;
        cout << "| Nomor Antrian        : " << list_antrian[i] << endl;
        cout << "==========================================\n\n";
    }
}
void menu_tiga(){
    cout << " ===============================================" << endl;
    cout << " |\t      List Sewa Peralatan              |" << endl;
    cout << " ===============================================" << endl;
    cout << " |\t1. Tenda Dome     : Rp.30.000,-/hari   |" << endl;
    cout << " |\t2. Tas Carrier    : Rp.20.000,-/hari   |" << endl;
    cout << " |\t3. Matras         : Rp.5.000,-/hari    |" <<endl;
    cout << " |\t4. Sleeping Bag   : Rp.10.000,-/hari   |" << endl;
    cout << " ===============================================" << endl;
}
int kembalian_sewa(int total, int bayar){
    int kembalian=bayar-total+534;
    return kembalian;
}
void menu_empat(){
    cout << " =================================================" << endl;
    cout << " |\t      List Data Penyewaan                |"     << endl;
    cout << " =================================================" << endl;
    cout << " |  1. Urutan Berdasarkan Nomor Antrian          |" << endl;
    cout << " |  2. Urutan Berdasarkan Tanggal Peminjaman     |" << endl;
    cout << " |  3. Urutan Berdasarkan Tanggal Pengembalian   |" << endl;
    cout << " |  4. Cari Berdasarkan Nomor Antrian            |" << endl;
    cout << " =================================================" << endl;
}
void buble_int (int arr[], int length){
    bool not_sorted = true;
    int j=0;
    int tmp;

  while (not_sorted) {
    not_sorted = false;
    j++;
    for (int i=0; i<length -j; i++){
        if (arr[i] > arr[i+1]) {
            tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
            not_sorted = true;
        }
    }
  }
}
void print_int (int arr[], int length){
     for (int i=0;i<length;i++) {
        cout << arr[i] << "\t";
     }
     cout << endl;
}
void buble_string (string arr[], int length){
    bool not_sorted = true;
    int j=0;
    string tmp;

  while (not_sorted) {
    not_sorted = false;
    j++;
    for (int i=0; i<length -j; i++){
        if (arr[i] > arr[i+1]) {
            tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
            not_sorted = true;
        }
    }
  }
}
void print_string (string arr[], int length){
     for (int i=0;i<length;i++) {
        cout << arr[i] << "\t";
     }
     cout << endl;
}
int sequential_search(int list_antrian[], int cari_antrian)
{
    int posisi, i, ketemu;

    if(2<=0){
        posisi = -1;
    } else {
        ketemu = 0;
        i = 0;
        while ((i<=2) && !ketemu){
            if(list_antrian[i] == cari_antrian){
                posisi = i;
                ketemu = 1;
            } else {
                i++;
            }
            if(!ketemu){
                posisi = -1;
            }
        }
    }
    return posisi;
}
int main()
{
    int pilihan;

    menu :
    do{
        menu_awal();
        cout << "\n Masukkan Pilihan : ";
        cin >> pilihan;
        system("cls");

        if(pilihan == 1){
            menu_awal();
            cout << endl;
            menu_satu();

            system("pause");
            system("cls");
            goto menu;
            break;

        } else if (pilihan==2){
            menu_awal();
            cout << endl;
            menu_dua();

            system("pause");
            system("cls");
            goto menu;
            break;

        }else if(pilihan == 3){
            int jenis_alat, lama_pinjam;
            int total_bayar, bayarr, totall;
            char pinjam;

            menu_awal();
            cout << endl;
            menutiga:
            menu_tiga();

                do {
                    cout << "\n Masukkan jenis alat (1-4)  : ";
                    cin >> jenis_alat;

                    if(jenis_alat == 1){
                        cout << " Lama Peminjaman Alat (hari): ";
                        cin >> lama_pinjam;
                        total_bayar = 30000 * lama_pinjam;
                    }else if(jenis_alat == 2){
                        cout << " Lama Peminjaman Alat (hari): ";
                        cin >> lama_pinjam;
                        total_bayar = 20000 * lama_pinjam;
                    }else if (jenis_alat == 3){
                        cout << " Lama Peminjaman Alat (hari) : ";
                        cin >> lama_pinjam;
                        total_bayar = 5000 * lama_pinjam;
                    }else if (jenis_alat == 4){
                        cout << " Lama Peminjaman Alat (hari) : ";
                        cin >> lama_pinjam;
                        total_bayar = 10000 * lama_pinjam;
                    }else{
                        cout << "\n Angka yang diinputkan salah " << endl << endl;
                        system("pause");
                        system("cls");
                        goto menutiga;
                    }
                    cout << "\n Ingin menyewa lagi?(y/n)   : ";
                    cin >> pinjam;
                    totall += total_bayar;
                } while (pinjam=='y');

                cout << endl;

                cout << " Total yang Harus Dibayar   : Rp. " << totall-534 << endl;
                cout << " Masukkan Uang Tunai        : Rp. ";
                cin >> bayarr;

                if (kembalian_sewa(totall,bayarr) >= 0){
                    cout << " Kembalian Anda             : Rp. " << kembalian_sewa(totall,bayarr) << endl;
                }else {
                    cout << " Uang Anda Kurang           : Rp. " << kembalian_sewa(totall,bayarr) << endl;
                    cout << " Harap Dibayarkan Sesuai Kekurangnya ^.^\n";
                }

                cout << " \n----- Cetak Bukti Penyewaan -----\n";

                system("pause");
                system("cls");

                time_t now = time(0);
                cout << " =================================================\n";
                cout << " |\t\tBUKTI PENYEWAAN                  |\n";
                cout << " =================================================\n";
                cout << " | Waktu Transaksi : " << ctime(&now);
                cout << " |                                               |\n";
                cout << " | Lama Peminjaman : " << lama_pinjam << " hari\t\t\t |\n";
                cout << " | Total Bayar     : Rp. " << totall-534 << "\t\t\t |\n";
                cout << " | Uang Tunai      : Rp. " << bayarr << "\t\t\t |\n";
                cout << " | Kembalian Anda  : RP. " << kembalian_sewa(totall,bayarr) << "\t\t\t |\n";
                cout << " |                                               |\n";
                cout << " |\t   ~ TERIMAKASIH TELAH MENYEWA ~         |\n";
                cout << " |\t     ~ SELAMAT SAMPAI TUJUAN ~           |\n";
                cout << " =================================================\n";

                system("pause");

                ofstream filedibuat;
                filedibuat.open("BuktiPembayaran.txt", ios::app);
                filedibuat << endl;
                filedibuat << " |==============================================|\n";
                filedibuat << " | Waktu Transaksi   : " << ctime(&now);
                filedibuat << " | Total Bayar       : Rp. " << totall-534 << "\t\t|\n";
                filedibuat << " | Uang Tunai        : Rp. " << bayarr << "\t\t|\n";
                filedibuat << " | Kembalian         : Rp. " << kembalian_sewa(totall,bayarr) << "\t\t|\n";
                filedibuat << " |==============================================|";
                filedibuat << endl;
                filedibuat.close();

                system("cls");
                goto menu;
                break;

        } else if (pilihan==4){
            int pilih, nomor;
            int length = 2;

            menu_awal();
            cout << endl;
            menuempat:
            menu_empat();

            cout << "\nMasukan Pilihan <1-4> : ";
            cin >> pilih;

            if (pilih==1){
                buble_int(list_antrian,length);
                cout << "Urutan Berdasarkan Nomor Antrian : \n";
                print_int (list_antrian, length);
            } else if (pilih==2) {
                buble_string(list_pinjam,length);
                cout << "Urutan Berdasarkan Tanggal Peminjaman : \n";
                print_string(list_pinjam, length);
            }else if (pilih==3) {
                buble_string(list_kembali,length);
                cout << "Urutan Berdasarkan  Tanggal Pengembalian: \n";
                print_string(list_kembali, length);
            }else if (pilih==4){
                cout << "\nCari Nomor : ";
                cin >> nomor;

                int posisi = sequential_search(list_antrian,nomor);
                if(posisi!=-1){
                    cout << "\n ===============================================";
                    cout << "\n |      DATA ADMINISTRASI NOMOR ANTRIAN " <<nomor << "     |";
                    cout << "\n ===============================================";
                    cout << "\n | Nama Lengkap           : " << list_nama[posisi];
                    cout << "\n | No.Telpon/HP           : " << list_tlp[posisi];
                    cout << "\n | Tanggal Peminjaman     : " << list_pinjam[posisi];
                    cout << "\n | Tanggal Pengembalian   : " << list_kembali[posisi];
                    cout << "\n | Nomor Antrian          : " << list_antrian[posisi];
                    cout << "\n ===============================================\n";
                } else {
                    cout << "\nMaaf, nomor antrian " << nomor << " tidak ditemukan dalam data administrasi\n";
                }
            }else{
                cout << "\n Angka yang diinputkan salah " << endl << endl;
                system("pause");
                system("cls");
                goto menuempat;
            }
            system("pause");
            system("cls");
            goto menu;
            break;
        }
    } while(pilihan !=5);
    return 0;
}
