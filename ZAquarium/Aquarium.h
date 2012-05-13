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
#include "Algue.h"


#include <vector>
#include <string>
#include <memory>


class Aquarium
{

public:
    Aquarium(unsigned int toursMax);
    virtual ~Aquarium();
    void ajouterPoisson(const std::string& nom, Poisson::SEXE sexe, Poisson::RACE race);
    void ajouterAlgue();
    void run();
    void cleanAquarium();
    void reproductionAlgue(int PV);

    Poisson* getRandomPoisson() const;
    Algue* getRandomAlgue() const;

private:

    std::vector<std::shared_ptr<Poisson> > m_poissons;
    std::vector<std::shared_ptr<Algue> > m_algues;

    size_t m_compteurPoissons;
    unsigned int m_tours;

    void ajouterAlgue(int PV);

};


#endif
