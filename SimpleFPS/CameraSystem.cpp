//
//  CameraSystem.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 10/11/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "CameraSystem.h"
#include "RenderSystem.h"

Entity* CameraSystem::getCurrentCamera()
{
    return _currentCamera;
}

void CameraSystem::setCurrentCamera(Entity *newCamera)
{
    _currentCamera = newCamera;
    
    RenderSystem *renderSystem = &RenderSystem::getRenderSystem();
    renderSystem->setCurrentCamera(_currentCamera);
}

CameraSystem::CameraSystem()
{
    
}

CameraSystem::~CameraSystem()
{
    
}

CameraSystem& CameraSystem::getCameraSystem()
{
    static CameraSystem *cameraSystem = NULL;
    
    if (cameraSystem == NULL) {
        
        cameraSystem = new CameraSystem();
    }
    
    return *cameraSystem;
}

void CameraSystem::destroyCameraSystem()
{
    CameraSystem *cameraSystem = &getCameraSystem();
    delete cameraSystem;
}