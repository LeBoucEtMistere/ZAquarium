//
//  Algue.h
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ZAquarium_Algue_h
#define ZAquarium_Algue_h


class Aquarium;

class Algue
{
public:

    Algue();
    Algue(int PV);

    void afficher();
    void doSomething(Aquarium& aquarium);
    void degats(unsigned int degats);

    bool isAlive() const;



protected:

    bool m_alive;
    int m_PV;
    int m_age;


};

#endif
