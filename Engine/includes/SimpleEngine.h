/*
 *
 *   MIT License
 *
 *   Copyright (c) 2017 Sidhin S Thomas
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#ifndef _SIMPLE_ENGINE_MAIN_
#define _SIMPLE_ENGINE_MAIN_

#include <SimpleEngineConfig.h>
#include <SDL.h>

#define SE_SUCCESS SDL_TRUE
#define SE_FAIL SDL_FALSE
typedef SDL_bool SE_RESULT;
typedef SDL_bool SE_bool;

/* 
    This is the function that wil draw the object within the confines
    
    *Note*: The confines is not enforced. Hence it is the responsibility of function
    to maintain the integrity.

    Example -> If the shape is a rectangle:
        void draw(int x, int y, int w, int h){
            SE_DrawRect(x,y,w,h);
        }
*/
typedef void( *SE_DrawDef )(int x, int y, int w, int h);

/* The basic object which will be*/
typedef struct SE_SimpleObject {
    SDL_Rect location; /* A rect object that will maintain the object position and confines*/
    SDL_Color color;   /* Color with which the object should be drawn */
    SE_DrawDef texure; /* The shape of the object */
}SE_Object;

#endif // !_SIMPLE_ENGINE_MAIN_

