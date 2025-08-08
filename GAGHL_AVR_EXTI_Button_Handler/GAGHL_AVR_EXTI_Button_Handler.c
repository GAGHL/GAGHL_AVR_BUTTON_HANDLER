/*
 * GAGHL_AVR_EXTIH.c
 *
 * Created: 8/7/2025 2:59:22 PM
 *  Author: GAGHL
 */ 

#include <avr/interrupt.h>
#include "GAGHL_AVR_EXTI_Button_Handler.h"
#include "GAGHL_AVR_EXTI_Pins.h"
#include <stdint.h>

volatile event_t buttonEvent[3] = {EVENT_IDLE, EVENT_IDLE, EVENT_IDLE};

void button_handler_init(void) {
	INT0_DDR &= ~(1 << INT0_BIT);
	INT1_DDR &= ~(1 << INT1_BIT);
	//INT2_DDR &= ~(1 << INT2_BIT); // INT2 just can be Rising/Falling edge Not any logical change!

	INT0_PORT |= (1 << INT0_BIT);
	INT1_PORT |= (1 << INT1_BIT);
	//INT2_PORT |= (1 << INT2_BIT); // INT2 just can be Rising/Falling edge Not any logical change!

	MCUCR &= ~((1 << ISC01) | (1 << ISC11));
	MCUCR |=  ((1 << ISC00) | (1 << ISC10));
	//MCUCSR &= ~(1 << ISC2); // INT2 just can be Rising/Falling edge Not any logical change!

	GICR |= (1 << INT0) | (1 << INT1) | (1 << INT2);

	sei();
}

ISR(INT0_vect){
	if ((INT0_PIN & (1 << INT0_BIT)) == 0) {
		buttonEvent[0] = EVENT_PRESSED; //released
	} else {
		buttonEvent[0] = EVENT_RELEASED; //pressed
	}
}

ISR(INT1_vect){
	if ((INT1_PIN & (1 << INT1_BIT)) == 0) {
		buttonEvent[1] = EVENT_PRESSED; //released
	} else {
		buttonEvent[1] = EVENT_RELEASED; //pressed
	}
}

/*
ISR(INT2_vect){
	if ((INT2_PIN & (1 << INT2_BIT)) == 0) {
		buttonEvent[2] = EVENT_PRESSED; //released
	} else {
		buttonEvent[2] = EVENT_RELEASED; //pressed
	}
}
*/

void button_handler(void) {
	for (uint8_t i = 0; i < 3; i++) {
		switch (buttonEvent[i]) {
			
			case EVENT_PRESSED:
				if (i == 0)		 button0_pressed();
				else if (i == 1) button1_pressed();
				else if (i == 2) button2_pressed();
				buttonEvent[i] = EVENT_HOLD;
			break;
			
			case EVENT_HOLD:
				if (i == 0)		 button0_hold();
				else if (i == 1) button1_hold();
				else if (i == 2) button2_hold();
			break;
			
			case EVENT_RELEASED:
				if (i == 0)		 button0_released();
				else if (i == 1) button1_released();
				else if (i == 2) button2_released();
				buttonEvent[i] = EVENT_IDLE;
			break;
			
			default:
			break;
		}
	}
}


void button0_pressed(void){
	PORTA = 0x00;
}
void button1_pressed(void){
	PORTA = 0x00;
}
void button2_pressed(void){
	PORTA = 0x00;
}

void button0_hold(void){
	PORTA = 0x01;
}
void button1_hold(void){
	PORTA = 0x02;
}
void button2_hold(void){
	PORTA = 0x04;
}

void button0_released(void){
	PORTA = 0x00;
}
void button1_released(void){
	PORTA = 0x00;
}
void button2_released(void){
	PORTA = 0x00;
}
