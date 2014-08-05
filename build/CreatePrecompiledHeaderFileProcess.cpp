/**
 * This file is build first in the compilation process, unless you had defined NOPCH.
 *  This file won't be built if you had set a different cpp file to create the precompiled header file.
 *  The author's intention was to automate the process of the creation of a PCH so you wouldn't have to worry about it.
 * Instructions:
 *  Place
 *   #include <wx/wxprec.h>
 *  At the top of all of your .cpp files which use wxWidgets.  If they need something not in wx/wx.h, then place it below the above in the cpp file. e.g.:
 *   #include <wx/wxprec.h>
 *   #include <wx/thread.h>
 */
#include <wx/wxprec.h> // For compilers that support precompilation, includes "wx/wx.h".
#ifdef __BORLANDC__
    #pragma hdrstop
#endif
#ifndef WX_PRECOMP // for all others, include the necessary headers (this file is usually all you need because it includes almost all "standard" wxWidgets headers)
    #include <wx/wx.h>
#endif
#ifdef __WXMSW__ // See http://wiki.wxwidgets.org/Avoiding_Memory_Leaks
    #include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif
#if !defined(_INC_CRTDBG) || !defined(_CRTDBG_MAP_ALLOC)
    #error Debug CRT functions have not been included!
#endif