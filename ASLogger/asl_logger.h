//
//  asl_logger.h
//  Logger
//
//  Created by Dan Zinngrabe on 6/21/14.
//  Copyright (c) 2014 Dan Zinngrabe. All rights reserved.
//

#ifndef __ASL_LOGGER_H__
#define __ASL_LOGGER_H__

#include <asl.h>
#include <CoreFoundation/CoreFoundation.h>

#if PRAGMA_ONCE
#pragma once
#endif

extern void asl_logger(int level, CFStringRef format, ...);

#ifndef EmergencyLog
#define EmergencyLog(fmt, ...) asl_logger(ASL_LEVEL_EMERG, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#ifndef CriticalLog
#define CriticalLog(fmt, ...) asl_logger(ASL_LEVEL_CRIT, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#ifndef ErrorLog
#define ErrorLog(fmt, ...) asl_logger(ASL_LEVEL_ERR, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#ifndef WarningLog
#define WarningLog(fmt, ...) asl_logger(ASL_LEVEL_WARNING, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#ifndef NoticeLog
#define NoticeLog(fmt, ...) asl_logger(ASL_LEVEL_NOTICE, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#ifndef InfoLog
#define InfoLog(fmt, ...) asl_logger(ASL_LEVEL_INFO, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#ifndef DebugLog
#define DebugLog(fmt, ...) asl_logger(ASL_LEVEL_DEBUG, (__bridge CFStringRef)fmt, ##__VA_ARGS__)
#endif

#endif
