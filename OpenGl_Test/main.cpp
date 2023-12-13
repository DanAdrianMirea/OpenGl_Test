#include <GLFW/glfw3.h>

float angle = 0.0f;

void draw()
{
    glPushMatrix();
    //glTranslatef(-0, -50, 0);
    glRotatef(angle, 0, angle, 1.0);

    // draw a triangle
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    glBegin(GL_TRIANGLES);
    glColor4ub(255, 0, 0, 255);
    glVertex3fv(vertices);
    glColor4ub(0, 255, 0, 255);
    glVertex3fv(vertices + 3);
    glColor4ub(0, 0, 255, 255);
    glVertex3fv(vertices + 6);
    glEnd();

    glPopMatrix();
}

void update()
{
    	angle += 1.0f;
	if (angle > 360.0f)
		angle -= 360.0f;

}

int main(void)
{
    GLFWwindow* window;

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
        glClear(GL_COLOR_BUFFER_BIT);

        draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        update();
    }

    glfwTerminate();
    return 0;
}