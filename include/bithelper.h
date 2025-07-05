#ifndef BIT_HELPER_H
#define BIT_HELPER_H
#define NOP asm volatile ("nop\n nop\n nop\n nop\n nop\n nop\n");
#define SET_BIT(byte,bit) (byte |= _BV(bit))
#define CLEAR_BIT(byte,bit) (byte &= ~(_BV(bit)))

#define TOGGLE_BIT(byte,bit) (byte ^= _BV(bit))

#define PULSE_PIN(PORT, PIN)	\
		PORT |= _BV(PIN);		\
		NOP;					\
		PORT &= ~_BV(PIN);
#endif
