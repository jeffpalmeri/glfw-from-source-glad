#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "include/glad/gl.h"

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void) {

  glfwSetErrorCallback(error_callback);

  printf("GLFW_CONTEXT_VERSION_MAJOR: %d\n", GLFW_CONTEXT_VERSION_MAJOR);
  printf("glfw init: %d\n", glfwInit());

  GLFWwindow *window = glfwCreateWindow(640, 480, "new window baby", NULL, NULL);


  glfwSetKeyCallback(window, key_callback);

  if (!window) {
    // Window or OpenGL context creation failed
    printf("Window or OpenGL context creation failed\n");
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);
  gladLoadGL(glfwGetProcAddress);

  while (!glfwWindowShouldClose(window))
  {
    // glfwDestroyWindow(window);

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
}
// testing
// int main(void)
// {
//     GLFWwindow* window;
//
//     /* Initialize the library */
//     if (!glfwInit())
//         return -1;
//
//     /* Create a windowed mode window and its OpenGL context */
//     window = glfwCreateWindow(940, 480, "Helloooo World!?!?", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
//
//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);
//
//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window))
//     {
//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT);
//
//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);
//
//         /* Poll for and process events */
//         glfwPollEvents();
//     }
//
//     glfwTerminate();
//     return 0;
// }
