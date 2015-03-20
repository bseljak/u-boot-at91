/*
 * GPIO Watchdog driver for Atmel SAMA5D3 processors.
 *
 * Copyright (C) 2015 Borut Seljak <borut.seljak@t-2.net>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#include <common.h>
#include <watchdog.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>

// ARP32 PA23

#define AT91_WDTPORT  AT91_PIO_PORTA
#define AT91_WDTPIN	23

void hw_watchdog_reset(void)
{
	 int gpio_state=at91_get_pio_value(AT91_WDTPORT, AT91_WDTPIN);
	 at91_set_pio_value(AT91_WDTPORT, AT91_WDTPIN, !gpio_state);
}

void hw_watchdog_init(void)
{
	at91_set_pio_output(AT91_WDTPORT, AT91_WDTPIN, 1);
}
