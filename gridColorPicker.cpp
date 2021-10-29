#include "gridColorPicker.h"

gridColorPicker::gridColorPicker(HSLAPixel gridColor, int gridSpacing)
{
    
/* Your code here! */
    this.gridColor=gridColor;
    this.gridSpacing=gridSpacing;
}

HSLAPixel gridColorPicker::operator()(int x, int y)
{

/* Your code here! */
    HSLAPixcel color;
    if(x%gridSpacing==0){
        color.h=gridColor.h;
        color.s=1;
        color.l=0.5;
    }
    else{
        color.h=0;
        color.s=1;
        color.l=1.0;
    }

}
