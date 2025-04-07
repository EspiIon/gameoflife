#include "button.hpp"
#include <raylib.h>

void Button::draw()
{
    DrawRectangle(posx,posy,width,height,color);
    DrawText(text,posx+width/3,posy+height/3,16,colorText);
}

bool Button::clicked()
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
       int x=GetMouseX();
       int y= GetMouseY();
        
       if(x>posx && x<posx+width && y>posy && y<posy+height){
        return true;
       }
    }
    return false;
}
