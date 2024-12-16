// NOVITA
#include <iostream>
#include <cstdlib> // Untuk system("clear") atau system("cls")
#include <string>

using namespace std;

// Fungsi untuk membersihkan layar
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// FAJRI
// Data Paket
const int JUMLAH_PAKET = 4;
string daftarPaket[JUMLAH_PAKET][2] = {
    {"Paket 1 (Indomie, Air Mineral)", "16000"},
    {"Paket 2 (Kentang Goreng, Lemon Tea)", "16500"},
    {"Paket 3 (Mix Platter, Milk Shake)", "27000"},
    {"Paket 4 (Nasgor, Soda Gembira)", "35000"}
};

// Data PS dan Makanan
const int JUMLAH_PS = 4, JUMLAH_MAKANAN = 8;
string daftarPS[JUMLAH_PS][2] = {
    {"PS 3", "30000"},
    {"PS 4", "50000"},
    {"PS 5", "75000"},
    {"Nintendo Switch", "100000"}
};

string daftarMakanan[JUMLAH_MAKANAN][2] = {
    {"Indomie", "10000"},
    {"Mix Platter", "15000"},
    {"Kentang Goreng", "10000"},
    {"Nasi Goreng", "20000"},
    {"Lemon Tea", "6500"},
    {"Milk Shake", "12000"},
    {"Air Mineral", "6000"},
    {"Soda Gembira", "15000"}
};

// ARIF
// Fungsi untuk menghitung harga PS per 6 jam
int hitungHargaPS6Jam(int hargaPerHari) {
    return hargaPerHari / 4; // Harga 6 jam adalah 1/4 dari harga per hari
}

// Fungsi untuk menampilkan hasil transaksi
void tampilkanHasilTransaksi(string deskripsi, int totalHarga) {
    clearScreen();
    cout << "=== Hasil Transaksi ===\n";
    cout << deskripsi << "\n";
    cout << "Total harga: Rp" << totalHarga << "\n";
    cout << "Terima kasih telah menggunakan layanan kami!\n";
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// AMIN
// Fungsi untuk menu paket
void menuPaket() {
    while (true) {
        clearScreen();

        // Tampilkan daftar PS terlebih dahulu
        cout << "=== Pilih Jenis PS ===\n";
        for (int i = 0; i < JUMLAH_PS; i++) {
            int hargaPS6Jam = hitungHargaPS6Jam(stoi(daftarPS[i][1]));
            cout << i + 1 << ". " << daftarPS[i][0] << " - Rp" << hargaPS6Jam << " (6 jam)\n";
        }

        int pilihanPS;
        cout << "Pilih PS (1-4): ";
        cin >> pilihanPS;

        if (pilihanPS < 1 || pilihanPS > JUMLAH_PS) {
            cout << "Pilihan PS tidak valid.\n";
            continue; // Kembali ke menu jika pilihan tidak valid
        }

        // Pilihan PS valid, sesuaikan paket
        string psDipilih = daftarPS[pilihanPS - 1][0];
        int hargaPS6Jam = hitungHargaPS6Jam(stoi(daftarPS[pilihanPS - 1][1]));

        clearScreen();
        cout << "=== Pilih Paket untuk " << psDipilih << " (6 jam) ===\n";

        for (int i = 0; i < JUMLAH_PAKET; i++) {
            int hargaDasarPaket = stoi(daftarPaket[i][1]);
            int totalHargaPaket = hargaDasarPaket + hargaPS6Jam; // Total harga paket = harga paket paten + harga PS 6 jam
            cout << i + 1 << ". " << daftarPaket[i][0] << " dengan " << psDipilih << " - Rp" << totalHargaPaket << "\n";
        }

        int pilihanPaket;
        cout << "Pilih paket (1-4): ";
        cin >> pilihanPaket;

        if (pilihanPaket >= 1 && pilihanPaket <= JUMLAH_PAKET) {
            int hargaDasarPaket = stoi(daftarPaket[pilihanPaket - 1][1]);
            int totalHarga = hargaDasarPaket + hargaPS6Jam;
            string deskripsi = "Paket: " + daftarPaket[pilihanPaket - 1][0] + "\nPS: " + psDipilih + " (6 jam)\nHarga Paket: Rp" + to_string(totalHarga);
            cout << "\n" << deskripsi << "\nApakah Anda ingin melanjutkan? (y/n): ";
            char konfirmasi;
            cin >> konfirmasi;

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                tampilkanHasilTransaksi(deskripsi, totalHarga);
                break;
            } else {
                continue; // Kembali ke menu paket
            }
        } else {
            cout << "Pilihan paket tidak valid.\n";
        }
    }
}

