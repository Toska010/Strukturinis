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
    int Skaicius3;
    cout << "Iveskite du skaicius: ";
    cin >> Skaicius1 >> Skaicius2;
    if (Skaicius1 == 0 || Skaicius2 == 0){cout << "Dalyba is nulio negalima!" << endl;}
    else {
        if (Skaicius1 < Skaicius2){Skaicius3 = Skaicius1; Skaicius1 = Skaicius2; Skaicius2 = Skaicius3;}
        while (Skaicius2 != 0) {
            Skaicius3 = Skaicius1;
            Skaicius1 = Skaicius2;
            Skaicius2 = Skaicius3 % Skaicius1;
            if(Skaicius2 == 0){cout << "Didziausias bendras daliklis = " << Skaicius1 << endl;}
        }
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
