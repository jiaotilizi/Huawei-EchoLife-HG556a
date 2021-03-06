/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2004 by Ralf Baechle
 *
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/pci.h>
#include <asm/gt64240.h>
#include <asm/pci_channel.h>

extern struct pci_ops titan_pci_ops;

static struct resource py_mem_resource = {
	"Titan PCI MEM", 0xe0000000UL, 0xe3ffffffUL, IORESOURCE_MEM
};

/*
 * PMON really reserves 16MB of I/O port space but that's stupid, nothing
 * needs that much since allocations are limited to 256 bytes per device
 * anyway.  So we just claim 64kB here.
 */
#define TITAN_IO_SIZE	0x0000ffffUL

static struct resource py_io_resource = {
	"Titan IO MEM", 0x00001000UL, TITAN_IO_SIZE - 1, IORESOURCE_IO,
};

static struct pci_controller py_controller = {
	.pci_ops	= &titan_pci_ops,
	.mem_resource	= &py_mem_resource,
	.mem_offset	= 0x00000000UL,
	.io_resource	= &py_io_resource,
	.io_offset	= 0x00000000UL
};

static char ioremap_failed[] __initdata = "Could not ioremap I/O port range";

static int __init pmc_yosemite_setup(void)
{
	unsigned long io_v_base;

	io_v_base = (unsigned long) ioremap(0xe0000000UL,TITAN_IO_SIZE);
	if (!io_v_base)
		panic(ioremap_failed);

	set_io_port_base(io_v_base);

	ioport_resource.end = TITAN_IO_SIZE - 1;

	register_pci_controller(&py_controller);

	return 0;
}

arch_initcall(pmc_yosemite_setup);
