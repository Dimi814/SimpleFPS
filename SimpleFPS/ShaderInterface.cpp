//
//  ShaderInterface.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 22/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "ShaderInterface.h"
#include <stdio.h>
#include <stdlib.h>

GLuint ShaderInterface::getProgramHandle()
{
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex()
{
    return _aPositionVertex;
}

GLint ShaderInterface::get_aPositionNormal()
{
    return _aPositionNormal;
}

GLint ShaderInterface::get_uColor()
{
    return _uColor;
}

GLint ShaderInterface::get_uLightPosition()
{
    return _uLightPosition;
}

ShaderInterface::ShaderInterface(const char *VS, const char *FS)
{
    
    _vertexShaderString = loadTextFromFile(VS);
    _fragmentShaderString = loadTextFromFile(FS);
    
    shader = new ShaderLoader(_vertexShaderString, _fragmentShaderString);
    
    free(_vertexShaderString);
    free(_fragmentShaderString);
    
    _aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");
    _aPositionNormal = glGetAttribLocation(shader->getProgramHandle(), "aPositionNormal");
    
    _uColor = glGetUniformLocation(shader->getProgramHandle(), "uColor");
    _uLightPosition = glGetUniformLocation(shader->getProgramHandle(), "uLightPosition");

}

ShaderInterface::~ShaderInterface()
{
    delete shader;
}

char *ShaderInterface::loadTextFromFile(const char *file)
{
    FILE *currentFile = fopen(file, "rt");
    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile);
    
    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count +1));
    count = (int)fread(data, sizeof(char), count, currentFile);
    data[count] = '\0';
    
    fclose(currentFile);
    
    return data;
}