#include <stdlib.h>
#include "gradientColorPicker.h"

/**
 * Constructs a new gradientColorPicker.
 *
 * @param fadeColor1 The first color to start the gradient at.
 * @param fadeColor2 The second color to end the gradient with.
 * @param radius How quickly to transition to fadeColor2.
 * @param centerX X coordinate for the center of the gradient.
 * @param centerY Y coordinate for the center of the gradient.
 */
gradientColorPicker::gradientColorPicker(HSLAPixel fadeColor1,
                                         HSLAPixel fadeColor2, int radius,
                                         int centerX, int centerY): fadeColor1(fadeColor1), fadeColor2(fadeColor2),radius(radius),centerX(centerX),centerY(centerY)
{
    /**
     * @todo Construct your gradientColorPicker here! You may find it
     *	helpful to create additional member variables to store things.
     */
}

/**
 * Picks the color for pixel (x, y).
 *
 * The first color fades into the second color as you move from the initial
 * fill point, the center, to the radius. Beyond the radius, all pixels
 * should be just color2.
 *
 * You should calculate the distance between two points using the standard
 * Manhattan distance formula,
 *
 * \f$dist = |center\_x - given\_x| + |center\_y - given\_y|\f$
 *
 * Then, scale the hue channel from fadeColor1 to
 * fadeColor2 linearly from d = 0 to d = radius.
 * 
 * 
 * The s, and l channels of the color should be 1.0 and 0.5, resp.
 *
 * For example, the hue at distance d where d is less than the radius
 * must be
 *
 * newHue = fadeColor1.h + (dist/radius) * ( |fadeColor1.h - fadeColor2.h|)
 * where |fadeColor1.h - fadeColor2.h| is the longest distance between
 * fadeColor1 and fadeColor2... if the distance is < 180, then use
 * 360 - the distance. You'll have to figure out what to do if color2.h
 * is larger than color1.h, as well. Note that the hue value is a rainbow
 * of colors between 0 and 360, and that it both begins and ends at red.
 * It is as if the colors are around a circle, and the angle corresponds to its
 * value. 
 *
 * Note that all values are floats. If you do not follow the above formula,
 * your colors may be very close but round differently than ours.
 *
 * @param x The x coordinate to pick a color for.
 * @param y The y coordinate to pick a color for.
 * @return The color selected for (x, y).
 */
HSLAPixel gradientColorPicker::operator()(int x, int y)
{
    HSLAPixel color ;
    /**
     * @todo Return the correct color here!
     */
    
    double dist=calDist(x,y);
    if(dist<radius)
    {
        color.h=fadeColor1.h + (dist/radius) *  calColorDist(fadeColor1.h - fadeColor2.h);
    }
    else{
        color.h=fadeColor2.h;
    }
    color.s=1;
    color.l=0.5;
    return color;
}

double calDist(int x, int y){
    return sqrt(pow(centerX-x,2)+pow(centerY-y,2));
}

//Calculate the largest distance, which ensure that the distance is larger than 180.
double calColorDist(int h1,int h2){
    int d=abs(h1-h2);
    if(d>=180)return d;
    else return 360-d;
}