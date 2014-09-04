//
//  RenderSystem.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 8/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "RenderSystem.h"
#include "ShaderInterface.h"


Entity* RenderSystem::getCurrentCamera()
{
    return _currentCamera;
}

void RenderSystem::setCurrentCamera(Entity *newCamera)
{
    _currentCamera = newCamera;
}


RenderSystem::RenderSystem(): _window(glfwGetCurrentContext()),
_cameraSystem(&CameraSystem::getCameraSystem())
{
    _currentCamera = _cameraSystem->getCurrentCamera();
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::render(std::vector<Entity *> *entityArray)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (std::vector<Entity *>::iterator iterator = entityArray->begin(); iterator != entityArray->end(); iterator++) {
    
        Entity *entity = *iterator;
        if (entity->getVertexBuffer() != NULL) {
    
    glUseProgram(entity->getVertexBuffer()->getShader()->getProgramHandle());
    glLoadIdentity();
    
    gluLookAt(_currentCamera->getPosition().x,
              _currentCamera->getPosition().y,
              _currentCamera->getPosition().z,
              _currentCamera->getEyeVector().x,
              _currentCamera->getEyeVector().y,
              _currentCamera->getEyeVector().z,
              _currentCamera->getUpVector().x,
              _currentCamera->getUpVector().y,
              _currentCamera->getUpVector().z);
    
    glTranslatef(entity->getPosition().x, entity->getPosition().y, entity->getPosition().z);
    
    glRotatef(entity->getRotation().x, 0.0f, 0.0f, 1.0f);
    glRotatef(entity->getRotation().y, 0.0f, 1.0f, 0.0f);
    glRotatef(entity->getRotation().z, 1.0f, 0.0f, 0.0f);
    
    glScalef(entity->getScale().x, entity->getScale().y, entity->getScale().z);

    glUniform4f(entity->getVertexBuffer()->getShader()->get_uColor(),
                entity->getVertexBuffer()->getShaderData()->get_uColorValue().x,
                entity->getVertexBuffer()->getShaderData()->get_uColorValue().y,
                entity->getVertexBuffer()->getShaderData()->get_uColorValue().z,
                entity->getVertexBuffer()->getShaderData()->get_uColorValue().w);
    
    glUniform3f(entity->getVertexBuffer()->getShader()->get_uLightPosition(),
                entity->getVertexBuffer()->getShaderData()->get_uLightPosition().x,
                entity->getVertexBuffer()->getShaderData()->get_uLightPosition().y,
                entity->getVertexBuffer()->getShaderData()->get_uLightPosition().z);

    
    entity->getVertexBuffer()->configureVertexAttributes();
    entity->getVertexBuffer()->renderVertexBuffer();
        }
    }
        
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
        gluPerspective(65.0f, 1280.0f/720.0f, 1, 1000);
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
