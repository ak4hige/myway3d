#pragma once

#include "MWVector3.h"
#include "MWTriangle.h"

namespace Myway
{

class Plane;
class Aabb;
class Sphere;

struct MW_ENTRY RayIntersectionInfo
{
    bool    iterscetion;
    float   distance;

    RayIntersectionInfo()
    {
        iterscetion = false;
        distance = 0;
    }
};

class MW_ENTRY Ray
{
    DECLARE_ALLOC();

public:
    Ray();
    Ray(const Vec3 & vOrigin, const Vec3 & vDirection);
    ~Ray();

    RayIntersectionInfo Intersection(const Plane & rk);
    RayIntersectionInfo Intersection(const Sphere & rk);
    RayIntersectionInfo Intersection(const Aabb & rk);
    RayIntersectionInfo Intersection(const Tri3 & rk);

public:
    Vec3    origin;
    Vec3    direction;
};



}