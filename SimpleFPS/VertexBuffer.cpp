//
//  VertexBuffer.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 12/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "VertexBuffer.h"

GLuint VertexBuffer::getVertexBufferID()
{
    return _vertexBufferID;
}

ShaderInterface *VertexBuffer::getShader()
{
    return _shader;
}

VertexBuffer::VertexBuffer(const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride, ShaderInterface *shader):
_mode(mode), _count(count), _stride(stride), _shader(shader)
{
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_vertexBufferID);
    _vertexBufferID = 0;
}

void VertexBuffer::configureVertexAttributes()
{
    if (_shader->get_aPositionVertex() != -1) {
        glEnableVertexAttribArray(_shader->get_aPositionVertex());
        glVertexAttribPointer(_shader->get_aPositionVertex(), 3, GL_FLOAT, GL_FALSE, _stride, NULL);
    }
}

void VertexBuffer::renderVertexBuffer()
{
    glDrawArrays(_mode, 0, _count);
}