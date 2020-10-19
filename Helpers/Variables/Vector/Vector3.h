//
// Created by Salihcan Kahya on 17.10.2020.
//

#ifndef _VECTOR_H
#define _VECTOR_H
#include <iostream>
namespace Variables {
    template <typename T>
    class Vector3{
    public:
        T x;
        T y;
        T z;
        Vector3<T>(const T& x, const T& y, const T& z) : x(x), y(y), z(z){}

        Vector3<T> operator+(const Vector3<T>& vector);
        Vector3<T> operator-(const Vector3<T>& vector);

        Vector3<T> operator/(const Vector3<T>& vector);
        Vector3<T> operator/(const T value);

        Vector3<T> operator*(const Vector3<T>& vector);
        Vector3<T> operator*(const T value);

        void operator+=(const Vector3<T>& vector);
        void operator-=(const Vector3<T>& vector);
        bool operator==(const Vector3<T>& vector);
    };
}



#endif //VECTOR_H
