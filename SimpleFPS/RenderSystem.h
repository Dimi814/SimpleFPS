//
//  RenderSystem.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 8/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__RenderSystem__
#define __SimpleFPS__RenderSystem__

#include <iostream>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "VertexBuffer.h"
#include <vector>
#include "ShaderInterface.h"
#include "Entity.h"
#include "CameraSystem.h"

class RenderSystem
{
private:
    
    GLFWwindow *_window;
    
    CameraSystem *_cameraSystem;
    Entity *_currentCamera;
    
    RenderSystem();
    ~RenderSystem();
    
public:
    
    Entity *getCurrentCamera();
    void setCurrentCamera(Entity *newCamera);
    
    void render(std::vector<Entity *> *entityArray);
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
    
};

#endif /* defined(__SimpleFPS__RenderSystem__) */
