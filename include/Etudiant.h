#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <string>

class Filiere;

class Etudiant {
private:
    std::string nom;
    std::string cin;
    double note1;
    double note2;
    double note3;
    Filiere* filiere;   // Association 1-1 vers sa filiere

public:
    // Constructeurs
    Etudiant();
    Etudiant(std::string n, std::string c, double n1, double n2, double n3);

    // Getters
    std::string getNom() const;
    std::string getCin() const;
    double getNote1() const;
    double getNote2() const;
    double getNote3() const;
    Filiere* getFiliere() const;

    // Setters
    void setNom(std::string n);
    void setCin(std::string c);
    void setNote1(double n);
    void setNote2(double n);
    void setNote3(double n);
    void setFiliere(Filiere* f);

    // Methodes metier
    double calculerMoyenne() const;
    void changerDeFiliere(Filiere* nouvelleFiliere);   // NOUVEAU
};

#endif // ETUDIANT_H
