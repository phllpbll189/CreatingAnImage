#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
   // These are the image settings that we set before hand these are just for length and height.
    const int image_width = 256;
    const int image_height = 256;

    /*
    To make a circle I need to have a preset center for the circle and a radius so we know the size.
    */
    const double centerX = (image_width -1) / 2;
    const double centerY = (image_height - 1) / 2;

    const double radius = 60.0;

    ofstream ppmFile("Circle.ppm");

    /*This line gives the ppm picture a sizeand color range! i think this is why they have the extra pixel (width equals 256)
    so there is a small border if we wanted a bigger image we would just change those values*/
    ppmFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    //these for loops go from left to right on the image and then it will go down a pixel at the end
    //this is how we make each pixel's color
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {

            //this is to set up the x and y as doubles rather than ints for the calculations we will need to do later
            double X = double(i); //we also save them as x and y because its easier to look at!
            double Y = double(j);

            //this is a formula for the distance between 2 points and the calculation we need to make circle
            double length = sqrt(pow((centerX - X), 2) + pow((centerY - Y), 2));
            
            //if it is within the circle 
            if (length <= radius) {
                //then make the circle a cool gradient from blue to green!
                double R = 0.0;
                double G = 1 - length/radius;
                double B = length/radius;
                int intR = static_cast<int>(255.999 * R);
                int intG = static_cast<int>(255.999 * G);
                int intB = static_cast<int>(255.999 * B);
                ppmFile << intR << ' ' << intG << ' ' << intB << std::endl;
            }
            else {
                //if it is not in the circle then just make it red
                ppmFile << 255 << ' ' << 0 << ' ' << 0 << std::endl;
            }

            //NOTE: also we use doubles with 0 - 1 in the circle because it is much easier to make a gradient
            //out side the circle we can just use static values  to make it much easier
        }
    }
}
