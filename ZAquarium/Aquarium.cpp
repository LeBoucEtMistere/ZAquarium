//
//  Aquarium.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Aquarium.h"

using namespace std;


Aquarium::Aquarium(unsigned int toursMax) : m_compteurPoissons(0), m_tours(toursMax)
{
    srand(time(0));
}

Aquarium::~Aquarium()
{
    //DTOR
}

void Aquarium::ajouterPoisson(const string& nom, Poisson::SEXE sexe, Poisson::RACE race)
{

    switch (race) {
        case Poisson::MEROU:
        {
            shared_ptr<Poisson> ptr (new Merou(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
            break;
        }
        case Poisson::THON:
        {
            shared_ptr<Poisson> ptr(new Thon(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
            break;
        }
        case Poisson::POISSONCLOWN:
        {
            shared_ptr<Poisson> ptr(new PoissonClown(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
            break;
        }
        case Poisson::SOLE:
        {
            shared_ptr<Poisson> ptr(new Sole(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
            break;
        }
        case Poisson::BAR:
        {
            shared_ptr<Poisson> ptr(new Bar(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
            break;
        }
        case Poisson::CARPE:
        {
            shared_ptr<Poisson> ptr(new Carpe(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
            break;
        }
        default:
            break;
        }

            m_compteurPoissons++;

}

void Aquarium::ajouterAlgue()
{
    shared_ptr<Algue> ptr(new Algue());
    m_algues.push_back(ptr);

}

void Aquarium::run()
{


    for (int tour = 0; tour < m_tours; tour++)
    {
        //affichage
        cout << endl;
        cout << "=====TOUR " << tour+1 << " ======" << endl;

        cout << "Poissons : " << endl;
        for(auto poisson : m_poissons) { poisson->afficher(); }

        cout << "Algues : " << endl;
        for(auto algue : m_algues) { algue->afficher(); }

        //exécution des actions
        if(m_algues.capacity() < 2* m_algues.size()) m_algues.reserve(2* m_algues.size());
        for(auto algue : m_algues) { algue->doSomething(*this); }

        if(m_poissons.capacity() < 3* m_poissons.size()) m_poissons.reserve(3* m_poissons.size());
        for(auto poisson : m_poissons) { poisson->doSomething(*this); }



        //retirer les morts
        cleanAquarium();

        // std::cin.get();

    }

    //affichage
    cout << endl;
    cout << "=====FIN======" << endl;
    cout << "Poissons : " << endl;
    for(auto poisson : m_poissons) { poisson->afficher(); }

    cout << "Algues : " << endl;
    for(auto algue : m_algues) { algue->afficher(); }
    cout << endl;
}

void Aquarium::cleanAquarium()
{

    vector<shared_ptr<Algue> >::iterator it = m_algues.begin();


    while (it != m_algues.end()) {
        if (!(*it)->isAlive()) {
            it = m_algues.erase(it);
        }
        else ++it;
    }

    vector<shared_ptr<Poisson> >::iterator it3= m_poissons.begin();


    while (it3 != m_poissons.end()) {
        if (!(*it3)->isAlive()) {
            it3 = m_poissons.erase(it3);
        }
        else ++it3;
    }
}


Poisson* Aquarium::getRandomPoisson() const
{
    if (m_poissons.empty()) return NULL;

    int i = rand() % (m_poissons.size());


    return m_poissons[i].get();
}
Algue* Aquarium::getRandomAlgue() const
{
    if (m_algues.empty()) return NULL;
    int i = rand() % (m_algues.size());

    return m_algues[i].get();
}


void Aquarium::reproductionAlgue(int PV)
{
    ajouterAlgue(PV);
}

void Aquarium::ajouterAlgue(int PV)
{
    shared_ptr<Algue> ptr (new Algue(PV));
    m_algues.push_back(ptr);
}


