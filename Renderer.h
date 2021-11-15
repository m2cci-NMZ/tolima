#include <SDL2/SDL.h>
#include "Camera.h"
#include "TriMesh.h"
#include "Clipper.h"
#include "Shader.h"
#include "Scene.h"
#include <algorithm>
#include <cmath>
#include <vector>

class Renderer
{
private:
    int windowHeight;
    int windowWidth;
    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};
    SDL_Event events;
    bool isOpen{true};

public:
    Renderer(int hieght, int width);
    int getWidth();
    int getHeight();
    void setWidth(int width);
    void setHeight(int height);
    void drawObject(TriMesh object, std::vector<std::vector<float>> &zbuffer, Point campos);
    int init();
    void play();
    void eventManager(Camera &camera);
    void renderLoop(Camera camera, Scene scene, Shader shader, Clipper clip);
    int closeWindow();
    void boundingBox(Triangle &t, float &xmin, float &xmax, float &ymin, float &ymax);
    void renderTriangle(Triangle &t, std::vector<std::vector<float>> &zbuffer, Point campos);
};
