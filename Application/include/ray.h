#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
public:
	ray();
	ray(const point3& origin, const vec3& direction);

	const point3& get_origin() const;
	const vec3& get_direction() const;

	point3 at(double t) const;

private:
	point3 m_origin;
	vec3 m_direction;
};

#endif RAY_H