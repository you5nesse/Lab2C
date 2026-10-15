#include "Filiere.h"
#include "Etudiant.h"
#include <algorithm>   // pour std::find

Filiere::Filiere(std::string nom) : nomFiliere(nom) {}

Filiere::~Filiere() {
    // La filière possède ses étudiants : elle les libère
    for (Etudiant* e : etudiants) {
        delete e;
    }
    etudiants.clear();
}



void Filiere::retirerEtudiant(Etudiant* e) {
    auto it = std::find(etudiants.begin(), etudiants.end(), e);
    if (it != etudiants.end()) {
        (*it)->setFiliere(nullptr);   // délier l'étudiant
        etudiants.erase(it);
    }
}

int Filiere::getNombreEtudiants() const {
    return static_cast<int>(etudiants.size());
}

std::string Filiere::getNomFiliere() const {
    return nomFiliere;
}

void Filiere::afficherTous() const {
    std::cout << "Etudiants de la filiere " << nomFiliere << " :" << std::endl;
    for (const Etudiant* e : etudiants) {
        std::cout << "  - " << e->getNom()
                  << " (Moyenne : " << e->calculerMoyenne() << ")" << std::endl;
    }
}
void Filiere::inscrireEtudiant(Etudiant* e) {
    if (e == nullptr) {
        throw std::invalid_argument("Étudiant nul");
    }

    // Vérifier si l'étudiant est déjà inscrit
    for (const auto* et : etudiants) {
        if (et == e) {
            throw std::runtime_error("Étudiant déjà inscrit dans cette filière");
        }
    }

    // Vérifier si l'étudiant est déjà dans une autre filière
    if (e->getFiliere() != nullptr) {
        throw std::runtime_error("Étudiant déjà inscrit dans une autre filière");
    }

    etudiants.push_back(e);
    e->setFiliere(this);
}
