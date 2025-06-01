#include "hittable.h"

void hit_record::set_face_normal(const ray& r, const vec3& outward_normal)
{
	// Sets the hit record normal vector
	// NOTE: the paramteter 'outward_normal' is assumed to have unit length

	m_front_face = dot(r.get_direction(), outward_normal) < 0;
	m_normal = m_front_face ? outward_normal : -outward_normal;
}
