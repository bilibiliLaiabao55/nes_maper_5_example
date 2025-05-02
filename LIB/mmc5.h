#ifndef __MMC5_H__
#define __MMC5_H__
void __fastcall__ set_prg_mode(unsigned char mode);
void __fastcall__ set_chr_mode(unsigned char mode);

void __fastcall__ set_prg_5113(unsigned char bankID);
void __fastcall__ set_prg_5114(unsigned char bankID);
void __fastcall__ set_prg_5115(unsigned char bankID);
void __fastcall__ set_prg_5116(unsigned char bankID);
void __fastcall__ set_prg_5117(unsigned char bankID);

void __fastcall__ set_chr_5120(unsigned char bankID);
void __fastcall__ set_chr_5121(unsigned char bankID);
void __fastcall__ set_chr_5122(unsigned char bankID);
void __fastcall__ set_chr_5123(unsigned char bankID);
void __fastcall__ set_chr_5124(unsigned char bankID);
void __fastcall__ set_chr_5125(unsigned char bankID);
void __fastcall__ set_chr_5126(unsigned char bankID);
void __fastcall__ set_chr_5127(unsigned char bankID);
void __fastcall__ set_chr_5128(unsigned char bankID);
void __fastcall__ set_chr_5129(unsigned char bankID);
void __fastcall__ set_chr_512A(unsigned char bankID);
void __fastcall__ set_chr_512B(unsigned char bankID);
void __fastcall__ set_chr_upper_bits(unsigned char id);

void __fastcall__ set_nametable_mapping(unsigned char mapping);
#endif