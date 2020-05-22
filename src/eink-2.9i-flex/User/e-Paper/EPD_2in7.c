
//#include "BlueNRG_x_device.h"
//#include "BlueNRG1.h"
#include <stdio.h>
//#include "BlueNRG1_conf.h"
//#include "SDK_EVAL_Config.h"

#include "main.h"

#include "EPD_2in7.h"
//#include "Debug.h"


//#define GRAY_4

#ifdef GRAY_4

//////////////////////////////////////full screen update LUT////////////////////////////////////////////
//0~3 gray
const unsigned char lut_vcom_dc[] =
{
0x00	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x60	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x00	,0x00	,0x00	,0x01,
0x00	,0x13	,0x0A	,0x01	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00
				
};
//R21
const unsigned char lut_ww[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x10	,0x14	,0x0A	,0x00	,0x00	,0x01,
0xA0	,0x13	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R22H	r
const unsigned char lut_bw[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x99	,0x0C	,0x01	,0x03	,0x04	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R23H	w
const unsigned char lut_wb[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x99	,0x0B	,0x04	,0x04	,0x01	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R24H	b
const unsigned char lut_bb[] ={
0x80	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x20	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x50	,0x13	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};






const unsigned char lut_vcom1[] =
{
0x00	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x60	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x00	,0x00	,0x00	,0x01,
0x00	,0x13	,0x0A	,0x01	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00
				
};
//R21
const unsigned char lut_ww1[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x10	,0x14	,0x0A	,0x00	,0x00	,0x01,
0xA0	,0x13	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R22H	r
const unsigned char lut_bw1[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x99	,0x0C	,0x01	,0x03	,0x04	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R23H	w
const unsigned char lut_wb1[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x99	,0x0B	,0x04	,0x04	,0x01	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R24H	b
const unsigned char lut_bb1[] ={
0x80	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x20	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x50	,0x13	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};








const unsigned char LUTDefault_part[31] = {
	0x32,	// command

/*	0x00,0x00,0x00,0x18,	
	0x18,0x18,0x18,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x40,0x14,0x34,0x01,
	0x00,0x00,0x00,0x00,
	0x00,0x00,
*/
 0x10 //C221 25C partial update waveform
,0x18
,0x18
,0x08
,0x18
,0x18
,0x08
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00
,0x13
,0x14
,0x44
,0x12
,0x00
,0x00
,0x00
,0x00
,0x00
,0x00

	};

const unsigned char LUTDefault_full[31] = {
	0x32,	// command
/*	0x11,0x11,0x10,0x02,	// full
	0x02,0x22,0x22,0x22,
	0x22,0x22,0x51,0x51,
	0x55,0x88,0x08,0x08,
    	0x88,0x88,0x00,0x00,
	0x34,0x23,0x12,0x21,
	0x24,0x28,0x22,0x21,
	0xA1,0x01
*/
 0x02 //C221 25C Full update waveform
,0x02
,0x01
,0x11
,0x12
,0x12
,0x22
,0x22
,0x66
,0x69
,0x69
,0x59
,0x58
,0x99
,0x99
,0x88
,0x00
,0x00
,0x00
,0x00
,0xF8
,0xB4
,0x13
,0x51
,0x35
,0x51
,0x51
,0x19
,0x01
,0x00
	};










#else

#if 1

#if 1

//0~3 gray
const unsigned char lut_vcom_dc[] =
{
0x00	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x60	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x00	,0x00	,0x00	,0x01,
0x00	,0x13	,0x0A	,0x01	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00
				
};
//R21
const unsigned char lut_ww[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x10	,0x14	,0x0A	,0x00	,0x00	,0x01,
0xA0	,0x13	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R22H	r
const unsigned char lut_bw[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x99	,0x0C	,0x01	,0x03	,0x04	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R23H	w
const unsigned char lut_wb[] ={
0x40	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x00	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x99	,0x0B	,0x04	,0x04	,0x01	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
//R24H	b
const unsigned char lut_bb[] ={
0x80	,0x0A	,0x00	,0x00	,0x00	,0x01,
0x90	,0x14	,0x14	,0x00	,0x00	,0x01,
0x20	,0x14	,0x0A	,0x00	,0x00	,0x01,
0x50	,0x13	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};

#else
const unsigned char lut_vcom_dc[] = {
    0x00	,0x00,
    0x00	,0x08	,0x00	,0x00	,0x00	,0x02,
    0x60	,0x28	,0x28	,0x00	,0x00	,0x01,
    0x00	,0x14	,0x00	,0x00	,0x00	,0x01,
    0x00	,0x12	,0x12	,0x00	,0x00	,0x01,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00
};
const unsigned char lut_ww[] = {
    0x40	,0x08	,0x00	,0x00	,0x00	,0x02,
    0x90	,0x28	,0x28	,0x00	,0x00	,0x01,
    0x40	,0x14	,0x00	,0x00	,0x00	,0x01,
    0xA0	,0x12	,0x12	,0x00	,0x00	,0x01,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
const unsigned char lut_bw[] = {
    0x40	,0x08	,0x00	,0x00	,0x00	,0x02,
    0x90	,0x28	,0x28	,0x00	,0x00	,0x01,
    0x40	,0x14	,0x00	,0x00	,0x00	,0x01,
    0xA0	,0x12	,0x12	,0x00	,0x00	,0x01,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
const unsigned char lut_bb[] = {
    0x80	,0x08	,0x00	,0x00	,0x00	,0x02,
    0x90	,0x28	,0x28	,0x00	,0x00	,0x01,
    0x80	,0x14	,0x00	,0x00	,0x00	,0x01,
    0x50	,0x12	,0x12	,0x00	,0x00	,0x01,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
const unsigned char lut_wb[] = {
    0x80	,0x08	,0x00	,0x00	,0x00	,0x02,
    0x90	,0x28	,0x28	,0x00	,0x00	,0x01,
    0x80	,0x14	,0x00	,0x00	,0x00	,0x01,
    0x50	,0x12	,0x12	,0x00	,0x00	,0x01,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
    0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
};
#endif



/////////////////////////////////ˢ/////////////////////////////////////////////
const unsigned char lut_vcom1[] ={
0x00	,0x00,
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00
					};
const unsigned char lut_ww1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,};
const unsigned char lut_bw1[] ={
0x80	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
const unsigned char lut_wb1[] ={
0x40	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
const unsigned char lut_bb1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};

#else

const unsigned char lut_vcom_dc[] = {
    0x00, 0x00,
    0x00, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x00, 0x32, 0x32, 0x00, 0x00, 0x02,
    0x00, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//R21H
const unsigned char lut_ww[] = {
    0x50, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x60, 0x32, 0x32, 0x00, 0x00, 0x02,
    0xA0, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//R22H    r
const unsigned char lut_bw[] =
{
    0x50, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x60, 0x32, 0x32, 0x00, 0x00, 0x02,
    0xA0, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//R24H    b
const unsigned char lut_bb[] =
{
    0xA0, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x60, 0x32, 0x32, 0x00, 0x00, 0x02,
    0x50, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//R23H    w
const unsigned char lut_wb[] =
{
    0xA0, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x60, 0x32, 0x32, 0x00, 0x00, 0x02,
    0x50, 0x0F, 0x0F, 0x00, 0x00, 0x05,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};




/////////////////////////////////ˢ/////////////////////////////////////////////
const unsigned char lut_vcom1[] ={
0x00	,0x00,
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00
					};
const unsigned char lut_ww1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,};
const unsigned char lut_bw1[] ={
0x80	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
const unsigned char lut_wb1[] ={
0x40	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
const unsigned char lut_bb1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};



#endif

#endif // GRAY_4


/******************************************************************************
function :	Software reset
parameter:
******************************************************************************/
static void EPD_Reset(void)
{
//    DEV_Digital_Write(EPD_RST_PIN, 1);
    //GPIO_SetBits(EPD_RST_PIN);
//    DEV_Delay_ms(200);
    //SdkDelayMs(200);
//    DEV_Digital_Write(EPD_RST_PIN, 0);
    GPIO_ResetBits(EPD_RST_PIN);
//    DEV_Delay_ms(200);
    SdkDelayMs(500);
//    DEV_Digital_Write(EPD_RST_PIN, 1);
    GPIO_SetBits(EPD_RST_PIN);
//    DEV_Delay_ms(200);
    SdkDelayMs(200);
}

/******************************************************************************
function :	send command
parameter:
     Reg : Command register
******************************************************************************/
void EPD_SendCommand(UBYTE Reg)
{
    GPIO_ResetBits(EPD_DC_PIN);
//    DEV_Digital_Write(EPD_DC_PIN, 0);
	SPI_SendReceiveData(&Reg, 1);
//    DEV_Digital_Write(EPD_CS_PIN, 0);
//    DEV_SPI_WriteByte(Reg);
//    DEV_Digital_Write(EPD_CS_PIN, 1);
}

/******************************************************************************
function :	send data
parameter:
    Data : Write data
******************************************************************************/
void EPD_SendData(UBYTE Data)
{
    GPIO_SetBits(EPD_DC_PIN);
//    DEV_Digital_Write(EPD_DC_PIN, 1);
	SPI_SendReceiveData(&Data, 1);
//    DEV_Digital_Write(EPD_CS_PIN, 0);
//    DEV_SPI_WriteByte(Data);
//    DEV_Digital_Write(EPD_CS_PIN, 1);
}

/******************************************************************************
function :	Wait until the busy_pin goes LOW
parameter:
******************************************************************************/
void EPD_WaitUntilIdle(void)
{
    Debug("e-Paper busy\r\n");
#if 1 //{}
    int i = 0;
    UBYTE busy = 0;

    busy = GPIO_ReadBit(EPD_BUSY_PIN);
    while(busy == 0 && i < 12*50){
        SdkDelayMs(1);
        //__WFE();

        i++;

        EPD_SendCommand(0x71);
        busy = GPIO_ReadBit(EPD_BUSY_PIN);
    };
#endif

    //SdkDelayMs(300);
    Debug("e-Paper busy release\r\n");
}

/******************************************************************************
function :	set the look-up tables
parameter:
******************************************************************************/
void EPD_SetLut(void) {
    unsigned int count;
    EPD_SendCommand(LUT_FOR_VCOM);                            //vcom
    for(count = 0; count < /*44*/sizeof(lut_vcom_dc); count++) {
        EPD_SendData(lut_vcom_dc[count]);
    }

    EPD_SendCommand(LUT_WHITE_TO_WHITE);                      //ww --
    for(count = 0; count < /*42*/sizeof(lut_ww); count++) {
        EPD_SendData(lut_ww[count]);
    }

    EPD_SendCommand(LUT_BLACK_TO_WHITE);                      //bw r
    for(count = 0; count < /*42*/sizeof(lut_bw); count++) {
        EPD_SendData(lut_bw[count]);
    }

    EPD_SendCommand(LUT_WHITE_TO_BLACK);                      //wb w
    for(count = 0; count < /*42*/sizeof(lut_bb); count++) {
        EPD_SendData(lut_bb[count]);
    }

    EPD_SendCommand(LUT_BLACK_TO_BLACK);                      //bb b
    for(count = 0; count < /*42*/sizeof(lut_wb); count++) {
        EPD_SendData(lut_wb[count]);
    }
}

/******************************************************************************
function :	set the partial look-up tables
parameter:
******************************************************************************/
void EPD_SetPartialLut(void) {
    unsigned int count;
    EPD_SendCommand(LUT_FOR_VCOM);                            //vcom
    for(count = 0; count < /*44*/sizeof(lut_vcom1); count++) {
        EPD_SendData(lut_vcom1[count]);
    }

    EPD_SendCommand(LUT_WHITE_TO_WHITE);                      //ww --
    for(count = 0; count < /*42*/sizeof(lut_ww1); count++) {
        EPD_SendData(lut_ww1[count]);
    }

    EPD_SendCommand(LUT_BLACK_TO_WHITE);                      //bw r
    for(count = 0; count < /*42*/sizeof(lut_bw1); count++) {
        EPD_SendData(lut_bw1[count]);
    }

    EPD_SendCommand(LUT_WHITE_TO_BLACK);                      //wb w
    for(count = 0; count < /*42*/sizeof(lut_bb1); count++) {
        EPD_SendData(lut_bb1[count]);
    }

    EPD_SendCommand(LUT_BLACK_TO_BLACK);                      //bb b
    for(count = 0; count < /*42*/sizeof(lut_wb1); count++) {
        EPD_SendData(lut_wb1[count]);
    }
}

/******************************************************************************
function :	Initialize the e-Paper register
parameter:
******************************************************************************/
UBYTE EPD_Init(void)
{
    EPD_Reset();

    EPD_SendCommand(POWER_SETTING);
    EPD_SendData(0x03);                  // VDS_EN, VDG_EN
    EPD_SendData(0x00);                  // VCOM_HV, VGHL_LV[1], VGHL_LV[0]
    EPD_SendData(0x2b);                  // VDH
    EPD_SendData(0x2b);                  // VDL
#ifdef GRAY_4
    EPD_SendData(0x13); //9);                  // VDHR
#else
    EPD_SendData(0x03); //9);                  // VDHR
#endif
    
    EPD_SendCommand(BOOSTER_SOFT_START);
    EPD_SendData(0x17); //07);
    EPD_SendData(0x17); //07);
    EPD_SendData(0x17);

//#ifndef GRAY_4
    /** /
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0x60);
    EPD_SendData(0xA5);
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0x89);
    EPD_SendData(0xA5);
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0x90);
    EPD_SendData(0x00);
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0x93);
    EPD_SendData(0x2A);
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0xA0);
    EPD_SendData(0xA5);
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0xA1);
    EPD_SendData(0x00);
    // Power optimization
    EPD_SendCommand(0xF8);
    EPD_SendData(0x73);
    EPD_SendData(0x41);
    / **/
//#endif
    
//    EPD_SendCommand(PARTIAL_DISPLAY_REFRESH);
//    EPD_SendData(0x00);
    EPD_SendCommand(POWER_ON);
    EPD_WaitUntilIdle();

    EPD_SendCommand(PANEL_SETTING);
#ifdef GRAY_4
    EPD_SendData(0x3F);        //KW-3f   KWR-2F	BWROTP 0f	BWOTP 1f
#else
    EPD_SendData(0xAF);        //KW-BF   KWR-AF    BWROTP 0f
//    EPD_SendData(0xbF);        //KW-BF   KWR-AF    BWROTP 0f
//    EPD_SendData(0x9F);        // b/w, by OTP LUT
       EPD_SendData(0x0d);        //KW-BF   KWR-AF    BWROTP 0f
#endif
    EPD_SendCommand(PLL_CONTROL);
#ifdef GRAY_4
    EPD_SendData(0x3c);       //100HZ
#else
    EPD_SendData(0x3A);       //3A 100HZ   29 150Hz 39 200HZ    31 171HZ
#endif
/**/
#if 1
    EPD_SendCommand(TCON_RESOLUTION);
//    EPD_SendData(/*0x00*/ 0xff & (EPD_WIDTH  >> 8) );
    EPD_SendData(/*0xb0*/ 0xff & (EPD_WIDTH      ) );       // 176
    EPD_SendData(/*0x01*/ 0xff & (EPD_HEIGHT >> 8) );
    EPD_SendData(/*0x08*/ 0xff & (EPD_HEIGHT     ) );       // 264
#endif
/**/
#ifdef GRAY_4
    EPD_SendCommand(VCM_DC_SETTING_REGISTER);
    EPD_SendData(0x12);
#else
    EPD_SendCommand(VCM_DC_SETTING_REGISTER);				//vcom_DC setting
	EPD_SendData (0x28);			//0x28:-2.0V,0x12:-0.9V
#endif

	SdkDelayMs(2);
/******full screen for level update******************************************/
	EPD_SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);			 //VCOM AND DATA INTERVAL SETTING
#ifdef GRAY_4
	EPD_SendData(0x97);
#else
	EPD_SendData(0x47);
#endif

    EPD_SetPartialLut();
    //EPD_SetLut();

    return 0;
}

/******************************************************************************
function :	Clear screen
parameter:
******************************************************************************/
void EPD_Clear(void)
{
    UWORD Width, Height;
    Width = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
    Height = EPD_HEIGHT;

    EPD_SetLut();

    /**/
    EPD_SendCommand(DATA_START_TRANSMISSION_1);
    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {      //white
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0Xff);
        }
    }
#ifdef GRAY_4
    for (UWORD j = 0; j < Height; j++) {      //gray1
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0Xff);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //gray2
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //black
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
#endif

    /**/
//    SdkDelayMs(2);
    EPD_SendCommand(DATA_START_TRANSMISSION_2);
    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {      //white
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0XFF);
        }
    }
#ifdef GRAY_4
    for (UWORD j = 0; j < Height; j++) {      //gray1
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //gray2
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0XFF);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //black
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
#endif
    /**/
//    SdkDelayMs(2);

    EPD_SetLut();
    
    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

    EPD_SetPartialLut();

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();
    
    EPD_SetPartialLut();
}

/******************************************************************************
function :	Sends the image buffer in RAM to e-Paper and displays
parameter:
******************************************************************************/
//static int _disp_cntr = 0;

void EPD_Display(UBYTE *Image)
{
    UWORD Width, Height;
    Width = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
    Height = EPD_HEIGHT;

/**/
    EPD_SendCommand(DATA_START_TRANSMISSION_1);
//    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0Xff);
        }
    }
//    SdkDelayMs(2);
//#ifdef GRAY_4
    for (UWORD j = 0; j < Height; j++) {      //gray1
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0Xff);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //gray2
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //black
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
//#endif
/**/

    EPD_SendCommand(DATA_START_TRANSMISSION_2);
//    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(Image[i + j * Width]);
        }
    }
//#ifdef GRAY_4
    for (UWORD j = 0; j < Height; j++) {      //gray1
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //gray2
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0XFF);
        }
    }
    for (UWORD j = 0; j < Height; j++) {      //black
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0X00);
        }
    }
//#endif
//    SdkDelayMs(2);
    
    EPD_SetPartialLut();
    
//    if(_disp_cntr <= 0){
//          EPD_SetLut();
//    }

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

//    if(_disp_cntr <= 0)
//          EPD_SetPartialLut();

//    _disp_cntr++;
//    if(_disp_cntr > 15)
//      _disp_cntr = 0;

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();
}

/******************************************************************************
function :	Sends the image buffer in RAM to e-Paper and displays
parameter:
******************************************************************************/
static uint8_t refresh_cntr = 0;

void EPD_Display_Partial_pt2(UWORD x, UWORD y, UWORD w, UWORD h, UBYTE *Image)
{
    UWORD Width, Height;
    Width = (/*EPD_WIDTH*/w % 8 == 0)? (/*EPD_WIDTH*/w / 8 ): (/*EPD_WIDTH*/w / 8 + 1);
    Height = /*EPD_HEIGHT*/h;

/**
    EPD_SendCommand(PARTIAL_DATA_START_TRANSMISSION_1);
    EPD_SendData(x >> 8); EPD_SendData(x & 0xf8);
    EPD_SendData(y >> 8); EPD_SendData(y & 0xff);
    EPD_SendData(w >> 8); EPD_SendData(w & 0xf8);
    EPD_SendData(h >> 8); EPD_SendData(h & 0xff);
    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0XFF);
        }
    }
    SdkDelayMs(2);
/ **/

    EPD_SendCommand(PARTIAL_DATA_START_TRANSMISSION_2);
    SdkDelayMs(2);
    EPD_SendData(x >> 8); EPD_SendData(x & 0xf8);
    EPD_SendData(y >> 8); EPD_SendData(y & 0xff);
    EPD_SendData(w >> 8); EPD_SendData(w & 0xf8);
    EPD_SendData(h >> 8); EPD_SendData(h & 0xff);
    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(Image[i + j * Width]);
        }
    }
    SdkDelayMs(2);

/**
    EPD_SendCommand(PARTIAL_DISPLAY_REFRESH);
    SdkDelayMs(2);
    EPD_SendData(x >> 8); EPD_SendData(x & 0xf8);
    EPD_SendData(y >> 8); EPD_SendData(y & 0xff);
    EPD_SendData(w >> 8); EPD_SendData(w & 0xf8);
    EPD_SendData(h >> 8); EPD_SendData(h & 0xff);
/ **/

    uint8_t is_full_refresh = (refresh_cntr & 3) == 0;

    if(is_full_refresh){
        EPD_SetLut();
    }else{
        EPD_SendCommand(DISPLAY_REFRESH);
        EPD_WaitUntilIdle();

        EPD_SendCommand(DISPLAY_REFRESH);
        EPD_WaitUntilIdle();
    }
    EPD_SendCommand(DISPLAY_REFRESH);
    EPD_WaitUntilIdle();

    if(is_full_refresh)
        EPD_SetPartialLut();

    refresh_cntr++;
}

void EPD_Display_Partial_pt1(UWORD x, UWORD y, UWORD w, UWORD h, UBYTE *Image)
{
    UWORD Width, Height;
    Width = (/*EPD_WIDTH*/w % 8 == 0)? (/*EPD_WIDTH*/w / 8 ): (/*EPD_WIDTH*/w / 8 + 1);
    Height = /*EPD_HEIGHT*/h;

/**/
    EPD_SendCommand(PARTIAL_DATA_START_TRANSMISSION_1);
    SdkDelayMs(2);
    EPD_SendData(x >> 8); EPD_SendData(x & 0xf8);
    EPD_SendData(y >> 8); EPD_SendData(y & 0xff);
    EPD_SendData(w >> 8); EPD_SendData(w & 0xf8);
    EPD_SendData(h >> 8); EPD_SendData(h & 0xff);
    SdkDelayMs(2);
    for (UWORD j = 0; j < Height; j++) {
        for (UWORD i = 0; i < Width; i++) {
            EPD_SendData(0XFF);
        }
    }
    SdkDelayMs(2);
/**/
}

/******************************************************************************
function :	Enter sleep mode
parameter:
******************************************************************************/
void EPD_Sleep(void)
{
    EPD_SendCommand(0X50);
    EPD_SendData(0xf7);
    EPD_SendCommand(0X02);  	//power off
    EPD_SendCommand(0X07);  	//deep sleep
    EPD_SendData(0xA5);
}
