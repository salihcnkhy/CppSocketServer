//
// Created by Salihcan Kahya on 17.10.2020.
//

#include "Vector3.h"

namespace BaseClass{

    template <typename T>
    Vector3<T>::Vector3( T x,  T y, T z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator+(const Vector3<T> &vector) {
        Vector3 vectorT;
        vectorT.x = vector.x + this->x;
        vectorT.y = vector.y + this->y;
        vectorT.z = vector.z + this->z;
        return vectorT;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator/(const T value){

        Vector3 vectorT;
        vectorT.x = this->x / value;
        vectorT.y =  this->y / value ;
        vectorT.z = this->z / value;
        return vectorT;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator/(const Vector3<T> &vector) {
        Vector3 vectorT;
        vectorT.x = this->x / vector.x;
        vectorT.y =  this->y / vector.y ;
        vectorT.z = this->z / vector.z;
        return vectorT;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator*(const T value){

        Vector3 vectorT;
        vectorT.x = this->x * value;
        vectorT.y =  this->y * value ;
        vectorT.z = this->z * value;
        return vectorT;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator*(const Vector3<T> &vector) {
        Vector3 vectorT;
        vectorT.x = this->x * vector.x;
        vectorT.y =  this->y * vector.y ;
        vectorT.z = this->z * vector.z;
        return vectorT;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator-(const Vector3<T> &vector) {
        Vector3 vectorT;
        vectorT.x = this->x - vector.x;
        vectorT.y =  this->y - vector.y ;
        vectorT.z = this->z - vector.z;
        return vectorT;
    }

    template <typename T>
    void Vector3<T>::operator+=(const Vector3<T> &vector) {
        this->x = this->x + vector.x;
        this->y =  this->y + vector.y ;
        this->z = this->z + vector.z;
    }

    template <typename T>
    void Vector3<T>::operator-=(const Vector3<T> &vector) {
        this->x = this->x - vector.x;
        this->y = this->y - vector.y;
        this->z = this->z - vector.z;
    }

    template <typename T>
    bool Vector3<T>::operator==(const Vector3<T> &vector) {
        return vector.x == this->x && vector.y == this->y && vector.z == this->z;
    }
}