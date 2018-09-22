#include "tada68.h"
#include "led.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	led_init_ports();
};

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
};

void led_init_ports(void) {
    // * Set our LED pins as output
    DDRB |= (1<<2);
}

void led_set_kb(uint8_t usb_led) {
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        PORTB &= ~(1<<2);
    } else {
        // Turn capslock off
        PORTB |= (1<<2);
    }
	led_set_user(usb_led);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
	return true;
}
