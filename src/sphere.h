#pragma once

#include "rtweekend.h"

#include "hittable.h"

class sphere : public hittable
{
public:
    sphere(const Point3& center, double radius) : m_Center(center), m_Radius(std::fmax(0, radius)) {}

    bool hit(const Ray& r, interval ray_t, hit_record& rec) const override
    {
        Vec3 oc = m_Center - r.Origin();
        const double a = r.Direction().length_squared();
        const double h = dot(r.Direction(), oc);
        const double c = oc.length_squared() - m_Radius * m_Radius;
        const double discriminant = h * h - a * c;

        if (discriminant < 0)
        {
            return false;
        }

        const double sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range
        double root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root))
        {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
            {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - m_Center) / m_Radius;

        Vec3 outward_normal = (rec.p - m_Center) / m_Radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

private:
    Point3 m_Center;
    double m_Radius{ 0.0 };
};