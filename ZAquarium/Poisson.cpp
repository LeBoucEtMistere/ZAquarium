//
//  Poisson.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Poisson.h"
#include "Aquarium.h"

using namespace std;

//
// =============================Poisson==============================//

Poisson::Poisson(unsigned int ID) : m_sexe(MALE), m_nom("Nemo"), m_id(ID), alive(true), m_PV(10)
{
    cout << "Nouveau poisson créé : " << m_nom << " (";

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " ;
            break;
        case 2:
            cout << "Femelle) " ;

            break;

        default:
            break;
    }
}

Poisson::Poisson(SEXE sexe, std::string nom, unsigned int ID) : m_sexe(sexe), m_nom(nom), m_id(ID), alive(true),
                                                                m_PV(10)
{
    cout << "Nouveau poisson créé : " << m_nom << " (";
    // DRY : Don't Repeat Yourself. You have twice this switch. We might consider refactoring.
    switch (m_sexe) {
        case 1: // For better reading, use your enum. case MALE:
            cout << "Mâle) " ;
            break;
        case 2:
            cout << "Femelle) " ;

            break;

        default:
            break;
    }
}

Poisson::~Poisson()
{

}

void Poisson::doSomething(const Aquarium& aquarium)
{

}

void Poisson::manger()
{

}

unsigned int Poisson::getID() const
{
    return m_id;
}

string Poisson::getNom() const
{
    return m_nom;
}

void Poisson::degats(int degats)
{
    m_PV -= degats;

    if (m_PV <= 0)
    {
        alive = false;
        cout << m_nom << " est mort." << endl;
    }
}

bool Poisson::isAlive() const
{
    return alive;
}

//
// =============================PoissonCarnivore==============================//
Carnivore::Carnivore(unsigned int ID) : Poisson(ID)
{
    cout << " /type : Carnivore" << endl; // Prefer "\n" to endl. Better performances.
    srand(time(0)); // This should only be called once, not at every Carnivore constructor.

}

Carnivore::Carnivore(SEXE sexe, std::string nom, unsigned int ID) : Poisson(sexe,nom,ID)
{
    cout << " /type : Carnivore" << endl;
    srand(time(0));

}

Carnivore::~Carnivore()
{

}

void Carnivore::manger(const Aquarium& aquarium)
{
    Poisson *ptr = NULL;
    bool ok = aquarium.getRandomPoisson(ptr);

    if (ok)
    {
        ptr->degats(4);
        m_PV += 5;
        cout << m_nom << " mord " << ptr->getNom() << " et lui enlève 4PV, il en regagne 5" <<endl;
    }
}

void Carnivore::doSomething(const Aquarium& aquarium)
{
    if (true) {

        manger(aquarium);

    }
}



//
// =============================PoissonHerbivore==============================//
Herbivore::Herbivore(unsigned int ID) : Poisson(ID)
{
    cout << " /type : Herbivore" << endl;
    srand(time(0));

}

Herbivore::Herbivore(SEXE sexe, std::string nom, unsigned int ID) : Poisson(sexe,nom,ID)
{
    cout << " /type : Herbivore" << endl;
    srand(time(0));


}

Herbivore::~Herbivore()
{

}

void Herbivore::manger(const Aquarium& aquarium)
{
    Algue *ptr = NULL;
    bool ok = aquarium.getRandomAlgue(ptr);

    if (ok)
    {
        ptr->degats(2);
        m_PV += 3;
        cout << m_nom << " mange une algue et lui enlève 2PV, il en regagne 3" <<endl;
    }

}

void Herbivore::doSomething(const Aquarium& aquarium)
{
    manger(aquarium);
}


//
// =============================Merou==============================//

Merou::Merou(unsigned int ID) : Carnivore(ID)
{
    cout << " /espèce : Mérou" << endl;
}

Merou::Merou(SEXE sexe, std::string nom,unsigned int ID) : Carnivore(sexe,nom,ID)
{
    cout << " /espèce : Mérou" << endl;

}

void Merou::afficher() const
{
    cout << "Je suis un Mérou (" << m_PV << "), je m'appelle : " << m_nom << " (" ;

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " << endl; ;
            break;
        case 2:
            cout << "Femelle) " << endl; ;
            break;

        default:
            break;



    }
}



//
// =============================Thon==============================//

Thon::Thon(unsigned int ID) : Carnivore(ID)
{
    cout << " /espèce : Thon" << endl;
}

Thon::Thon(SEXE sexe, std::string nom,unsigned int ID) : Carnivore(sexe,nom,ID)
{
    cout << " /espèce : Thon" << endl;

}

void Thon::afficher() const
{
    cout << "Je suis un Thon (" << m_PV << "), je m'appelle : " << m_nom << " (" ;

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " << endl;
            break;
        case 2:
            cout << "Femelle) " << endl;

            break;

        default:
            break;

            cout << "(" << m_PV << ")" << endl;
    }
}

//
// =============================PoissonClown==============================//


PoissonClown::PoissonClown(unsigned int ID) : Carnivore(ID)
{
    cout << " /espèce : Poisson Clown" << endl;
}

PoissonClown::PoissonClown(SEXE sexe, std::string nom,unsigned int ID) : Carnivore(sexe,nom,ID)
{
    cout << " /espèce : Poisson Clown" << endl;
}

void PoissonClown::afficher() const
{
    cout << "Je suis un Poisson Clown (" << m_PV << "), je m'appelle : " << m_nom << " (" ;

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " << endl;
            break;
        case 2:
            cout << "Femelle) " << endl;

            break;

        default:
            break;

            cout << "(" << m_PV << ")" << endl;
    }
}

//
// =============================Sole==============================//

Sole::Sole(unsigned int ID) : Herbivore(ID)
{
    cout << " /espèce : Sole" << endl;
}

Sole::Sole(SEXE sexe, std::string nom,unsigned int ID) : Herbivore(sexe,nom,ID)
{
    cout << " /espèce : Sole" << endl;

}

void Sole::afficher() const
{
    cout << "Je suis un Sole (" << m_PV << "), je m'appelle : " << m_nom << " (" ;

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " << endl;
            break;
        case 2:
            cout << "Femelle) " << endl;

            break;

        default:
            break;

            cout << "(" << m_PV << ")" << endl;
    }
}



//
// =============================Bar==============================//

Bar::Bar(unsigned int ID) : Herbivore(ID)
{
    cout << " /espèce : Bar" << endl;
}

Bar::Bar(SEXE sexe, std::string nom,unsigned int ID) : Herbivore(sexe,nom,ID)
{
    cout << " /espèce : Bar" << endl;

}

void Bar::afficher() const
{
    cout << "Je suis un Bar (" << m_PV << "), je m'appelle : " << m_nom << " (" ;

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " << endl;
            break;
        case 2:
            cout << "Femelle) " << endl;

            break;

        default:
            break;

            cout << "(" << m_PV << ")" << endl;
    }
}

//
// =============================Carpe==============================//


Carpe::Carpe(unsigned int ID) : Herbivore(ID)
{
    cout << " /espèce : Carpe" << endl;
}

Carpe::Carpe(SEXE sexe, std::string nom,unsigned int ID) : Herbivore(sexe,nom,ID)
{
    cout << " /espèce : Carpe" << endl;
}

void Carpe::afficher() const
{
    cout << "Je suis une Carpe (" << m_PV << "), je m'appelle : " << m_nom << " (" ;

    switch (m_sexe) {
        case 1:
            cout << "Mâle) " << endl;
            break;
        case 2:
            cout << "Femelle) " << endl;

            break;

        default:
            break;

            cout << "(" << m_PV << ")" << endl;
    }
}



