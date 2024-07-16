#include <iostream>
using namespace std;

// Maziya Ats Tsaqofi
// 16 Juli 2024
// Final Exam 2024

// Struktur node queue
typedef struct queue_node {
    int data;
    queue_node* next;
    queue_node* prev;
} antrianNode;

// List head dan front queue
typedef struct list {
    queue_node* head;
    queue_node* front;
    queue_node* rear;
} antrianList;

int awal_antrian = 0;

// Queue
antrianList queue = {nullptr, nullptr, nullptr};

// Fungsi untuk memeriksa apakah queue kosong
bool empty() {
    return queue.head == nullptr;
}

// Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
void enque(int data) {
    if (awal_antrian >= 5) {
        cout << "Antrian sudah penuh.\n";
        return;
    }

    antrianNode* node_baru = new antrianNode;
    node_baru->data = data;
    node_baru->next = nullptr;
    node_baru->prev = nullptr;

    if (empty()) {
        queue.head = node_baru;
        queue.front = node_baru;
        queue.rear = node_baru;
    }
    else {
        queue.rear->next = node_baru;
        node_baru->prev = queue.rear;
        queue.rear = node_baru;
    }
    awal_antrian++;
    cout << "Antrian Masuk: " << data << "\n\n";
}

// Fungsi untuk menampilkan queue
void tampilan_queue() {
    if (empty()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    antrianNode* current = queue.head;
    while (current != nullptr) {
        cout << "Top: " << queue.rear->data << "\n";
        cout << "Alamat: " << current << "\n";
        cout << "Alamat prev: " << current->prev << "\n";
        cout << "Nilai: " << current->data << "\n";
        cout << "Alamat next: " << current->next << "\n\n";
        current = current->next;
    }
    cout << "\nIsi Antrian/Queue: ";
    current = queue.head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << "-";
        }
        current = current->next;
    }
    cout << "\n=========================\n";
}

int main() {
    char choice;
    int antrian;
    do {
        cout << "Masukkan antrian baru (hanya angka bulat): ";
        cin >> antrian;

        // Validasi input agar hanya menerima integer
        while (cin.fail()) {
            cin.clear(); // Menghapus error flag dari cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang tidak valid
            cout << "Masukkan salah. Mohon masukkan angka bulat: ";
            cin >> antrian;
        }

        enque(antrian);
        tampilan_queue();

        cout << "Ingin memasukkan elemen lagi? (y/n): ";
        cin >> choice;
        cout << endl;
    } while ((choice == 'y' || choice == 'Y') && awal_antrian < 5);

    if (awal_antrian >= 5) {
        cout << "Antrian penuh \n";
    }

    return 0;
}
