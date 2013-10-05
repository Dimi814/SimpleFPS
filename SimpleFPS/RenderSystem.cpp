//
//  RenderSystem.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 8/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "RenderSystem.h"
#include "ShaderInterface.h"


RenderSystem::RenderSystem(): _window(glfwGetCurrentContext())
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::render(VertexBuffer *vertexBuffer)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram((vertexBuffer->getShader())->getProgramHandle());
    
    glLoadIdentity();
    gluLookAt(3.0f, 2.0f, -2.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    
    glUniform4f((vertexBuffer->getShader())->get_uColor(),
                1.0f, 1.0f, 0.0f, 1.0f);
    
    vertexBuffer->configureVertexAttributes();
    vertexBuffer->renderVertexBuffer();
    
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

RenderSystem& RenderSystem::getRenderSystem()
{
    static RenderSystem *renderSystem = NULL;
    
    if (renderSystem == NULL) {
        renderSystem = new RenderSystem();
        
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        
        glMatrixMode(GL_PROJECTION);
        gluPerspective(75.0f, 1280.0f/720.0f, 1, 1000);
        glViewport(0.0f, 0.0f, 1280.0f, 720.0f);
        glMatrixMode(GL_MODELVIEW);
        
        glEnable(GL_CULL_FACE);
    }
    
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem()
{
    RenderSystem *renderSystem = &getRenderSystem();
    delete renderSystem;
}