#include <iostream>
#include <string>

using namespace std;

string BALSIAI[10]{"A","a","E","e","U","u","I","i","O","o"};
string EndLoop = "GO";
string Check;

void Balsiai() {
    int BalsiuKiekis = 0;
    cout << "Iveskite raide: ";
    cin >> Check;
    if (Check == "STOP") {
        EndLoop = Check;
    }
    else {
        for (int i = 0; i < 10; i++) {
            if(Check == BALSIAI[i]) {BalsiuKiekis++;}
        }
        if (BalsiuKiekis != 0) {cout << "Tai yra balsis" << endl;}
        else {cout << "Tai nera balsis" << endl;}
    }
}

void Daliklis() {
    int Skaicius1;
    int Skaicius2;
    int BendrasDaliklis;
    int Loop;
    cout << "Iveskite du skaicius: ";
    cin >> Check;
    if (Check == "STOP"){EndLoop = Check;}
    else {
        Skaicius1 = Check;
        cin >> Skaicius2;
        if (Skaicius1 > Skaicius2){Loop = Skaicius1;}
        else {Loop = Skaicius2;}
        for (int i = 1; i <= Loop; i++) {
            if(Skaicius1 % i == 0 & Skaicius2 % i == 0){BendrasDaliklis = i;}
        }
        cout << BendrasDaliklis;
    }
}

int main() {
    cout << "Noredami sustabdyti programa iveskite ''STOP''" << endl;
    while (EndLoop != "STOP") {
    //Balsiai();
        Daliklis();
    }
    return 0;
}
