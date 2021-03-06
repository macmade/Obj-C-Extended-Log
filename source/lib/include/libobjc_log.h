/*******************************************************************************
 * Copyright (c) 2010, Jean-David Gadina www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

/*!
    @header         libobjc_log
    @abstract       Replacement of the built-in NSLog function and various log macros
    @discussion     Inluding this header will automatically replace the built-in
                    NSLog function with an extended variant. The extended
                    version includes details about the file which called NSLog
                    as well as the current process and thread. The extended
                    NSLog function outputs on stderr and on the Apple's console
                    (ASL). The console output can be controlled by defining two
                    different constants:
                        - LIBOBJC_NO_CONSOLE:   If set, log messages won't be
                                                displayed on the console, but
                                                only in stderr.
                        - LIBOBJC_CONSOLE_STD:  If set, standard log messages
                                                (like NSLog) will be printed on
                                                the console. Extended messages
                                                will still be printed on stderr.
                    This header also includes macros to log various structures
                    from the Core Foundation, displaying each member
                    explicitely.
 */

#import <Foundation/Foundation.h>

#pragma mark -- Constants

/*!
    @define         LIBOBJC_LOG
    @abstract       Enables extended log messages
    @discussion     Enables to use of extended log, replacing the built-in
                    NSLog function. Set by default when including this header,
                    so use #undef to disable.
 */
#define LIBOBJC_LOG

#pragma mark -- Types

/*!
    @typedef    libobjc_log_opt
    @abstract   Options passed to the libobjc_log log function to control the type of log to produce
    @constant   LIBOBJC_LOG_OPT_CONSOLE_EXTENDED    Extended log on stderr and on the Apple console (ASL)
    @constant   LIBOBJC_LOG_OPT_CONSOLE_STANDARD    Extended log on stderr and standard log on the Apple console (ASL)
    @constant   LIBOBJC_LOG_OPT_CONSOLE_IGNORE      Extended log on stderr and no display on the Apple console (ASL)
 */
typedef enum
{
    LIBOBJC_LOG_OPT_CONSOLE_EXTENDED    = 0,
    LIBOBJC_LOG_OPT_CONSOLE_STANDARD    = 1,
    LIBOBJC_LOG_OPT_CONSOLE_IGNORE      = 2
}
libobjc_log_opt;

#pragma mark -- Prototypes

/*!
    @function       libobjc_log
    @abstract       NSLog equivalent with extended log informations
    @param          file    The file's name
    @param          line    The file's line number
    @param          fmt     The format string
    @param          ...     The format's arguments
    @result         void
    @discussion     This function is an equivalent to the built-in NSLog
                    function, but with additionnal log informations. Printed
                    informations includes:
                        -   The file name
                        -   The line number
                        -   The process ID
                        -   The tread number and name
                        -   The time with milliseconds
 */
void libobjc_log( char * file, int line, libobjc_log_opt opt, NSString * fmt, ... );

#pragma mark -- Macros

#ifdef LIBOBJC_LOG
#if defined( LIBOBJC_LOG_NO_CONSOLE )

/*!
    @define         NSLog
    @abstract       Replaces the built-in NSLog function with extended log informations, without console ouptut
 */
#define NSLog( ... ) libobjc_log( __FILE__, __LINE__, LIBOBJC_LOG_OPT_CONSOLE_IGNORE, __VA_ARGS__ )

#else
#if defined( LIBOBJC_LOG_CONSOLE_STD )

/*!
    @define         NSLog
    @abstract       Replaces the built-in NSLog function with extended log informations, with standard console output
 */
#define NSLog( ... ) libobjc_log( __FILE__, __LINE__, LIBOBJC_LOG_OPT_CONSOLE_STANDARD, __VA_ARGS__ )

#else

/*!
    @define         NSLog
    @abstract       Replaces the built-in NSLog function with extended log informations
 */
#define NSLog( ... ) libobjc_log( __FILE__, __LINE__, LIBOBJC_LOG_OPT_CONSOLE_EXTENDED, __VA_ARGS__ )

#endif
#endif
#endif

/*!
    @define         LogPoint
    @abstract       Logs a NSPoint/CGPoint structure to the console
 */
#define LogPoint( p )       \
    NSLog                   \
    (                       \
        @"X: %f\n"          \
        @"Y: %f",           \
        p.x,                \
        p.y                 \
    )

/*!
    @define         LogSize
    @abstract       Logs a NSSize/CGSize structure to the console
 */
#define LogSize( s )        \
    NSLog                   \
    (                       \
        @"Width:  %f\n"     \
        @"Height: %f",      \
        s.width,            \
        s.height            \
    )

/*!
    @define         LogRect
    @abstract       Logs a NSRect/CGRect structure to the console
 */
#define LogRect( r )        \
    NSLog                   \
    (                       \
        @"X:      %f\n"     \
        @"Y:      %f\n"     \
        @"Width:  %f\n"     \
        @"Height: %f",      \
        r.origin.x,         \
        r.origin.y,         \
        r.size.width,       \
        r.size.height       \
    )

/*!
    @define         LogRange
    @abstract       Logs a NSRange structure to the console
 */
#define LogRange( r )       \
    NSLog                   \
    (                       \
        @"Location: %i\n"   \
        @"Length:   %i",    \
        r.location,         \
        r.length            \
    )

#ifdef TARGET_OS_IPHONE

/*!
    @define         LogEdgeInsets
    @abstract       Logs a UIEdgeInsets structure to the console
 */
#define LogEdgeInsets( e )  \
    NSLog                   \
    (                       \
        @"Top:    %f\n"     \
        @"Left:   %f\n"     \
        @"Bottom: %f\n"     \
        @"Right:  %f",      \
        e.top,              \
        e.left,             \
        e.bottom,           \
        e.right             \
    )

#endif
