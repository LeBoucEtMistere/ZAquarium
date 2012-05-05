//
//  Poisson.h
//  ZAquarium
//
//  Created by DEPASSE Arthur on 30/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ZAquarium_Poisson_h
#define ZAquarium_Poisson_h

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

#include <string>
#include <vector>
#include "Algue.h"



//
// =============================Poisson==============================//
class Poisson
{
    
public:
    
    Poisson( unsigned int ID);
    Poisson(SEXE sexe, std::string nom, unsigned int ID);
    
    virtual void afficher() const =0;
    virtual void doSomething(const std::vector<Poisson*> &poissons,const std::vector<Algue*> &algues) ;
    virtual void manger() ;
    void degats(int degats);
    
    unsigned int getID() const;
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
    virtual void afficher() const =0;
    void doSomething(const std::vector<Poisson*> &poissons,const std::vector<Algue*> &algues);
    void manger(const std::vector<Poisson*> &poissons);
    
    
protected:
    

    
};


//
// =============================PoissonHerbivore==============================//
class Herbivore : public Poisson
{
    
public:
    
    Herbivore(unsigned int ID);
    Herbivore(SEXE sexe, std::string nom,unsigned int ID);
    virtual void afficher() const =0;
    void doSomething(const std::vector<Poisson*> &poissons,const std::vector<Algue*> &algues);
    void manger(const std::vector<Algue*> &liste_algues);
    
    
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