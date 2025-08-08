/*
 * GAGHL_AVR_EXTIH.h
 *
 * Created: 8/7/2025 2:58:58 PM
 *  Author: GAGHL
 */ 


#ifndef GAGHL_AVR_EXTI_Button_Handler_H_
#define GAGHL_AVR_EXTI_Button_Handler_H_

#define __weak __attribute__((weak))

typedef enum {
	EVENT_IDLE,
	EVENT_PRESSED,
	EVENT_HOLD,
	EVENT_RELEASED
} event_t;

void button_handler_init(void);

void button0_pressed(void);
void button1_pressed(void);
void button2_pressed(void);

void button0_released(void);
void button1_released(void);
void button2_released(void);

void button0_hold(void);
void button1_hold(void);
void button2_hold(void);

void button_handler(void);


#endif /* GAGHL_AVR_EXTI_Button_Handler_H_ */