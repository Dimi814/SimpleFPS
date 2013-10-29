//
//  Vector4.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 8/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Vector4.h"

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    Vector4 newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.z = z;
    newVector.w = w;
    
    return newVector;
}