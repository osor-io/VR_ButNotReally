#include "./render/RenderManager.h"

/*

	Next Step for the renderer: VALIDATION LAYERS

	Reference: https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Validation_layers

*/


/**

Prints the message in standard output that we are waiting
for a key press and returns after any keypress.

*/
auto pressToContinue() noexcept -> void;

int main() {
	
	/*
	
	Scope useful to be able to stop after every local main variable
	has been destroyed in case we want to check the state, print
	some messages or wait for character input to see the terminal output.

	*/
	{
		try {
			RenderManager render_manager;
			while (!render_manager.shouldClose()) {
				render_manager.update();
			}
		}
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
			return EXIT_FAILURE;
		}
	}

	std::cout << "\nThe program will now be closed" << std::endl;
	pressToContinue();
	return EXIT_SUCCESS;

}



#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
auto pressToContinue() noexcept -> void { system("pause"); }
#else
auto pressToContinue() noexcept -> void { system("read"); }
#endif