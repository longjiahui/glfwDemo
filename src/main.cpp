// #include <glad/glad.h>
#include "vulkan.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

using namespace std;

int main(void)
{
    GLFWwindow *window;

    glfwInit();

    /* 禁止GLFW 自动创建OPENGL 上下文 */
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    /* GLFW需要启用的VK插件列表 */
    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    cout << "glfwExtensions: " << endl;
    for (int i = 0; i < glfwExtensionCount; i++)
    {
        cout << "\t" << glfwExtensions[i] << endl;
    }

    if (glfwVulkanSupported())
    {
        cout << "supported ! vulkan" << endl;

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        cout << "availale extensions: " << endl;
        for (const auto &extension : extensions)
        {
            cout << "\t" << extension.extensionName << endl;
        }
    }

    // window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    // glfwMakeContextCurrent(window);

    // while (!glfwWindowShouldClose(window))
    // {
    //     glfwSwapBuffers(window);
    //     glfwPollEvents();
    // }
    // glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
