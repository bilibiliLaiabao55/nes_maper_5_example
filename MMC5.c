/*	simple Hello World, for cc65, for NES
 *  writing to the screen with rendering disabled
 *	using neslib
 *	Doug Fraker 2018
 */	

#include "MUSIC/famistudio_cc65.h"
#include "LIB/mmc5.h"
#include "LIB/neslib.h"
#include "LIB/nesdoug.h" 

#define BLACK 0x0f
#define DK_GY 0x00
#define LT_GY 0x10
#define WHITE 0x30
// there's some oddities in the palette code, black must be 0x0f, white must be 0x30
 
 
 
#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
// all variables should be global for speed
// zeropage global is even faster

unsigned char pad; 
unsigned char pad_new; 
unsigned char font_index; 
unsigned char song_index; 
unsigned char paused; 
unsigned char i;



const unsigned char text1[]="HELLO WORLD!"; // zero terminated c string
const unsigned char text2[]="SONG INDEX:"; // zero terminated c string
const unsigned char text3[]="FONT INDEX:"; // zero terminated c string

const char palette[]={
BLACK, DK_GY, LT_GY, WHITE,
0,0,0,0,
0,0,0,0,
0,0,0,0
}; 



	

void main (void) {
	
	ppu_off(); // screen off

	pal_bg(palette); //	load the BG palette
		
	// set a starting point on the screen
	// vram_adr(NTADR_A(x,y));
	vram_adr(NTADR_A(10,14)); // screen is 32 x 30 tiles

	i = 0;
	while(text1[i]){
		vram_put(text1[i]); // this pushes 1 char to the screen
		++i;
	}	
	vram_adr(NTADR_A(9,15)); // screen is 32 x 30 tiles
	i = 0;
	while(text2[i]){
		vram_put(text2[i]); // this pushes 1 char to the screen
		++i;
	}	
	vram_adr(NTADR_A(9,16)); // screen is 32 x 30 tiles
	i = 0;
	while(text3[i]){
		vram_put(text3[i]); // this pushes 1 char to the screen
		++i;
	}	
	vram_adr(NTADR_C(11,14)); // screen is 32 x 30 tiles
	i = 0;
	while(text1[i]){
		vram_put(text1[i]); // this pushes 1 char to the screen
		++i;
	}
	// vram_adr and vram_put only work with screen off
	// NOTE, you could replace everything between i = 0; and here with...
	// vram_write(text,sizeof(text));
	famistudio_music_play(0);
	ppu_on_all(); //	turn on screen
	ppu_wait_nmi();
	set_vram_buffer();
	while (1){
		// infinite loop
		// game code can go here later.
		pad = pad_poll(0);
		pad_new = get_pad_new(0);
		one_vram_buffer(song_index+0x30, NTADR_A(21, 15));
		one_vram_buffer(font_index+0x30, NTADR_A(21, 16));
		if(pad_new & PAD_A){
			++font_index;
			if(font_index == 4)font_index = 0;
			set_chr_5120(font_index * 4);
			set_chr_5121(font_index * 4 + 1);
			set_chr_5122(font_index * 4 + 2);
			set_chr_5123(font_index * 4 + 3);
		}
		if((pad_new & PAD_B)&&(!paused)){
			++song_index;
			if(song_index == 2)song_index = 0;
			famistudio_music_stop();
			famistudio_music_play(song_index);
		}
		if(pad_new & PAD_START){
			paused = !paused;
			famistudio_music_pause(paused);
		}
		ppu_wait_nmi();
	}
}
	
	