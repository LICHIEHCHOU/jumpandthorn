#include <stdlib.h>

#include "functionlist.h"


void moveAming(g* gPtr)
{

    // if (al_key_down(&KBstate, ALLEGRO_KEY_LEFT)) barD_x -= PADDLE_MOVE;
    if (al_key_down(&gPtr->KBstate, ALLEGRO_KEY_LEFT))
        gPtr->barD_x -= PADDLE_MOVE;

    // if (al_key_down(&KBstate, ALLEGRO_KEY_RIGHT)) barD_x += PADDLE_MOVE;
    if (al_key_down(&gPtr->KBstate, ALLEGRO_KEY_RIGHT))
        gPtr->barD_x += PADDLE_MOVE;

    // if(al_key_down(&KBstate, ALLEGRO_KEY_J) && jump)
    if(al_key_down(&gPtr->KBstate, ALLEGRO_KEY_J) && gPtr->jump)//JUMP 104
    {
        // velY = -jumpSpeed;
        gPtr->velY = -gPtr->jumpSpeed;
        // jump = false;
        gPtr->jump = false;
    }

    // if(!jump)
    if(!gPtr->jump)//jump
        // velY += gravity;
        gPtr->velY += gPtr->gravity;
    else
        // velX = 0;
        gPtr->velX = 0;

    // barD_x += velX;
    gPtr->barD_x += gPtr->velX;
    // barD_y += velY;
    gPtr->barD_y += gPtr->velY;

    // jump = (barD_y >= groundHeight);
    gPtr->jump = (gPtr->barD_y >= gPtr->groundHeight);

    // if(jump)
    if(gPtr->jump)//didnt jump
    {
        // barD_y = groundHeight;
        gPtr->barD_y = gPtr->groundHeight;
    }

    // if (al_key_down(&KBstate, ALLEGRO_KEY_SPACE)) barD_x -= PADDLE_MOVE; /*JUMP*/

    // if (barD_x < 0)
    if (gPtr->barD_x < 0)
        // barD_x =0; /* make sure the paddles don go off screen */
        gPtr->barD_x =0; /* make sure the paddles don go off screen */

    // if (barD_x > 625)
    if (gPtr->barD_x > 625)
        // barD_x =620; /* make sure the paddles don go off screen */
        gPtr->barD_x =620; /* make sure the paddles don go off screen */
}
/*void game(struct GAME* gamePtr)
{

}*/

void gameStructInit(g* gPtr)
{
    gPtr->x=100;
    gPtr->y=440;
    gPtr->jump = false;
    gPtr->jumpSpeed = 15;
    gPtr->velX = 0;
    gPtr->velY = 0;
    gPtr->gravity = 1;
    gPtr->groundHeight = 430;//change this when the screen h has been change
    gPtr->right1 = NULL;
    gPtr->right2 = NULL;
    gPtr->left1 = NULL;
    gPtr->left2 = NULL;
    gPtr->brick = NULL;
    gPtr->gthorn= NULL;
    gPtr->display = NULL;
}
