//
//  Aquarium.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Aquarium.h"

using namespace std;


Aquarium::Aquarium() : m_compteurPoissons(0)
{
    
}

Aquarium::~Aquarium()
{
    vector<Algue*>::iterator it;
    
    
    for (it = m_algues.begin(); it!= m_algues.end() ; ++it) {
        
        delete *it;
        m_algues.erase(it);
        
    }
    
    vector<Poisson*>::iterator it2;
    
    
    for (it2 = m_poissons.begin(); it2!= m_poissons.end() ; ++it2) {
        
        delete *it2;
        m_poissons.erase(it2);
        
    }
}

void Aquarium::ajouterPoisson(const string& nom, SEXE sexe, RACE race)
{
    switch (race) {
        case MEROU:
            m_poissons.push_back(new Merou(sexe,nom,m_compteurPoissons));
            break;
        case THON:
            m_poissons.push_back(new Thon(sexe,nom,m_compteurPoissons));
            break;
        case POISSONCLOWN:
            m_poissons.push_back(new PoissonClown(sexe,nom,m_compteurPoissons));
            break;
        case SOLE:
            m_poissons.push_back(new Sole(sexe,nom,m_compteurPoissons));
            break;
        case BAR:
            m_poissons.push_back(new Bar(sexe,nom,m_compteurPoissons));
            break;
        case CARPE:
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
        
        
    }
}

void Aquarium::cleanAquarium()
{
    vector<Algue*>::iterator it;
    
    
    for (it = m_algues.begin(); it!= m_algues.end() ; ++it) {
        if ((*it)->isAlive() != true) {
            delete *it;
            m_algues.erase(it);
        }
    }
    
    vector<Poisson*>::iterator it2;
    
    
    for (it2 = m_poissons.begin(); it2!= m_poissons.end() ; ++it2) {
        if ((*it2)->isAlive() != true) {
            delete *it2;
            m_poissons.erase(it2);
        }
    }
}


