#include "Etudiant.h"
#include "Filiere.h"   // indispensable : on appelle des methodes de Filiere

// Constructeurs
Etudiant::Etudiant()
    : nom(""), cin(""), note1(0), note2(0), note3(0), filiere(nullptr) {}

Etudiant::Etudiant(std::string n, std::string c, double n1, double n2, double n3)
    : nom(n), cin(c), note1(n1), note2(n2), note3(n3), filiere(nullptr) {}

// Getters
std::string Etudiant::getNom() const { return nom; }
std::string Etudiant::getCin() const { return cin; }
double Etudiant::getNote1() const { return note1; }
double Etudiant::getNote2() const { return note2; }
double Etudiant::getNote3() const { return note3; }
Filiere* Etudiant::getFiliere() const { return filiere; }

// Setters
void Etudiant::setNom(std::string n) { nom = n; }
void Etudiant::setCin(std::string c) { cin = c; }
void Etudiant::setNote1(double n) { note1 = n; }
void Etudiant::setNote2(double n) { note2 = n; }
void Etudiant::setNote3(double n) { note3 = n; }
void Etudiant::setFiliere(Filiere* f) { filiere = f; }

// Methodes metier
double Etudiant::calculerMoyenne() const {
    return (note1 + note2 + note3) / 3.0;
}

void Etudiant::changerDeFiliere(Filiere* nouvelleFiliere) {
    if (nouvelleFiliere == nullptr) {
        std::cerr << "Nouvelle filiere invalide." << std::endl;
        return;
    }
    if (nouvelleFiliere == filiere) {
        std::cout << nom << " est deja dans cette filiere." << std::endl;
        return;
    }

    // 1. Se retirer de l'ancienne filiere (elle met aussi filiere = nullptr)
    if (filiere != nullptr) {
        filiere->retirerEtudiant(this);
    }

    // 2. S'inscrire dans la nouvelle (elle appelle setFiliere(this) pour nous)
    nouvelleFiliere->inscrireEtudiant(this);

    std::cout << nom << " a change de filiere : "
              << nouvelleFiliere->getNomFiliere() << std::endl;
}
