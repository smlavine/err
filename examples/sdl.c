/**
 * @example sdl.c
 * This example demonstrates how struct err_configuration and errl() can be
 * used to interface a library's own error functionality with err.
 *
 * This example requires libsdl2-dev to run.
 */

#include <assert.h>
#include <SDL2/SDL.h>
#include <stdlib.h>

#include "../err.h"

int
check_sdl_error(void)
{
	/* SDL_GetError() returns an empty string if there isn't an error
	 * message set. */
	return SDL_GetError()[0] != '\0';
}

int
main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	int quit;
	struct err_configuration sdl = {
		&SDL_GetError,
		&check_sdl_error,
	};

	program_invocation_name = argv[0];

	if (argc != 1) {
		err("Do not provide arguments.");
	}

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		errl(&sdl, "Error initializing SDL");
	}
	atexit(SDL_Quit);

	window = SDL_CreateWindow("sdl",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	if (window == NULL) {
		errl(&sdl, "Error creating window");
	}

	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		SDL_DestroyWindow(window);
		errl(&sdl, "Error creating renderer");
	};

	assert(SDL_SetRenderDrawColor(renderer,
			0xAD, 0xD8, 0xE6, SDL_ALPHA_OPAQUE)
		== 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	quit = 0;
	while (!quit) {
		if (SDL_WaitEvent(&event) == 0) {
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			errl(&sdl, "SDL_WaitEvent() error");
		}

		if (event.type == SDL_QUIT) {
			quit = 1;
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	return EXIT_SUCCESS;
}
