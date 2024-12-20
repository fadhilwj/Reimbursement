#include "menu.h"
#include "parent.h"
#include <iostream>

int displayMenu()
{
    int choice;

    cout << "\n===== Menu Pengelolaan Pengeluaran [Reimbursement] =====\n";
    cout << "1. Tambah Jenis                        \n";//no 1 12
    cout << "2. Tambah Biaya pada Jenis tertentu    \n";//no 5 16
    cout << "3. Hapus Jenis                         \n";//no 3 14
    cout << "4. Hapus Biaya (...)                   \n";//no 9 20
    cout << "5. Update data (...)                   \n";//
    cout << "6. Tampilkan Semua Jenis               \n";//no 7
    cout << "7. Tampilkan Semua Jenis beserta Biaya \n";
    cout << "8. Tampilkan Total Biaya               \n";//
    cout << "9. Cari Data Jenis                     \n";
    cout << "10. Cari Data Child pada Jenis Tertentu\n";
    cout << "0. Keluar                              \n";
    cout << "Pilih menu: ";
    cin >> choice;

    return choice;
}

string displayUpdateBiaya()
{
    string choice;
    cout << "\n========== OPSI UPDATE ==========\n";
    cout << "1. ID Biaya                    \n";
    cout << "2. ID Pegawai                  \n";
    cout << "3. Deskripsi                   \n";
    cout << "4. Jumlah                      \n";
    cout << "5. Biaya                       \n";
    cout << "6. Jenis Biaya                 \n";
    cout << "7. Seluruhnya                  \n";
    cout << "0. kembali                     \n";
    cout << "Pilihan: ";
    cin >> choice;
    return choice;
}

string displayHapusBiaya()
{
    string choice;
    cout << "\n============= OPSI HAPUS BIAYA =============\n";
    cout << "1. Hapus Biaya berdasarkan ID              \n";
    cout << "2. Hapus Semua Biaya berdasarkan Jenis     \n";
    cout << "0. kembali                                 \n";
    cout << "Pilihan: ";
    cin>> choice;
    return choice;
}
