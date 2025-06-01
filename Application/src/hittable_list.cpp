#include "hittable_list.h"

hittable_list::hittable_list()
{

}

hittable_list::hittable_list(shared_ptr<hittable> object)
{
	add(object);
}

void hittable_list::clear()
{
	m_objects.clear();
}

void hittable_list::add(shared_ptr<hittable> object)
{
	m_objects.push_back(object);
}

bool hittable_list::hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const
{
	hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = ray_tmax;

	// Iterate through the list of hittable objects and return the record of the closest hit
	for (const shared_ptr<hittable>& object : m_objects)
	{
		if (object->hit(r, ray_tmin, closest_so_far, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.m_t;
			rec = temp_rec;
		}
	}

	return hit_anything;
}
