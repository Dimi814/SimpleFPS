//
//  ShaderLoader.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 13/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "ShaderLoader.h"

/*void printShaderInfoLog(GLuint obj)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
    
    glGetShaderiv(obj, GL_INFO_LOG_LENGTH,&infologLength);
    
    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
        printf("%s\n",infoLog);
        free(infoLog);
    }
}*/

//didn't make that yet ep09

GLuint ShaderLoader::getProgramHandle()
{
    return _programHandle;
}

GLuint ShaderLoader::compileShader(GLenum shader, const char *source)
{
    GLuint shaderHandle = glCreateShader(shader);
    glShaderSource(shaderHandle, 1, &source, NULL);
    glCompileShader(shaderHandle);
    
    //printShaderInfoLog(shaderHandle);
    
    return shaderHandle;
}

ShaderLoader::ShaderLoader(const char *sourceVS, const char *sourceFS)
{
    _programHandle = glCreateProgram();
    
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, sourceVS);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, sourceFS);
    
    glAttachShader(_programHandle, vertexShader);
    glAttachShader(_programHandle, fragmentShader);
    
    glLinkProgram(_programHandle);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ShaderLoader::~ShaderLoader()
{
    glDeleteProgram(_programHandle);
}