#include <iostream>
using namespace std;

// Struktur untuk simpul dalam linked list
struct Mahasiswa {
    string nama;
    int nilai;
    Mahasiswa* next;
};

// Kelas untuk linked list Mahasiswa
class LinkedList {
private:
    Mahasiswa* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Prosedur untuk menambah data mahasiswa di awal linked list
    void tambahData(string nama, int nilai) {
        Mahasiswa* baru = new Mahasiswa;
        baru->nama = nama;
        baru->nilai = nilai;
        baru->next = head;
        head = baru;
    }

    // Prosedur untuk menghapus data mahasiswa berdasarkan nama
    void hapusData(string nama) {
        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;

        // Cari data yang ingin dihapus
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }

        // Jika data ditemukan
        if (temp != nullptr) {
            // Jika data adalah data awal
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Data mahasiswa dengan nama " << nama << " berhasil dihapus." << endl;
        } else {
            cout << "Data mahasiswa dengan nama " << nama << " tidak ditemukan." << endl;
        }
    }

    // Prosedur untuk menampilkan data mahasiswa
    void tampilkanData() {
        Mahasiswa* temp = head;
        cout << "Data Mahasiswa:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", Nilai: " << temp->nilai << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // Fungsi untuk menghitung dan mengembalikan nilai rata-rata
    float hitungRataRata() {
        Mahasiswa* temp = head;
        int total = 0;
        int jumlah_siswa = 0;
        while (temp != nullptr) {
            total += temp->nilai;
            jumlah_siswa++;
            temp = temp->next;
        }
        if (jumlah_siswa == 0) {
            return 0; // Menghindari pembagian oleh nol
        }
        return static_cast<float>(total) / jumlah_siswa;
    }
};

int main() {
    LinkedList daftarMahasiswa;

    // Menambahkan beberapa data mahasiswa
    daftarMahasiswa.tambahData("Lala", 80);
    daftarMahasiswa.tambahData("Nadia", 75);
    daftarMahasiswa.tambahData("Jia", 90);

    // Menampilkan data mahasiswa
    daftarMahasiswa.tampilkanData();

    // Menghitung dan menampilkan nilai rata-rata
    float rata_rata = daftarMahasiswa.hitungRataRata();
    cout << "Nilai rata-rata: " << rata_rata << endl;

    // Menambahkan data mahasiswa baru
    daftarMahasiswa.tambahData("Putri", 85);
    daftarMahasiswa.tambahData("Putra", 95);

    // Menampilkan data mahasiswa setelah penambahan
    daftarMahasiswa.tampilkanData();

    // Menghapus data mahasiswa "Budi"
    daftarMahasiswa.hapusData("Nadia");

    // Menampilkan data mahasiswa setelah penghapusan
    daftarMahasiswa.tampilkanData();

    // Menghitung dan menampilkan nilai rata-rata setelah perubahan
    rata_rata = daftarMahasiswa.hitungRataRata();
    cout << "Nilai rata-rata: " << rata_rata << endl;

    return 0;
}
