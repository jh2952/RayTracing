#include "color.h"

void write_color(std::ostream& out, const color& pixel_color)
{
	double r = pixel_color.x();
	double g = pixel_color.y();
	double b = pixel_color.z();

	// Translate the [0, 1] component values to the byte range [0, 255]
	int rbyte = static_cast<int>(255.999 * r);
	int gbyte = static_cast<int>(255.999 * g);
	int bbyte = static_cast<int>(255.999 * b);

	// Write out the pixel color components.
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
