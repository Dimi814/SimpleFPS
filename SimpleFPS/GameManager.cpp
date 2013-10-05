//
//  GameManager.cpp
//  SimpleFPS
//
//  Created by Dimitriy Dounaev on 1/09/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "GameManager.h"


GameManager::GameManager(bool running):
_running(running), _window(glfwGetCurrentContext()),
_renderSystem(&RenderSystem::getRenderSystem()),
_resourceManager(&ResourceManager::getResourceManager())
{
}

GameManager::~GameManager()
{
    ResourceManager::destroyResourceManager();
    RenderSystem::destroyRenderSystem();
}

void GameManager::runGameLoop()
{
    while (_running) {
        
        _running = !glfwWindowShouldClose(_window);

        _renderSystem->render((_resourceManager->getVertexBufferArray())->at(1));
    }
}

GameManager& GameManager::getGameManager()
{
    static GameManager *gameManager = NULL;
    
    if (gameManager == NULL) {
        
        glfwInit();
        
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        GLFWwindow *window = glfwCreateWindow(1280, 720, "Simple FPS", NULL, NULL);
        glfwMakeContextCurrent(window);
        
        gameManager = new GameManager(true);
        
        std::cout << "GameManager created" << std::endl;
    }
    
    return *gameManager;
}

void GameManager::destroyGameManager()
{
    GameManager *gameManager = &getGameManager();
    delete gameManager;
    
    std::cout << "GameManager destroyed" << std::endl;
    
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    
    glfwTerminate();
    
}