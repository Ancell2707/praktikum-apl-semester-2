#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_STOK 100
#define MAX_KAT  4

struct AlatMusik {
    int    id;
    string nama;
    int    harga;
    int    jumlah;
    string kategori;
};

AlatMusik stok[MAX_STOK] = {
    {1, "Gitar",     1500000, 5, "Senar"},
    {2, "Piano",     5000000, 2, "Keyboard"},
    {3, "Drum",      3000000, 3, "Perkusi"},
    {4, "Saxophone", 2500000, 1, "Tiup"}
};
int jumlahStok = 4;

string daftarKategori[MAX_KAT] = {"Senar", "Tiup", "Perkusi", "Keyboard"};

const string ATAP   =        string(62, '_');
const string LANTAI = "||" + string(58, '_') + "||";
const string SPASI  = "||" + string(58, ' ') + "||";

void cls() {
    for (int i = 0; i < 50; i++) cout << "\n";
}

void pause() {
    cout << "\nEnter untuk lanjut...";
    cin.ignore();
    cin.get();
}

string toLower(string s) {
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;   // 
    return s;
}
string capitalize(string s) {
    if (!s.empty())
        if (s[0] >= 'a' && s[0] <= 'z')
            s[0] = s[0] - 32;   // 
    return s;
}

bool kategoriValid(const string& kat) {
    for (int i = 0; i < MAX_KAT; i++)
        if (daftarKategori[i] == kat) return true;
    return false;
}   

int nextId() {
    int maxId = 0;
    for (int i = 0; i < jumlahStok; i++)
        if (stok[i].id > maxId) maxId = stok[i].id;
    return maxId + 1;
}

void cetakGarisTabel() {
    cout << "+" << string(6,'-')
         << "+" << string(20,'-')
         << "+" << string(14,'-')
         << "+" << string(8,'-')
         << "+" << string(12,'-')
         << "+\n";
}

void tampilStok(bool adminMode) {
    cls();
    cout << ATAP << "\n";
    if (adminMode)
        cout << "||" << setw(58) << left << "  Daftar Stok Alat Musik [ADMIN]" << "||\n";
    else
        cout << "||" << setw(58) << left << "  Daftar Stok Alat Musik (Hanya Lihat)" << "||\n";
    cout << LANTAI << "\n\n";

    if (jumlahStok == 0) {
        cout << "  (Belum ada data)\n";
        return;
    }

    cetakGarisTabel();
    cout << "| " << left
         << setw(5)  << "ID"         << "| "
         << setw(19) << "Nama"       << "| "
         << setw(13) << "Harga (Rp)" << "| "
         << setw(7)  << "Stok"       << "| "
         << setw(11) << "Kategori"
         << "|\n";
    cetakGarisTabel();

    for (int i = 0; i < jumlahStok; i++) {
        cout << "| " << left
             << setw(5)  << stok[i].id       << "| "
             << setw(19) << stok[i].nama     << "| "
             << setw(13) << stok[i].harga    << "| "
             << setw(7)  << stok[i].jumlah   << "| "
             << setw(11) << stok[i].kategori
             << "|\n";
    }
    cetakGarisTabel();
    cout << "  Total: " << jumlahStok << " item\n";
}


void tambahItem() {
    if (jumlahStok >= MAX_STOK) {
        cout << "\n  Array penuh! Maksimal " << MAX_STOK << " item.\n";
        pause();
        return;
    }

    cls();
    cout << ATAP << "\n";
    cout << "||" << setw(58) << left << "  Tambah Item Baru" << "||\n";
    cout << LANTAI << "\n\n";

    AlatMusik baru;
    baru.id = nextId();

    cout << "  Nama alat musik : "; getline(cin, baru.nama);
    cout << "  Harga (Rp)      : "; cin >> baru.harga;
    cout << "  Jumlah stok     : "; cin >> baru.jumlah;
    cin.ignore();

    cout << "\n  Kategori tersedia:\n";
    for (int i = 0; i < MAX_KAT; i++)
        cout << "    - " << daftarKategori[i] << "\n";

    cout << "  Pilih kategori  : ";
    getline(cin, baru.kategori);
    baru.kategori = capitalize(baru.kategori);

    if (kategoriValid(baru.kategori)) {
        stok[jumlahStok] = baru;
        jumlahStok++;
        cout << "\n  Item \"" << baru.nama << "\" ditambahkan (ID: " << baru.id << ").\n";
    } else {
        cout << "\n  Kategori tidak valid!\n";
    }
    pause();
}


void ubahStok() {
    if (jumlahStok == 0) { cout << "\n  Stok kosong!\n"; pause(); return; }

    tampilStok(true);

    int idCari;
    cout << "\n  ID item yang ingin diubah stoknya: ";
    cin >> idCari;
    cin.ignore();

    for (int i = 0; i < jumlahStok; i++) {
        if (stok[i].id == idCari) {
            cout << "  Stok baru untuk \"" << stok[i].nama
                 << "\" (saat ini: " << stok[i].jumlah << "): ";
            cin >> stok[i].jumlah;
            cin.ignore();
            cout << "  Stok berhasil diubah!\n";
            pause();
            return;
        }
    }
    cout << "  ID tidak ditemukan!\n";
    pause();
}


