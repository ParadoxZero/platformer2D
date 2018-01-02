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

#ifndef _SS_PLATFORMER_ENGINE_COLLIDER
#define _SS_PLATFORMER_ENGINE_COLLIDER

#include <SDL.h>
#include <SimpleEngine.h>

/* This function will be called when a collision happens
    a -> Self
    b -> Other

    Example is a 'player' collides with 'wall'.
    check_collision(player, wall);
        => collision_routine(player, wall);
*/
typedef void( *SE_CollisionRoutine )(SE_Object *a, SE_Object *b);

struct SE_Collider {
    const SDL_Rect *geometry; /* pointer to the rect of SE_object */
    SE_Object *object;
    SE_bool is_active;
    SE_CollisionRoutine collision_routine; /* Collision Handling*/
};
typedef struct SE_Collider SE_Collider;

SE_Collider* create_collider( const SE_Object * object  );
SE_RESULT destroy_collider( SE_Collider* collider );

SE_RESULT disable_collider( SE_Collider* collider );
SE_RESULT enable_collider( SE_Collider* collider );

SDL_bool check_collision( const SE_Collider *a, const SE_Collider *b );
SDL_bool check_inside( const SE_Collider *outer, const SE_Collider *inner );

#endif // !_SS_PLATFORMER_ENGINE_COLLIDER

