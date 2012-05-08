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
<<<<<<< HEAD
    Aquarium monAquarium;

    monAquarium.ajouterPoisson("Pinoquio", MALE, MEROU);
    monAquarium.ajouterPoisson("Bambino", MALE, THON);
    monAquarium.ajouterPoisson("Ella", FEMELLE, CARPE);

=======
    Aquarium monAquarium(21);
    
    monAquarium.ajouterPoisson("Pinoquio", MALE, MEROU);
    monAquarium.ajouterPoisson("Bambino", MALE, THON);
    monAquarium.ajouterPoisson("Ella", FEMELLE, CARPE);
    monAquarium.ajouterPoisson("Benni", FEMELLE, POISSONCLOWN);
    monAquarium.ajouterPoisson("Pamella", FEMELLE, BAR);
    monAquarium.ajouterPoisson("Ben", MALE, SOLE);


    
>>>>>>> BugFixes et implémentation début reproduction (encore bugé)
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();

    monAquarium.run();

    return EXIT_SUCCESS;
}

