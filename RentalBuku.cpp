/* ======================================================================================
Kodingan ini dibuat untuk menyelesaikan Ujian Tengah Praktikum Dasar-Dasar Pemrograman,
yang dibuat oleh Kelompok 8 dengan anggota sebagai berikut : 
1. Berli Anta Atrizki - 2217051076
2. Daffa Rizqan Fairuz - 2217051066
3. Nicholas Vitto Adrianto - 2217051024
====================================================================================== */

#include <iostream>
int hargaTipis = 10000, hargaSedang = 15000, hargaTebal = 20000;
using namespace std;
// List User Tersedia (member)
string username[4] = {"Test Member", "Anta", "Dafariz", "Vitto"};
string password[4] = {"test", "atna", "zirafad", "ottiv"};

// list user =
// 1. Test Biasa
// 2. Anta
// 3. Dafariz
// 4. Vitto
// member = diskon 10% + 5 buku sekaligus

// jenis kategori
string kategori[3] = {"tebal", "sedang", "tipis"};
// List BUKU Tersedia
string buku_tersedia[26] = {"0", "Logika Proposisi", "Kalkulus", "C++ Untuk Pemula", "C Untuk Pemula", "Cara Menjadi Kaya",
                            "Dasar-Dasar Pemrogramman", "Logika asik dan menyenangkan", "Aljabar itu ASIK!", "Tata Cara Ber-ETIKA", "Panduan Hackerrank 10 Miliyar",
                            "Kamus Bahasa Inggris 100 Miliyar", "Lirik Lagu Populer", "Panduan Membaca", "Cara Menghemat uang", "Sepongebob episode 2",
                            "Dora tidak budek", "Panduan Pembuatan Stiker", "How-To Design UI/UX", "Python Easy For Beginner", "C++ For Beginner",
                            "Caro-Kann Defence (Chess Opening)", "Paul Morphy's Game Of Chess", "101 Memes", "100 Cerita Rakyat", "Matematika Dasar"};

// Deklarasi Fungsi
int priceCheck(int tipis, int sedang, int tebal)
{
    // Inisiasi harga buku
    int price;
    // Tiga kondisi yang berkumulatif setiap berapa jenis buku, akan ditambah harganya
    if (tipis > 0)
    {
        for (int i = 1; i <= tipis; i++)
        {
            price = price + hargaTipis;
        }
    }
    if (sedang > 0)
    {
        for (int i = 1; i <= sedang; i++)
        {
            price = price + hargaSedang;
        }
    }
    if (tebal > 0)
    {
        for (int i = 1; i <= tebal; i++)
        {
            price = price + hargaTebal;
        }
    }
    // Mengembalikan harga total
    return price;
}

