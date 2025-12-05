// Harjoitustehtävä Hotelli Aaro Jantunen
// yritys 3
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#define RED    "\033[31m"
#define BLUE   "\033[34m" // väreillä leikkimistä 

using namespace std;


int arvoHuone(int varattu[], int huonemaara) { // valitaan vapaa huone
    int vapaat[100];
    int vmaara = 0;
    
// luodaan lista vapaista huoneista
    for (int i = 0; i < huonemaara; i++) { 
        if (varattu[i] == 0) {
            vapaat[vmaara] = i; // huoneen numero 
            vmaara++; 
        }
    }

    if (vmaara == 0) return -1; // ei vapaita huoneita

    return vapaat[rand() % vmaara]; // Antaa satunnaisen vapaan huoneen numeron
}

int main() {
    srand(time(0)); // random luku generaattori

    int huonemaara = 30 + rand() % 41; // 30 - 70 huonetta
    int hinta = 80 + rand() % 21; // hinta per yö 80-100e
    int varattu[100] = {0}; // max 100 huonetta
    int varauksia = 0; // kuinka monta varausta on tehty
    int uusiVaraus = 0; // tämä että saadaan eri viesti kysyttä kun uusi huone varataan


    cout << "\n";
    cout << RED << "================= HOTELLI =================\n";
    cout << BLUE <<"   Hotellissa on: " << huonemaara << " huonetta.   \n";
    cout << BLUE << "   Yhden huoneen hinta on: " << hinta << " euroa.  \n"; // tekstiä
    cout << RED << "===========================================\n";

    

    while (true) {  // pääsilmukka
       int vastaus1; 

       if (uusiVaraus == 0) {
        cout << RED << "===========================================\n";
       cout << BLUE << "Haluatko varata huoneen? (Kyllä, 1 / Ei, 0) \n";
       cout << RED << "===========================================\n";
       // kun kysytään uudestaan haluatko varata huoneen on teksti eri.


    } else {
       cout << BLUE << "Haluatko tehdä uuden varauksen? (Kyllä, 1 / Ei, 0) \n";
       cout << RED << "===========================================\n";
    }
         cin >> vastaus1;
         uusiVaraus ++; //Katsotaan että seuraavalla kerralla kysytään uudestaan varataanko huone

        if (vastaus1 == 1) {
            int huone = arvoHuone(varattu, huonemaara); // arpoo vapaan huoneen


            if (huone == -1) {
                cout << RED << "===========================================\n";
                cout << BLUE << "Kaikki huoneet ovat täynnä. Kiitos käynnistä!\n";
                cout << RED << "===========================================\n";
                break;
            }
            
            varattu[huone] = 1; // merkkaa huoneen varatuksi että ei voi varata uudestaan
            varauksia++; 


            cout << RED << "===========================================\n";
            cout << BLUE << "       Huoneesi numero on: " << (huone + 1) << ".\n";

            // kuinka monta yötä
            cout << BLUE << "   Kuinka monta yötä haluat yöpyä? \n";
            cout << RED << "===========================================\n";
            int yot;
            cin >> yot;

            while (yot < 1) { // katsoo että yöpymismäärä on ainakin 1
                cout << RED << "================== VIRHE ==================\n";
                cout << BLUE << "Sinun on yövyttävä vähintään yksi yö varataksesi huoneen.\n";
                cout << BLUE << "           Yritä uudelleen.        \n";
                cout << BLUE << "   Kuinka monta yötä haluat yöpyä? \n";
                cout << RED << "===========================================\n";
                cin >> yot;
            }

            int kokonaishinta = hinta * yot; // laskee hinnan yöpymiselle
            cout << "\n";
            cout << RED << "============== VARAUS ON TEHTY ==============\n";
            cout << BLUE << "Huoneesi on varattu: " << yot << " yöksi ja kokonaishinta on: " << kokonaishinta << ".\n";


        }   else if (vastaus1 == 0) {
                 cout << RED << "============= KIITOS KÄYNNISTÄ ============\n";
                cout << BLUE << "             Varaukia tehty: " << varauksia << ".\n";
                 cout << RED << "===========================================\n";
            break;
            } else {
                 cout << RED << "================== VIRHE ==================\n";
                cout << BLUE <<"            Yritä uudelleen.\n";
                 cout << RED << "===========================================\n";
            }
        }
        return 0;
    }
