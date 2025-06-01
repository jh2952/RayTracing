#include "sphere.h"

sphere::sphere(const point3& center, double radius)
	: m_center{center}
	, m_radius{radius}
{
}

bool sphere::hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const
{
	// This maths is checking if the ray is intersecting the sphere or not. 
	// Maths is explained in the book, but basically checking if ray is inside the sphere : x^2 + y^2 + z^2 = r^2
	vec3 oc = m_center - r.get_origin();
	double a = r.get_direction().length_squared();
	double h = dot(r.get_direction(), oc);
	double c = oc.length_squared() - m_radius * m_radius;
	double discriminant = h * h - a * c;

	if (discriminant < 0)
	{
		return false;
	}

	double sqrtd = std::sqrt(discriminant);

	// Find the nearest root that lies in the acceptable range
	double root = (h - sqrtd) / a;
	if (root <= ray_tmin || ray_tmax <= root)
	{
		root = (h + sqrtd) / a;
		if (root <= ray_tmin || ray_tmax <= root)
		{
			return false;
		}
	}

	rec.m_t = root;
	rec.m_p = r.at(rec.m_t);
	vec3 outward_normal = (rec.m_p - m_center) / m_radius;
	rec.set_face_normal(r, outward_normal);

	return true;
}
