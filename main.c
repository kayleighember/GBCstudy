#include <gb/gb.h>
#include <stdio.h>
#include "background.c"
#include "backgroundtile.c"
#include "bubbles.c"

void main(){
    UINT8 currentspriteindex = 0;     //start with the first tile
    set_bkg_data(0, 0, backgroundtile);
    set_bkg_tiles(0, 0, 20, 18, background);

    SHOW_BKG;
    DISPLAY_ON;

    set_sprite_data(0, 6, bubbles);     //start at begin of bubbles sprite, load 6 tiles from it
    set_sprite_tile(0, 0);              //first sprite, load from first tile in sprite
    move_sprite(0, 88, 78);             //position
    SHOW_SPRITES;

    while(1){
        currentspriteindex++;
        if (currentspriteindex > 5){
            currentspriteindex = 0;
        }
        set_sprite_tile(0, currentspriteindex);
        delay(500);
    }
}