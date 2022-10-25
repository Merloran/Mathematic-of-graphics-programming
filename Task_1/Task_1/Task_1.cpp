
#include <iostream>
#include "Source/Public/Vector.h"

// Macro for fast type change ( default: double )
#define TestType double

int main()
{
    Vector3<TestType> V0;
    Vector3<TestType> V1(2.0, 12.0, -12.0);
    Vector3<TestType> V2(3.0, -2.0, -4.0);

    V0 = V1 + V2;
    V0.ToString();

    V0 = V2 + V1;
    V0.ToString();
    std::cout << std::endl;

    V1 = Vector3<TestType>(0.0, 3.0, 0.0);
    V2 = Vector3<TestType>(5.0, 5.0, 0.0);

    std::cout << "The angle between the vectors:" << std::endl;
    V1.ToString();
    V2.ToString();
    std::cout << "is " << V1.RadToDeg(V1.GetAngle(V1, V2)) << " degrees.\n" << std::endl;

    V1 = Vector3<TestType>(4.0, 5.0, 1.0);
    V2 = Vector3<TestType>(4.0, 1.0, 3.0);
    V0 = V1.Cross(V2);
    V0.ToString();
    std::cout << "Is normal to" << std::endl;
    V1.ToString();
    V2.ToString();
    std::cout << std::endl;

    std::cout << "Normalized: " << std::endl;
    V0.Normalize().ToString();
}
