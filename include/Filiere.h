#ifndef FILIERE_H
#define FILIERE_H

#include <iostream>
#include <string>
#include <vector>

class Etudiant;   // déclaration anticipée

class Filiere {
private:
    std::string nomFiliere;
    std::vector<Etudiant*> etudiants;   // Association 1-N

public:
    Filiere(std::string nom);
    ~Filiere();

    void inscrireEtudiant(Etudiant* e);
    void retirerEtudiant(Etudiant* e);
    int getNombreEtudiants() const;
    std::string getNomFiliere() const;
    void afficherTous() const;
};

#endif // FILIERE_H
