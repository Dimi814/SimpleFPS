//
//  VertexBuffer.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 12/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__VertexBuffer__
#define __SimpleFPS__VertexBuffer__

#include <iostream>
#include <GLFW/glfw3.h>
#include "ShaderInterface.h"
#include "ShaderData.h"

class VertexBuffer
{
private:
    
    GLuint _vertexBufferID;
    ShaderInterface *_shader;
    ShaderData *_shaderData;
    
    GLenum _mode;
    GLsizei _count;
    GLsizei _stride;
    GLvoid *_positionOffset;
    GLvoid *_normalOffset;
    
public:
    
    GLuint getVertexBufferID();
    ShaderInterface *getShader();
    ShaderData *getShaderData();
    
    VertexBuffer(const GLvoid *data,
                 GLsizeiptr size,
                 GLenum mode,
                 GLsizei count,
                 GLsizei stride,
                 ShaderInterface *shader,
                 ShaderData *shaderData,
                 GLvoid *positionOffset,
                 GLvoid *normalOffset);
    ~VertexBuffer();
    
    void configureVertexAttributes();
    void renderVertexBuffer();
};

#endif /* defined(__SimpleFPS__VertexBuffer__) */
