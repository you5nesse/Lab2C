#include <iostream>
#include "Filiere.h"
#include "Etudiant.h"
using namespace std;

#include <stdexcept>

int main() {
    try {
        Filiere* f1 = new Filiere("Informatique");
        Etudiant* e1 = new Etudiant("Alice", "123", 15, 16, 17);

        f1->inscrireEtudiant(e1);
        f1->inscrireEtudiant(e1); // Doit lever une exception

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // ... nettoyage
    return 0;
}
