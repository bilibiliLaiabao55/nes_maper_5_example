.export _set_chr_mode, _set_chr_mode
.export _set_prg_5113, _set_prg_5114, _set_prg_5115, _set_prg_5116, _set_prg_5117
.export _set_chr_5120, _set_chr_5121, _set_chr_5122, _set_chr_5123, _set_chr_5124, _set_chr_5125, _set_chr_5126, _set_chr_5127, _set_chr_5128, _set_chr_5129, _set_chr_512A, _set_chr_512B
.export _set_chr_upper_bits
.export _set_nametable_mapping

; [A] mode
_set_prg_mode:
    sta $5100
    rts
_set_chr_mode:
    sta $5101
    rts

; [A] bankID
_set_prg_5113:
    sta $5113
    rts
_set_prg_5114:
    sta $5114
    rts
_set_prg_5115:
    sta $5115
    rts
_set_prg_5116:
    sta $5116
    rts
_set_prg_5117:
    sta $5117
    rts

_set_chr_5120:
    sta $5120
    rts
_set_chr_5121:
    sta $5121
    rts
_set_chr_5122:
    sta $5122
    rts
_set_chr_5123:
    sta $5123
    rts
_set_chr_5124:
    sta $5124
    rts
_set_chr_5125:
    sta $5125
    rts
_set_chr_5126:
    sta $5126
    rts
_set_chr_5127:
    sta $5127
    rts
_set_chr_5128:
    sta $5128
    rts
_set_chr_5129:
    sta $5129
    rts
_set_chr_512A:
    sta $512A
    rts
_set_chr_512B:
    sta $512B
    rts
_set_chr_upper_bits:
    sta $5130
    rts

_set_nametable_mapping:
    sta $5105
    rts
