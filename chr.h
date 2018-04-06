/** Copyright 2017 Mish7913 <Mish7913@gmail.com> **/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

wchar_t * chr_to_wchr(const char * chr);
char * wchr_to_chr(const wchar_t * wchr);

wchar_t * chr_to_wchr(const char * chr) {
	char * curLocale = setlocale(LC_ALL, ""); size_t ch_dsize = mbstowcs(NULL, chr, 0) + 1;
	wchar_t * ch_dest = malloc(ch_dsize); wmemset (ch_dest, 0, ch_dsize); mbstowcs (ch_dest, chr, ch_dsize);
	setlocale(  0,   curLocale  ); return ch_dest;
}

char * wchr_to_chr(const wchar_t * wchr) {
	char * curLocale = setlocale(LC_ALL, ""); size_t ch_dsize = wcstombs(NULL, wchr, 0) + 1;
	char * ch_dest = malloc(ch_dsize); memset (ch_dest, 0, ch_dsize); wcstombs (ch_dest, wchr, ch_dsize);
	setlocale(  0,   curLocale  ); return ch_dest;
}
