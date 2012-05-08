//
//  InterfaceReproduction.h
//  ZAquarium
//
//  Created by DEPASSE Arthur on 08/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ZAquarium_InterfaceReproduction_h
#define ZAquarium_InterfaceReproduction_h


/* interfaces de reproduction */

class IReproduction
{
    public :
    
    virtual void reproduction() = 0;
    
    
};

class IReproductionMerou : public IReproduction
{
    public :
    
    virtual void reproduction();
    
    
};

class IReproductionThon : public IReproduction
{
    public :
    
    virtual void reproduction();
    
    
};

class IReproductionPoissonClown : public IReproduction
{
    public :
    
    virtual void reproduction();
    
    
};

class IReproductionSole : public IReproduction
{
    public :
    
    virtual void reproduction();
    
    
};

class IReproductionBar : public IReproduction
{
    public :
    
    virtual void reproduction();
    
    
};

class IReproductionCarpe : public IReproduction
{
    public :
    
    virtual void reproduction();
    
    
};

class IReproductionAlgue : public IReproduction
{
    public :
    
    virtual void reproduction(int age);
};




#endif
