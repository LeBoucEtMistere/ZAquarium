//
//  Aquarium.h
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ZAquarium_Aquarium_h
#define ZAquarium_Aquarium_h

<<<<<<< HEAD
#include "Algue.h"
=======


>>>>>>> BugFixes et implémentation début reproduction (encore bugé)
#include "Poisson.h"
#include "Algue.h"
#include "InterfaceReproduction.h"


#include <vector>
#include <string>

class Aquarium
{

public:
    Aquarium(unsigned int toursMax);
    virtual ~Aquarium();
    void ajouterPoisson(const std::string& nom, SEXE sexe, RACE race);
    void ajouterAlgue();
    void run();
    void cleanAquarium();

private:

    std::vector<Poisson*> m_poissons; // Vector of pointers is not exeption safe. Should use vector of smart pointers.
    std::vector<Algue*> m_algues;
<<<<<<< HEAD
    unsigned int m_compteurPoissons; //Would consider using type size_t
=======
    unsigned int m_compteurPoissons;
    unsigned int m_tours;
    
    
>>>>>>> BugFixes et implémentation début reproduction (encore bugé)
};


#endif
