#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "WindowManager.h"


// Renderowanie okna
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

// Wczytywanie tekstury
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
    {
        std::cout << "Failed to load texture: " << SDL_GetError() << std::endl;
    }

    return texture;
}

// Czyszczenie pami�ci itp
void RenderWindow::cleanUp()
{
    if (renderer != nullptr) 
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) 
    {
        SDL_DestroyWindow(window);
    }
}

// Czyszczenie okna
void RenderWindow::clear()
{
    if (renderer != nullptr)
    {
        SDL_RenderClear(renderer);
    }
}
// Renderowanie obiekt�w na obraz
SDL_Rect RenderWindow::render(GameObject& p_gameObject, float cameraX)
{
    SDL_Rect spriteFrame = p_gameObject.getObjectSize();
    SDL_Rect objectSize;

    objectSize.x = static_cast<int>((p_gameObject.getPos().x - cameraX) * 4);
    objectSize.y = static_cast<int>(p_gameObject.getPos().y * 4);
    objectSize.w = static_cast<int>(p_gameObject.getObjectSize().w / 10 * 4);
    objectSize.h = static_cast<int>(p_gameObject.getObjectSize().h / 10 * 4);

    SDL_RenderCopyEx(renderer, p_gameObject.getTex(), &spriteFrame, &objectSize, p_gameObject.getRotation(), nullptr, SDL_FLIP_NONE);

    return objectSize;
}


// Pokazywanie na obrazie
void RenderWindow::display()
{
    if (renderer != nullptr) 
    {
        SDL_RenderPresent(renderer);
    }
}

// Renderowanie t�a
void RenderWindow::renderBackground(SDL_Texture* backgroundTexture)
{
    SDL_Rect TargetRec;
    TargetRec.x = 0;
    TargetRec.y = 0;
    TargetRec.w = 1920;
    TargetRec.h = 1080;

    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &TargetRec);
}

// Zwracanie wska�nika na renderer
SDL_Renderer* RenderWindow::getRenderer() const
{
    return renderer;
}