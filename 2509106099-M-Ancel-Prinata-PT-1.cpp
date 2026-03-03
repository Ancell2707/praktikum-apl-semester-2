#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, password;
    string correctname = "ancel";   
    string correctPass = "099";         
    int percobaan = 0;
    bool loginBerhasil = false;

    cout << "========================================" << endl;
    cout << "         PROGRAM PENEBAK  WAKTU         " << endl;
    cout << "========================================" << endl;

    while (percobaan < 3) {
        cout << "\n--- LOGIN ---" << endl;
        cout << "name     : ";
        cin >> name;
        cout << "Password (3 digit terakhir NIM): ";
        cin >> password;

        if (name == correctname && password == correctPass) {
            loginBerhasil = true;
            cout << "\nLogin berhasil! Selamat datang, " << name << "!" << endl;
            break;
        } else {
            percobaan++;
            int sisa = 3 - percobaan;
            if (sisa > 0)
                cout << "name atau password salah! Sisa percobaan: " << sisa << endl;
        }
    }

    if (!loginBerhasil) {
        cout << "\nsorry wall gagal login 3 kali sudah. Program berhenti." << endl;
        return 0;
    }
    int pilihan;
    do {
        cout << "\n======================================" << endl;
        cout << "             MENU UTAMA                 " << endl;
        cout << "========================================" << endl;
        cout << "1. Konversi jam     -> Menit dan Detik"   << endl;
        cout << "2. Konversi Menit  -> Jam dan Detik"     << endl;
        cout << "3. Konversi Detik  -> Jam dan Menit"     << endl;
        cout << "4. out ikam"                               << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan aja mau yang mana: ";
        cin >> pilihan;

        if (pilihan == 1) {
            double jam;
            cout << "\nMasukkan nilai Jam: ";
            cin >> jam;
            double menit = jam * 60;
            double detik = jam * 3600;
            cout << "----------------------------------------" << endl;
            cout << "Hasil Konversi:" << endl;
            cout << jam << " Jam = " << menit << " Menit" << endl;
            cout << jam << " Jam = " << detik << " Detik" << endl;

        } else if (pilihan == 2) {
            double menit;
            cout << "\nMasukkan nilai Menit: ";
            cin >> menit;
            double jam  = menit / 60;
            double detik = menit * 60;
            cout << "----------------------------------------" << endl;
            cout << "Hasil Konversi:" << endl;
            cout << menit << " Menit = " << jam   << " Jam"   << endl;
            cout << menit << " Menit = " << detik << " Detik" << endl;

        } else if (pilihan == 3) {
            double detik;
            cout << "\nMasukkan nilai Detik: ";
            cin >> detik;
            double jam   = detik / 3600;
            double menit = detik / 60;
            cout << "----------------------------------------" << endl;
            cout << "Hasil Konversi:" << endl;
            cout << detik << " Detik = " << jam   << " Jam"   << endl;
            cout << detik << " Detik = " << menit << " Menit" << endl;

        } else if (pilihan == 4) {
            cout << "\nTerima kasih telah menggunakan program ku. Sampai jumpa dan jangan balik lagi!" << endl;

        } else {
            cout << "\nPilihan ikam tidak valid  wall ! pilih yang ada aja sudah  1-4." << endl;
        }

    } while (pilihan != 4);

    return 0;
}