/*
 * GAGHL_AVR_BUTTON_HANDLER.c
 *
 * Created: 8/7/2025 2:59:22 PM
 *  Author: GAGHL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "GAGHL_AVR_BUTTON_HANDLER.h"
#include "GAGHL_AVR_BUTTON_HANDLER_Pins.h"
#include <stdint.h>

volatile event_t buttonEvent[8] = {EVENT_IDLE};

void button_handler_init(void) {
	#if defined(__AVR_ATmega8__)  || defined(__AVR_ATmega8A__)  || \
		defined(__AVR_ATmega16__) || defined(__AVR_ATmega16A__) || \
		defined(__AVR_ATmega32__) || defined(__AVR_ATmega32A__)
	
		INT0_DDR &= ~(1 << INT0_BIT);
		INT1_DDR &= ~(1 << INT1_BIT);

		INT0_PORT |= (1 << INT0_BIT);
		INT1_PORT |= (1 << INT1_BIT);

		MCUCR &= ~((1 << ISC01) | (1 << ISC11));
		MCUCR |=  ((1 << ISC00) | (1 << ISC10));

		GICR |= (1 << INT0) | (1 << INT1);
		
	#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	
		INT0_DDR &= ~(1 << INT0_BIT);
		INT1_DDR &= ~(1 << INT1_BIT);

		INT0_PORT |= (1 << INT0_BIT);
		INT1_PORT |= (1 << INT1_BIT);

		EICRA &= ~((1 << ISC01) | (1 << ISC11));
		EICRA |=  ((1 << ISC00) | (1 << ISC10));

		EIMSK |= (1 << INT0) | (1 << INT1);
		
	#elif defined(__AVR_ATmega64__)  || defined(__AVR_ATmega64A__)  || \
		  defined(__AVR_ATmega128__) || defined(__AVR_ATmega128A__)
		
		DDRE &= ~((1 << PE4) | (1 << PE5) | (1 << PE6) | (1 << PE7));
		PORTE |=  ((1 << PE4) | (1 << PE5) | (1 << PE6) | (1 << PE7));

		EICRB &= ~((1 << ISC41) | (1 << ISC51) | (1 << ISC61) | (1 << ISC71));
		EICRB |=  ((1 << ISC40) | (1 << ISC50) | (1 << ISC60) | (1 << ISC70));

		EIMSK |= (1 << INT4) | (1 << INT5) | (1 << INT6) | (1 << INT7);
		
	#elif defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		
		DDRD &= ~((1 << PD0) | (1 << PD1) | (1 << PD2) | (1 << PD3));
		PORTD |=  ((1 << PD0) | (1 << PD1) | (1 << PD2) | (1 << PD3));

		DDRE &= ~((1 << PE4) | (1 << PE5) | (1 << PE6) | (1 << PE7));
		PORTE |=  ((1 << PE4) | (1 << PE5) | (1 << PE6) | (1 << PE7));
		
		EICRA &= ~((1 << ISC01) | (1 << ISC11) | (1 << ISC21) | (1 << ISC31));
		EICRB &= ~((1 << ISC41) | (1 << ISC51) | (1 << ISC61) | (1 << ISC71));

		EICRA |=  ((1 << ISC00) | (1 << ISC10) | (1 << ISC20) | (1 << ISC30));
		EICRB |=  ((1 << ISC40) | (1 << ISC50) | (1 << ISC60) | (1 << ISC70));
		
		EIMSK |= (1 << INT0) | (1 << INT1) | (1 << INT2) | (1 << INT3) |
		(1 << INT4) | (1 << INT5) | (1 << INT6) | (1 << INT7);
		
	#endif

	sei();
}

#ifdef INT0_PIN
ISR(INT0_vect){
	if ((INT0_PIN & (1 << INT0_BIT)) == 0) {
		buttonEvent[0] = EVENT_PRESSED; //pressed
	} else {
		buttonEvent[0] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT1_PIN
ISR(INT1_vect){
	if ((INT1_PIN & (1 << INT1_BIT)) == 0) {
		buttonEvent[1] = EVENT_PRESSED; //pressed
	} else {
		buttonEvent[1] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT2_PIN
ISR(INT2_vect){
	if ((INT2_PIN & (1 << INT2_BIT)) == 0) {
		buttonEvent[2] = EVENT_PRESSED; //pressed
	} else {
		buttonEvent[2] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT3_PIN
ISR(INT3_vect){
	if ((INT3_PIN & (1 << INT3_BIT)) == 0) {
		buttonEvent[3] = EVENT_PRESSED; //pressed
		} else {
		buttonEvent[3] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT4_PIN
ISR(INT4_vect){
	if ((INT4_PIN & (1 << INT4_BIT)) == 0) {
		buttonEvent[4] = EVENT_PRESSED; //pressed
		} else {
		buttonEvent[4] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT5_PIN
ISR(INT5_vect){
	if ((INT5_PIN & (1 << INT5_BIT)) == 0) {
		buttonEvent[5] = EVENT_PRESSED; //pressed
		} else {
		buttonEvent[5] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT6_PIN
ISR(INT6_vect){
	if ((INT6_PIN & (1 << INT6_BIT)) == 0) {
		buttonEvent[6] = EVENT_PRESSED; //pressed
		} else {
		buttonEvent[6] = EVENT_RELEASED; //released
	}
}
#endif

#ifdef INT7_PIN
ISR(INT7_vect){
	if ((INT7_PIN & (1 << INT7_BIT)) == 0) {
		buttonEvent[7] = EVENT_PRESSED; //pressed
		} else {
		buttonEvent[7] = EVENT_RELEASED; //released
	}
}
#endif

void button_handler(void) {
	for (uint8_t i = 0; i < 8; i++) {
		switch (buttonEvent[i]) {
			
			case EVENT_PRESSED:
				if (i == 0)		 button0_pressed();
				else if (i == 1) button1_pressed();
				else if (i == 2) button2_pressed();
				else if (i == 3) button3_pressed();
				else if (i == 4) button4_pressed();
				else if (i == 5) button5_pressed();
				else if (i == 6) button6_pressed();
				else if (i == 7) button7_pressed();
				buttonEvent[i] = EVENT_HOLD;
			break;
			
			case EVENT_HOLD:
				if (i == 0)		 button0_hold();
				else if (i == 1) button1_hold();
				else if (i == 2) button2_hold();
				else if (i == 3) button3_hold();
				else if (i == 4) button4_hold();
				else if (i == 5) button5_hold();
				else if (i == 6) button6_hold();
				else if (i == 7) button7_hold();
			break;
			
			case EVENT_RELEASED:
				if (i == 0)		 button0_released();
				else if (i == 1) button1_released();
				else if (i == 2) button2_released();
				else if (i == 3) button3_released();
				else if (i == 4) button4_released();
				else if (i == 5) button5_released();
				else if (i == 6) button6_released();
				else if (i == 7) button7_released();
				buttonEvent[i] = EVENT_IDLE;
			break;
			
			default:
			break;
		}
	}
}

//user override
__weak void button0_pressed(void){
	PORTA = 0x00;
}
__weak void button1_pressed(void){
	PORTA = 0x00;
}
__weak void button2_pressed(void){
	PORTA = 0x00;
}
__weak void button3_pressed(void){
	PORTA = 0x00;
}
__weak void button4_pressed(void){
	PORTA = 0x00;
}
__weak void button5_pressed(void){
	PORTA = 0x00;
}
__weak void button6_pressed(void){
	PORTA = 0x00;
}
__weak void button7_pressed(void){
	PORTA = 0x00;
}

__weak void button0_hold(void){
	PORTA = 0x01;
}
__weak void button1_hold(void){
	PORTA = 0x02;
}
__weak void button2_hold(void){
	PORTA = 0x04;
}
__weak void button3_hold(void){
	PORTA = 0x08;
}
__weak void button4_hold(void){
	PORTA = 0x10;
}
__weak void button5_hold(void){
	PORTA = 0x20;
}
__weak void button6_hold(void){
	PORTA = 0x40;
}
__weak void button7_hold(void){
	PORTA = 0x80;
}

__weak void button0_released(void){
	PORTA = 0x00;
}
__weak void button1_released(void){
	PORTA = 0x00;
}
__weak void button2_released(void){
	PORTA = 0x00;
}
__weak void button3_released(void){
	PORTA = 0x00;
}
__weak void button4_released(void){
	PORTA = 0x00;
}
__weak void button5_released(void){
	PORTA = 0x00;
}
__weak void button6_released(void){
	PORTA = 0x00;
}
__weak void button7_released(void){
	PORTA = 0x00;
}
