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
    ~Aquarium();
    void ajouterPoisson(const std::string& nom, SEXE sexe, RACE race);
    void ajouterAlgue();
    void run();
    void cleanAquarium();
    
    
private:
    
    std::vector<Poisson*> m_poissons;
    std::vector<Algue*> m_algues;
    unsigned int m_compteurPoissons;
    
    
};


#endif