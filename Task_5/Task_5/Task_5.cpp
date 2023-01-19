#include <iostream>
#include <conio.h>

#include "Source/Public/Vector3.h"
#include "Source/Public/Quaternion.h"
#include "Source/Public/Line.h"
#include "Source/Public/Plane.h"
#include "Source/Public/Camera.h"

const int change = 5;

const int SIZE = 60;
int main() 
{
    float cubeSize = 2;
    Plane p_front  = Plane(Vec3f( 0,  0,  1), Vec3f(-cubeSize / 2, -cubeSize / 2,  cubeSize / 2));
    Plane p_back   = Plane(Vec3f( 0,  0, -1), Vec3f(-cubeSize / 2, -cubeSize / 2, -cubeSize / 2));
    Plane p_left   = Plane(Vec3f(-1,  0,  0), Vec3f(-cubeSize / 2, -cubeSize / 2,  cubeSize / 2));
    Plane p_right  = Plane(Vec3f( 1,  0,  0), Vec3f( cubeSize / 2, -cubeSize / 2,  cubeSize / 2));
    Plane p_bottom = Plane(Vec3f( 0, -1,  0), Vec3f(-cubeSize / 2, -cubeSize / 2,  cubeSize / 2));
    Plane p_up     = Plane(Vec3f( 0,  1,  0), Vec3f(-cubeSize / 2,  cubeSize / 2,  cubeSize / 2));

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

    char input;
    float zoom = 3;
    do {
        cam = Camera(zoom);
        cam.RotateX(angleX);
        cam.RotateY(angleY);
        cam.RotateZ(angleZ);

        Vec3f rightDirectionView = cam.direction.Cross(cam.up);
        Line ray = Line(cam.direction, cam.position);
        Vec3f point;
        bool isCrossing = false;
        for (int X = 0; X < SIZE; X++) { //wiersze
            for (int Y = 0; Y < SIZE; Y++) { //kolumny
                ray.Direction =
                    cam.direction +
                    Vec3f((Y - SIZE / 2) * (width / 60) * rightDirectionView.X,
                        (Y - SIZE / 2) * (width / 60) * rightDirectionView.Y,
                        (Y - SIZE / 2) * (width / 60) * rightDirectionView.Z) +
                    Vec3f((SIZE / 2 - X) * width / 60 * cam.up.X,
                        (SIZE / 2 - X) * width / 60 * cam.up.Y,
                        (SIZE / 2 - X) * width / 60 * cam.up.Z); //od górnego lewego rogu

                point = ray.Intersect(p_front);
                if (point != Vec3f::INVALID()) 
                {
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }

                point = ray.Intersect(p_back);
                if (point != Vec3f::INVALID())
                {
                    point = ray.Intersect(p_back);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2) 
                    {
                        isCrossing = true;
                    }
                }

                point = ray.Intersect(p_left);
                if (point != Vec3f::INVALID())
                {
                    point = ray.Intersect(p_left);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2) 
                    {
                        isCrossing = true;
                    }
                }

                point = ray.Intersect(p_right);
                if (point != Vec3f::INVALID())
                {
                    point = ray.Intersect(p_right);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }

                point = ray.Intersect(p_up);
                if (point != Vec3f::INVALID())
                {
                    point = ray.Intersect(p_up);
                    if (point.X <= cubeSize / 2 && point.Y <= cubeSize / 2 && point.Z <= cubeSize / 2
                        && point.X >= -cubeSize / 2 && point.Y >= -cubeSize / 2 && point.Z >= -cubeSize / 2)
                    {
                        isCrossing = true;
                    }
                }

                point = ray.Intersect(p_bottom);
                if (point != Vec3f::INVALID())
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
                    tab[X][Y] = '0';
                }
                else {
                    tab[X][Y] = '.';
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
        std::cout << std::endl << std::endl;
        
        std::cout << "Position: " << cam.position << ", Direction: " << cam.direction << ", UpVector: " << cam.up << std::endl;

        while (!_kbhit()) {}
        if (_kbhit()) {
            input = _getch();
            switch (input) {
            case 'a':
                angleY -= change;
                break;
            case 'd':
                angleY += change;
                break;
            case 'w':
                angleX -= change;
                break;
            case 's':
                angleX += change;
                break;
            case 'q':
                angleZ -= change;
                break;
            case 'e':
                angleZ += change;
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