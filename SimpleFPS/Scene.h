//
//  Scene.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 19/11/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__Scene__
#define __SimpleFPS__Scene__

#include <iostream>
#include "Entity.h"
#include <vector>

class Scene
{
private:
    
    std::vector<Entity *> *_children;
    
public:
    
    std::vector<Entity *>* getChildren();
    
    Scene();
    ~Scene();
    
};

#endif /* defined(__SimpleFPS__Scene__) */