int main()
{
    bool cek1 = false;
    int tipis = 0, sedang = 0, tebal = 0;
    // user biasa = default maka user_valid = 0;
    bool user_valid = false;
    // deklarasi untuk perbandingan username
    string username_temp, password_temp;
    // opsi ingin masuk sebagai user biasa atau member
    cout << "Selamat datang di Rental Buku";
    cout << "\n ~~Emot Batu~~";
    cout << "\n\n==== Pilih Opsi Berikut ====";
    cout << "\n1. Login Member";
    cout << "\n2. Meminjam Buku";
    cout << "\n\nOpsi Anda : ";
    int opsi;
    cin >> opsi;
    cout << endl;

    // login untuk yang memiliki member
    if (opsi == 1)
    {
        // deklarasi batas percobaan login
        int batas = 3, coba = 0, perc = batas - 1;
        bool cek = false;
        do
        {
            cout << "Masukan Username : ";
            cin >> username_temp;
            cout << "Masukan Password : ";
            cin >> password_temp;
            cout << endl;
            for (int i = 0; i < 4; i++)
            {
                if (username_temp == username[i] && password_temp == password[i])
                {
                    cout << "LOGIN BERHASIL!";
                    cek = true;
                    cek1 = false;
                    coba = 3;
                    user_valid = true;
                    opsi = 2;
                    break;
                }
            }
            if (cek != true && coba < batas)
            {
                cout << "Username dan Password Salah!"
                     << "\nTersisa " << perc-- << " percobaan" << endl;
                coba += 1;
                cek1 = true;
            }
            cout << endl;
        } while (coba < batas);

        if (cek1 == true)
        {
            cout << "Anda Telah Mencoba Sebanyakan 3 Kali! dan Anda Berbohong!" << endl;
            opsi = 2;
        }
    }

    if (opsi == 2)
    {
        int opsi_tmp;
        bool cek2 = false;
        // list buku tersedia
        cout << "\n=========== LIST BUKU ===========" << endl
             << endl;
        for (int i = 1; i < 26; i++)
        {
            cout << i << ".\t"
                 << "\b\b\b\b\b" << buku_tersedia[i] << endl;
        }
        int lanjut = 0;
        do
        {
            if (user_valid == true)
            {
                cout << "\n"
                     << username_temp << ", kamu dapat memilih 5 buku sekaligus untuk dipinjam!";
                // Memilih berapa buku yang ingin di pinjam
                cout << "\nBerapa buku yang ingin anda pinjam : ";
                cin >> opsi_tmp;
                cek2 = true;
                if (opsi_tmp <= 5)
                {
                    lanjut++;
                }
                else
                {
                    cout << "\nMelebihi batas pinjaman!";
                }
            }
            else if (user_valid == false)
            {
                cout << "\nAnda Bukan member, anda hanya bisa memilih 2 buku sekaligus!";
                // Memilih berapa buku yang ingin di pinjam
                cout << "\nBerapa buku yang ingin anda pinjam : ";
                cin >> opsi_tmp;
                if (opsi_tmp <= 2)
                {
                    lanjut++;
                }
                else
                {
                    cout << "\nMelebihi batas pinjaman!\n";
                }
            }
        } while (lanjut < 1);
        // n adalah jenis kategori buku
        int pilih_tmp, jenisBuku, n;

        if (cek2 == true && opsi_tmp <= 5)
        {
            for (int i = 1; i <= opsi_tmp; i++)
            {
                // Memilih Buku yang tersedia di list.
                cout << "\nPilih Buku : ";
                cin >> pilih_tmp;
                int batas1 = 2;
                // Pengecekan Apakah buku sudah tepilih apa belum
                string a = "0";
                if (buku_tersedia[pilih_tmp] != a && batas1 > 0)
                {
                    if (pilih_tmp >= 0 && pilih_tmp < 5)
                    {
                        n = 0;
                        jenisBuku = 3;
                    }
                    else if (pilih_tmp >= 5 && pilih_tmp < 15)
                    {
                        n = 1;
                        jenisBuku = 2;
                    }
                    else if (pilih_tmp >= 15 && pilih_tmp < 25)
                    {
                        n = 2;
                        jenisBuku = 1;
                    }

                    switch (jenisBuku)
                    {
                    case 1:
                        tipis++;
                        break;
                    case 2:
                        sedang++;
                        break;
                    case 3:
                        tebal++;
                        break;
                    default:
                        cout << "Salah input";
                    }
                    cout << "Anda Memilih \"" << buku_tersedia[pilih_tmp] << "\" Untuk dipinjam";
                    cout << "\nBuku ini termasuk dalam kategori " << kategori[n] << endl;
                    buku_tersedia[pilih_tmp] = a;
                }
                else
                {
                    cout << "Buku tidak tersedia/Telah dipinjam!" << endl;
                    cout << "Coba lagi!\n";
                    i--;
                }
            }
        }
        else if (cek2 == false && opsi_tmp <= 2)
        {
            for (int i = 1; i <= opsi_tmp; i++)
            {
                // Memilih Buku yang tersedia di list.
                cout << "\nPilih Buku : ";
                cin >> pilih_tmp;
                int batas1 = 2;
                // Pengecekan Apakah buku sudah tepilih apa belum
                string a = "0";
                if (buku_tersedia[pilih_tmp] != a && batas1 > 0)
                {
                    if (pilih_tmp >= 0 && pilih_tmp < 5)
                    {
                        n = 0;
                        jenisBuku = 3;
                    }
                    else if (pilih_tmp >= 5 && pilih_tmp < 15)
                    {
                        n = 1;
                        jenisBuku = 2;
                    }
                    else if (pilih_tmp >= 15 && pilih_tmp < 25)
                    {
                        n = 2;
                        jenisBuku = 1;
                    }

                    switch (jenisBuku)
                    {
                    case 1:
                        tipis++;
                        break;
                    case 2:
                        sedang++;
                        break;
                    case 3:
                        tebal++;
                        break;
                    default:
                        cout << "Salah input";
                    }
                    cout << "Anda Memilih \"" << buku_tersedia[pilih_tmp] << "\" Untuk dipinjam";
                    cout << "\nBuku ini termasuk dalam kategori " << kategori[n] << endl;
                    buku_tersedia[pilih_tmp] = a;
                }
                else
                {
                    cout << "Buku tidak tersedia/Telah dipinjam!" << endl;
                    cout << "Coba lagi!\n";
                    i--;
                }
            }
        }
    }
    // Pembayaran. Kondisi apakah member atau bukan
    if (user_valid == false)
    {
        cout << "\nTotal harga yang dibayar : " << priceCheck(tipis, sedang, tebal);
    }
    else
    {
        cout << "\nTotal harga yang dibayar : " << priceCheck(tipis, sedang, tebal) * 0.9;
    }

    return 0;
}
