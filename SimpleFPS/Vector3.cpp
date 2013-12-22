//
//  Vector3.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 30/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Vector3.h"
#include <math.h>

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

Vector3 subtractVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 newVector;
    newVector.x = vectorA.x - vectorB.x;
    newVector.y = vectorA.y - vectorB.y;
    newVector.z = vectorA.z - vectorB.z;
    
    return newVector;
}


Vector3 normalizeVector3(Vector3 vector)
{
    GLdouble lenght = sqrt(vector.x*vector.x+vector.y*vector.y+vector.z*vector.z);
    
    Vector3 unitVector;
    unitVector.x = vector.x/lenght;
    unitVector.y = vector.y/lenght;
    unitVector.z = vector.z/lenght;
    
    return unitVector;
}

Vector3 crossProductVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 newVector;
    newVector.x = vectorA.y*vectorB.z - vectorA.z*vectorB.y;
    newVector.y = vectorA.z*vectorB.x - vectorA.x*vectorB.z;
    newVector.z = vectorA.x*vectorB.y - vectorA.y*vectorB.x;
    
    return newVector;
}

Vector3 scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue)
{
    Vector3 newVector;
    newVector.x = vectorToMultiply.x*scalerValue;
    newVector.y = vectorToMultiply.y*scalerValue;
    newVector.z = vectorToMultiply.z*scalerValue;
    
    return newVector;
}

GLfloat dotProductVector3(Vector3 vectorA, Vector3 vectorB)
{
    return vectorA.x*vectorB.x+vectorA.y*vectorB.y+vectorA.z*vectorB.z;
}

Vector3 transformVector3(Vector3 vector, Matrix3 transformationMatrix)
{
    Vector3 newVector;
    newVector.x = dotProductVector3(vector, makeVector3(transformationMatrix.m00, transformationMatrix.m10, transformationMatrix.m20));
    newVector.y = dotProductVector3(vector, makeVector3(transformationMatrix.m01, transformationMatrix.m11, transformationMatrix.m21));
    newVector.z = dotProductVector3(vector, makeVector3(transformationMatrix.m02, transformationMatrix.m12, transformationMatrix.m22));
    
    return newVector;
}