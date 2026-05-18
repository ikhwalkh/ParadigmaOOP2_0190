#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
    protected:
        string namaNasabah; 
        double saldo;

    public:
    RekeningBank(string nama, double saldoAwal)
    {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0;

    void tampilkanSaldo() {
        cout << "Nama Nasabah : " << namaNasabah << endl;
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


class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        if (saldo > 10000000)
        {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        }
        else
        {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 berhasil dipotong." << endl;
        }
    }
};


int main() {
    RekeningBank *rekening1;
    RekeningBank *rekening2;
    RekeningBank *rekening3;

    rekening1 = new RekeningSyariah("Ryukatsuya", 5000000);
    rekening2 = new RekeningKonvensional("Jokowi", 7000000);
    rekening3 = new RekeningPremium("ikhwal", 12000000);

    rekening1->potongAdmin();
    rekening1->tampilkanSaldo();

    rekening2->potongAdmin();
    rekening2->tampilkanSaldo();

    rekening3->potongAdmin();
    rekening3->tampilkanSaldo();

    delete rekening1;
    delete rekening2;
    delete rekening3;

    return 0;
}