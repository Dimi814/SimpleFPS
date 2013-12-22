//
//  Scene.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 19/11/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Scene.h"
#include "CameraSystem.h"
#include "ResourceManager.h"
#include "PlayerInputSystem.h"

std::vector<Entity *>* Scene::getChildren()
{
    return _children;
}

Scene::Scene()
{
    _children = new std::vector<Entity *>();
    
    ResourceManager *resourceManager = &ResourceManager::getResourceManager();
    Entity *entity =new Entity(resourceManager->getVertexBufferArray()->at(1),
                       makeVector3(0.0f, 0.0f, 5.0f));
    
    _children->push_back(entity);
    
    Entity *camera = new Entity(NULL, makeVector3(0.0f, 0.0f, 0.0f));
    camera->setEyeVector(normalizeVector3(makeVector3(0.0f, 0.0f, 1.0f)));
    
    PlayerInputSystem *playerInputSystem = &PlayerInputSystem::getPlayerInputSystem();
    playerInputSystem->setCurrentPlayer(camera);
    
    _children->push_back(camera);
    
    CameraSystem *cameraSystem = &CameraSystem::getCameraSystem();
    cameraSystem->setCurrentCamera(camera);
}

Scene::~Scene()
{
    for (std::vector<Entity *>::iterator iterator = _children->begin(); iterator != _children->end(); iterator++) {
        delete *iterator;
    }
    
    delete _children;
}