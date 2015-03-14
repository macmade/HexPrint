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

void DisplayPrintFile( const char * file, FILE * fp, size_t line, size_t cols, size_t rows )
{
    size_t       i;
    char       * hr;
    char       * filename;
    const char * filePart;
    size_t       size;
    
    clear();
    
    if( file == NULL || fp == NULL )
    {
        return;
    }
    
    if( cols < 50 || rows < 10 )
    {
        return;
    }
    
    fseek( fp, 0, SEEK_END );
    
    size = ( size_t )ftell( fp );
    
    fseek( fp, 0, SEEK_SET );
    
    hr       = calloc( cols + 1, 1 );
    filename = calloc( cols + 1, 1 );
    
    if( hr == NULL || filename == NULL )
    {
        goto end;
    }
    
    for( i = 0; i < cols - 1; i++ )
    {
        hr[ i ] = '-';
    }
    
    #ifdef WIN32
    filePart = strrchr( file, '\\' );
    #else
    filePart = strrchr( file, '/' );
    #endif
    
    if( filePart == NULL )
    {
        filePart = file;
    }
    else
    {
        filePart++;
    }
    
    strncpy( filename, filePart, cols - 7 );
    
    printw( "%s\n", hr );
    printw( "File: <%s>\n", filename );
    printw( "Size: %zu bytes\n", size );
    printw( "%s\n", hr );
    
    if( size == 0 )
    {
        goto end;
    }
    
    ( void )line;
    
    move( rows - 3, 0 );
    printw( "%s\n", hr );
    printw( "Press <q> to quit or navigate with the arrow keys:\n", hr );
    
    end:
    
    refresh();
    
    free( hr );
    free( filename );
}
