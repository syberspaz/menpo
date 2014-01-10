#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glrglfw.h"
#include "glrasterizer.h"

glr_glfw_config glr_build_glfw_config(int width, int height){
	glr_glfw_config config;
	config.title = "Generic Viewer";
    config.WINDOW_WIDTH = width;
    config.WINDOW_HEIGHT = height;
    config.WINDOW_X_POSITION = 0;
    config.WINDOW_Y_POSITION = 0;
    //config.display_mode = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH GLFW_VISIBLE;
    return config;
}

void glr_glfw_init(glr_glfw_config* config)
{
	printf("glr_glfw_init(...)\n");
	// Fire up glfw
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_VISIBLE, 0);
    config->window = glfwCreateWindow(
            config->WINDOW_WIDTH, config->WINDOW_HEIGHT,
            config->title, NULL, NULL);
    if (!config->window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(config->window);

    printf("Have context.\n");
	// Fire up GLEW
	GLenum status = glewInit();
	if (status != GLEW_OK) {
	   fprintf(stderr, "GLEW Failed to start! Error: %s\n",
			   glewGetErrorString(status));
	   exit(EXIT_FAILURE);
	}
	fprintf(stdout, "  - Using GLEW %s\n", glewGetString(GLEW_VERSION));
	if(GLEW_ARB_texture_buffer_object_rgb32)
	   fprintf(stdout, "  - Float (X,Y,Z) rendering is supported\n");
	else
	   fprintf(stdout, "  - Float (X,Y,Z) rendering not supported\n");

	fprintf(stdout,"  - OpenGL Version: %s\n",glGetString(GL_VERSION));
}

