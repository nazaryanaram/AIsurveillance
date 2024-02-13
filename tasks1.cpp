#include <iostream>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} colors;

colors** create_pictures(int x_cordinat_size, int y_cordinat_size);
void generate_random_pixels(colors** pictures, int x_cordinat_size, int y_cordinat_size);
void change_pixel(colors** pictures, int x_cordinat, int y_cordinat, unsigned char red, unsigned char green, unsigned char blue);
void show_pictures(colors** pictures, int x_cordinat_size, int y_cordinat_size);
colors* get_pixel (colors** pictures, int x_cordinat, int y_cordinat);

int main()
{
    int x_cordinat_size = 0;
    int y_cordinat_size = 0;

    do {
        std::cout << "Enter size of x cordinat: ";
        std::cin >> x_cordinat_size;
        std::cout << "Enter size of y cordinat: ";
        std::cin >> y_cordinat_size;

        if (x_cordinat_size < 0 || y_cordinat_size < 0)
        {
            std::cout << "Invalid Input" << std::endl;
        }
    } while (x_cordinat_size < 0 || y_cordinat_size < 0);
    
     colors** pictures = create_pictures(x_cordinat_size, y_cordinat_size);
    generate_random_pixels(pictures, x_cordinat_size, y_cordinat_size);

    show_pictures(pictures, x_cordinat_size, y_cordinat_size);

    change_pixel(pictures, 1, 1, 233, 233, 233);
    std::cout << std::endl;
    show_pictures(pictures, x_cordinat_size, y_cordinat_size);

    colors* pixel = get_pixel(pictures, 1, 1);

    return 0;
}

void show_pictures(colors** pictures, int x_cordinat_size, int y_cordinat_size)
{
    for (int i = 0; i < x_cordinat_size; ++i)
    {
        std::cout << std::endl;
        for (int j = 0; j < y_cordinat_size; ++j)
        {
            std::cout << "[" << pictures[i][j].red << ", " << pictures[i][j].green << ", " << pictures[i][j].blue << "]" ; 
        }
    }
    return;
}

void change_pixel(colors** pictures, int x_cordinat, int y_cordinat, unsigned char red, unsigned char green, unsigned char blue)
{
    pictures[x_cordinat][y_cordinat].red = red;
    pictures[x_cordinat][y_cordinat].green = green;
    pictures[x_cordinat][y_cordinat].blue = blue;
    return;
}

void generate_random_pixels(colors** pictures, int x_cordinat_size, int y_cordinat_size)
{
    srand(time(0));
    for (int i = 0; i < x_cordinat_size; ++i)
    {
        for (int j = 0; j < y_cordinat_size; ++j){
            pictures[i][j].red = 0 + rand() % 256;
            pictures[i][j].green = 0 + rand() % 256;
            pictures[i][j].blue = 0 + rand() % 256;
        }
    }
    return;
}

colors* get_pixel (colors** pictures, int x_cordinat, int y_cordinat)
{
    return &pictures[x_cordinat][y_cordinat];
}

colors** create_pictures(int x_cordinat_size, int y_cordinat_size)
{
    colors** pictures = (colors**) malloc (x_cordinat_size * sizeof(colors*));
    for (int i = 0; i < x_cordinat_size; ++i)
    {
        pictures[i] = (colors*) malloc(y_cordinat_size * sizeof(colors));
    }
    return pictures;
}

