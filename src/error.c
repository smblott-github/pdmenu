/*
 * Error routines
 */

/* 
 * Copyright (c) 1997 by Joey Hess (joey@kite.ml.org) and William Thompson 
 * (wakko@kite.ml.org)
 * All rights reserved. See COPYING for full copyright information (GPL).
 */

#include "global.h"
#include "mouse.h"
#include "error.h"
#include "screen.h"
#include <stdio.h>
#include <stdarg.h>

/* Display an error. The parameters work like printf() */
void Error(const char *fmt, ...) {
	va_list arglist;

#ifdef GPM_SUPPORT
	EndMouse();
#endif
	Screen_Reset();

	va_start(arglist, fmt);
	fprintf(stderr, ERROR_HEADER);
	vfprintf(stderr, fmt, arglist);
	fprintf(stderr, "\n");
	va_end(arglist);

	exit(1);
}