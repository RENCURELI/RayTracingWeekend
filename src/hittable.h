#pragma once

#include "rtweekend.h"

struct hit_record
{
    Point3 p;
    Vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const Ray& r, const Vec3& outward_normal)
    {
        //Sets the hit record normal vector
        // NOTE : The parameter "outward_normal" is assumed to have unit length

        front_face = dot(r.Direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable() = default;

    virtual bool hit(const Ray& r, interval ray_t, hit_record& rec) const = 0;
};