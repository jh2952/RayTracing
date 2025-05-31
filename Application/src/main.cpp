#include "color.h"
#include "vec3.h"
#include "ray.h"

#include <iostream>

// #TODO: Candidate for shader
double hit_sphere(const point3& center, double radius, const ray& r)
{
	// Chapter 5: https://raytracing.github.io/books/RayTracingInOneWeekend.html#addingasphere
	vec3 oc = center - r.get_origin();
	double a = r.get_direction().length_squared();
	double h = dot(r.get_direction(), oc);
	double c = oc.length_squared() - radius * radius;
	double discriminant = h * h - a * c;

	// What we're calculating here is the value t in the equation P = Q + tD, where t is the value which bring
	// the ray to the hit point

	if (discriminant < 0)
	{
		return -1.0f;
	}
	else
	{
		return (h - std::sqrt(discriminant)) / a;
	}
}

color ray_color(const ray& r)
{
	double t = hit_sphere(point3(0, 0, -1), 0.5, r);

	// Colour the sphere
	if (t > 0.0)
	{
		// Unit vector is from the center of the sphere to the hit point
		vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
		return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
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

			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\rDone.          \n";

	return 0;
}