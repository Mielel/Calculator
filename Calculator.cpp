#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool cekValiditas(const string Operasi);
void masukkanString(string *Operasi);
void pecahkanOperasi(const string Operasi, vector<int> *numbers, vector<char> *sign, vector<int> *posisiKaliBagi);

void lakukanPerkalianDanPembagian(vector<int> *numbers, vector<char> *sign, vector<int> *posisiKaliBagi){
    for(int i = 0; i < posisiKaliBagi->size(); i++){
        switch((*sign)[(*posisiKaliBagi)[i]-i]){
            case ('*'):
                (*numbers)[(*posisiKaliBagi)[i] - i] *= (*numbers)[(*posisiKaliBagi)[i] - i + 1];
                break;
            case ('/'):
                (*numbers)[(*posisiKaliBagi)[i] - i] /= (*numbers)[(*posisiKaliBagi)[i] - i + 1];
                break;
            default:
                cout << "Error di prosedur perkalian dan pembagian!" << endl;
                break;
        }
        numbers->erase(numbers->begin() + (*posisiKaliBagi)[i] - i + 1);
        sign->erase(sign->begin() + (*posisiKaliBagi)[i]);
    }
}

void lakukanPenjumlahanDanPengurangan(vector<int> *numbers, vector<char> *sign, float *hasil){
    *hasil = (*numbers)[0];
    for(int i = 0; i < sign->size(); i++){
        switch((*sign)[i]){
            case ('+'):
                *hasil += (*numbers)[i+1];
                break;
            case ('-'):
                *hasil -= (*numbers)[i+1];
                break;
            default:
                cout << "Error di prosedur penjumlahan dan pengurangan!" << endl;
                break;
        }
    }
}

int main(){
    string Operasi; // Variabel yang digunakan untuk menerima input
    vector<int> numbers; // Variabel untuk menyimpan seluruh angka dalam operasi
    vector<char> sign; // Variabel untuk menyimpan seluruh tanda dalam operasi
    vector<int> posisiKaliBagi; // Variabel untuk menyimpan posisi tanda kali dan bagi ada di mana

    masukkanString(&Operasi);
    pecahkanOperasi(Operasi, &numbers, &sign, &posisiKaliBagi);

    lakukanPerkalianDanPembagian(&numbers, &sign, &posisiKaliBagi);

    float hasil = 0;
    lakukanPenjumlahanDanPengurangan(&numbers, &sign, &hasil);

    ofstream outFile("Hasil.csv");

    cout << "Hasil: " << hasil << endl;
    outFile << Operasi << " = " << hasil;
    return 0;
}

bool cekValiditas(const string Operasi){
    /* Function untuk memastikan :
    1. bahwa tidak ada inputan lain selain angka dan tanda operasi matematika (+, -, /, *)
    2. tidak berakhir dengan tanda operasi matematika. 
    3. tidak diawali tanda operasi matematika (kecuali negatif)
    3. tidak ada tanda operasi matematika bersebelahan (contoh 3++4)
    Jika ada, return false. */
    if (Operasi.empty()) return false;
    if (!isdigit(Operasi[0]) && Operasi[0] != '-') return false; // Harus dimulai dengan angka atau tanda negatif
    if (!isdigit(Operasi.back())) return false; // Harus diakhiri dengan angka

    for (size_t i = 0; i < Operasi.length(); i++) {
        if (!isdigit(Operasi[i]) && Operasi[i] != '+' && Operasi[i] != '-' && Operasi[i] != '*' && Operasi[i] != '/') {
            return false; // Karakter tidak valid
        }
        if (i > 0 && !isdigit(Operasi[i]) && !isdigit(Operasi[i - 1])) {
            return false; // Tidak boleh ada dua operator bersebelahan
        }
    }
    return true; // Implementasi validasi perlu ditambahkan
}

void masukkanString(string *Operasi){ 
    // Prosedur untuk menerima input dari user
    cout << "Masukkan sebuah operasi matematika tanpa spasi: ";
    cin >> *Operasi; 
    while(!cekValiditas(*Operasi)){
    // Masukkan kembali input sampai sesuai dengan cekValiditas
        cout << endl;
        cout << "Ada kesalahan dalam input Anda.\nMasukkan kembali sebuah operasi matematika: ";
        cin >> *Operasi;
    }
}

void pecahkanOperasi(const string Operasi, vector<int> *numbers, vector<char> *sign, vector<int> *posisiKaliBagi){
    string temp = "";
    temp += Operasi[0];
    for (size_t i = 1; i < Operasi.length(); i++) {
        if (isdigit(Operasi[i])) {
            temp += Operasi[i];
        } else {
            numbers->push_back(stoi(temp));
            temp = "";
            sign->push_back(Operasi[i]);
            if (Operasi[i] == '*' || Operasi[i] == '/') {
                posisiKaliBagi->push_back(sign->size() - 1);
            }
        }
    }
    if (!temp.empty()) {
        numbers->push_back(stoi(temp));
    }
}
