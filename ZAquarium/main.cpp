//
//  main.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include <iostream>



#include "Aquarium.h"


int main (int argc, const char * argv[])
{
    Aquarium monAquarium;
    
    monAquarium.ajouterPoisson("Pinoquio", MALE, MEROU);
    monAquarium.ajouterPoisson("Bambino", MALE, THON);
    monAquarium.ajouterPoisson("Ella", FEMELLE, CARPE);
    
    monAquarium.ajouterAlgue();
    monAquarium.ajouterAlgue();

    monAquarium.run();

    return EXIT_SUCCESS;
}

