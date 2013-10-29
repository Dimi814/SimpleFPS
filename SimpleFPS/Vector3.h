//
//  Vector3.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 30/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__Vector3__
#define __SimpleFPS__Vector3__

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct {
    
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
} Vector3;

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z);
Vector3 addVector3(Vector3 vectorA, Vector3 vectorB);

#endif /* defined(__SimpleFPS__Vector3__) */
