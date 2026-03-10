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