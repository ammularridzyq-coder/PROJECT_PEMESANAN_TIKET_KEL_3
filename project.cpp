#include <iostream>
using namespace std;

const int MAX = 100;
string nama[MAX], rute[MAX], tanggal[MAX];
int jumlah[MAX], total[MAX];
int jumlahPelanggan = 0;

int hitungTotal(int jumlah, int harga) {
    return jumlah * harga;
}

void cetakStruk(string nama, string rute, string tanggal, int jumlah, int total) {
    cout << "\n===== STRUK PEMBELIAN =====\n";
    cout << "Nama        : " << nama << endl;
    cout << "Rute        : " << rute << endl;
    cout << "Tanggal     : " << tanggal << endl;
    cout << "Jumlah      : " << jumlah << endl;
    cout << "Total Bayar : Rp " << total << endl;
    cout << "===========================\n";
}

void daftarPelanggan() {
    cout << "\n===== DAFTAR PELANGGAN =====\n";
    if (jumlahPelanggan == 0) {
        cout << "Belum ada data pelanggan.\n";
        return;
    }
    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << i + 1 << ". Nama: " << nama[i]
             << " | Rute: " << rute[i]
             << " | Tanggal: " << tanggal[i]
             << " | Jumlah: " << jumlah[i]
             << " | Total: Rp " << total[i] << endl;
    }
}
void statistikPenjualan() {
    cout << "\n===== STATISTIK PENJUALAN =====\n";
    cout << "Total pelanggan  : " << jumlahPelanggan << endl;
    int pendapatan = 0;
    for (int i = 0; i < jumlahPelanggan; i++) pendapatan += total[i];
    cout << "Total pendapatan : Rp " << pendapatan << endl;
}
void riwayatPemesanan() {
    if (jumlahPelanggan == 0) {
        cout << "\nBelum ada riwayat pemesanan.\n";
        return;
    }

    cout << "\n===== RIWAYAT PEMESANAN =====\n";
    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << nama[i] << " || " << rute[i] << " || " << tanggal[i]
             << " || Tiket: " << jumlah[i] << endl;
    }
    cout << "\nIngin mencari riwayat berdasarkan apa?\n";
    cout << "1. Nama\n2. Tanggal Keberangkatan\n3. Rute\nPilih: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    string cari;
    bool ditemukan = false;

    if (pilihan == 1) {
        cout << "Masukkan nama yang ingin dicari: ";
        getline(cin, cari);
    } else if (pilihan == 2) {
        cout << "Masukkan tanggal keberangkatan: ";
        getline(cin, cari);
    } else if (pilihan == 3) {
        cout << "Masukkan rute: ";
        getline(cin, cari);
    } else {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    cout << "\n===== HASIL PENCARIAN =====\n";
    for (int i = 0; i < jumlahPelanggan; i++) {
        if ((pilihan == 1 && nama[i] == cari) ||
            (pilihan == 2 && tanggal[i] == cari) ||
            (pilihan == 3 && rute[i] == cari)) {
            cout << nama[i] << " || " << rute[i] << " || " << tanggal[i]
                 << " || Tiket: " << jumlah[i] << " || Total: Rp " << total[i] << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan)
        cout << "Data tidak ditemukan.\n";
}

void pemesananTiket() {
    char ulang;
    do {
        cout << "\n===== PEMESANAN TIKET KERETA =====\n";
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, nama[jumlahPelanggan]);

        cout << "\nPilih rute (1-5):\n";
        cout << "1. Palu - Makassar\n2. Palu - Mamuju\n3. Palu - Manado\n4. Palu - Gorontalo\n5. Palu - Kendari\n";
        int pilihRute, harga = 0;
        cout << "Pilihan Anda: ";
        cin >> pilihRute;
        cin.ignore();

        switch (pilihRute) {
            case 1: rute[jumlahPelanggan] = "Palu - Makassar"; harga = 200000; break;
            case 2: rute[jumlahPelanggan] = "Palu - Mamuju"; harga = 180000; break;
            case 3: rute[jumlahPelanggan] = "Palu - Manado"; harga = 220000; break;
            case 4: rute[jumlahPelanggan] = "Palu - Gorontalo"; harga = 210000; break;
            case 5: rute[jumlahPelanggan] = "Palu - Kendari"; harga = 190000; break;
            default: cout << "Rute tidak valid!\n"; return;
        }

        cout << "Masukkan tanggal keberangkatan (dd/mm/yyyy): ";
        getline(cin, tanggal[jumlahPelanggan]);
        cout << "Masukkan jumlah tiket: ";
        cin >> jumlah[jumlahPelanggan];

        total[jumlahPelanggan] = hitungTotal(jumlah[jumlahPelanggan], harga);
        cetakStruk(nama[jumlahPelanggan], rute[jumlahPelanggan], tanggal[jumlahPelanggan], jumlah[jumlahPelanggan], total[jumlahPelanggan]);

        jumlahPelanggan++;

        cout << "Tambah pelanggan lagi? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
}
int main() {
    int pilihan;
    do {
        cout << "\n===== SISTEM PEMESANAN TIKET KERETA =====\n";
        cout << "1. Pemesanan Tiket\n";
        cout << "2. Daftar Pelanggan\n";
        cout << "3. Statistik Penjualan\n";
        cout << "4. Riwayat & Pencarian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: pemesananTiket(); break;
            case 2: daftarPelanggan(); break;
            case 3: statistikPenjualan(); break;
            case 4: riwayatPemesanan(); break;
            case 5: cout << "\nTerima kasih telah menggunakan sistem pemesanan tiket!\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}