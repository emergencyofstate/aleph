
/* liquid.c
 *
 * bitmap font data 
 * designed by Henrik Theiling for Liquid Rendering, 2009
 *
 * adapted for aleph project by monome 2012
*/

// ordering is column-first for easier variable spacing
/* (0,0) = top left
 * pixel(x,y) = (bool)(font_data[x].data & (1 << y)) */

#include "compiler.h"
#include "font.h"

// static glyph_attr_t const fontliqminus_attr[]= {
//     { /*lang*/0, 0, /*spc_cp*/0, /*spc_x*/1 },
//     { /*lang*/0, glyph_flag(fix_w,FIX_W), /*spc_cp*/0, /*spc_x*/0 },
//     { /*lang*/0, glyph_flag(fix_w,FIX_W), /*spc_cp*/0, /*spc_x*/1 },
//     { /*lang*/0, glyph_flag(mono,MONO), /*spc_cp*/0, /*spc_x*/1 }
// };

//static U32 const fontliqminus_attr_nentries= sizeof(fontliqminus_attr)/sizeof(glyph_attr_t);

// FIXME: store last column as (FONTW-[this])
const glyph font_data[]= {
  { /* 0x00020UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
  { /* 0x00021UL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x5e, 0x00, 0x00 } },
  { /* 0x00022UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x06, 0x00, 0x06, 0x00 } },
  { /* 0x00023UL, 0, 0UL, */ 1, 0, { 0x00, 0x24, 0x7e, 0x24, 0x7e, 0x24 } },
  { /* 0x00024UL, 0, 0UL, */ 1, 0, { 0x00, 0x48, 0x54, 0xfe, 0x54, 0x24 } },
  { /* 0x00025UL, 0, 0UL, */ 1, 1, { 0x00, 0x48, 0x20, 0x10, 0x48, 0x00 } },
  { /* 0x00026UL, 0, 0UL, */ 1, 0, { 0x00, 0x34, 0x4a, 0x54, 0x20, 0x50 } },
  { /* 0x00027UL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00 } },
  { /* 0x00028UL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x3c, 0x42, 0x00, 0x00 } },
  { /* 0x00029UL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x42, 0x3c, 0x00, 0x00 } },
  { /* 0x0002aUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x54, 0x38, 0x54, 0x00 } },
  { /* 0x0002bUL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x10, 0x38, 0x10, 0x00 } },
  { /* 0x0002cUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x80, 0x60, 0x00, 0x00 } },
  { /* 0x0002dUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x10, 0x10, 0x00, 0x00 } },
  { /* 0x0002eUL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x40, 0x00, 0x00 } },
  { /* 0x0002fUL, 0, 0UL, */ 1, 2, { 0x00, 0x60, 0x18, 0x06, 0x00, 0x00 } },
  { /* 0x00030UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0x42, 0x3c, 0x00 } },
  { /* 0x00031UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x04, 0x7e, 0x00, 0x00 } },
  { /* 0x00032UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x62, 0x52, 0x4c, 0x00 } },
  { /* 0x00033UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x42, 0x4a, 0x36, 0x00 } },
  { /* 0x00034UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x1c, 0x10, 0x7e, 0x00 } },
  { /* 0x00035UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x4e, 0x4a, 0x32, 0x00 } },
  { /* 0x00036UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0x4a, 0x32, 0x00 } },
  { /* 0x00037UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x02, 0x72, 0x0e, 0x00 } },
  { /* 0x00038UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x34, 0x4a, 0x34, 0x00 } },
  { /* 0x00039UL, 0, 2UL, */ 2, 1, { 0x00, 0x00, 0x4c, 0x52, 0x3c, 0x00 } },
  { /* 0x0003aUL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x48, 0x00, 0x00 } },
  { /* 0x0003bUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x80, 0x64, 0x00, 0x00 } },
  { /* 0x0003cUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x10, 0x28, 0x44, 0x00 } },
  { /* 0x0003dUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x28, 0x28, 0x28, 0x00 } },
  { /* 0x0003eUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x44, 0x28, 0x10, 0x00 } },
  { /* 0x0003fUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x52, 0x0a, 0x04, 0x00 } },
  { /* 0x00040UL, 0, 0UL, */ 1, 0, { 0x00, 0x7c, 0x82, 0x92, 0xaa, 0x3c } },
  { /* 0x00041UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7c, 0x12, 0x7c, 0x00 } },
  { /* 0x00042UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x4a, 0x34, 0x00 } },
  { /* 0x00043UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0x42, 0x42, 0x00 } },
  { /* 0x00044UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x42, 0x3c, 0x00 } },
  { /* 0x00045UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x4a, 0x42, 0x00 } },
  { /* 0x00046UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x0a, 0x02, 0x00 } },
  { /* 0x00047UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0x42, 0x72, 0x00 } },
  { /* 0x00048UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x08, 0x7e, 0x00 } },
  //  { /* 0x00049UL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00 } },
  // there are 2 uppercase I's... this one has serifs
  { /* 0x00049UL, 0, 3UL, */ 2, 1, { 0x00, 0x00, 0x42, 0x7e, 0x42, 0x00 } },
  { /* 0x0004aUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x80, 0x7e, 0x00, 0x00 } },
  { /* 0x0004bUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x08, 0x76, 0x00 } },
  { /* 0x0004cUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x40, 0x40, 0x00 } },
  { /* 0x0004dUL, 0, 0UL, */ 1, 0, { 0x00, 0x7e, 0x04, 0x08, 0x04, 0x7e } },
  { /* 0x0004eUL, 0, 0UL, */ 1, 1, { 0x00, 0x7e, 0x04, 0x08, 0x7e, 0x00 } },
  { /* 0x0004fUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0x42, 0x3c, 0x00 } },
  { /* 0x00050UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x12, 0x0c, 0x00 } },
  { /* 0x00051UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0xc2, 0xbc, 0x00 } },
  { /* 0x00052UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x12, 0x6c, 0x00 } },
  { /* 0x00053UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x44, 0x4a, 0x32, 0x00 } },
  { /* 0x00054UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x02, 0x7e, 0x02, 0x00 } },
  { /* 0x00055UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x3e, 0x40, 0x7e, 0x00 } },
  { /* 0x00056UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x20, 0x1e, 0x00 } },
  { /* 0x00057UL, 0, 0UL, */ 1, 0, { 0x00, 0x3e, 0x40, 0x30, 0x40, 0x3e } },
  { /* 0x00058UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x66, 0x18, 0x66, 0x00 } },
  { /* 0x00059UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x0e, 0x70, 0x0e, 0x00 } },
  { /* 0x0005aUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x62, 0x5a, 0x46, 0x00 } },
  { /* 0x0005bUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x7e, 0x42, 0x00, 0x00 } },
  { /* 0x0005cUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x06, 0x18, 0x60, 0x00 } },
  { /* 0x0005dUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x42, 0x7e, 0x00, 0x00 } },
  { /* 0x0005eUL, 0, 0UL, */ 1, 0, { 0x00, 0x08, 0x04, 0x7e, 0x04, 0x08 } },
  { /* 0x0005fUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x80, 0x80, 0x80, 0x00 } },
  { /* 0x00060UL, 0, 0UL, */ 1, 1, { 0x00, 0x48, 0x7c, 0x4a, 0x42, 0x00 } },
  { /* 0x00061UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x20, 0x54, 0x78, 0x00 } },
  { /* 0x00062UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x44, 0x38, 0x00 } },
  { /* 0x00063UL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x38, 0x44, 0x00, 0x00 } },
  { /* 0x00064UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x38, 0x44, 0x7e, 0x00 } },
  { /* 0x00065UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x38, 0x54, 0x4c, 0x00 } },
  { /* 0x00066UL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x7c, 0x0a, 0x00, 0x00 } },
  { /* 0x00067UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x98, 0xa4, 0x7c, 0x00 } },
  { /* 0x00068UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x04, 0x78, 0x00 } },
  { /* 0x00069UL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00 } },
  { /* 0x0006aUL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x80, 0x7a, 0x00, 0x00 } },
  { /* 0x0006bUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7e, 0x18, 0x64, 0x00 } },
  { /* 0x0006cUL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00 } },
  { /* 0x0006dUL, 0, 0UL, */ 1, 0, { 0x00, 0x7c, 0x04, 0x7c, 0x04, 0x78 } },
  { /* 0x0006eUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7c, 0x04, 0x78, 0x00 } },
  { /* 0x0006fUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x38, 0x44, 0x38, 0x00 } },
  { /* 0x00070UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0xfc, 0x44, 0x78, 0x00 } },
  { /* 0x00071UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x38, 0x24, 0xfc, 0x00 } },
  { /* 0x00072UL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x78, 0x04, 0x00, 0x00 } },
  { /* 0x00073UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x48, 0x54, 0x24, 0x00 } },
  { /* 0x00074UL, 0, 0UL, */ 2, 2, { 0x00, 0x00, 0x3e, 0x44, 0x00, 0x00 } },
  { /* 0x00075UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x3c, 0x40, 0x7c, 0x00 } },
  { /* 0x00076UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x7c, 0x20, 0x1c, 0x00 } },
  { /* 0x00077UL, 0, 0UL, */ 1, 0, { 0x00, 0x3c, 0x40, 0x38, 0x40, 0x3c } },
  { /* 0x00078UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x6c, 0x10, 0x6c, 0x00 } },
  { /* 0x00079UL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x1c, 0xa0, 0x7c, 0x00 } },
  { /* 0x0007aUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x64, 0x54, 0x4c, 0x00 } },
  { /* 0x0007bUL, 0, 0UL, */ 2, 1, { 0x00, 0x00, 0x08, 0x76, 0x42, 0x00 } },
  { /* 0x0007cUL, 0, 0UL, */ 3, 2, { 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00 } },
  { /* 0x0007dUL, 0, 0UL, */ 1, 2, { 0x00, 0x42, 0x76, 0x08, 0x00, 0x00 } },
  { /* 0x0007eUL, 0, 0UL, */ 1, 1, { 0x00, 0x04, 0x02, 0x04, 0x02, 0x00 } },
};

//static const U32 font_nglyphs = sizeof(font_data)/sizeof(glyph) - 1;

///// functions
//const U32 getNumGlyphs(void) { return font_nglyphs; }

