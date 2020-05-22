/*****************************************************************************
* | File      	:   GUI_Paint.h
* | Author      :   Waveshare team
* | Function    :	Achieve drawing: draw points, lines, boxes, circles and
*                   their size, solid dotted line, solid rectangle hollow
*                   rectangle, solid circle hollow circle.
* | Info        :
*   Achieve display characters: Display a single character, string, number
*   Achieve time display: adaptive size display time minutes and seconds
*----------------
* |	This version:   V2.0
* | Date        :   2018-11-15
* | Info        :
* 1.add: Paint_NewImage()
*    Create an image's properties
* 2.add: Paint_SelectImage()
*    Select the picture to be drawn
* 3.add: Paint_SetRotate()
*    Set the direction of the cache
* 4.add: Paint_RotateImage()
*    Can flip the picture, Support 0-360 degrees,
*    but only 90.180.270 rotation is better
* 4.add: Paint_SetMirroring()
*    Can Mirroring the picture, horizontal, vertical, origin
* 5.add: Paint_DrawString_CN()
*    Can display Chinese(GB1312)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documnetation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to  whom the Software is
* furished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
******************************************************************************/
#ifndef __GUI_PAINT_H
#define __GUI_PAINT_H

#include "main.h"
//#include "DEV_Config.h"
#include "../Fonts/fonts.h"

/**
 * Image attributes
**/
typedef struct {
    UBYTE *Image;
    UWORD Width;
    UWORD Height;
    UWORD WidthMemory;
    UWORD HeightMemory;
    UWORD Color;
    UWORD Rotate;
    UWORD Mirror;
    UWORD WidthByte;
    UWORD HeightByte;
} PAINT;
extern PAINT Paint;

/**
 * Display rotate
**/
#define ROTATE_0            0
#define ROTATE_90           90
#define ROTATE_180          180
#define ROTATE_270          270

/**
 * Display Flip
**/
typedef enum {
    MIRROR_NONE  = 0x00,
    MIRROR_HORIZONTAL = 0x01,
    MIRROR_VERTICAL = 0x02,
    MIRROR_ORIGIN = 0x03,
} MIRROR_IMAGE;
#define MIRROR_IMAGE_DFT MIRROR_NONE

/**
 * image color
**/
#define WHITE          0xFF
#define BLACK          0x00
#define RED            BLACK

#define IMAGE_BACKGROUND    WHITE
#define FONT_FOREGROUND     BLACK
#define FONT_BACKGROUND     WHITE

/**
 * The size of the point
**/
typedef enum {
    DOT_PIXEL_1X1  = 1,		// 1 x 1
    DOT_PIXEL_2X2  , 		// 2 X 2
    DOT_PIXEL_3X3  ,		// 3 X 3
    DOT_PIXEL_4X4  ,		// 4 X 4
    DOT_PIXEL_5X5  , 		// 5 X 5
    DOT_PIXEL_6X6  , 		// 6 X 6
    DOT_PIXEL_7X7  , 		// 7 X 7
    DOT_PIXEL_8X8  , 		// 8 X 8
} DOT_PIXEL;
#define DOT_PIXEL_DFT  DOT_PIXEL_1X1  //Default dot pilex

/**
 * Point size fill style
**/
typedef enum {
    DOT_FILL_AROUND  = 1,		// dot pixel 1 x 1
    DOT_FILL_RIGHTUP  , 		// dot pixel 2 X 2
} DOT_STYLE;
#define DOT_STYLE_DFT  DOT_FILL_AROUND  //Default dot pilex

/**
 * Line style, solid or dashed
**/
typedef enum {
    LINE_STYLE_SOLID = 0,
    LINE_STYLE_DOTTED,
} LINE_STYLE;

/**
 * Whether the graphic is filled
**/
typedef enum {
    DRAW_FILL_EMPTY = 0,
    DRAW_FILL_FULL,
} DRAW_FILL;

/**
 * Custom structure of a time attribute
**/
typedef struct {
    UWORD Year;  //0000
    UBYTE  Month; //1 - 12
    UBYTE  Day;   //1 - 30
    UBYTE  Hour;  //0 - 23
    UBYTE  Min;   //0 - 59
    UBYTE  Sec;   //0 - 59
} PAINT_TIME;
extern PAINT_TIME sPaint_time;


//init and Clear
void Paint_NewImage(UBYTE *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color);
void Paint_SelectImage(UBYTE *image);
void Paint_SetRotate(UWORD Rotate);
void Paint_SetMirroring(UBYTE mirror);
void Paint_SetPixel(UWORD Xpoint, UWORD Ypoint, UWORD Color);

void Paint_Clear(UWORD Color);
void Paint_ClearWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color);

//Drawing
void Paint_DrawPoint(UWORD Xpoint, UWORD Ypoint, UWORD Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_FillWay);
void Paint_DrawLine(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color, LINE_STYLE Line_Style, DOT_PIXEL Dot_Pixel);
void Paint_DrawRectangle(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color, DRAW_FILL Filled , DOT_PIXEL Dot_Pixel);
void Paint_DrawCircle(UWORD X_Center, UWORD Y_Center, UWORD Radius, UWORD Color, DRAW_FILL Draw_Fill , DOT_PIXEL Dot_Pixel);

//Display string
void Paint_DrawChar(UWORD Xstart, UWORD Ystart, const char Acsii_Char, sFONT* Font, UWORD Color_Background, UWORD Color_Foreground);
void Paint_DrawString_EN(UWORD Xstart, UWORD Ystart, const char * pString, sFONT* Font, UWORD Color_Background, UWORD Color_Foreground);
void Paint_DrawString_CN(UWORD Xstart, UWORD Ystart, const char * pString, cFONT* font, UWORD Color_Background, UWORD Color_Foreground);
void Paint_DrawNum(UWORD Xpoint, UWORD Ypoint, int32_t Nummber, sFONT* Font, UWORD Color_Background, UWORD Color_Foreground);
void Paint_DrawTime(UWORD Xstart, UWORD Ystart, PAINT_TIME *pTime, sFONT* Font, UWORD Color_Background, UWORD Color_Foreground);

uint8_t Paint_DrawChar_XBM (UWORD Xstart, UWORD Ystart, const char Acsii_Char, xbm_font* Font, UWORD Color_Background, UWORD Color_Foreground);
uint16_t Paint_DrawString_XBM(UWORD Xstart, UWORD Ystart, const char * pString, xbm_font* Font, UWORD Color_Background, UWORD Color_Foreground);
uint16_t Paint_DrawNum_XBM (UWORD Xpoint, UWORD Ypoint, int32_t Nummber, xbm_font* Font, UWORD Color_Background, UWORD Color_Foreground);
uint16_t Paint_DrawTime_XBM(UWORD Xstart, UWORD Ystart, PAINT_TIME *pTime, xbm_font* Font, UWORD Color_Background, UWORD Color_Foreground);

uint16_t Paint_GetDrawNumWidth_XBM(int32_t Nummber, xbm_font* Font );
uint16_t Paint_GetDrawStringWidth_XBM(const char *pString, xbm_font* Font);


//pic
void Paint_DrawBitMap(const unsigned char* image_buffer);

#define Paint_DrawXBM(x, y, xbm_pic_name) \
               __aux_Paint_DrawXBM((x), (y), \
                               xbm_pic_name ## _width, \
                               xbm_pic_name ## _height, \
                               xbm_pic_name ## _bits)

#define Paint_DrawCompressedXBM(x, y, xbm_pic_name) \
               __aux_Paint_DrawCompressedXBM((x), (y), \
                               xbm_pic_name ## _width, \
                               xbm_pic_name ## _height, \
                               xbm_pic_name ## _bits)


void __aux_Paint_DrawXBM(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                               const uint8_t* xbm_buffer);

void __aux_Paint_DrawCompressedXBM(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
                               const uint8_t* xbm_buffer);

#endif





