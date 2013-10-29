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

void RenderSystem::render(Entity *entity)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(entity->getVertexBuffer()->getShader()->getProgramHandle());
    
    glLoadIdentity();
    gluLookAt(1.0f, 1.0f, 2.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    
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