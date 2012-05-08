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


Aquarium::Aquarium() : m_compteurPoissons(0)
{
    srand(time(0));
}

Aquarium::~Aquarium()
{
    vector<Algue*>::iterator it;

    /* I would compute m_algues.end() before this loop. As it is,
     * you're calling end() function at every iteration.
     * Consider this
     * vector<Algue*>::iterator it, itEnd = m_algues.end();
     * for (it = m_algues.begin(); it!= itEnd ; ++it) {
     */

    /* Also it would be much nicer with C++11 syntax
     * for(auto algue : m_algues) {
     *      delete *algue;
     * }
     */

    /* And final remark. If you were using vectors of smart pointers
     * you would not even need to clean here.
     */
    for (it = m_algues.begin(); it!= m_algues.end() ; ++it) {
        delete *it;
    }

    vector<Poisson*>::iterator it2;


    for (it2 = m_poissons.begin(); it2!= m_poissons.end() ; ++it2) {

        delete *it2;
        //m_poissons.erase(it2);

    }
}

void Aquarium::ajouterPoisson(const string& nom, Poisson::SEXE sexe, Poisson::RACE race)
{
    switch (race) {
        case Poisson::MEROU:
            m_poissons.push_back(new Merou(sexe,nom,m_compteurPoissons));
            break;
        case Poisson::THON:
            m_poissons.push_back(new Thon(sexe,nom,m_compteurPoissons));
            break;
        case Poisson::POISSONCLOWN:
            m_poissons.push_back(new PoissonClown(sexe,nom,m_compteurPoissons));
            break;
        case Poisson::SOLE:
            m_poissons.push_back(new Sole(sexe,nom,m_compteurPoissons));
            break;
        case Poisson::BAR:
            m_poissons.push_back(new Bar(sexe,nom,m_compteurPoissons));
            break;
        case Poisson::CARPE:
            m_poissons.push_back(new Carpe(sexe,nom,m_compteurPoissons));
            break;
        default:
            break;

            m_compteurPoissons++;
    }
}

void Aquarium::ajouterAlgue()
{
    Algue* ptr = new Algue();
    m_algues.push_back(ptr);

}

void Aquarium::run()
{
    for (int tour = 0; tour < 10; tour++)
    {
        //affichage
        cout << endl;
        cout << "=====TOUR " << tour << " ======" << endl;

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
            m_poissons[i]->doSomething(m_poissons, m_algues);
        }


        //retirer les morts
        cleanAquarium();

        // Maybe here wait for a key input before displaying the next tour
        // std::cin.get();

    }
}

void Aquarium::cleanAquarium()
{
    vector<Algue*>::iterator it = m_algues.begin();

    // This fixed the memory leak. But it shows that using stl algo
    // is safer and probably more efficient. Have you read about the
    // idiom remove erase ?
    // Good reading : STL Algorithms vs. Hand-Written Loops. http://www.drdobbs.com/cpp/184401446
    while (it!= m_algues.end()) {
        if ((*it)->isAlive() != true) {
            delete *it;
            it = m_algues.erase(it);
        }
        else ++it;
    }

    vector<Poisson*>::iterator it2= m_poissons.begin();


    while (it2!= m_poissons.end()) {
        if ((*it2)->isAlive() != true) {
            delete *it2;
            it2 = m_poissons.erase(it2);
        }
        else ++it2;
    }
}

bool Aquarium::getRandomPoisson(Poisson *ptr)
{
    if (m_poissons.empty()) return false;

    int i = rand() % (m_poissons.size());
    ptr = m_poissons[i];

    return true;
}
bool Aquarium::getRandomAlgue(Algue *ptr)
{
    if (m_algues.empty()) return false;
    int i = rand() % (m_algues.size());
    ptr = m_algues[i];

    return true;
}
