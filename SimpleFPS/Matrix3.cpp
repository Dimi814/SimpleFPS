//
//  Matrix3.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 22/12/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Matrix3.h"
#include <math.h>

Matrix3 scalerMultiplyMatrix3(Matrix3 matrix, GLfloat scalerValue)
{
    Matrix3 newMatrix3;
    newMatrix3.m00 = matrix.m00*scalerValue;
    newMatrix3.m01 = matrix.m01*scalerValue;
    newMatrix3.m02 = matrix.m02*scalerValue;
    newMatrix3.m10 = matrix.m10*scalerValue;
    newMatrix3.m11 = matrix.m11*scalerValue;
    newMatrix3.m12 = matrix.m12*scalerValue;
    newMatrix3.m20 = matrix.m20*scalerValue;
    newMatrix3.m21 = matrix.m21*scalerValue;
    newMatrix3.m22 = matrix.m22*scalerValue;
    
    return newMatrix3;
}

Matrix3 addMatrix3(Matrix3 matrixA, Matrix3 matrixB)
{
    Matrix3 newMatrix3;
    newMatrix3.m00 = matrixA.m00 + matrixB.m00;
    newMatrix3.m01 = matrixA.m01 + matrixB.m01;
    newMatrix3.m02 = matrixA.m02 + matrixB.m02;
    newMatrix3.m10 = matrixA.m10 + matrixB.m10;
    newMatrix3.m11 = matrixA.m11 + matrixB.m11;
    newMatrix3.m12 = matrixA.m12 + matrixB.m12;
    newMatrix3.m20 = matrixA.m20 + matrixB.m20;
    newMatrix3.m21 = matrixA.m21 + matrixB.m21;
    newMatrix3.m22 = matrixA.m22 + matrixB.m22;
    
    return newMatrix3;
}

Matrix3 makeRotationMatrix3(GLfloat angle, GLfloat xAxis, GLfloat yAxis,GLfloat zAxis)
{
    GLfloat x = xAxis;
    GLfloat y = yAxis;
    GLfloat z = zAxis;
    
    GLfloat cosine = (GLfloat)cos(angle);
    
    Matrix3 cosineMatrix = scalerMultiplyMatrix3(identityMatrix3, cosine);
    
    Matrix3 tangentMatrix = { x * x, x * y, x * z,
        x * y, y * y, y * z,
        x * z, y * z, z * z};
    GLfloat tangent = 1.0f - cosine;
    
    
    tangentMatrix = scalerMultiplyMatrix3(tangentMatrix, tangent);
    
    
    Matrix3 sineMatrix = { 0.0f,    z, -y,
        -z, 0.0f,  x,
        y,   -x,0.0f};
    
    GLfloat sine = (GLfloat)sin(angle);
    
    sineMatrix = scalerMultiplyMatrix3(sineMatrix, sine);
    
    return addMatrix3(addMatrix3(cosineMatrix, tangentMatrix), sineMatrix);
}