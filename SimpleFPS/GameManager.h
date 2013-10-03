//
//  GameManager.h
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 1/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __SimpleFPS__GameManager__
#define __SimpleFPS__GameManager__

#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderSystem.h"
#include "ResourceManager.h"

class GameManager
{
private:
    
    bool _running;
    RenderSystem *_renderSystem;
    ResourceManager *_resourceManager;
    GLFWwindow *_window;

    
    GameManager(bool running);
    ~GameManager();

public:

    void runGameLoop();
    
    static GameManager& getGameManager();
    static void destroyGameManager();
    
};

#endif /* defined(__SimpleFPS__GameManager__) */
