#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Struct pour le Tournois 
// Structure joueur
struct Joueur {
    string nom;
    int points;
};

//Mini jeux
Joueur pileOuFace (const Joueur &j1, const Joueur &j2) {
    int choix;
    // 50% de chance de gagner
    choix = rand()%2;
    if (choix ==0) return j1;
    return j2;
}

Joueur pileOuFaceTruque (const Joueur &j1, const Joueur &j2) {
    int choix;
    // 75% de chance que j1 gagne, 25% pour j2
    choix = rand()%100;
    if (choix < 75) return j1;
    return j2;
}

Joueur pierreFeuilleCiseau(const Joueur &j1, const Joueur &j2) {
    string entreeJ1, entreeJ2;

    cout << j1.nom << " : ";
    cin >> entreeJ1;

    cout << j2.nom << " : ";
    cin >> entreeJ2;

    //Si égalité relancer
    if (entreeJ1 == entreeJ2) return pierreFeuilleCiseau(j1, j2);

    if ((entreeJ1 == "Pierre" || entreeJ1 == "pierre") &&
        (entreeJ2 == "Ciseau" || entreeJ2 == "ciseau")) return j1;
    if ((entreeJ1 == "Feuille" || entreeJ1 == "feuille") &&
        (entreeJ2 == "Pierre" || entreeJ2 == "pierre")) return j1;
    if ((entreeJ1 == "Ciseau" || entreeJ1 == "ciseau") &&
        (entreeJ2 == "Feuille" || entreeJ2 == "feuille")) return j1;

    return j2;
}

Joueur matchBO3(const Joueur &j1, const Joueur &j2) {

    int score1 = 0;
    int score2 = 0;
    int manche = 0;

    while (score1 < 2 && score2 < 2) {

        Joueur gagnant;
        if (manche == 0) {
            cout << "Jeux choisi : Pile ou Face" << endl;
            gagnant = pileOuFace(j1, j2);
        } else if (manche == 1) {
            cout << "Jeux choisi : Pile ou Face truque" << endl;
            gagnant = pileOuFaceTruque(j1, j2);
        } else {
            cout << "Jeux choisi : Pierre Feuille Ciseau" << endl;
            gagnant = pierreFeuilleCiseau(j1, j2);
        }
        manche++;

        cout << gagnant.nom << " gagne le mini jeu !" << endl;

        if (gagnant.nom == j1.nom) score1++;
        else score2++;

        cout << "Score : " << score1 << " - " << score2 << endl;
    }

    if (score1 == 2)
        return j1;

    return j2;
}

int main() {
    srand(time(NULL));
    
    return 0;
}