//
//  Entity.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 11/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__Entity__
#define __SimpleFPS__Entity__

#include <iostream>
#include "VertexBuffer.h"
#include "Vector3.h"
#include <vector>

class Entity
{
private:
    
    VertexBuffer *_vertexBuffer;
    
    Vector3 _position;
    Vector3 _scale;
    Vector3 _rotation;
    
    Vector3 _velocity;
    Vector3 _scaleVelocity;
    Vector3 _rotationVelocity;
    
    Vector3 _eyeVector;
    Vector3 _upVector;
    
public:
    
    VertexBuffer *getVertexBuffer();
    void setVertexBuffer(VertexBuffer *newVertexBuffer);
    
    Vector3 getPosition();
    void setPosition(Vector3 newPosition);
    
    Vector3 getScale();
    void setScale(Vector3 newScale);
    
    Vector3 getRotation();
    void setRotation(Vector3 newRotation);
    
    Vector3 getVelocity();
    void setVelocity(Vector3 newVelocity);
    
    Vector3 getScaleVelocity();
    void setScaleVelocity(Vector3 newScaleVelocity);
    
    Vector3 getRotationVelocity();
    void setRotationVelocity(Vector3 newRotationVelocity);
    
    Vector3 getEyeVector();
    void setEyeVector(Vector3 newEyeVector);
    
    Vector3 getUpVector();
    void setUpVector(Vector3 newUpVector);

    Entity(VertexBuffer *vertexBuffer, Vector3 position);
    ~Entity();
};

#endif /* defined(__SimpleFPS__Entity__) */
