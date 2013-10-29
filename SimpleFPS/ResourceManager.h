//
//  ResourceManager.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 30/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__ResourceManager__
#define __SimpleFPS__ResourceManager__

#include <iostream>
#include <vector>
#include "ShaderInterface.h"
#include "VertexBuffer.h"
#include "ShaderData.h"

class ResourceManager
{
private:
    
    std::vector<ShaderInterface *> *_shaderArray;
    std::vector<VertexBuffer *> *_vertexBufferArray;
    
    ShaderData *shaderData;
    
    ResourceManager();
    ~ResourceManager();
    
public:
    
    std::vector<ShaderInterface *>* getShaderArray();
    std::vector<VertexBuffer *>* getVertexBufferArray();
    
    static ResourceManager& getResourceManager();
    static void destroyResourceManager();
    
};

#endif /* defined(__SimpleFPS__ResourceManager__) */
