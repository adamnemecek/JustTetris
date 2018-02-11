// 
// Filename: tetris_types.h
// Created: 2018-02-09 16:41:11 +0100
// Author: Felix Nared
//

#ifndef TETRIS_TYPES_H
#define TETRIS_TYPES_H

#include <stdbool.h>

// -------------------------------------------------------------
// Break for my auto complete in emacs
//
#define J_BREAK;
typedef int jBreak;
typedef int iBreak;
typedef int uBreak;
typedef int cBreak;
// -------------------------------------------------------------


typedef struct
{
	int x;
	int y;
} jsVec2i;

typedef struct
{
	float x;
	float y;
} jsVec2f;

typedef struct
{
	int x;
	int y;
	int z;
} jsVec3i;

typedef struct
{
	float x;
	float y;
	float z;	
} jsVec3f;

int js_vec2i_equal(jsVec2i a, jsVec2i b);
int js_vec2f_equal(jsVec2f a, jsVec2f b);
int js_vec3i_equal(jsVec3i a, jsVec3i b);
int js_vec3f_equal(jsVec3f a, jsVec3f b);

jsVec2i js_vec2i_add(jsVec2i a, jsVec2i b);
jsVec2f js_vec2f_add(jsVec2f a, jsVec2f b);
jsVec3i js_vec3i_add(jsVec3i a, jsVec3i b);
jsVec3f js_vec3f_add(jsVec3f a, jsVec3f b);


typedef struct
{
	float r;
	float g;
	float b;
} jsColor;


typedef struct
{
	int color;
	int status;
	jsVec2i position;
} jsBlock;

bool js_block_is_empty(jsBlock block);
jsColor js_block_color(jsBlock block);


#define JS_BOARD_ROW_AMOUNT 20
#define JS_BOARD_COLUMN_AMOUNT 10
#define JS_BOARD_BLOCK_AMOUNT JS_BOARD_ROW_AMOUNT * JS_BOARD_COLUMN_AMOUNT

typedef struct
{
	jsBlock blocks[JS_BOARD_COLUMN_AMOUNT];
} jsRow;

typedef struct
{
	jsRow *rows[JS_BOARD_ROW_AMOUNT];
} jsBoard;

unsigned js_row_positions(const jsRow *row, jsVec2i *des);
bool js_row_full(const jsRow *row);
unsigned js_board_positions(const jsBoard *board, jsVec2i *des);
unsigned js_board_indicies(const jsBoard *board, unsigned *des);


#define JS_SHAPE_BLOCK_AMOUNT 4

typedef struct
{
	jsVec2i offset;
	jsBlock blocks[JS_SHAPE_BLOCK_AMOUNT];
} jsShape;

typedef enum {
	jsShapeFormationO = 0x20000000,
	jsShapeFormationI = 0x40000000,
	jsShapeFormationS = 0x60000000,
	jsShapeFormationZ = 0x80000000,
	jsShapeFormationL = 0xA0000000,
	jsShapeFormationJ = 0xC0000000,
	jsShapeFormationT = 0xE0000000,
} jsShapeFormation;

void js_set_shape(jsShape *shape, jsShapeFormation form, jsVec2i offset);
jsShapeFormation js_get_shape_formation(const jsShape *shape);
unsigned js_shape_positions(const jsShape *shape, jsVec2i *des);	


#endif /* TETRIS_TYPES_H */
