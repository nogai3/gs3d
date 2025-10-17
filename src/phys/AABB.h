#ifndef AABB_H
#define AABB_H

#include <iostream>

class AABB {
public:
    float minX, minY, minZ;
    float maxX, maxY, maxZ;

    AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    AABB copy();
    AABB offset(float dx, float dy, float dz);
    AABB expand(float dx, float dy, float dz);

    bool intersects(AABB& other);
    bool intersectsOrTouches(AABB& other);

    float clipXCollide(AABB& other, float dx);
    float clipYCollide(AABB& other, float dy);
    float clipZCollide(AABB& other, float dz);

    std::string toString() const;
};

#endif
