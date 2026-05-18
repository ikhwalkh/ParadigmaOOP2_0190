#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
    protected:
        string Ryukatsuya; 
        double saldo;

    public:
    RekeningBank(string nama, double saldoAwal)
    {
        Ryukatsuya = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0;

    void tampilanSaldo() {
        cout << "Nama Nasabah : " << Ryukatsuya << endl;
        cout << "Saldo Akhir  : Rp " << saldo << endl;
        cout << "-----------------------------" << endl;
    }
};

class RekeningSyariah : public RekeningBank
{
   public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        // Tidak ada potongan admin
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
}; 


class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 berhasil dipotong." << endl;
    }
};