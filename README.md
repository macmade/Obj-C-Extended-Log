Obj-C Extended Log
==================

[![Build Status](https://travis-ci.org/macmade/Obj-C-Extended-Log.svg?branch=master)](https://travis-ci.org/macmade/Obj-C-Extended-Log)

About
-----

Obj-C Extended Log is a replacement library for the for the built-in NSLog() function, from the Apple Core Foundation framework.

It provides better logging informations, as well as some useful macros to help various data-structures of the Core Foundation Framework.

Documentation
-------------

### Features

The NSLog() function is often used while developing Objective-C applications to output debug informations on the console.

Unfortunately, its output is pretty basic.

For instance, the following code:

    NSArray * arr = [ NSArray arrayWithObjects: @"hello", @"world", nil ];
    NSLog( @"This is an array: %@", arr );

The following will be outputted on the console:

    2010-08-05 19:20:00.901 test[39730:903] This is an array: (
        hello,
        world
    )
    
With the Obj-C Extended Log library, the very same code will produce the following output:

    --------------------------------------------------
     Log informations:
    --------------------------------------------------
    
        - File:    ./file.m
        - Line:    42
        - PID:     170582
        - Thread:  1 - <Main>
        - Time:    2010-08-05 19:42:24.000
    
    Message:
    
    This is an array: (
        hello,
        world
    )

As you can see, it provides additional informations that can be useful for debug purpose, like the file name and line number in which the log was made, the process and thread number, etc.

The library also includes usefull macros, to help with the Core Foundation structures.  
For instance:

    NSRect rect = NSMakeRect( 0, 0, 100, 200 );

The NSRect C structure represents a rectangle. It contains two members:

 * position  
   A NSPoint structure, containing two float members: x & y
 * size  
   A NSSize structure, containing two float members: width & height

You can't pass such a structure directly to the built-in NSLog function.

But with the Obj-C Extended Log library, you can use the `LogRect` macro to automatically log each member of the structure:

    LogRect( rect );

Which will display:

    --------------------------------------------------
     Log informations:
    --------------------------------------------------
    
        - File:    ./file.m
        - Line:    42
        - PID:     170582
        - Thread:  1 - <Main>
        - Time:    2010-08-05 19:42:24.000
    
    Message:
    
    X:      0
    Y:      0
    Width:  100
    Height: 200

### Usage

The library consist of a header file (.h), and a source file (.m).  
You can either include it directly into your project, or compile it separately as a static library, linked with your binary.

To enable the extended log, you simply need to include the header file.  
You don't need to change your code, as it will replace the built-in NSLog() function.

For instance, a Objective-C main routine:

    #import <Foundation/Foundation.h>
    #import "libobj_log.h"
    
    int main( void )
    {
        NSAutoreleasePool * ap;
        
        ap = [ NSAutoreleasePool new ];
        
        NSLog( @"hello, %@", @"world" );
        
        [ ap drain ];
        
        return EXIT_SUCCESS;
    }

The extended log will be automatically enabled when including the header file.

Log informations will be displayed on `stderr`, as well as on the Apple console (Console.app), using the Apple System Logger API (ASL).

You can control what's logged on the Apple Console by defining two constants.  
These constants must be defined before including the header file:

LIBOBJC_LOG_CONSOLE_STD

    #define LIBOBJC_LOG_CONSOLE_STD
    #import "libobj_log.h"

If this is defined, the extended log informations will be displayed on `stderr`, but a standard log will be displayed on the Apple console (exactly like the built-in NSLog() function).

LIBOBJC_LOG_NO_CONSOLE

    #define LIBOBJC_LOG_NO_CONSOLE
    #import "libobj_log.h"

If this is defined, the extended log informations will be displayed on stderr, but not on the Apple console.

### Macros

	// The replacement for the built-in NSLog() function.
    // Takes a NSString * for the format, and optional arguments, depending on the format.
    NSLog( NSString * fmt, ... )
    
    // Logs a NSPoint/CGPoint structure. Members are x, y.
    LogPoint( NSPoint p )
    LogPoint( CGPoint p )
    
    // Logs a NSSize/CGSize structure. Members are width, height.
    LogSize( NSSize s )
    LogSize( CGSize s )
    
    // Logs a NSRect/CGRect structure. Members are x, y, width, height.
    LogRect( NSRect r )
    LogRect( CGRect r )
    
    // Logs a NSRange structure. Members are location, length.
    LogRange( NSRange r )
    
    // Only available for iPhone OS
    // Logs a UIEdgeInsets structure. Members are top, left, bottom, right.
    LogEdgeInsets( UIEdgeInsets e )

License
-------

Obj-C Extended Log is released under the terms of the Boost Software License - Version 1.0.

Repository Infos
----------------

    Owner:			Jean-David Gadina - XS-Labs
    Web:			www.xs-labs.com
    Blog:			www.noxeos.com
    Twitter:		@macmade
    GitHub:			github.com/macmade
    LinkedIn:		ch.linkedin.com/in/macmade/
    StackOverflow:	stackoverflow.com/users/182676/macmade