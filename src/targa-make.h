#include <stdint.h>

typedef struct TGAHead {
	uint8_t id_length;
	uint8_t color_map_type;
	uint8_t image_type;

	uint16_t color_map_origin;
	uint16_t color_map_length;
	uint8_t color_map_depth;

	uint16_t x_origin;
	uint16_t y_origin;
	uint16_t width;
	uint16_t height;

	uint8_t pixel_depth;
	uint8_t image_desc;
};
