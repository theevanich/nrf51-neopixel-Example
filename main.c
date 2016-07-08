#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"
#include "neopixel.h"


neopixel_strip_t m_strip;
uint8_t dig_pin_num = 0;
uint8_t leds_per_strip = 10;
uint8_t error;
uint8_t led_to_enable = 5;
uint8_t red = 255;
uint8_t green = 255;
uint8_t blue = 255;

int main(void)
{
	neopixel_init(&m_strip, dig_pin_num, leds_per_strip);
	neopixel_clear(&m_strip);


	while(true)
	{
//		error = neopixel_set_color_and_show(&m_strip, led_to_enable, red, green, blue);
//		error = neopixel_set_color_and_show(&m_strip, 2, red, green, blue);
//		error = neopixel_set_color_and_show(&m_strip, 9, red, green, blue);
//		nrf_delay_ms(100);

		for(int i = 0; i < 10; i++)
		{
			neopixel_set_color_and_show(&m_strip, i, red, green, blue);
			nrf_delay_ms(50);
			neopixel_clear(&m_strip);
			nrf_delay_ms(50);
		}
	}

	if (error) {
		//led_to_enable was not within number leds_per_strip
	}
}
