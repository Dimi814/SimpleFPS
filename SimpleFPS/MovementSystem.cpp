//
//  MovementSystem.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 18/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "MovementSystem.h"

MovementSystem::MovementSystem()
{
    
}

MovementSystem::~MovementSystem()
{
    
}

void MovementSystem::update(std::vector<Entity *> *entityArray)
{
    for (std::vector<Entity *>::iterator iterator = entityArray->begin(); iterator != entityArray->end(); iterator++) {

        Entity *entity = *iterator;
        
    entity->setPosition(addVector3(entity->getPosition(), entity->getVelocity()));
    entity->setScale(addVector3(entity->getScale(), entity->getScaleVelocity()));
    entity->setRotation(addVector3(entity->getRotation(), entity->getRotationVelocity()));
        
    }
}

MovementSystem& MovementSystem::getMovementSystem()
{
    static MovementSystem* movementSystem = NULL;
    
    if (movementSystem == NULL) {
        movementSystem = new MovementSystem();
    }
    
    return *movementSystem;
}

void MovementSystem::destroyMovementSystem()
{
    MovementSystem *movementSystem = &getMovementSystem();
    delete movementSystem;
}