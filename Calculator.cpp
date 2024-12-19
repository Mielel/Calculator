#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Angka{
    int nilai;
    int posisiAngka;
};

struct Operator{
    char tanda;
    int posisiOperator;
};

bool cekValiditas(string Operasi){
    /* Function untuk memastikan :
    1. bahwa tidak ada inputan lain selain angka dan tanda operasi matematika (+, -, /, *)
    2. tidak berakhir dengan tanda operasi matematika. 
    3. tidak diawali tanda operasi matematika (kecuali negatif)
    3. tidak ada tanda operasi matematika bersebelahan (contoh 3++4)
    Jika ada, return false. */


}

void masukkanString(string Operasi){ 
    // Prosedur untuk menerima input dari user
    cout << "Masukkan sebuah operasi matematika tanpa spasi: ";
    cin >> Operasi; 
    while(!cekValiditas(Operasi)){
    // Masukkan kembali input sampai sesuai dengan cekValiditas
        cout << endl;
        cout << "Ada kesalahan dalam input Anda.\nMasukkan kembali sebuah operasi matematika: ";
        cin >> Operasi;
    }
}

void pecahkanOperasi(string Operasi, vector<Angka> numbers, vector<Operator> sign, vector<int> posisiKaliBagi){
    // Prosedur untuk mengubah operasi matematika ke angka-angka dan tanda-tandanya

}

void lakukanPerkalianDanPembagian(vector<Angka> numbers, vector<Operator> sign, vector<int> posisiKaliBagi);
void lakukanPenjumlahanDanPengurangan(vector<Angka> numbers, vector<Operator> sign, int hasil);




int main(){
    string Operasi; // Variabel yang digunakan untuk menerima input
    vector<Angka> numbers; // Variabel untuk menyimpan seluruh angka dan posisinya dalam operasi
    vector<Operator> sign; // Variabel untuk menyimpan seluruh tanda dan posisinya dalam operasi 
    vector<int> posisiKaliBagi; // Variabel untuk menyimpan posisi tanda kali dan bagi ada di mana
    
    masukkanString(Operasi);
    pecahkanOperasi(Operasi, numbers, sign, posisiKaliBagi);

    lakukanPerkalianDanPembagian(numbers, sign, posisiKaliBagi);

    int hasil = 0;
    lakukanPenjumlahanDanPengurangan(numbers, sign, hasil);

    return 0;
}