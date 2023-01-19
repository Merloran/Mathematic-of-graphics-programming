#include <iostream>
#include <conio.h>

#include "Source/Public/Vector3.h"
#include "Source/Public/Quaternion.h"
#include "Source/Public/Line.h"
#include "Source/Public/Plane.h"
#include "Source/Public/Camera.h"

const int SIZE = 60;
int main() {

    //bryla2x2x2
    float cubeSize = 2;
    Plane p_front = Plane(Vec3f(-cubeSize / 2, -cubeSize / 2, cubeSize / 2), Vec3f(0, 0, 1));
    Plane p_back = Plane(Vec3f(-cubeSize / 2, -cubeSize / 2, -cubeSize / 2), Vec3f(0, 0, -1));
    Plane p_left = Plane(Vec3f(-cubeSize / 2, -cubeSize / 2, cubeSize / 2), Vec3f(-1, 0, 0));
    Plane p_right = Plane(Vec3f(cubeSize / 2, -cubeSize / 2, cubeSize / 2), Vec3f(1, 0, 0));
    Plane p_bottom = Plane(Vec3f(-cubeSize / 2, -cubeSize / 2, cubeSize / 2), Vec3f(0, -1, 0));
    Plane p_up = Plane(Vec3f(-cubeSize / 2, cubeSize / 2, cubeSize / 2), Vec3f(0, 1, 0));

    char tab[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tab[i][j] = '.';
        }
    }

    float width = 2;

    Camera cam = Camera(3);

    float angleX = 0;
    float angleY = 0;
    float angleZ = 0;

    int input;
    float zoom = 3;
    do {
        cam = Camera(zoom);
        cam.rotateX(angleX);
        cam.rotateY(angleY);
        //cam.rotateAxis(45, Vec3f(1, 1, 0));
        cam.rotateZ(angleZ);
        //        std::cout << "pos: " << cam.position << ", dir: " << cam.direction << ", up: " << cam.up << std::endl;

        Vec3f rightDirectionView = cam.direction.Cross(cam.up);
        Line ray = Line(cam.position, cam.direction);
        Vec3f point;
        bool isCrossing = false;
        for (int i = 0; i < SIZE; i++) { //wiersze
            for (int j = 0; j < SIZE; j++) { //kolumny
                ray.V =
                    cam.direction +
                    Vec3f((j - SIZE / 2) * (width / 60) * rightDirectionView.X,
                        (j - SIZE / 2) * (width / 60) * rightDirectionView.Y,
                        (j - SIZE / 2) * (width / 60) * rightDirectionView.Z) +
                    Vec3f((SIZE / 2 - i) * width / 60 * cam.up.X,
                        (SIZE / 2 - i) * width / 60 * cam.up.Y,
                        (SIZE / 2 - i) * width / 60 * cam.up.Z);; //od górnego lewego rogu
                if (ray.Intersect(p_front) != !Vec3f()) 
                {
                    point = ray.Intersect(p_front);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }
                if (ray.Intersect(p_back) != !Vec3f()) 
                {
                    point = ray.Intersect(p_back);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2) 
                    {
                        isCrossing = true;
                    }
                }
                if (ray.Intersect(p_left) != !Vec3f()) {
                    point = ray.Intersect(p_left);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2) 
                    {
                        isCrossing = true;
                    }

                }
                if (ray.Intersect(p_right) != !Vec3f()) 
                {
                    point = ray.Intersect(p_left);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }
                if (ray.Intersect(p_up) != !Vec3f()) 
                {
                    point = ray.Intersect(p_left);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }
                if (ray.Intersect(p_up) != !Vec3f()) 
                {
                    point = ray.Intersect(p_bottom);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }
                if (isCrossing) 
                {
                    tab[i][j] = '0';
                }
                else {
                    tab[i][j] = '.';
                }
                isCrossing = false;
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                std::cout << tab[i][j] << " ";
            }
            std::cout << std::endl;
        }
        //std::cout << std::endl << std::endl << "pos: " << cam.position << ", dir: " << cam.direction << ", up: " << cam.up << std::endl;

        while (!_kbhit()) {}
        if (_kbhit()) {
            input = _getch();
            switch (input) {
            case 'a':
                angleY -= 1;
                break;
            case 'd':
                angleY += 1;
                break;
            case 'w':
                angleX -= 1;
                break;
            case 's':
                angleX += 1;
                break;
            case 'q':
                angleZ -= 1;
                break;
            case 'e':
                angleZ += 1;
                break;
            case 'z':
                zoom -= 0.1;
                break;
            case 'x':
                zoom += 0.1;
                break;
            }
        }
        system("CLS");
    } while (input != 'p');
    return 0;
}