// To compile: g++ -o main main.cpp ./glad/src/glad.c -I./glad/include -lSDL2 -ldl

/*
Ishai Masada
Game Source Code!
*/

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>

const char* window_title = "Game";

using namespace std;

int main(int argc, char* args[])
{
    // Check if SDL can Initialize
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Initialiation FAILED. SDL ERROR: " << SDL_GetError() << endl;
    }
    
    else
    {
        cout << "SDL Video system Initialized." << endl;
    }

    // Create SDL window for the game
    SDL_Window *window = nullptr;

    window = SDL_CreateWindow(
             window_title,
             SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED,
             640,
             480,
             SDL_WINDOW_SHOWN
    );

    // Infinite Loop
    bool game_is_running = true;
    while (game_is_running)
    {
        SDL_Event event;

        // Event loop
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            switch(event.type)
            {
                case SDL_QUIT:
                    game_is_running = false;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    cout << "Program Terminated" << endl;

    return 0;
}
