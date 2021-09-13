/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <asm/gpio.h>

DECLARE_GLOBAL_DATA_PTR;

int rockchip_dnl_key_pressed(void)
{
	struct gpio_desc gpio;
	ofnode node;
	int press = false;

	node = ofnode_path("/config");
	if (!ofnode_valid(node)) {
		debug("%s: no /config node?\n", __FUNCTION__);
		return false;
	}

	if (gpio_request_by_name_nodev(node, "download,gpio", 0, &gpio, GPIOD_IS_IN)) {
		debug("%s: no download,gpio\n", __FUNCTION__);
		return false;
	}

	if (dm_gpio_is_valid(&gpio)) {
		press = !dm_gpio_get_value(&gpio);
	}

	dm_gpio_free(NULL, &gpio);
	return press;
}

int rk_board_late_init(void)
{
	struct gpio_desc gpio;
	ofnode node;

	node = ofnode_path("/config");
	if (!ofnode_valid(node)) {
		debug("%s: no /config node?\n", __FUNCTION__);
		return 0;
	}

	if (gpio_request_by_name_nodev(node, "pm-enable,gpio", 0, &gpio, GPIOD_IS_OUT | GPIOD_IS_OUT_ACTIVE)) {
		debug("%s: no pm-enable,gpio\n", __FUNCTION__);
		return 0;
	}

	dm_gpio_free(NULL, &gpio);
	return 0;
}