// ROMI
// Fungsi untuk menu rental PS
void menuRental() {
    while (true) {
        clearScreen();
        cout << "=== Rental PS ===\n";
        for (int i = 0; i < JUMLAH_PS; i++) {
            cout << i + 1 << ". " << daftarPS[i][0] << " - Rp" << daftarPS[i][1] << "/hari\n";
        }

        int pilihan, hari;
        cout << "Pilih PS (1-4): ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= JUMLAH_PS) {
            cout << "Masukkan jumlah hari: ";
            cin >> hari;

            int harga = stoi(daftarPS[pilihan - 1][1]) * hari;
            string deskripsi = "PS: " + string(daftarPS[pilihan - 1][0]) + "\nDurasi: " + to_string(hari) + " hari\nHarga: Rp" + to_string(harga);
            cout << "\n" << deskripsi << "\nApakah Anda ingin melanjutkan? (y/n): ";
            char konfirmasi;
            cin >> konfirmasi;

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                tampilkanHasilTransaksi(deskripsi, harga);
                break;
            }
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }
}

// MAIN
// Fungsi untuk menu custom
void menuCustom() {
    while (true) {
        clearScreen();
        cout << "=== Custom Menu ===\n";
        cout << "List PS:\n";
        for (int i = 0; i < JUMLAH_PS; i++) {
            cout << i + 1 << ". " << daftarPS[i][0] << " - Rp" << hitungHargaPS6Jam(stoi(daftarPS[i][1])) << " (6 jam)\n";
        }

        cout << "\nList Makanan:\n";
        for (int i = 0; i < JUMLAH_MAKANAN; i++) {
            cout << i + 5 << ". " << daftarMakanan[i][0] << " - Rp" << daftarMakanan[i][1] << "\n";
        }

        int pilihan;
        int total = 0;
        string pesanan = "Pesanan Anda:\n"; 

        do {
            cout << "\nPilih item (1-12, 0 untuk selesai): ";
            cin >> pilihan;

            if (pilihan >= 1 && pilihan <= 4) {
                int hargaPS6Jam = hitungHargaPS6Jam(stoi(daftarPS[pilihan - 1][1]));
                pesanan += "- " + string(daftarPS[pilihan - 1][0]) + " (6 jam) - Rp" + to_string(hargaPS6Jam) + "\n";
                total += hargaPS6Jam;
            } else if (pilihan >= 5 && pilihan <= 12) {
                pesanan += "- " + string(daftarMakanan[pilihan - 5][0]) + " - Rp" + daftarMakanan[pilihan - 5][1] + "\n";
                total += stoi(daftarMakanan[pilihan - 5][1]);
            } else if (pilihan != 0) {
                cout << "Pilihan tidak valid.\n";
            }
        } while (pilihan != 0);

        cout << "\n" << pesanan << "Total harga: Rp" << total << "\nApakah Anda ingin melanjutkan? (y/n): ";
        char konfirmasi;
        cin >> konfirmasi;

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            tampilkanHasilTransaksi(pesanan, total);
            break;
        }
    }
}

// Menu utama
int main() {
    while (true) {
        clearScreen();
        cout << "=== Menu Utama ===\n";
        cout << "1. Paket\n";
        cout << "2. Rental\n";
        cout << "3. Custom\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuPaket();
                break;
            case 2:
                menuRental();
                break;
            case 3:
                menuCustom();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi ini.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}
