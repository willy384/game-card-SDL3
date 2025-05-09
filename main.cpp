#include <SDL3/SDL.h>
//#include <SDL3/SDL_audio.h>

bool init();
bool load();
bool loop();
void kill();

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* winSurface;
SDL_Surface* image1;
SDL_Surface* image2;

int main( int argc, char *argv[] )
{
    init();
    load();
    while(loop()){
        SDL_Delay(10);
    }

    kill();
    return 0;    
}

bool loop(){
    SDL_Event e;
	// Event loop
    
	while ( SDL_PollEvent( &e ) != 0 ) {
        SDL_BlitSurface( image1, NULL, winSurface, NULL );
        SDL_UpdateWindowSurface( window );
        
		switch ( e.type ) {
		case SDL_EVENT_QUIT:
		    return false;
		break;
		}
	}
    return true;  
}

bool load(){
    SDL_Surface *temp1, *temp2;

    temp1 = SDL_LoadBMP("images/background.bmp");
    temp2 = SDL_LoadBMP("images/background.bmp");
    if ( temp1 == NULL || temp2 == NULL ) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
        return false;
    }
    image1 = SDL_ConvertSurface( temp1, winSurface->format );
    image2 = SDL_ConvertSurface( temp2, winSurface->format );
    if ( image1 == NULL || image2 == NULL ) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
        return false;
    }
    SDL_DestroySurface( temp1 );
    SDL_DestroySurface( temp2 );
}

bool init(){
    SDL_Init( SDL_INIT_VIDEO );
    window = SDL_CreateWindow( "gamedev", 1408, 768, SDL_WINDOW_MINIMIZED );
    if ( !window )
    {
        // In the case that the window could not be made...
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
        return 1;
    }
    renderer = SDL_CreateRenderer( window, 0);
    if ( !renderer ) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
		return false;
	}
    
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );

    winSurface = SDL_GetWindowSurface( window );
    return true;
}

void kill(){
    SDL_DestroyRenderer( renderer );
    SDL_Surface(image1);
    SDL_DestroyWindow(window);
    SDL_Quit();
}