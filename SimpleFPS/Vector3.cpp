//
//  Vector3.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 30/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Vector3.h"

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z)
{
    Vector3 newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.z = z;
    
    return newVector;
}

Vector3 addVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 newVector;
    newVector.x = vectorA.x + vectorB.x;
    newVector.y = vectorA.y + vectorB.y;
    newVector.z = vectorA.z + vectorB.z;

    return newVector;
}