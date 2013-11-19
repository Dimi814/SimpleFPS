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

std::vector<Entity *>* Scene::getChildren()
{
    return _children;
}

Scene::Scene()
{
    _children = new std::vector<Entity *>();
    
    ResourceManager *resourceManager = &ResourceManager::getResourceManager();
    Entity *entity =new Entity(resourceManager->getVertexBufferArray()->at(1),
                       makeVector3(0.0f, 1.0f, 0.0f));
    entity->setRotation(makeVector3(90.0f, 0.0f, 0.0f));
    entity->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    //entity->setVelocity(makeVector3(-0.05f, 0.001f, -0.001f));
    //entity->setRotationVelocity(makeVector3(1.0f, 1.0f, 0.0f));
    //entity->setScaleVelocity(makeVector3(0.01f, 0.0f, 0.0f));
    
    _children->push_back(entity);
    
    Entity *camera = new Entity(NULL, makeVector3(1.0f, 1.0f, 2.0f));
    camera->setEyeVector(makeVector3(0.0f, 0.0f, 0.0f));
    camera->setVelocity(makeVector3(0.0f, 0.01f, 0.01f));
    
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