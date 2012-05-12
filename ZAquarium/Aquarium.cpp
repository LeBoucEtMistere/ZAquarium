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
    //vector<Algue*>::iterator it;

    /* I would compute m_algues.end() before this loop. As it is,
     * you're calling end() function at every iteration.
     * Consider this
     * vector<Algue*>::iterator it, itEnd = m_algues.end();
     * for (it = m_algues.begin(); it!= itEnd ; ++it) {
     */


        /*for(auto algue : m_algues) {
           delete *algue;
     }

      for(auto algue : m_algues) {
           delete *algue;
     }*/


    /* And final remark. If you were using vectors of smart pointers
     * you would not even need to clean here.
     */
    /*for (it = m_algues.begin(); it!= m_algues.end() ; ++it) {
        delete *it;

    }

    vector<Poisson*>::iterator it2;


    for (it2 = m_poissons.begin(); it2!= m_poissons.end() ; ++it2) {
        delete *it2;
    }*/
}

void Aquarium::ajouterPoisson(const string& nom, Poisson::SEXE sexe, Poisson::RACE race)
{
    /*shared_ptr<Poisson> ptr;

    switch (race) {
        case Poisson::MEROU:
            ptr = new Merou(sexe,nom,m_compteurPoissons);
            m_poissons.push_back(ptr);
            break;
        case Poisson::THON:
            shared_ptr<Poisson> ptr2(new Thon(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr2);
            break;
        case Poisson::POISSONCLOWN:
            shared_ptr<Poisson> ptr3(new PoissonClown(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr3);
            break;
        case Poisson::SOLE:
            shared_ptr<Poisson> ptr4(new Sole(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr4);
            break;
        case Poisson::BAR:
            shared_ptr<Poisson> ptr5(new Bar(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr5);
            break;
        case Poisson::CARPE:
            shared_ptr<Poisson> ptr6(new Carpe(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr6);
            break;
        default:
            break;
            }*/

        if(race == Poisson::MEROU)
        {
            shared_ptr<Poisson> ptr(new Merou(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
        }
        else if (race == Poisson::THON)
        {
            shared_ptr<Poisson> ptr(new Thon(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
        }
        else if (race == Poisson::POISSONCLOWN)
        {
            shared_ptr<Poisson> ptr(new PoissonClown(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
        }
        else if (race == Poisson::SOLE)
        {
            shared_ptr<Poisson> ptr(new Sole(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
        }
        else if (race == Poisson::BAR)
        {
            shared_ptr<Poisson> ptr(new Bar(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
        }
        else if (race == Poisson::CARPE)
        {
            shared_ptr<Poisson> ptr(new Carpe(sexe,nom,m_compteurPoissons));
            m_poissons.push_back(ptr);
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
        // Same remark as before. m_poisson.size() is computed at evey
        // iteration. Prefer stl algo, like for_each or C++11
        // for(auto poisson : m_poissons) { poisson->afficher(); }
        for (int i=0; i < m_poissons.size(); i++) {
            m_poissons[i]->afficher();
        }

        cout << "Algues : " << endl;
        for (int i=0; i < m_algues.size(); i++) {
            m_algues[i]->afficher();
        }



        //exécution des actions
        for (int i=0; i < m_algues.size(); i++) {
            m_algues[i]->doSomething();
        }

        for (int i=0; i < m_poissons.size(); i++) {
            m_poissons[i]->doSomething(*this);
        }


        //retirer les morts
        cleanAquarium();

        // Maybe here wait for a key input before displaying the next tour
        // std::cin.get();

    }

    //affichage
    cout << endl;
    cout << "=====FIN======" << endl;
    cout << "Poissons : " << endl;
    for (int i=0; i < m_poissons.size(); i++) {
        m_poissons[i]->afficher();
    }

    cout << "Algues : " << endl;
    for (int i=0; i < m_algues.size(); i++) {
        m_algues[i]->afficher();
    }
    cout << endl;
}

void Aquarium::cleanAquarium()
{

    vector<shared_ptr<Algue> >::iterator it = m_algues.begin();
    vector<shared_ptr<Algue> >::iterator it2 = m_algues.end();

    while (it!=it2) {
        if (!(*it)->isAlive()) {
            it = m_algues.erase(it);
        }
        else ++it;
    }


    // This fixed the memory leak. But it shows that using stl algo
    // is safer and probably more efficient. Have you read about the
    // idiom remove erase ?
    // Good reading : STL Algorithms vs. Hand-Written Loops. http://www.drdobbs.com/cpp/184401446


    vector<shared_ptr<Poisson> >::iterator it3= m_poissons.begin();
    vector<shared_ptr<Poisson> >::iterator it4 = m_poissons.end();


    while (it3 != it4) {
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
