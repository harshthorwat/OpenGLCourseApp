#include<stdio.h>

#include<GL/glew.h>
#include<GLFW/glfw3.h>

//Window Dimentions
const GLint WIDTH = 800, HEIGHT = 600;

int main() {

	//Initialize GLFW
	if (!glfwInit()) {
		printf("GLFW Initialization Failed.\n");
		glfwTerminate();
		return 1;
	}

	//Setup GLFW window Properties
	//OpenGL Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Core Profile == no Backword Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow Forward Compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);

	if (!mainWindow) {
		printf("GLFW Window Creation Failed\n");
		glfwTerminate();
		return 1;
	}

	//Get BufferSize Information

	int bufferwidth, bufferheight;
	glfwGetFramebufferSize(mainWindow, &bufferwidth, &bufferheight);

	//Set Context for GLEW to use

	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension feature

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("GLEW Initialization Failed.\n");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Setup ViewPort Size

	glViewport(0, 0, bufferwidth, bufferheight);

	//Loop Until Window Close

	while (!glfwWindowShouldClose(mainWindow)) {
		//Get + Handle User input Events
		glfwPollEvents();

		// Clear Window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}