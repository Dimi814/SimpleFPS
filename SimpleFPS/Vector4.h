//
//  Vector4.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 8/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__Vector4__
#define __SimpleFPS__Vector4__

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
    
} Vector4;

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#endif /* defined(__SimpleFPS__Vector4__) */
