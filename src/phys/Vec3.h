#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class Vec3 {
public:
    const float x;
    const float y;
    const float z;

    static const Vec3 ZERO;

    Vec3(float x, float y, float z);

    Vec3 add(const Vec3& other);
    Vec3 sub(const Vec3& other);
    Vec3 mul(float scalar);
    Vec3 div(float scalar);
    Vec3 lerp(const Vec3& target, float t);

    float length();
    Vec3 normalize();
    float dot(const Vec3& other);
    Vec3 cross(const Vec3& other);
    float distance(const Vec3& other);
    std::string toString();
};

#endif
