#include "color.h"
#include "vec3.h"

#include <iostream>

int main()
{
	// Image
	int image_width = 256;
	int image_height = 256;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j{}; j < image_height; j++)
	{
		std::clog << "\rScanlines Remaining" << (image_height - j) << ' ' << std::flush;
		for (int i{}; i < image_width; i++)
		{
			color pixel_color = color(static_cast<double>(i) / (image_width - 1), static_cast<double>(j) / (image_height - 1), 0.0);
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\rDone.          \n";

	return 0;
}