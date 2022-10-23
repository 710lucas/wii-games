/*===========================================
        GRRLIB (GX Version)
        - Template Code -

        Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <time.h>

#include "Roboto_ttf.h"
#include "cursor_png.h"

int main(int argc, char **argv) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    int jogadas = 0; //ao chegar em 9 o jogo acaba
    bool ganhou = false;
    bool perdeu = false;
    bool empate = false;
    char tabuleiro[3][3] = { {'_','_','_'}, {'_','_','_'},{'_','_','_'}};
    /*
    [0]  |  [0]  |  [0]
    -------------------
    [0]  |  [0]  |  [0]
    --------------------
    [0]  |  [0]  |  [0]
    */

    int coords_x[3] = {238, 295, 351};
    int coords_y[3] = {156, 216, 272};
    bool enemy_played = true;

    // Initialise the Wiimotes
    WPAD_Init();
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

    GRRLIB_texImg *ponteiro = GRRLIB_LoadTexture(cursor_png);
    GRRLIB_ttfFont *roboto = GRRLIB_LoadTTF(Roboto_ttf, Roboto_ttf_size);

    ir_t ir1;
    u32 wpaddown, wpadheld;

    // Loop forever
    while(1) {

        WPAD_SetVRes(0, 640, 480);
        WPAD_ScanPads();
        wpaddown = WPAD_ButtonsDown(0);
        wpadheld = WPAD_ButtonsHeld(0);


        WPAD_IR(WPAD_CHAN_0, &ir1);


        // If [PLUS] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_PLUS)  break;

        // ---------------------------------------------------------------------
        // Place your drawing code here
        GRRLIB_Rectangle(288, 156, 7, 169, 0x147878FF, true);
        GRRLIB_Rectangle(344, 156, 7, 169, 0x147878FF, true);
        GRRLIB_Rectangle(235, 209, 169, 7, 0x147878FF, true);
        GRRLIB_Rectangle(235, 265, 169, 7, 0x147878FF, true);


        if(ir1.x > 232 && ir1.y > 153 && ir1.x < 232+56 && ir1.y < 153+56 && enemy_played && !ganhou && !perdeu && tabuleiro[0][0] == '_'){
            GRRLIB_Rectangle(232, 153, 56, 56, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[0][0] = 'x';//continuar dps
                jogadas++;
            }
        }//Topo 1
        else if(ir1.x > 295 && ir1.y > 156 && ir1.x < 295+56 && ir1.y < 156+56 && enemy_played && !ganhou && !perdeu && tabuleiro[0][1] == '_'){
            GRRLIB_Rectangle(295, 156, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[0][1] = 'x';
                jogadas++;
            }
        }//Topo 2
        else if(ir1.x > 351 && ir1.y > 156&& ir1.x < 351+56 && ir1.y < 156+56 && enemy_played && !ganhou && !perdeu && tabuleiro[0][2] == '_'){
            GRRLIB_Rectangle(351, 156, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[0][2] = 'x';
                jogadas++;
            }
        }//Topo 3

        else if(ir1.x > 239 && ir1.y > 216 && ir1.x < 239+56 && ir1.y < 216+56 && enemy_played && !ganhou && !perdeu && tabuleiro[1][0] == '_'){
            GRRLIB_Rectangle(239, 216, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[1][0] = 'x';
                jogadas++;
            }
        }//meio 1
        else if(ir1.x > 295 && ir1.y > 216 && ir1.x < 295+56 && ir1.y < 216+56 && enemy_played && !ganhou && !perdeu && tabuleiro[1][1] == '_'){
            GRRLIB_Rectangle(295, 214, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[1][1] = 'x';
                jogadas++;
            }
        }//meio 2
        else if(ir1.x > 351 && ir1.y > 216 && ir1.x < 351+56 && ir1.y < 216+56 && enemy_played && !ganhou && !perdeu && tabuleiro[1][2] == '_'){
            GRRLIB_Rectangle(351, 214, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[1][2] = 'x';
                jogadas++;
            }
        }//meio 3

        else if(ir1.x > 239 && ir1.y > 272 && ir1.x < 239+56 && ir1.y < 272+56 && enemy_played && !ganhou && !perdeu && tabuleiro[2][0] == '_'){
            GRRLIB_Rectangle(239, 272, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[2][0] = 'x';
                jogadas++;
            }
        }//Baixo 1
        else if(ir1.x > 351 && ir1.y > 272 && ir1.x < 351+56 && ir1.y < 272+56 && enemy_played && !ganhou && !perdeu && tabuleiro[2][2] == '_'){
            GRRLIB_Rectangle(351, 272, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[2][2] = 'x';
                jogadas++;
            }
        }//Baixo 3
        else if(ir1.x > 295 && ir1.y > 272 && ir1.x < 295+56 && ir1.y < 272+56 && enemy_played && !ganhou && !perdeu && tabuleiro[2][1] == '_'){
            GRRLIB_Rectangle(295, 272, 50, 53, 0x1a5858FF, true);
            if(wpaddown & WPAD_BUTTON_A){
                enemy_played = false;
                tabuleiro[2][1] = 'x';
                jogadas++;
            }
        }//Baixo 2


        for(int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if(tabuleiro[i][j] == 'x')
                    GRRLIB_PrintfTTF(coords_x[j]+10, coords_y[i] - 3, roboto, "X", 50, 0x00FF00FF);
                else if(tabuleiro[i][j] == 'o')
                    GRRLIB_PrintfTTF(coords_x[j]+10, coords_y[i]- 3, roboto, "O", 50, 0xFF0000FF);
            }
        }

        if (tabuleiro[0][0] == 'x' && tabuleiro[0][1] == 'x' && tabuleiro[0][2] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[1][0] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[1][2] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[2][0] == 'x' && tabuleiro[2][1] == 'x' && tabuleiro[2][2] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[0][0] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][2] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[0][2] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][0] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[0][0] == 'x' && tabuleiro[1][0] == 'x' && tabuleiro[2][0] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[0][1] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][1] == 'x' && !ganhou){
            ganhou = true;
        }
        else if (tabuleiro[0][2] == 'x' && tabuleiro[1][2] == 'x' && tabuleiro[2][2] == 'x' && !ganhou){
            ganhou = true;
        }


        if (ganhou){
            GRRLIB_PrintfTTF(25, 50, roboto, "You won!", 50, 0xFFFFFFFF);
        }


        if (tabuleiro[0][0] == 'o' && tabuleiro[0][1] == 'o' && tabuleiro[0][2] == 'o' && !perdeu){
            perdeu = true;
        }
        else if (tabuleiro[1][0] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[1][2] == 'o' && !perdeu){
            perdeu = true;
        }
        else if (tabuleiro[2][0] == 'o' && tabuleiro[2][1] == 'o' && tabuleiro[2][2] == 'o' && !perdeu){
            perdeu = true;
        }
        else if (tabuleiro[0][0] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][2] == 'o' && !perdeu){
            perdeu = true;
        }
        else if (tabuleiro[0][2] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][0] == 'o' && !perdeu){
            perdeu = true;
        }
        else if (tabuleiro[0][0] == 'o' && tabuleiro[1][0] == 'o' && tabuleiro[2][0] == 'o' && !ganhou){
            perdeu = true;
        }
        else if (tabuleiro[0][1] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][1] == 'o' && !ganhou){
            perdeu = true;
        }
        else if (tabuleiro[0][2] == 'o' && tabuleiro[1][2] == 'o' && tabuleiro[2][2] == 'o' && !ganhou){
            perdeu = true;
        }
        if (perdeu)
            GRRLIB_PrintfTTF(25, 50, roboto, "You Lost!", 50, 0xFFFFFFFF);
        
        if(jogadas == 9 && !perdeu && !ganhou)
            empate = true;
        
        if (ganhou || perdeu || empate){
            GRRLIB_Rectangle(177, 400, 285, 53, 0xFFFFFFFF, true);
            GRRLIB_PrintfTTF(234, 400, roboto, "Restart", 50, 0xF00000FF);
            if ((wpaddown & WPAD_BUTTON_A) && ir1.x >177 && ir1.x < 177+285 && ir1.y>400 && ir1.y<400+53){ 

                jogadas = 0; //ao chegar em 9 o jogo acaba
                ganhou = false;
                perdeu = false;
                empate = false;
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        tabuleiro[i][j] = '_';
                    }
                }
                /*
                [0]  |  [0]  |  [0]
                -------------------
                [0]  |  [0]  |  [0]
                --------------------
                [0]  |  [0]  |  [0]
                */

                int coords_x[3] = {238, 295, 351};
                int coords_y[3] = {156, 216, 272};
                enemy_played = true;
            }

        }

        int tmp_x;
        int tmp_y;
        srand(time(NULL));

        while (!enemy_played && jogadas < 9 && !ganhou && !perdeu){
            int vidas = 9;
            srand(time(NULL));
            for(int i = 0; i<3 && !enemy_played; i++){
                for(int j = 0; j<3 && !enemy_played; j++){
                    if(rand()%2 == 1 && tabuleiro[i][j] =='_'){
                        tabuleiro[i][j] = 'o'; enemy_played = true; jogadas++;
                    }
                    else if(rand()%2 != 1 && tabuleiro[i][j] == '_' && vidas>0)
                        vidas--;
                }
            }
            if(vidas == 0){
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(tabuleiro[i][j] == '_'){
                            tabuleiro[i][j] = 'o'; enemy_played = true; jogadas++;
                        }
                    }
                }
            }
            srand(time(NULL));
        }

        GRRLIB_DrawImg(ir1.x, ir1.y, ponteiro, 0, 0.25, 0.25, 0xffffffff);
        // ---------------------------------------------------------------------

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
