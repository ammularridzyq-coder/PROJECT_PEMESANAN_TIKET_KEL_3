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
