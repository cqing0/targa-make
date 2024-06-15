#include <stdio.h>
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

void write_tga(const char *filename, const uint8_t *pixel_data, int width, int height)
{
	FILE *file = fopen(filename "wb");
	if (!file) {
		perror("[ERROR]: Could not open TGA file\n");
		return;
	}

	TGAHead tga_head = {0};
	tga_head.image_type = 2;
	tga_head.width = width;
	tga_head.height = height;
	tga_head.pixel_depth = 24;
	tga_head.image_desc = 0x20;

	fwrite(&tga_head, sizeof(TGAHead), 1, file);
	fwrite(pixel_data, width * height * 3, 1, file);

	fclose(file);
}
