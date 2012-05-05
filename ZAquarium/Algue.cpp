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



Algue::Algue() : m_alive(true), m_PV(10)
{
    cout << "Nouvelle algue créée" << endl;
}

void Algue::afficher()
{
    cout << "Je suis une algue" << endl;
}

void Algue::doSomething()
{
    m_PV += 1;
}

void Algue::degats(int degats)
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
