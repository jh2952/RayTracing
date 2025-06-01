#ifndef HITTABLE_H
#define HITTABLE_H

class hit_record
{
public:
	point3 m_p;
	vec3 m_normal;
	double m_t;
	bool m_front_face;

	void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable
{
public:
	virtual ~hittable() = default;
	virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif