#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <vector>

class hittable_list : public hittable
{
public:
	std::vector<shared_ptr<hittable>> m_objects;

	hittable_list();
	hittable_list(shared_ptr<hittable> object);

	void clear();

	void add(shared_ptr<hittable> object);

	bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
};

#endif