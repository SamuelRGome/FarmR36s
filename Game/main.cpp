#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int main(int argc, char *argv[]) {
    
    // Janela que vai ser renderizada
    SDL_Window* window = NULL;

    // Surface contido pela janela
    SDL_Surface* screenSurface = NULL;

    // Inicializa o SDL
    if( SDL_Init( SDL_INIT_VIDEO) < 0) {

        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    } else {
        //Cria a janela
        window = SDL_CreateWindow( "FarmR36s", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
    } 

    // Pega a surface da janela
    screenSurface = SDL_GetWindowSurface(window);

    //Pinta a surface de branco
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Atualiza a janela
    SDL_UpdateWindowSurface(window);

    // janela aberta até fechar
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
    return 0;
}