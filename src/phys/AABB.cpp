#include "AABB.h"

AABB::AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
    : minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ) {}

AABB AABB::copy() {
    return AABB(minX, minY, minZ, maxX, maxY, maxZ);
}

AABB AABB::offset(float dx, float dy, float dz) {
    return AABB(minX + dx, minY + dy, minZ + dz, maxX + dx, maxY + dy, maxZ + dz);
}

AABB AABB::expand(float dx, float dy, float dz) {
    float nx = dx < 0 ? minX + dx : minX;
    float px = dx > 0 ? maxX + dx : maxX;

    float ny = dy < 0 ? minY + dy : minY;
    float py = dy > 0 ? maxY + dy : maxY;

    float nz = dz < 0 ? minZ + dz : minZ;
    float pz = dz > 0 ? maxZ + dz : maxZ;

    return AABB(nx, ny, nz, px, py, pz);
}

bool AABB::intersects(AABB& other) {
    return maxX > other.minX && minX < other.maxX &&
            maxY > other.minY && minY < other.maxY &&
            maxZ > other.minZ && minZ < other.maxZ;
}

bool AABB::intersectsOrTouches(AABB& other) {
    return maxX >= other.minX && minX <= other.maxX &&
            maxY >= other.minY && minY <= other.maxY &&
            maxZ >= other.minZ && minZ <= other.maxZ;
}

float AABB::clipXCollide(AABB& other, float dx) {
    if (other.maxY <= minY || other.minY >= maxY || other.maxZ <= minZ || other.minZ >= maxZ) return dx;

    if (dx > 0.0f && other.maxX <= minX) {
        float diff = minX - other.maxX;
        if (diff < dx) dx = diff;
    } else if (dx < 0.0f && other.minX >= maxX) {
        float diff = maxX - other.minX;
        if (diff > dx) dx = diff;
    }
    return dx;
}

float AABB::clipYCollide(AABB& other, float dy) {
    if (other.maxX <= minX || other.minX >= maxX || other.maxZ <= minZ || other.minZ >= maxZ) return dy;

    if (dy > 0.0f && other.maxY <= minY) {
        float diff = minY - other.maxY;
        if (diff < dy) dy = diff;
    } else if (dy < 0.0f && other.minY >= maxY) {
        float diff = maxY - other.minY;
        if (diff > dy) dy = diff;
    }
    return dy;
}

float AABB::clipZCollide(AABB& other, float dz) {
    if (other.maxX <= minX || other.minX >= maxX || other.maxY <= minY || other.minY >= maxY) return dz;

    if (dz > 0.0f && other.maxZ <= minZ) {
        float diff = minZ - other.maxZ;
        if (diff < dz) dz = diff;
    } else if (dz < 0.0f && other.minZ >= maxZ) {
        float diff = maxZ - other.minZ;
        if (diff > dz) dz = diff;
    }
    return dz;
}

std::string AABB::toString() const {
    return "AABB(" + std::to_string(minX) + ", " + std::to_string(minY) + ", " + std::to_string(minZ) +
        " | " + std::to_string(maxX) + ", " + std::to_string(maxY) + ", " + std::to_string(maxZ) + ")";
}