//
//  asl_logger.c
//  Logger
//
//  Created by Dan Zinngrabe on 6/21/14.
//  Copyright (c) 2014 Dan Zinngrabe. All rights reserved.
//

#include <stdio.h>
#include <asl.h>

#include <CoreFoundation/CoreFoundation.h>
#include <dispatch/dispatch.h>
#include "asl_logger.h"

static void stderr_once();

static void stderr_once() {
	static dispatch_once_t onceToken    = 0L;
	dispatch_once(&onceToken, ^{
		asl_add_log_file(NULL, STDERR_FILENO);
	});
}

extern void asl_logger(int level, CFStringRef format, ...) {
	CFStringRef message =   NULL;
    
    stderr_once();
    va_list arguments;
    va_start(arguments, format);
	message = CFStringCreateWithFormatAndArguments(kCFAllocatorDefault, NULL, format, arguments);
	asl_log(NULL, NULL, level, "%s", CFStringGetCStringPtr(message, kCFStringEncodingUTF8) );
    CFRelease(message);
    va_end(arguments);
}

