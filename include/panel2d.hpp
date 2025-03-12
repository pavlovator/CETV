#pragma once

class Panel2d {
public:
    Panel2d(int x, int y, int width, int height)
        : x {x}
        , y {y}
        , width {width}
        , height {height}        
    {
        
    }
private:
    int x;
    int y;
    int width;
    int height;
};