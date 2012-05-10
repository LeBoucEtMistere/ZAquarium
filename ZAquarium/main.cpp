//
//  main.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include <iostream>
#include "Aquarium.h"

#include <cstdlib>

int main (int argc, const char * argv[])
{


    srand(time(0));

    Aquarium monAquarium(21);
    
    monAquarium.ajouterPoisson("Pinoquio", Poisson::MALE, Poisson::MEROU);
    monAquarium.ajouterPoisson("Bambino", Poisson::MALE, Poisson::THON);
    monAquarium.ajouterPoisson("Ella", Poisson::FEMELLE, Poisson::CARPE);
    monAquarium.ajouterPoisson("Benni", Poisson::FEMELLE, Poisson::POISSONCLOWN);
    monAquarium.ajouterPoisson("Pamella", Poisson::FEMELLE, Poisson::BAR);
    monAquarium.ajouterPoisson("Ben", Poisson::MALE, Poisson::SOLE);


    
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();

    monAquarium.run();

    return EXIT_SUCCESS;
}

