//
//  ShaderData.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 8/10/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "ShaderData.h"

Vector4 ShaderData::get_uColorValue()
{
    return _uColorValue;
}

void ShaderData::set_uColorValue(Vector4 newColor)
{
    _uColorValue = newColor;
}

Vector3 ShaderData::get_uLightPosition()
{
    return _uLightPosition;
}

void ShaderData::set_uLightPosition(Vector3 newPosition)
{
    _uLightPosition = newPosition;
}

ShaderData::ShaderData(Vector4 newColor, Vector3 newPosition):
_uColorValue(newColor),_uLightPosition(newPosition)
{
    
}

ShaderData::~ShaderData()
{
    
}
