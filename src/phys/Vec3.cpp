#include "Vec3.h"

const Vec3 Vec3::ZERO = Vec3(0, 0, 0);

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::add(const Vec3& other) {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::sub(const Vec3& other) {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::mul(float scalar) {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::div(float scalar) {
    return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3 Vec3::lerp(const Vec3& target, float t) {
    return Vec3(
        x + (target.x - x) * t,
        y + (target.y - y) * t,
        z + (target.z - z) * t
    );
}

float Vec3::length() {
    return std::sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() {
    float len = length();
    return len == 0 ? ZERO : div(len);
}

float Vec3::dot(const Vec3& other) {
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::cross(const Vec3& other) {
    return Vec3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

float Vec3::distance(const Vec3& other) {
    return sub(other).length();
}

std::string Vec3::toString() {
    return "Vec3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}