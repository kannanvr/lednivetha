 #define __SFR_OFFSET 0
 #include <avr/io.h>

 ;extern void output_grb(u8 * ptr, u16 count)
 ;
 ; r18 = data byte
 ; r19 = 7-bit count
 ; r20 = 1 output
 ; r21 = 0 output
 ; r22 = SREG save
 ; r24:25 = 16-bit count
 ; r26:27 (X) = data pointer

 .equ      OUTBIT,   0


 .global output_grb
 output_grb:
 movw   r26, r24      ;r26:27 = X = p_buf
 movw   r24, r22      ;r24:25 = count
 in     r22, SREG     ;save SREG (global int state)
 cli                  ;no interrupts from here on, we are cycle-counting
 in     r20, PORTB
 nop
 ori    r20, (1<<OUTBIT)         ;our '1' output
 nop
 in     r21, PORTB
 nop
 andi   r21, ~(1<<OUTBIT)        ;our '0' output
 nop
 ldi    r19, 7        ;7 bit counter (8th bit is different)
 nop
 ld     r18,X+        ;get first data byte
 nop
 loop1:
 nop ; Add some extra low time
 nop ; Add some extra low time
 nop ; Add some extra low time
 nop ; Add some extra low time
 nop ; Add some extra low time
 out    PORTB, r20    ; 1   +0 start of a bit pulse
 nop
 lsl    r18           ; 1   +1 next bit into C, MSB first
 nop
 brcs   L1            ; 1/2 +2 branch if 1
 nop
 out    PORTB, r21    ; 1   +3 end hi for '0' bit (3 clocks hi)
 nop
 nop                  ; 1   +4
 nop
 bst    r18, 7        ; 1   +5 save last bit of data for fast branching
 nop
 subi   r19, 1        ; 1   +6 how many more bits for this byte?
 nop
 breq   bit8          ; 1/2 +7 last bit, do differently
 nop
 rjmp   loop1         ; 2   +8, 10 total for 0 bit
 nop
 L1:
 nop                  ; 1   +4
 nop
 bst    r18, 7        ; 1   +5 save last bit of data for fast branching
 nop
 subi   r19, 1        ; 1   +6 how many more bits for this byte
 nop
 out    PORTB, r21    ; 1   +7 end hi for '1' bit (7 clocks hi)
 nop
 brne   loop1         ; 2/1 +8 10 total for 1 bit (fall thru if last bit)
 nop
 bit8:
 ldi    r19, 7        ; 1   +9 bit count for next byte
 nop
 nop ; Add some extra low time
 nop ; Add some extra low time
 nop ; Add some extra low time
 nop ; Add some extra low time
 nop ; Add some extra low time
 out    PORTB, r20    ; 1   +0 start of a bit pulse
 nop
 brts   L2            ; 1/2 +1 branch if last bit is a 1
 nop
 nop                  ; 1   +2
 nop
 out    PORTB, r21    ; 1   +3 end hi for '0' bit (3 clocks hi)
 nop
 ld     r18, X+       ; 2   +4 fetch next byte
 nop
 sbiw   r24, 1        ; 2   +6 dec byte counter
 nop
 brne   loop1         ; 2   +8 loop back or return
 nop
 out    SREG, r22     ; restore global int flag
 nop
 ret
 L2:
 ld     r18, X+       ; 2   +3 fetch next byte
 nop
 sbiw   r24, 1        ; 2   +5 dec byte counter
 nop
 out    PORTB, r21    ; 1   +7 end hi for '1' bit (7 clocks hi)
 nop
 brne   loop1         ; 2   +8 loop back or return
 nop
 out    SREG, r22     ; restore global int flag
 ret
