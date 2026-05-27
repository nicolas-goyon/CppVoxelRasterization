//
// Created by Nico on 5/19/2026.
//

#ifndef CPPVOXELRASTERIZATION_VECTOR3_HPP
#define CPPVOXELRASTERIZATION_VECTOR3_HPP

#include <iostream>
namespace Math {

    struct  Vector3{
    public:
        //constructors
        constexpr Vector3(float const ix, float const iy, float const iz): data{ix, iy, iz}{}
        explicit constexpr Vector3(float const ia): data{ia, ia, ia}{}
        constexpr Vector3(): data{0}{}

        //variables
        float data[3];

        //operators
        float operator[](unsigned int index) const{
            return data[index];
        }
        float& operator[](unsigned int index){
            return data[index];
        }
        Vector3 operator+(const Vector3 &right) const;
        Vector3 operator-(const Vector3 &right) const;
        Vector3 operator-() const{return {-data[0], -data[1], -data[2]};};
        Vector3 operator*(const Vector3 &right) const;
        Vector3 operator/(const Vector3 &right) const;
        Vector3& operator+=(const Vector3 &right);
        Vector3& operator-=(const Vector3 &right);
        Vector3& operator*=(const Vector3 &right);
        Vector3& operator/=(const Vector3 &right);

        //functions
        static float dotProduct(const Vector3 &left, const Vector3 &right);
        static Vector3 crossProduct(const Vector3 &left, const Vector3 &right);

        void normalize();
        [[nodiscard]] Vector3 normalized() const;
        [[nodiscard]] float absolute() const;
        [[nodiscard]] float absolute2() const; // Squared variant
        [[nodiscard]] bool isZero() const{return data[0] == 0 && data[1] == 0 && data[2] == 0;}
        [[nodiscard]] float angleBetweenVectors(const Vector3& otherVector) const;
        /**
         * @brief      Rotate this vector using another vector as rotation axis.
         *
         * @param[in]  v         Vector used as rotations axis. Needs to be
         *                       normalized
         * @param[in]  rotation  The rotation angle in radians.
         */
        void rotateAroundVector(const Vector3& v, float rotation);
    };

    std::ostream& operator<<(std::ostream& os, const Vector3& vector3);
    std::istream& operator>>(std::istream& is, Vector3& vector3);


} // Math

#endif //CPPVOXELRASTERIZATION_VECTOR3_HPP
