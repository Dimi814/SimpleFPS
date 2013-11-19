//
//  MovementSystem.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 18/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__MovementSystem__
#define __SimpleFPS__MovementSystem__

#include <iostream>
#include "Vector3.h"
#include <GLFW/glfw3.h>
#include "Entity.h"

class MovementSystem
{
private:
    
    MovementSystem();
    ~MovementSystem();
    
public:
    
    void update(std::vector<Entity *> *entityArray);
    
    static MovementSystem& getMovementSystem();
    static void destroyMovementSystem();
};


#endif /* defined(__SimpleFPS__MovementSystem__) */
