#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    // initialization
    if (!glfwInit())
        return -1;

    // create window
    window = glfwCreateWindow(32, 32, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // assign window's current context
    glfwMakeContextCurrent(window);

    // update while window is open
    while (!glfwWindowShouldClose(window))
    {
        // rendering
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        // event handling
        glfwPollEvents();
    }
    // terminate window
    glfwTerminate();
    return 0;
}
