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

#include "C99.h"
#include "Arguments.h"
#include "Display.h"
#include "IO.h"
#include <ncurses.h>

int main( int argc, char * argv[] )
{
    MutableArgumentsRef args;
    int                 ret;
    FILE              * fp;
    
    fp   = NULL;
    args = ArgumentsCreate( argc, argv );
    
    if( ArgumentsValidate( args ) == false )
    {
        goto failure;
    }
    
    if( ArgumentsGetShowHelp( args ) )
    {
        DisplayPrintHelp();
        
        goto success;
    }
    
    if( IOGetFileSize( ArgumentsGetFilePath( args ) ) == 0 )
    {
        DisplayPrintError( "File is empty: %s", ArgumentsGetFilePath( args ) );
        
        goto failure;
    }
    
    fp = fopen( ArgumentsGetFilePath( args ), "rb" );
    
    if( fp == NULL )
    {
        DisplayPrintError( "Cannot open file for reading: %s", ArgumentsGetFilePath( args ) );
        
        goto failure;
    }
    
    DisplayStart();
    
    {
        int    c;
        size_t line;
        size_t cols;
        size_t rows;
        
        line = 0;
        c    = 0;
        
        do
        {
            cols = DisplayGetAvailableColumns();
            rows = DisplayGetAvailableRows();
            
            if( c == KEY_UP && line > 0 )
            {
                line--;
            }
            else if( c == KEY_DOWN || c == 10 )
            {
                line++;
            }   
            else if( c == KEY_PPAGE || c == 21 )
            {
                line = ( line < rows ) ? 0 : line - rows;
            }
            else if( c == KEY_NPAGE || c == 4 )
            {
                line += rows;
            }
            else if( c == 'q' )
            {
                break;
            }
            
            DisplayPrintFile
            (
                ArgumentsGetFilePath( args ),
                fp,
                &line,
                cols,
                rows
            );
        }
        while( ( c = getch() ) );
    }
    
    DisplayStop();
    
    success:
    
    ret = EXIT_SUCCESS;
    
    goto end;
        
    failure:
        
        ret = EXIT_FAILURE;
        
    end:
        
        if( fp != NULL )
        {
            fclose( fp );
        }
        
        ArgumentsDelete( args );
        
        return ret;
}
