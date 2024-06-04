#include <iostream>
#include <GLFW/glfw3.h>
#include "vulkan.hpp"

void TitleFps(GLFWwindow *pWindow)
{
    static double time0 = glfwGetTime();
    static double time1;
    static double dt;
    static int dframe = -1;
    static std::stringstream info;
    time1 = glfwGetTime();
    dframe++;
    if ((dt = time1 - time0) >= 1)
    {
        info.precision(1);
        info << "anfo window" << "    " << std::fixed << dframe / dt << " FPS";
        glfwSetWindowTitle(pWindow, info.str().c_str());
        info.str(""); // 别忘了在设置完窗口标题后清空所用的stringstream
        time0 = time1;
        dframe = 0;
    }
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        // glClear(GL_COLOR_BUFFER_BIT);

        TitleFps(window);
        /* Swap front and back buffers */
        // glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
