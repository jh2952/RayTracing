#include "util.h"
#include "ray.h"

ray::ray()
{
}

ray::ray(const point3& origin, const vec3& direction)
	: m_origin{origin}
	, m_direction{ direction }
{
}

const point3& ray::get_origin() const
{
	return m_origin;
}

const vec3& ray::get_direction() const
{
	return m_direction;
}

point3 ray::at(double t) const
{
	return m_origin + t * m_direction;
}
