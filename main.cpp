#include <iostream>
using namespace std;
struct Rgb
{
    float r, g, b;
    Rgb(): r(0), g(0), b(0){}
    Rgb(float rr, float gg, float bb): r(rr), g(gg), b(bb){}

};
void filter_red(Rgb &pixel);
void display_pixel_channels(const Rgb &pixel, string name);
void blackout_image_pointer(const int &width, const int& height, Rgb *image );
void whiteout_image(const int &width, const int& height, Rgb *image );
int main() {
    Rgb blackPixel;
    Rgb whitePixel(1.0,1.0,1.0);
    Rgb redPixel(1.0,0.0,0);
    Rgb greenPixel(0,1.0,0);
    Rgb bluePixel(0,0,1.0);
    Rgb pinkPixel(1.0,0.75,.75);
    Rgb magentaPixel(1.0,0,1.0);
    display_pixel_channels(pinkPixel, "Pink");
    filter_red(pinkPixel);
    display_pixel_channels(pinkPixel, "Pink");
    display_pixel_channels(blackPixel, "Black");
    display_pixel_channels(redPixel, "Red");
    display_pixel_channels(greenPixel, "Green");
    display_pixel_channels(bluePixel, "Blue");
    display_pixel_channels(magentaPixel, "Magenta");
    display_pixel_channels(whitePixel, "White");
    int width = 200;
    int height = 100;
    Rgb *image = new Rgb[width*height];
    whiteout_image(width, height, image);

    int r = 100;
    int c = 199;
    Rgb pixel = image[(r-1)*width + (c-1)];
    cout << pixel.r <<", "<< pixel.g <<", "<< pixel.b <<endl;

    return 0;
}
void display_pixel_channels(const Rgb &pixel, string name)
{
    cout <<name<< " (Red: " <<pixel.r << "; Green: "
    <<pixel.g<< "; Blue: " <<pixel.b<<")"<<endl;
}

void filter_red(Rgb &pixel)
{
    pixel.g = 0;
    pixel.b = 0;
}

void blackout_image_pointer(const int &width, const int& height, Rgb *image )
{
    for(int c = 0; c < width*height; c++)
    {
        image->r = 0;
        image->g = 0;
        image->b = 0;
        image++;
    }


}

void whiteout_image(const int &width, const int& height, Rgb *image )
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width; c++)
        {
            image[r*width+c].r = 1;
            image[(r)*width+(c)].g = 1;
            image[(r)*width+(c)].b = 1;
        }
    }
}