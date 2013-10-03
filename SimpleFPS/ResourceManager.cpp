//
//  ResourceManager.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 30/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "ResourceManager.h"
#include "TraingleVertices.h"

std::vector<ShaderInterface *>* ResourceManager::getShaderArray()
{
    return _shaderArray;
}

std::vector<VertexBuffer *>* ResourceManager::getVertexBufferArray()
{
    return _vertexBufferArray;
}

ResourceManager::ResourceManager()
{
    _shaderArray = new std::vector<ShaderInterface *>();
    ShaderInterface *shader = new ShaderInterface("ColorShader.vsh", "ColorShader.fsh");
    _shaderArray->push_back(shader);
    
    _vertexBufferArray = new std::vector<VertexBuffer *>();
    VertexBuffer *vertexBuffer = new VertexBuffer(vertices, sizeof(vertices), GL_TRIANGLES, 3, sizeof(GLfloat)*3, _shaderArray->at(0));
    _vertexBufferArray->push_back(vertexBuffer);
}

ResourceManager::~ResourceManager()
{
    
    for (std::vector<ShaderInterface *>::iterator iterator = _shaderArray->begin(); iterator != _shaderArray->end(); iterator++) {
        delete *iterator;
    }
    
    delete _shaderArray;
    
    for (std::vector<VertexBuffer *>::iterator iterator = _vertexBufferArray->begin(); iterator != _vertexBufferArray->end(); iterator++) {
        delete *iterator;
    }
    
    delete _vertexBufferArray;
}

ResourceManager& ResourceManager::getResourceManager()
{
    ResourceManager *resourceManager = NULL;
    
    if (resourceManager == NULL) {
        resourceManager = new ResourceManager();
    }
    
    return *resourceManager;
}

void ResourceManager::destroyResourceManager()
{
    ResourceManager *resourceManager = &getResourceManager();
    delete resourceManager;
}