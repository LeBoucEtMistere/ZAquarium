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

#include "Aquarium.h"
#include "Poisson.h"
#include "Algue.h"

using namespace std;

//
// =============================Poisson==============================//

Poisson::Poisson(size_t ID) : m_sexe(MALE), m_nom("Nemo"), m_id(ID), alive(true), m_PV(10), m_age(0)
{
    cout << "Nouveau poisson créé : " << m_nom << " (";

    afficherSexe();
}

Poisson::Poisson(SEXE sexe, std::string nom, size_t ID) : m_sexe(sexe), m_nom(nom), m_id(ID), alive(true),
                                                                m_PV(10)
{
    cout << "Nouveau poisson créé : " << m_nom << " (";
    afficherSexe();
}

Poisson::~Poisson()
{

}

void Poisson::doSomething(Aquarium& aquarium)
{

}



unsigned int Poisson::getID() const
{
    return m_id;
}

string& Poisson::getNom()
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

void Poisson::afficherSexe() const
{
    switch (m_sexe) {
        case MALE:
            cout << "Mâle) " ;
            break;
        case FEMELLE:
            cout << "Femelle) " ;

            break;

        default:
            break;
    }
}

//
// =============================PoissonCarnivore==============================//
Carnivore::Carnivore(unsigned int ID) : Poisson(ID)
{
    cout << " /type : Carnivore" << endl;

}

Carnivore::Carnivore(SEXE sexe, std::string nom, unsigned int ID) : Poisson(sexe,nom,ID)
{
    cout << " /type : Carnivore" << endl;


}

Carnivore::~Carnivore()
{

}

void Carnivore::manger(Aquarium& aquarium)
{


    Poisson *ptr = aquarium.getRandomPoisson();

    if (ptr)
    {
        ptr->degats(4);
        m_PV += 5;
        cout << m_nom << " mord " << ptr->getNom() << " et lui enlève 4PV, il en regagne 5" <<endl;
    }
    else
    {
        cout << m_nom << " ne trouve rien à manger." <<endl;

    }

}

void Carnivore::doSomething(Aquarium& aquarium)
{

    if (m_age<20)
    {
        manger(aquarium);
        m_age++;
    }
    else
    {
        alive = false;
        cout << m_nom << " décède de vieillesse" << endl;

    }
}



//
// =============================PoissonHerbivore==============================//
Herbivore::Herbivore(size_t ID) : Poisson(ID)
{
    cout << " /type : Herbivore" << endl;
    srand(time(0));

}

Herbivore::Herbivore(SEXE sexe, std::string nom, size_t ID) : Poisson(sexe,nom,ID)
{
    cout << " /type : Herbivore" << endl;
    srand(time(0));


}

Herbivore::~Herbivore()
{

}

void Herbivore::manger(Aquarium& aquarium)
{

    Algue *ptr = aquarium.getRandomAlgue();

    if (ptr)
    {
        ptr->degats(2);
        m_PV += 3;
        cout << m_nom << " mange une algue et lui enlève 2PV, il en regagne 3" <<endl;
    }


}

void Herbivore::doSomething(Aquarium& aquarium)
{
    if (m_age<20)
    {
        manger(aquarium);
        m_age++;
    }
    else
    {
        alive = false;
        cout << m_nom << " décède de vieillesse" << endl;
    }




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



