#include <png.h>
#include <vector>
#include <iostream>

void write_png_file(const char* file_name, png_bytep* row_pointers, int width, int height) {
    FILE *fp = fopen(file_name, "wb");
    if(!fp) abort();

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();

    png_infop info = png_create_info_struct(png);
    if (!info) abort();

    if (setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    // Output is 8-bit depth, RGBA format.
    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png, info);

    png_write_image(png, row_pointers);
    png_write_end(png, NULL);

    fclose(fp);

    png_destroy_write_struct(&png, &info);
}

int main() {
    int width = 256;
    int height = 256;

    std::vector<png_bytep> row_pointers(height);

    for(int y = 0; y < height; y++) {
        row_pointers[y] = new png_byte[4 * width];
        for(int x = 0; x < width; x++) {
            png_bytep px = &(row_pointers[y][x * 4]);
            px[0] = x % 256; // R
            px[1] = y % 256; // G
            px[2] = 128;     // B
            px[3] = 255;     // A
        }
    }

    write_png_file("output.png", row_pointers.data(), width, height);

    for(int y = 0; y < height; y++) {
        delete[] row_pointers[y];
    }

    return 0;
}
