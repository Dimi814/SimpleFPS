//
//  CameraSystem.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 10/11/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__CameraSystem__
#define __SimpleFPS__CameraSystem__

#include <iostream>
#include "Entity.h"

class CameraSystem
{
private:
    
    Entity *_currentCamera;
    
    CameraSystem();
    ~CameraSystem();
    
public:
    
    Entity *getCurrentCamera();
    void setCurrentCamera(Entity *newCamera);
    
    static CameraSystem& getCameraSystem();
    static  void destroyCameraSystem();
};


#endif /* defined(__SimpleFPS__CameraSystem__) */
