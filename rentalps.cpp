#include <iostream>
#include <cstdlib> // Untuk system("clear") atau system("cls")

using namespace std;

// Fungsi untuk membersihkan layar
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Untuk paket masukan jenis PS nya terlebih dahulu baru paket nya menyesuaikan ps nya

// Data Paket
const int JUMLAH_PAKET = 4;
string daftarPaket[JUMLAH_PAKET][2] = {
    {"Paket 1 (PS 3, Indomie, Air Mineral)", "40000"},
    {"Paket 2 (PS 4, Kentang Goreng, Lemon Tea)", "50000"},
    {"Paket 3 (PS 5, Mix Platter, Milk Shake)", "65000"},
    {"Paket 4 (Nintendo Switch, Nasgor, Soda Gembira)", "75000"}
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
};

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

// Fungsi untuk menu paket
void menuPaket() {
    while (true) {
        clearScreen();
        cout << "=== Pilih Paket ===\n";
        for (int i = 0; i < JUMLAH_PAKET; i++) {
            cout << i + 1 << ". " << daftarPaket[i][0] << " - Rp" << daftarPaket[i][1] << "\n";
        }

        int pilihan;
        cout << "Pilih paket (1-4): ";
        cin >> pilihan;

        // Pengecekan pilihan paket di antara 1 sampai jumlah paket yang ada, which is 4
        if (pilihan >= 1 && pilihan <= JUMLAH_PAKET) {
            int harga = stoi(daftarPaket[pilihan - 1][1]);
            string deskripsi = "Paket: " + daftarPaket[pilihan - 1][0] + "\nHarga: Rp" + to_string(harga);
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

// Fungsi untuk menu custom
void menuCustom() {
    while (true) {
        clearScreen();
        cout << "=== Custom Menu ===\n";
        cout << "List PS:\n";
        for (int i = 0; i < JUMLAH_PS; i++) {
            cout << i + 1 << ". " << daftarPS[i][0] << " - Rp" << daftarPS[i][1] << "\n";
        }

        cout << "\nList Makanan:\n";
        for (int i = 0; i < JUMLAH_MAKANAN; i++) {
            cout << i + 5 << ". " << daftarMakanan[i][0] << " - Rp" << daftarMakanan[i][1] << "\n";
        }

        int pilihan;
        int total = 0;
        string pesanan = "Pesanan Anda:\n"; 

        do {
            cout << "\nPilih item (1-8, 0 untuk selesai): ";
            cin >> pilihan;

            if (pilihan >= 1 && pilihan <= 4) {
                pesanan += "- " + string(daftarPS[pilihan - 1][0]) + " (Rp" + daftarPS[pilihan - 1][1] + ")\n";
                total += stoi(daftarPS[pilihan - 1][1]);
            } else if (pilihan >= 5 && pilihan <= 11) {
                pesanan += "- " + string(daftarMakanan[pilihan - 5][0]) + " (Rp" + daftarMakanan[pilihan - 5][1] + ")\n";
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
