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
_resourceManager(&ResourceManager::getResourceManager()),
_movementSystem(&MovementSystem::getMovementSystem()),
_cameraSystem(&CameraSystem::getCameraSystem()), scene(new Scene), _playerInputSystem(&PlayerInputSystem::getPlayerInputSystem())
{
}

GameManager::~GameManager()
{
    ResourceManager::destroyResourceManager();
    CameraSystem::destroyCameraSystem();
    RenderSystem::destroyRenderSystem();
    PlayerInputSystem::destroyPlayerInputSystem();
}

#define Updates_Per_Second 60.0f

void GameManager::runGameLoop()
{
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;
    
    while (_running) {
        
        double currentTime = glfwGetTime();
        deltaTime += (currentTime - lastTime) * Updates_Per_Second;
        lastTime = currentTime;
        
        while (deltaTime >= 1.0f) {
        
            _running = !glfwWindowShouldClose(_window);
        
            _movementSystem->update(scene->getChildren());
            _playerInputSystem->update();
        
            --deltaTime;
        }
        
        _renderSystem->render(scene->getChildren());
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
        glfwWindowHint(GLFW_SAMPLES, 16);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
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