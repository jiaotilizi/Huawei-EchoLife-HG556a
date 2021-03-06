/*
 * Common code for wl command line utility
 *
 * Copyright 2002, Broadcom Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied or
 * duplicated in any form, in whole or in part, without the prior written
 * permission of Broadcom Corporation.
 *
 * $Id: wlu.h,v 1.1 2008/08/25 06:41:55 l65130 Exp $
 */

#ifndef _wlu_h_
#define _wlu_h_

#include "wlu_cmd.h"

extern const char *av0;

/* integer output format */
extern uint8 int_fmt;

/* parse common option */
extern int wl_option(char ***pargv, char **pifname, int *phelp);
extern void wl_cmd_init(void);

/* print usage */
extern void cmd_usage(FILE *fid, cmd_t *cmd);
extern void wl_usage(FILE *fid, cmd_t *port_cmds);
extern void wl_cmds_usage(FILE *fid, cmd_t *port_cmds);

/* print helpers */
extern void wl_printlasterror(void *wl);
extern void wl_printint(int val);

/* pretty print an SSID */
extern int wl_format_ssid(char* buf, uint8* ssid, int ssid_len);

/* pretty hex print a contiguous buffer */
extern void wl_hexdump(uchar *buf, uint nbytes);

/* check driver version */
extern int wl_check(void *wl);

/* wl functions used by the ndis wl. */
extern void dump_rateset(uint8 *rates, uint count);
extern uint freq2channel(uint freq);
extern int wl_ether_atoe(const char *a, struct ether_addr *n);
extern char *wl_ether_etoa(const struct ether_addr *n);
struct ipv4_addr;	/* forward declaration */
extern int wl_atoip(const char *a, struct ipv4_addr *n);
extern char *wl_iptoa(const struct ipv4_addr *n);
extern cmd_func_t wl_int;
extern cmd_func_t wl_varint;
extern void wl_dump_raw_ie(bcm_tlv_t *ie, uint len);

extern void wl_printlasterror(void *wl);
extern bool wc_cmd_check(const char *cmd);


#ifdef BCMDLL
extern FILE *dll_fd;
#undef printf
#define printf printf_to_fprintf
extern void printf_to_fprintf(const char *fmt, ...);
#endif

/* useful macros */
#ifndef ARRAYSIZE
#define ARRAYSIZE(a)  (sizeof(a)/sizeof(a[0]))
#endif /* ARRAYSIZE */

/* buffer length needed for wl_format_ssid
 * 32 SSID chars, max of 4 chars for each SSID char "\xFF", plus NULL
 */
#define SSID_FMT_BUF_LEN 4*32+1	/* Length for SSID format string */

#define USAGE_ERROR  -1		/* Error code for Usage */
#define IOCTL_ERROR  -2		/* Error code for Ioctl failure */

/* integer output format */
#define INT_FMT_DEC	0	/* signed integer */
#define INT_FMT_UINT	1	/* unsigned integer */
#define INT_FMT_HEX	2	/* hexdecimal */

/* command line argument usage */
#define CMD_ERR	-1	/* Error for command */
#define CMD_OPT	0	/* a command line option */
#define CMD_WL	1	/* the start of a wl command */

/* Mini Option parser util */
#define MINIOPT_MAXKEY	128	/* Max options */
typedef struct miniopt {
	const char* name;	/* name for prompt in error strings */
	const char* flags;	/* set of chars that are option flags
				 * with no args
				 */
	int consumed;		/* number of argv entries cosumed in
				 * the most recent call to miniopt()
				 */
	bool opt_end;		/* at end of options since a "--" flag
				 * was encountered
				 */
	bool positional;	
	bool good_int;		/* 'val' member is the result of a sucessful
				 * strtol conversion of the option value
				 */
	char opt;		
	char key[MINIOPT_MAXKEY];	
	char* valstr;		/* positional param, or value for the option,
				 * or null if the option had
				 * no accompanying value
				 */
	int val;		/* strtol translation of valstr */
} miniopt_t;

void miniopt_init(miniopt_t *t, const char* name, const char* flags);
int miniopt(miniopt_t *t, char **argv);

#endif /* _wlu_h_ */
