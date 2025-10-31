#include<iostream>
using namespace std;

struct node{
    string n_b;
    long harga;
    int jumlah;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertFirst(string nama_barang, long harga_barang, int jumlah_barang){
    node *newNode = new node;
    newNode -> n_b = nama_barang;
    newNode -> harga = harga_barang;
    newNode -> jumlah = jumlah_barang;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
    cout<<"[ "<<nama_barang<<" | "<<harga_barang<<" | "<<jumlah_barang<<" ]"<<endl;
}

void insertLast(string nama_barang, long harga_barang, int jumlah_barang){
    node *newNode = new node;
    newNode -> n_b = nama_barang;
    newNode -> harga = harga_barang;
    newNode -> jumlah = jumlah_barang;
    newNode -> next = NULL;
    
    if(head==NULL){
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
    cout<<"[ "<<nama_barang<<" | "<<harga_barang<<" | "<<jumlah_barang<<" ]"<<endl;
}

void insertAfter(string target_nama, string nama_barang, long harga_barang, int jumlah_barang){
    node *p = head;
    while (p != NULL && p->n_b != target_nama){
        p = p->next;
    }

    if (p == NULL){
        cout << "Barang dengan nama \"" << target_nama << "\" tidak ditemukan.\n";
        return;
    }

    node *newNode = new node;
    newNode->n_b = nama_barang;
    newNode->harga = harga_barang;
    newNode->jumlah = jumlah_barang;
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail){
        tail = newNode;
    }
}

void hapusBarang(string nama_barang){
    node *p = head;
    node *prev = NULL;

    while (p != NULL && p -> n_b != nama_barang){
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout<< "Barang " << nama_barang << " tidak ditemukan.";
        return;
    }

    if (prev == NULL){
        head = p -> next;
    }
    else {
        prev -> next = p -> next;
    }

    if (p == tail){
        tail = prev;
    }

    delete p;
    cout << "Barang " << nama_barang << " berhasil dihapus."<<endl;
    cout<<endl;
}

void tampilkanKeranjang(){
    node *p = head;
    int total_barang = 0;
    long total_harga = 0;

    while (p != NULL){
        cout << p->n_b << " - Rp" << p->harga << " x" << p->jumlah << endl;
        total_barang++;
        total_harga += p->harga * p->jumlah;
        p = p->next;
    }

    cout << "Total barang: " << total_barang << endl;
    cout << "Total harga: Rp" << total_harga << endl;
    cout<<endl;
}


int main(){
    int n, pilih;
    string nama_hapus;
    balek:
    while (true){
    cout<<"===Keranjang Belanja Ajaib==="<<endl;
    cout<<"1. Tambah Barang"<<endl;
    cout<<"2. Sisipkan Barang "<<endl;
    cout<<"3. Hapus Barang"<<endl;
    cout<<"4. Tampilkan Barang"<<endl;
    cout<<"5. Keluar program"<<endl;
    cout<<"Pilih: ";cin>>pilih;
    cout<<endl;
    cout<<endl;

    if(pilih == 1){
        cout<<"Masukkan jumlah barang awal: ";cin>>n;
        for(int i = 0; i<n; i++){
            string nama;
            long harga;
            int jumlah;
            cout<< "Barang " << i + 1 << ":\n";
            cout<<"Nama: "; cin.ignore(); getline(cin, nama);
            cout<<"Harga: "; cin >> harga;
            cout<<"Jumlah: "; cin >> jumlah;
            if (head == NULL){
                insertFirst(nama, harga, jumlah);
            }
            else {
                insertLast(nama, harga, jumlah);
            }
            cout<<endl;
        }
    }
    else if(pilih == 2){
        string target,sisip; long harga; int jumlah;
        cout<<"Target Sisipan: ";cin>>target;
        cout<<"Apa yang mau disisipkan: ";cin>>sisip;
        cout<<"Harga: ";cin>>harga;
        cout<<"Jumlah: ";cin>>jumlah;
        insertAfter(target, sisip, harga, jumlah);
    }
    else if (pilih == 3){
        cout<< "Masukkan nama barang yang ingin dihapus: ";
        cin.ignore(); getline(cin, nama_hapus);
        hapusBarang(nama_hapus);
    }
    else if (pilih == 4){
        cout<<"Isi Keranjang Belanja:\n";
        tampilkanKeranjang();
    }
    else if (pilih == 5){
        break;
    }
    else{
        goto balek;
    }
    }
}