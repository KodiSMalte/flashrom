/*
 * This file is part of the flashrom project.
 *
 * Copyright (C) 2000 Silicon Integrated System Corporation
 * Copyright (C) 2004 Tyan Corp
 * Copyright (C) 2005-2008 coresystems GmbH <stepan@openbios.org>
 * Copyright (C) 2006-2009 Carl-Daniel Hailfinger
 * Copyright (C) 2009 Sean Nelson <audiohacked@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

	{
		.vendor		= "ESMT",
		.name		= "F25L008A",
		.bustype	= BUS_SPI,
		.manufacture_id	= ESMT_ID,
		.model_id	= ESMT_F25L008A,
		.total_size	= 1024,
		.page_size	= 256,
		.feature_bits	= FEATURE_WRSR_EITHER,
		.tested		= TEST_OK_PREW,
		.probe		= PROBE_SPI_RDID,
		.probe_timing	= TIMING_ZERO,
		.block_erasers	=
		{
			{
				.eraseblocks = { {4 * 1024, 256} },
				.block_erase = SPI_BLOCK_ERASE_20,
			}, {
				.eraseblocks = { {64 * 1024, 16} },
				.block_erase = SPI_BLOCK_ERASE_D8,
			}, {
				.eraseblocks = { {1024 * 1024, 1} },
				.block_erase = SPI_BLOCK_ERASE_60,
			}, {
				.eraseblocks = { {1024 * 1024, 1} },
				.block_erase = SPI_BLOCK_ERASE_C7,
			}
		},
		.printlock	= SPI_PRETTYPRINT_STATUS_REGISTER_PLAIN, /* TODO: improve */
		.unlock		= SPI_DISABLE_BLOCKPROTECT,
		.write		= SPI_CHIP_WRITE1,
		.read		= SPI_CHIP_READ,
		.voltage	= {2700, 3600},
	},

	{
		.vendor		= "ESMT",
		.name		= "F25L32PA",
		.bustype	= BUS_SPI,
		.manufacture_id	= ESMT_ID,
		.model_id	= ESMT_F25L32PA,
		.total_size	= 4096,
		.page_size	= 256,
		.feature_bits	= FEATURE_WRSR_EITHER | FEATURE_OTP,
		.tested		= TEST_UNTESTED,
		.probe		= PROBE_SPI_RDID,
		.probe_timing	= TIMING_ZERO,
		.block_erasers	=
		{
			{
				.eraseblocks = { {4 * 1024, 1024} },
				.block_erase = SPI_BLOCK_ERASE_20,
			}, {
				.eraseblocks = { {64 * 1024, 64} },
				.block_erase = SPI_BLOCK_ERASE_D8,
			}, {
				.eraseblocks = { {4 * 1024 * 1024, 1} },
				.block_erase = SPI_BLOCK_ERASE_60,
			}, {
				.eraseblocks = { {4 * 1024 * 1024, 1} },
				.block_erase = SPI_BLOCK_ERASE_C7,
			}
		},
		.printlock	= SPI_PRETTYPRINT_STATUS_REGISTER_BP2_BPL,
		.unlock		= SPI_DISABLE_BLOCKPROTECT,
		.write		= SPI_CHIP_WRITE256,
		.read		= SPI_CHIP_READ,
		.voltage	= {2700, 3600},
	},

	{
		.vendor		= "ESMT",
		.name		= "F49B002UA",
		.bustype	= BUS_PARALLEL,
		.manufacture_id	= ESMT_ID,
		.model_id	= ESMT_F49B002UA,
		.total_size	= 256,
		.page_size	= 4096,
		.feature_bits	= FEATURE_EITHER_RESET,
		.tested		= TEST_UNTESTED,
		.probe		= PROBE_JEDEC,
		.probe_timing	= TIMING_ZERO,	/* Datasheet has no timing info specified */
		.block_erasers	=
		{
			{
				.eraseblocks = {
					{128 * 1024, 1},
					{96 * 1024, 1},
					{8 * 1024, 2},
					{16 * 1024, 1},
				},
				.block_erase = JEDEC_SECTOR_ERASE,
			}, {
				.eraseblocks = { {256 * 1024, 1} },
				.block_erase = JEDEC_CHIP_BLOCK_ERASE,
			}
		},
		.write		= WRITE_JEDEC1,
		.read		= READ_MEMMAPPED,
		.voltage	= {4500, 5500},
	},
	
	{
			.vendor		= "ESMT",
			.name		= "F50L1G41LB(2M)",
			.bustype	= BUS_SPI,                     /* SPI-NAND device */
			.manufacture_id	= ESMT_ID,                     /* maker code 0xC8 */
			.model_id	= ESMT_F50L1G41LB,             /* define/alias in your headers */
			.total_size	= 131072,                      /* KiB (128 MiB) */
			/* datasheet: page = 2048 + 64 spare = 2112 bytes; use main page size where appropriate */
			.page_size	= 2048,                        /* main data bytes per page */
			.feature_bits	= FEATURE_OTP | FEATURE_EITHER_RESET,
			.tested		= TEST_UNTESTED,
			.probe		= PROBE_SPI_RDID,              /* standard SPI RDID (0x9F) */
			.probe_timing	= TIMING_ZERO,
			.block_erasers	=
			{
				{
					/* 4 KiB erasable units (small blocks) */
					.eraseblocks = { {4 * 1024, 32768} }, /* 128 MiB / 4 KiB = 32768 */
					.block_erase = SPI_BLOCK_ERASE_20,    /* 0x20-style 4K erase */
				}, {
					/* 128 KiB blocks (primary NAND block size) */
					.eraseblocks = { {128 * 1024, 1024} }, /* 128 MiB / 128 KiB = 1024 */
					.block_erase = SPI_BLOCK_ERASE_D8,    /* D8h (128K) as in datasheet */
				}
			},
			.printlock	= SPI_PRETTYPRINT_STATUS_REGISTER_PLAIN,
			.unlock		= SPI_DISABLE_BLOCKPROTECT,
			/* SPI-NAND programming sequence uses PROGRAM LOAD/EXECUTE (02h/10h) + internal ECC.
			Use the standard chip read/write helpers in flashrom for SPI devices; adjust if your
			tree has dedicated SPI_NAND handlers. */
			.write		= SPI_CHIP_WRITE,
			.read		= SPI_CHIP_READ,
			.voltage	= {2700, 3600},
		},