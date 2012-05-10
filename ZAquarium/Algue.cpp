//
//  Algue.cpp
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Algue.h"

using namespace std;



Algue::Algue() : m_alive(true), m_PV(10), m_age(0)
{
    cout << "Nouvelle algue créée" << endl;
}

void Algue::afficher()
{
    cout << "Je suis une algue (" << m_PV << ")" << endl;
}

void Algue::doSomething()
{

    if (m_age<20) 
    {
        if (m_PV >= 10) 
        {
        
            //reproduction
            
        }
        m_PV += 1;
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
