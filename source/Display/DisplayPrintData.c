/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  -   Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *  -   Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *  -   Neither the name of 'Jean-David Gadina' nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/*!
 * @author          Jean-David Gadina
 * @copyright       (c) 2015, Jean-David Gadina - www.xs-labs.com
 */

#include "Display.h"
#include <ncurses.h>

void DisplayPrintData( FILE * fp, size_t * line, size_t cols, size_t rows )
{
    size_t    n1;
    size_t    n2;
    size_t    i;
    size_t    j;
    size_t    c;
    size_t    end;
    size_t    pos;
    uint8_t * buf;
    uint8_t   b;
    
    if( fp == NULL )
    {
        return;
    }
    
    if( cols < 50 || rows < 1 )
    {
        return;
    }
    
    n1  = ( cols - 20 ) / 4;
    n2  = n1 * rows;
    buf = calloc( 1, n2 );
    
    if( buf == NULL )
    {
        return;
    }
    
    fseek( fp, 0, SEEK_END );
    
    end = ( size_t )ftell( fp );
    pos = n1 * *( line );
    
    fseek( fp, ( long )pos, SEEK_SET );
    
    c = fread( buf, 1, n2, fp );
    
    for( i = 0; i < rows; i++ )
    {
        if( c == 0 )
        {
            break;
        }
        
        printw( "%015X: ", n1 * ( i + *( line ) ) );
        
        for( j = 0; j < n1; j++ )
        {
            if( ( n1 * i ) + j >= c )
            {
                printw( "   " );
            }
            else
            {
                b = buf[ ( n1 * i ) + j ];
                
                printw( "%02X ", b );
            }
        }
        
        printw( "| " );
        
        for( j = 0; j < n1; j++ )
        {
            if( ( n1 * i ) + j >= c )
            {
                break;
            }
            
            b = buf[ ( n1 * i ) + j ];
            
            printw( "%c", ( isgraph( b ) ) ? b : '.' );
        }
        
        printw( "\n" );
        
        if( ( i + 1 ) * n1 >= c )
        {
            break;
        }
    }
    
    free( buf );
}