void hapusItem() {
    if (jumlahStok == 0) { cout << "\n  Stok kosong!\n"; pause(); return; }

    tampilStok(true);

    string namaHapus;
    cout << "\n  Nama item yang ingin dihapus: ";
    getline(cin, namaHapus);

    for (int i = 0; i < jumlahStok; i++) {
        if (toLower(stok[i].nama) == toLower(namaHapus)) {
            string namaTemp = stok[i].nama;

          
            for (int j = i; j < jumlahStok - 1; j++)
                stok[j] = stok[j + 1];
            jumlahStok--;

            cout << "  Item \"" << namaTemp << "\" berhasil dihapus!\n";
            pause();
            return;
        }
    }

    cls();
    cout << ATAP << "\n";
    cout << "||" << setw(58) << left << "  Item Tidak Ditemukan" << "||\n";
    cout << LANTAI << "\n";
    pause();
}


void cariKategori() {
    cout << "\n  Kategori tersedia:\n";
    for (int i = 0; i < MAX_KAT; i++)
        cout << "    - " << daftarKategori[i] << "\n";

    string cari;
    cout << "\n  Masukkan kategori: ";
    getline(cin, cari);
    cari = capitalize(cari);

    bool ada = false;
    for (int i = 0; i < jumlahStok; i++) {
        if (stok[i].kategori == cari) {
            if (!ada) {
                cout << "\n";
                cetakGarisTabel();
                cout << "| " << left
                     << setw(5)  << "ID"         << "| "
                     << setw(19) << "Nama"       << "| "
                     << setw(13) << "Harga (Rp)" << "| "
                     << setw(7)  << "Stok"       << "| "
                     << setw(11) << "Kategori"
                     << "|\n";
                cetakGarisTabel();
                ada = true;
            }
            cout << "| " << left
                 << setw(5)  << stok[i].id       << "| "
                 << setw(19) << stok[i].nama     << "| "
                 << setw(13) << stok[i].harga    << "| "
                 << setw(7)  << stok[i].jumlah   << "| "
                 << setw(11) << stok[i].kategori
                 << "|\n";
        }
    }
    if (ada) cetakGarisTabel();
    else cout << "\n  Tidak ada item di kategori \"" << cari << "\".\n";
    pause();
}


void menuUser() {
    while (true) {
        cls();
        cout << ATAP << "\n";
        cout << "||" << setw(58) << left << "  MENU USER (Pengguna)" << "||\n";
        cout << SPASI << "\n";
        cout << "||" << left << setw(58) << "  1. Tampilkan Stok"                 << "||\n";
        cout << "||" << left << setw(58) << "  2. Cari Item Berdasarkan Kategori" << "||\n";
        cout << "||" << left << setw(58) << "  3. Kembali ke Menu Utama"          << "||\n";
        cout << LANTAI << "\n\n";

        string pilihan;
        cout << "  Pilih menu (1-3): ";
        cin >> pilihan;
        cin.ignore();

        if      (pilihan == "1") { tampilStok(false); pause(); }
        else if (pilihan == "2") { cariKategori(); }
        else if (pilihan == "3") { break; }
        else { cout << "\n  Pilihan tidak valid!\n"; pause(); }
    }
}


void menuAdmin() {
    while (true) {
        cls();
        cout << ATAP << "\n";
        cout << "||" << setw(58) << left << "  MENU ADMIN" << "||\n";
        cout << SPASI << "\n";
        cout << "||" << left << setw(58) << "  1. Tampilkan Stok                  "   << "||\n";
        cout << "||" << left << setw(58) << "  2. Tambah Item Baru                  " << "||\n";
        cout << "||" << left << setw(58) << "  3. Ubah Stok Item                    " << "||\n";
        cout << "||" << left << setw(58) << "  4. Hapus Item                         " << "||\n";
        cout << "||" << left << setw(58) << "  5. Cari Item Berdasarkan Kategori"     << "||\n";
        cout << "||" << left << setw(58) << "  6. Kembali ke Menu Utama"              << "||\n";
        cout << LANTAI << "\n\n";

        string pilihan;
        cout << "  Pilih menu (1-6): ";
        cin >> pilihan;
        cin.ignore();

        if      (pilihan == "1") { tampilStok(true); pause(); }
        else if (pilihan == "2") { tambahItem(); }
        else if (pilihan == "3") { ubahStok();   }
        else if (pilihan == "4") { hapusItem();  }
        else if (pilihan == "5") { cariKategori(); }
        else if (pilihan == "6") { break; }
        else { cout << "\n  Pilihan tidak valid!\n"; pause(); }
    }
}


int main() {
    while (true) {
        cls();
        cout << ATAP << "\n";
        cout << "||" << setw(58) << left << "       SELAMAT DATANG DI TOKO ALAT MUSIK" << "||\n";
        cout << SPASI << "\n";
        cout << "||" << left << setw(58) << "  1. Masuk sebagai User  - Akses Terbatas" << "||\n";
        cout << "||" << left << setw(58) << "  2. Masuk sebagai Admin - Akses Penuh"    << "||\n";
        cout << "||" << left << setw(58) << "  3. Keluar"                                << "||\n";
        cout << LANTAI << "\n\n";

        string role;
        cout << "  Pilih role (1-3): ";
        cin >> role;
        cin.ignore();

        if      (role == "1") { menuUser();  }
        else if (role == "2") { menuAdmin(); }
        else if (role == "3") {
            cout << "\n  Terima kasih telah mengunjungi Toko Alat Musik!\n\n";
            break;
        } else {
            cout << "\n  Pilihan tidak valid!\n";
            pause();
        }
    }
    return 0;
}
