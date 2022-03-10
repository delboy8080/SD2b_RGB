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