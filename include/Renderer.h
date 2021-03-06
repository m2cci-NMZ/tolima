#include <SDL2/SDL.h>
#include "../include/Camera.h"
#include "../include/TriMesh.h"
#include "../include/Clipper.h"
#include "../include/Shader.h"
#include "../include/Scene.h"
#include <algorithm>
#include <cmath>
#include <vector>

#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

class Renderer
{
private:
    int windowHeight;
    int windowWidth;
    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};
    SDL_Event events;
    float zBuffer[MAX_HEIGHT][MAX_WIDTH];
    bool isOpen{true};
    bool wireMode{false};

public:
    Renderer(int hieght, int width);
    int getWidth();
    int getHeight();
    void setWidth(int width);
    void setHeight(int height);
    Scene transformScene(Camera &camera, Scene &scene, Clipper clip);
    void drawScene(Scene& scene, const Point& campos);
    void drawObject(TriMesh& object, const Point& campos, Shader& s);
    int init();
    void play();
    void eventManager(Camera &camera);
    void renderLoop(Camera& camera, Scene& scene, Clipper& clip);
    int closeWindow();
    void boundingBox(Triangle &t, float &xmin, float &xmax, float &ymin, float &ymax);
    void renderTriangle(Triangle &t, Point campos, Shader& s);
    float edge(const Point& a, const Point& b, const Point& c);
    void resetzBuffer(float depth);
    void drawWireTriangle(Triangle &t);
};
