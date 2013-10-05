//
//  VertexData.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 30/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef SimpleFPS_VertexData_h
#define SimpleFPS_VertexData_h

#include "Vector3.h"

typedef struct {
    
    Vector3 positionCoordinates;
    
} VertexDataP;

typedef struct {
    
    Vector3 positionCoordinates;
    Vector3 normalCoordinates;
    
} VertexDataPN;

#endif
