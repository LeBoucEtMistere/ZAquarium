//
//  Aquarium.h
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ZAquarium_Aquarium_h
#define ZAquarium_Aquarium_h

#include "Algue.h"
#include "Poisson.h"

#include <vector>
#include <string>

class Aquarium
{

public:
    Aquarium();
    virtual ~Aquarium();
    void ajouterPoisson(const std::string& nom, Poisson::SEXE sexe, Poisson::RACE race);
    void ajouterAlgue();
    void run();
    void cleanAquarium();

    bool getRandomPoisson(Poisson*& ptr) const;
    bool getRandomAlgue(Algue*& ptr) const;

private:

    std::vector<Poisson*> m_poissons; // Vector of pointers is not exeption safe. Should use vector of smart pointers.
    std::vector<Algue*> m_algues;
    unsigned int m_compteurPoissons; //Would consider using type size_t
};


#endif
