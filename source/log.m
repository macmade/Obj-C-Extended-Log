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

#import <Foundation/Foundation.h>

/*
 * Un-comment to disable the console output
 * The log message will only be displayed on stderr
 */
/* #define LIBOBJC_NO_CONSOLE */

/*
 * Un-comment to disable the extended console output
 * The extended log message will be displayed on stderr, and the usual one on
 * the console
 */
/* #define LIBOBJC_CONSOLE_STD */

/* Enables the extended log (NSLog replacement) */
#import "libobjc_log.h"

/*!
    @function    main
    @abstract    C main entry point
    @param       argc    The number of command line parameters
    @param       argv    An array of pointers to the command line parameters
    @result      The process exit code
 */
int main( void )
{
    NSAutoreleasePool * pool;
    
    pool  = [ NSAutoreleasePool new ];
    
    NSLog( @"hello, %@", @"world" );
    
    [ pool drain ];
    
    return 0;
}
