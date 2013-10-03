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

class RenderSystem
{
private:
    
    GLFWwindow *_window;
    
    RenderSystem();
    ~RenderSystem();
    
public:
    
    void render(VertexBuffer *vertexBuffer);
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
    
};

#endif /* defined(__SimpleFPS__RenderSystem__) */
