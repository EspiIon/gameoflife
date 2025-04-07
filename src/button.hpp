#include <raylib.h>

class Button{
    public:
        Button(int width, int height, int x,int y,Color color,const char* text,Color colorText)
        :width(width),height(height),posx(x),posy(y),color(color),text(text),colorText(colorText){};
        void draw();
        bool clicked();
    private:
    int width; 
    int height;
    int posx;
    int posy;
    Color color;
    const char* text;
    Color colorText;
};