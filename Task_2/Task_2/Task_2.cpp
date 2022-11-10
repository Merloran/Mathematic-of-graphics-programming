#include "Source/Public/Matrix.h"
#include <iostream>

typedef Matrix<float, 4, 4> Mat4f;
typedef Matrix<float, 3, 3> Mat3f;
typedef Matrix<float, 2, 2> Mat2f;

typedef Matrix<double, 4, 4> Mat4;
typedef Matrix<double, 3, 3> Mat3;
typedef Matrix<double, 2, 2> Mat2;

typedef Vector3<float> Vec3f;
typedef Vector4<float> Vec4f;

using namespace std;

int main()
{
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Zadanie 2" << endl;
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Dodawanie macierzy" << endl;
    float ValuesA1[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  11.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  16.0f,
    };
    Mat4f MatrixA1(ValuesA1);
    MatrixA1.ToString();
    cout << "+" << endl;
    float ValuesB1[4][4] =
    {
             1.0f, 1.0f, 1.0f, 1.0f,
             2.0f, 2.0f, 2.0f, 2.0f,
             3.0f, 3.0f, 3.0f, 3.0f,
             4.0f, 4.0f, 4.0f, 4.0f,
    };
    Mat4f MatrixB1(ValuesB1);
    MatrixB1.ToString();
    cout << "=" << endl;
    Mat4f MatrixC1(1.0f);
    MatrixC1 = MatrixA1 + MatrixB1;
    MatrixC1.ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Odejmowanie macierzy" << endl;
    float ValuesA2[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  11.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  16.0f,
    };
    Mat4f MatrixA2(ValuesA2);
    MatrixA2.ToString();
    cout << "-" << endl;
    float ValuesB2[4][4] =
    {
             1.0f, 1.0f, 1.0f, 1.0f,
             2.0f, 2.0f, 2.0f, 2.0f,
             3.0f, 3.0f, 3.0f, 3.0f,
             4.0f, 4.0f, 4.0f, 4.0f,
    };
    Mat4f MatrixB2(ValuesB2);
    MatrixB2.ToString();
    cout << "=" << endl;
    MatrixA2 -= MatrixB2;
    MatrixA2.ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Mnozenie macierzy przez skalar" << endl;
    float ValuesA3[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  11.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  16.0f,
    };
    Mat4f MatrixA3(ValuesA3);
    MatrixA3.ToString();
    cout << "* 3 =" << endl;
    (MatrixA3 * 3.0f).ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Mnozenie macierzy" << endl;
    float ValuesA4[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  11.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  16.0f,
    };
    Mat4f MatrixA4(ValuesA4);
    MatrixA4.ToString();
    cout << "*" << endl;
    float ValuesB4[4][4] =
    {
             1.0f, 1.0f, 1.0f, 1.0f,
             2.0f, 2.0f, 2.0f, 2.0f,
             3.0f, 3.0f, 3.0f, 3.0f,
             4.0f, 4.0f, 4.0f, 4.0f,
    };
    Mat4f MatrixB4(ValuesB4);
    MatrixB4.ToString();
    cout << "=" << endl;
    MatrixA4 *= MatrixB4;
    MatrixA4.ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Odwracanie macierzy" << endl;
    float ValuesA5[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  2.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  3.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  10.0f,
    };
    Mat4f MatrixA5(ValuesA5);
    MatrixA5.ToString();
    cout << "odwrocona =" << endl;
    MatrixA5 = Mat4f::Inverse(MatrixA5);
    MatrixA5.ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Transponowanie macierzy" << endl;
    float ValuesA6[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  11.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  16.0f,
    };
    Mat4f MatrixA6(ValuesA6);
    MatrixA6.ToString();
    cout << "Transponowana = " << endl;
    MatrixA6.Transpose();
    MatrixA6.ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Wyznacznik macierzy" << endl;
    float ValuesA7[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  10.0f,  10.0f,
             13.0f,  14.0f,  10.0f,  10.0f,
    };
    Mat4f MatrixA7(ValuesA7);
    MatrixA7.ToString();
    cout << "wyznacznik = " << Mat4f::Determinant(MatrixA7) << endl;

    cout << "///////////////////////////////////////////////////////////" << endl;

    Vec4f vect(1, 0, 0, 1);
    cout << "Obrot wektora (1, 0, 0, 1) o 90 stopni" << endl;
    Mat4f RotationMatrix(1.0f);
    RotationMatrix.Rotate(90.0f, Vec3f(0.0f, 1.0f, 0.0f));
    vect = RotationMatrix * vect;
    vect.ToString();

    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "Brak przemiennosci mnozenia macierzy" << endl;
    float ValuesA[4][4] =
    {
             1.0f,  2.0f,  3.0f,  4.0f,
             5.0f,  6.0f,  7.0f,  8.0f,
             9.0f,  10.0f,  11.0f,  12.0f,
             13.0f,  14.0f,  15.0f,  16.0f,
    };
    Mat4f MatrixA(ValuesA);
    MatrixA.ToString();
    float ValuesB[4][4] =
    {
             1.0f, 1.0f, 1.0f, 1.0f,
             2.0f, 2.0f, 2.0f, 2.0f,
             3.0f, 3.0f, 3.0f, 3.0f,
             4.0f, 4.0f, 4.0f, 4.0f,
    };
    Mat4f MatrixB(ValuesB);
    MatrixB.ToString();
    Mat4f MatrixC(1.0f);
    MatrixC = MatrixA * MatrixB;
    MatrixC.ToString();
    MatrixC = MatrixB * MatrixA;
    MatrixC.ToString();
    cout << "///////////////////////////////////////////////////////////" << endl;
}