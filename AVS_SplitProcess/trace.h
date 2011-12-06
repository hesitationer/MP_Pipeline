#pragma once

#ifdef _DEBUG

#define __TEXT(x) L##x

#ifndef TRACE_PREFIX
#define TRACE_PREFIX __TEXT("AVS_SplitProcess ")
#endif

#ifndef TRACE_COMPONENT
#define TRACE_COMPONENT __TEXT("")
#endif


void _trace(wchar_t *format, ...);
void _trace_hr( const wchar_t* strFile, DWORD dwLine, const wchar_t* strFunction, HRESULT hr, const wchar_t* strMsg );
void _trace_hr( const wchar_t* strFile, DWORD dwLine, const wchar_t* strFunction, HRESULT hr, const wchar_t* strMsg, const wchar_t* strMsg2 );

#define TRACE(format, ...) _trace(TRACE_PREFIX TRACE_COMPONENT __TEXT(":") __TEXT(format), __VA_ARGS__)
#define TRACE_HR(hr, msg) _trace_hr( __TEXT(__FILE__), (DWORD)__LINE__, __TEXT(__FUNCTION__), hr, msg )
#define TRACE_HR2(hr, msg, msg2) _trace_hr( __TEXT(__FILE__), (DWORD)__LINE__, __TEXT(__FUNCTION__), hr, msg, msg2 )
#else
#define TRACE(...) 
#define TRACE_HR(...) 
#define TRACE_HR2(...) 
#endif