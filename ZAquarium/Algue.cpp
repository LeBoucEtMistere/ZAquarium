//
//  Algue.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Algue.h"
#include "Aquarium.h"


using namespace std;



Algue::Algue() : m_alive(true), m_PV(9), m_age(0)
{
    cout << "Nouvelle algue créée" << endl;
}

<<<<<<< HEAD
Algue::Algue(int PV) : m_PV(PV),m_alive(true), m_age(0)
=======
Algue::Algue(int PV) : m_alive(true), m_PV(PV), m_age(0)
>>>>>>> a1eb793ae2294fb65bc35b473d1a713cbcf618cd
{

}

void Algue::afficher()
{
    cout << "Je suis une algue (" << m_PV << ")" << endl;
}

void Algue::doSomething(Aquarium& aquarium)
{

    if (m_age<20)
    {
        if (m_PV >= 10)
        {

            //reproduction
            int pv = m_PV;

            if (pv%2 == 1)
            {
                pv -=1;
                pv/=2;
            }

            else pv/=2;


            aquarium.reproductionAlgue(pv);
            m_PV /= 2;

        }

        else m_PV += 1;

        m_age++;
    }
    else
    {
        m_alive = false;

    }
}

void Algue::degats(unsigned int degats)
{
    m_PV -= degats;

    if (m_PV <= 0)
    {
        m_alive = false;
    }
}

bool Algue::isAlive() const
{
    return m_alive;
}
