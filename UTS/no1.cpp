#include <iostream>
using namespace std;

int main() {
    system("CLS");
    int n;
    cout << "Masukkan jumlah pesanan: "; cin >> n;
    cout << endl;

    string* nama_hewan = new string[n];
    string* menu = new string[n];
    int* status = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Pesanan " << i + 1 << endl;
        cout << "Nama hewan: "; cin >> nama_hewan[i];
        cin.ignore();
        cout << "Menu pesanan: "; getline(cin, menu[i]);
        cout << "Status VIP (1=biasa, 2=VIP): "; cin >> status[i];
        cout << endl;
    }

    cout << "\n--- Daftar Pesanan (Prioritas VIP) ---\n";
    int nomor = 1;
    for (int i = 0; i < n; i++) {
        if (status[i] == 2) {
            for (int j = 0; j < nama_hewan[i].length(); j++) {
                nama_hewan[i][j] = toupper(nama_hewan[i][j]);
            }
            cout << nomor++ << ". " << nama_hewan[i] << " - " << menu[i] << " [VIP]" << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            for (int j = 0; j < nama_hewan[i].length(); j++) {
                nama_hewan[i][j] = toupper(nama_hewan[i][j]);
            }
            cout << nomor++ << ". " << nama_hewan[i] << " - " << menu[i] << endl;
        }
    }

    delete[] nama_hewan;
    delete[] menu;
    delete[] status;

    return 0;
}