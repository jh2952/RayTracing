#include "util.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

color ray_color(const ray& r, const hittable& world)
{
	hit_record rec;
	if (world.hit(r, 0, infinity, rec))
	{
		return 0.5 * (rec.m_normal + color(1, 1, 1));
	}

	// Colour the background
	vec3 unit_direction = unit_vector(r.get_direction());
	double a = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{
	// Image
	double aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// Calculate the image height, and ensure that it's at least 1
	int image_height = static_cast<int>(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// World
	hittable_list world;

	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

	// Camera
	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
	point3 camera_center = point3(0, 0, 0);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	vec3 viewport_u = vec3(viewport_width, 0, 0);
	vec3 viewport_v = vec3(0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	vec3 pixel_delta_u = viewport_u / image_width;
	vec3 pixel_delta_v = viewport_v / image_height;

	// Calculate the location of the upper left pixel
	vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	vec3 pixel00_location = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	// Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	// #TODO : Some hardware acceleration here
	for (int j{}; j < image_height; j++)
	{
		std::clog << "\rScanlines Remaining" << (image_height - j) << ' ' << std::flush;
		for (int i{}; i < image_width; i++)
		{
			vec3 pixel_center = pixel00_location + (i * pixel_delta_u) + (j * pixel_delta_v);
			vec3 ray_direction = pixel_center - camera_center;
			ray r(camera_center, ray_direction);

			color pixel_color = ray_color(r, world);
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\rDone.          \n";

	return 0;
}