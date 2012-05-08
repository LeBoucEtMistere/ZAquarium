//
//  Poisson.h
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ZAquarium_Poisson_h
#define ZAquarium_Poisson_h



#include <string>
#include <vector>
#include "Algue.h"

class Aquarium;

//
// =============================Poisson==============================//
class Poisson
{

public:

    enum SEXE {
    MALE = 1,
    FEMELLE = 2
};

enum RACE {
    MEROU = 1,
    THON = 2,
    POISSONCLOWN = 3,
    SOLE = 4,
    BAR = 5,
    CARPE = 6
};

    Poisson( size_t ID);
    Poisson(SEXE sexe, std::string nom, unsigned int ID);
    virtual ~Poisson();

    virtual void afficher() const =0;
/*  I would pass a reference to the Aquarium here instead of passing these 2 vectors.
 *  In Aquarium, you would add some method to retrieve either a Poisson or an Algue randomly.
 *  This would preserve encapsulation better and is more OO, we must think in terms of services.
*/
    virtual void doSomething(const Aquarium& aquarium);
    virtual void manger() ;
    void degats(int degats);

    unsigned int getID() const;
    //Maybe return a const std::string&
    std::string getNom() const;
    bool isAlive() const;



protected:

    SEXE m_sexe;
    std::string m_nom;
    unsigned int m_id;
    bool alive;
    int m_PV;


};


//
// =============================PoissonCarnivore==============================//
class Carnivore : public Poisson
{

public:

    Carnivore(unsigned int ID);
    Carnivore(SEXE sexe, std::string nom,unsigned int ID);
    virtual ~Carnivore();
    virtual void afficher() const =0;
    void doSomething(const Aquarium& aquarium);
    void manger(const Aquarium& aquarium);


protected:



};


//
// =============================PoissonHerbivore==============================//
class Herbivore : public Poisson
{

public:

    Herbivore(unsigned int ID);
    Herbivore(SEXE sexe, std::string nom,unsigned int ID);
    virtual ~Herbivore();
    virtual void afficher() const =0;
    void doSomething(const Aquarium& aquarium);
    void manger(const Aquarium& aquarium);


protected:



};


//
// =============================Merou==============================//
class Merou : public Carnivore
{

public:

    Merou(unsigned int ID);
    Merou(SEXE sexe, std::string nom, unsigned int ID);
    virtual void afficher() const ;




private:


};


//
// =============================Thon==============================//
class Thon : public Carnivore
{

public:

    Thon(unsigned int ID);
    Thon(SEXE sexe, std::string nom,unsigned int ID);
    virtual void afficher() const ;




private:


};


//
// =============================PoissonClown==============================//
class PoissonClown : public Carnivore
{

public:

    PoissonClown(unsigned int ID);
    PoissonClown(SEXE sexe, std::string nom,unsigned int ID);
    virtual void afficher() const ;




private:


};

//
// =============================Sole==============================//
class Sole : public Herbivore
{

public:

    Sole(unsigned int ID);
    Sole(SEXE sexe, std::string nom,unsigned int ID);
    virtual void afficher() const ;




private:


};


//
// =============================Bar==============================//
class Bar : public Herbivore
{

public:

    Bar(unsigned int ID);
    Bar(SEXE sexe, std::string nom,unsigned int ID);
    virtual void afficher() const ;




private:


};


//
// =============================Carpe==============================//
class Carpe : public Herbivore
{

public:

    Carpe(unsigned int ID);
    Carpe(SEXE sexe, std::string nom,unsigned int ID);
    virtual void afficher() const ;




private:


};

#endif
