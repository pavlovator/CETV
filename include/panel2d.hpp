#pragma once
#include <iostream>
#include "raylib.h"

class Panel2d {
public:
    Panel2d(int x, int y, int width, int height)
        : x {x}
        , y {y}
        , width {width}
        , height {height}   
        , padding_left {0}
        , padding_top {0}    
    {
        Image image = LoadImage("../data/slice_0252.jpg");   // Loaded in CPU memory (RAM)
        ImageFormat(&image, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);         // Format image to RGBA 32bit (required for texture update) <-- ISSUE

        std::cout << image.width << " " << image.height << std::endl;
        
        float ratio = (image.width < image.height) ? ((float) height / (float) image.height) : ((float) width / (float) image.width);
        if (image.width > image.height) {
            float ratio = ((float) width / (float) image.width);
            int new_height = image.height*ratio;
            ImageResize(&image, width, image.height*ratio);
            padding_top = (height - new_height) / 2;
        } else {
            float ratio = ((float) height / (float) image.height);
            int new_width = image.width*ratio;
            ImageResize(&image, new_width, height);
            padding_left = (width - new_width) / 2;
        }

        texture = LoadTextureFromImage(image);

        UnloadImage(image);
    }

    void unloadTexture()
    {
        UnloadTexture(texture);
    }

    void draw() 
    {
        DrawTexture(texture, x + padding_left, y + padding_top, WHITE);
        DrawRectangleLines(x, y, width, height, BLACK);

    }
private:
    int x;
    int y;
    int width;
    int height;
    int padding_left;
    int padding_top;
    Texture2D texture;
};