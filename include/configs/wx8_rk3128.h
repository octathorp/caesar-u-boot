/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __PS5000_RK3128_H
#define __PS5000_RK3128_H

#include <configs/rk3128_common.h>

#define CONFIG_BMP_16BPP
#define CONFIG_BMP_24BPP
#define CONFIG_BMP_32BPP

#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV 0

/*
#define ROCKCHIP_DEVICE_SETTINGS \
		"stdout=serial\0" \
		"stderr=serial\0"
*/

#define ROCKCHIP_DEVICE_SETTINGS \
		"stdout=serial,vidconsole\0" \
		"stderr=serial,vidconsole\0"

#ifndef CONFIG_SPL_BUILD

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND RKIMG_BOOTCOMMAND

#undef RKIMG_DET_BOOTDEV
#define RKIMG_DET_BOOTDEV \
	"rkimg_bootdev=" \
	"if mmc dev 1 && rkimgtest mmc 1; then " \
		"setenv devtype mmc; setenv devnum 1; echo Boot from SDCARD;" \
	"elif rksfc dev 0; then " \
		"setenv devtype spinand; setenv devnum 0; echo Boot from SPINAND;" \
	"else " \
		"setenv devtype ramdisk; setenv devnum 0;" \
	"fi; \0"

#endif

#endif
