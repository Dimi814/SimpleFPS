//
//  ShaderLoader.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 13/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__ShaderLoader__
#define __SimpleFPS__ShaderLoader__

#include <iostream>
#include <GLFW/glfw3.h>

class ShaderLoader
{
private:
    
    GLuint _programHandle;
    
    GLuint compileShader(GLenum shader, const  char *source);
    
public:
    
    GLuint getProgramHandle();
    
    ShaderLoader(const char *sourceVS, const char *sourceFS);
    ~ShaderLoader();

};

#endif /* defined(__SimpleFPS__ShaderLoader__) */
