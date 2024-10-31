#include <iostream>
#include <string>
#include <ctime>
#include<string.h>

using namespace std;

string Velniava[31][32] {
    {"A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž"},
    {"Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A"},
    {"C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B"},
    {"Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C"},
    {"D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č"},
    {"E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D"},
    {"Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E"},
    {"Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę"},
    {"F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė"},
    {"G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F"},
    {"H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G"},
    {"I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H"},
    {"Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I"},
    {"Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į"},
    {"J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y"},
    {"K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J"},
    {"L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K"},
    {"M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L"},
    {"N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M"},
    {"O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N"},
    {"P","R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O"},
    {"R","S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P"},
    {"S","Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R"},
    {"Š","T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S"},
    {"T","U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š"},
    {"U","Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T"},
    {"Ų","Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U"},
    {"Ū","V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų"},
    {"V","Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū"},
    {"Z","Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V"},
    {"Ž","A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z"}
};

string Abc[32] {"A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž"};
int Abc1[32] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

void SifruoteAbc() {
    string Tekstas;
    cout << "Ivesk norima uzsifruoti teksta: " << endl;
    cin >> Tekstas;
    int Dydis = size(Tekstas);
    cout << Tekstas << " | jo dydis | " << Dydis << endl;

}

int main() {
    srand(time(nullptr));
    int RaktoNr;

    int Pasirinkimas;
    cout << "Pasirinkite funkcija:\t1: Sifruoti\t2: Desifruoti" << endl;
    cin >> Pasirinkimas;
    switch(Pasirinkimas) {
        case 1: {
            int Pasirinkimas2;
            cout << "Kokiu metodu:\t1: Abecele\t2: ASCII" << endl;
            cin >> Pasirinkimas2;
            switch(Pasirinkimas2) {
                case 1: {
                    while(true) {
                        SifruoteAbc();
                    }
                    break;
                }
                case 2: {

                    break;
                }
                default: {
                    break;
                }
            }

        }
        case 2: {

        }
        default: {
            break;
        }
    }

    cout << "Hello, World!" << endl;
    return 0;
}
