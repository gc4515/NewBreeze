#include "tools.h"

/*! We are bundling the keyboard layouts with newbreeze
*/
QString get_kb_layout_dir() {

	return QLatin1String(":/Data/");
}

/*! We are bundling the color schemes with newbreeze
*/
QString get_color_schemes_dir() {

	return QLatin1String(":/Data/");
}
