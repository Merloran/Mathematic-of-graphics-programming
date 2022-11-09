#include "Source/Public/Matrix.h"
#include <iostream>

typedef Matrix<float, 4, 4> Mat4f;
typedef Matrix<float, 3, 3> Mat3f;
typedef Matrix<float, 2, 2> Mat2f;

typedef Matrix<double, 4, 4> Mat4;
typedef Matrix<double, 3, 3> Mat3;
typedef Matrix<double, 2, 2> Mat2;

int main()
{
    Mat4f mat1 = Mat4f();
    Mat4f mat2 = Mat4f(1.0f);
    Mat4f Helper = Mat4f(1.0f);
    mat1[0][0] = 5.0f;
    std::cout << "Mat1" << std::endl;
    mat1.ToString();
    std::cout << "Mat2" << std::endl;
    mat2.ToString();


    std::cout << "Mat2 * 5" << std::endl;
    Helper = mat2 * 5.0f;
    Helper.ToString();
    mat2 *= 5.0f;
    std::cout << "Mat2 *= 5" << std::endl;
    mat2.ToString();


    float Values1[4][4] =
    {
             5.0f,  7.0f,  9.0f,  10.0f,
             2.0f,  3.0f,  3.0f,  8.0f,
             8.0f,  10.0f,  2.0f,  3.0f,
             3.0f,  3.0f,  4.0f,  8.0f,
    };

    float Values2[4][4] =
    {
             3.0f,  10.0f,  12.0f,  18.0f,
             12.0f,  1.0f,  4.0f,  9.0f,
             9.0f,  10.0f,  12.0f,  2.0f,
             3.0f,  12.0f,  4.0f,  10.0f,
    };
    float Values4[4][4] =
    {
             -5.0f,  2.0f,  0.0f,  0.0f,
             0.0f,  3.0f,  0.0f,  0.0f,
             0.0f,  0.0f,  -5.0f,  0.0f,
             0.0f,  0.0f,  0.0f,  5.0f,
    };
    Mat4f Test1 = Mat4f(Values1);
    Mat4f Test2 = Mat4f(Values2);
    Mat4f Test3 = Mat4f(Values1);
    Mat4f Test4 = Mat4f(Values4);

    Test1 *= Test2;

    std::cout << Mat4f::Determinant(Test4) << std::endl << std::endl;
    Test2.ToString();
    Test2.Transpose();
    Test2.ToString();

    Test2 = Mat4f::Inverse(Test2);
    Test2.ToString();

    Mat4f Rot = Mat4f(1.0f);
    Rot.ToString();
    Rot.Rotate(90.0f, Vector3<float>(0.0f, 1.0f, 0.0f));
    Vector4<float> Example(1.0f, 0.0f, 0.0f, 1.0f);
    Rot.ToString();
    Example.ToString();
    (Rot * Example).ToString();
    Rot.Translate(Vector3<float>(5.0f, 2.0f, 0.0f));
    Rot.ToString();
    (Rot * Example).ToString();
    Rot.Scale(Vector3<float>(3.0f));
    Rot.ToString();
    (Rot * Example).ToString();
}