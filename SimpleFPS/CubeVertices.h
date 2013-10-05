//
//  CubeVertices.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 4/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef SimpleFPS_CubeVertices_h
#define SimpleFPS_CubeVertices_h

#include "VertexData.h"

VertexDataPN cubeVertices[] = {
    0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f, //B
    0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f, //C
    0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, //Bb
    0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, //Bb
    0.5f, 0.5f, -0.5f,          1.0f, 0.0f, 0.0f,//C
    0.5f, 0.5f, 0.5f,         1.0f, 0.0f, 0.0f,  //Cc
    
    0.5f, 0.5f, -0.5f,         0.0f, 1.0f, 0.0f, //C
    -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, //D
    0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, //Cc
    0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, //Cc
    -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, //D
    -0.5f, 0.5f, 0.5f,         0.0f, 1.0f, 0.0f, //Dd
    
    -0.5f, 0.5f, -0.5f,        -1.0f, 0.0f, 0.0f, //D
    -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, //A
    -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, //Dd
    -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, //Dd
    -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, //A
    -0.5f, -0.5f, 0.5f,        -1.0f, 0.0f, 0.0f, //Aa
    
    -0.5f, -0.5f, -0.5f,       0.0f, -1.0f, 0.0f, //A
    0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, //B
    -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, //Aa
    -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, //Aa
    0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, //B
    0.5f, -0.5f, 0.5f,         0.0f, -1.0f, 0.0f, //Bb
    
    0.5f, 0.5f, 0.5f,          0.0f, 0.0f, 1.0f, //Cc
    -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Dd
    0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Bb
    0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Bb
    -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Dd
    -0.5f, -0.5f, 0.5f,        0.0f, 0.0f, 1.0f, //Aa
    
    0.5f, -0.5f, -0.5f,        0.0f, 0.0f, -1.0f, //B
    -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, //A
    0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, //C
    0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, //C
    -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, //A
    -0.5f, 0.5f, -0.5f,        0.0f, 0.0f, -1.0f
};


#endif
