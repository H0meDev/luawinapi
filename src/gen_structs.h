//////////////////////////////////////////////////////////////////////////
/**

  luawinapi - winapi wrapper for Lua
  Copyright (C) 2011 Klaus Oberhofer. See copyright notice in
  LICENSE file
  
  !!! This file is generated by gen-w32api.lua  !!!

*/////////////////////////////////////////////////////////////////////////

#pragma once

#include <windows.h>

#include "luaaux.h"

#include "luacwrap.h"
#include "wndproc.h"
#ifdef LUACE_USE_AYGSHELL
#include <aygshell.h>
#endif

int winapi_GetLastError( lua_State *L );
int winapi_SetLastError( lua_State *L );
int winapi_GetModuleHandleW( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_OutputDebugStringA( lua_State *L );
#endif
int winapi_OutputDebugStringW( lua_State *L );
int winapi_GetVersionExW( lua_State *L );
int winapi_CreateProcessW( lua_State *L );
int winapi_Sleep( lua_State *L );
int winapi_CreateMutexW( lua_State *L );
int winapi_CreateEventW( lua_State *L );
int winapi_OpenEventW( lua_State *L );
int winapi_CreateSemaphoreW( lua_State *L );
int winapi_SetEvent( lua_State *L );
int winapi_ResetEvent( lua_State *L );
int winapi_PulseEvent( lua_State *L );
int winapi_ReleaseSemaphore( lua_State *L );
int winapi_ReleaseMutex( lua_State *L );
int winapi_WaitForSingleObject( lua_State *L );
int winapi_GetExitCodeThread( lua_State *L );
int winapi_GetExitCodeProcess( lua_State *L );
int winapi_RegisterClassW( lua_State *L );
int winapi_UnregisterClassW( lua_State *L );
int winapi_GetClassInfoW( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_RegisterClassExW( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetClassInfoExW( lua_State *L );
#endif
int winapi_CreateWindowExW( lua_State *L );
int winapi_GetDesktopWindow( lua_State *L );
int winapi_IsWindow( lua_State *L );
int winapi_IsWindowVisible( lua_State *L );
int winapi_IsWindowEnabled( lua_State *L );
int winapi_IsChild( lua_State *L );
int winapi_DestroyWindow( lua_State *L );
int winapi_ShowWindow( lua_State *L );
int winapi_EnableWindow( lua_State *L );
int winapi_UpdateWindow( lua_State *L );
int winapi_RedrawWindow( lua_State *L );
int winapi_SetParent( lua_State *L );
int winapi_GetParent( lua_State *L );
int winapi_FindWindowW( lua_State *L );
int winapi_SetActiveWindow( lua_State *L );
int winapi_GetActiveWindow( lua_State *L );
int winapi_GetKeyState( lua_State *L );
int winapi_GetAsyncKeyState( lua_State *L );
int winapi_DrawMenuBar( lua_State *L );
int winapi_CreateMenu( lua_State *L );
int winapi_CreatePopupMenu( lua_State *L );
int winapi_DestroyMenu( lua_State *L );
int winapi_CheckMenuItem( lua_State *L );
int winapi_EnableMenuItem( lua_State *L );
int winapi_GetSubMenu( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_GetMenuItemID( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetMenuItemCount( lua_State *L );
#endif
int winapi_InsertMenuW( lua_State *L );
int winapi_AppendMenuW( lua_State *L );
int winapi_RemoveMenu( lua_State *L );
int winapi_DeleteMenu( lua_State *L );
int winapi_TrackPopupMenu( lua_State *L );
int winapi_TrackPopupMenuEx( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_InsertMenuItemW( lua_State *L );
#endif
int winapi_GetMenuItemInfoW( lua_State *L );
int winapi_SetMenuItemInfoW( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_IsMenu( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_CloseWindow( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetMenuItemBitmaps( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetMenuCheckMarkDimensions( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_ModifyMenuW( lua_State *L );
#endif
int winapi_MoveWindow( lua_State *L );
int winapi_SetWindowPos( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_GetWindowPlacement( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetWindowPlacement( lua_State *L );
#endif
int winapi_BringWindowToTop( lua_State *L );
int winapi_GetForegroundWindow( lua_State *L );
int winapi_SetForegroundWindow( lua_State *L );
int winapi_SetFocus( lua_State *L );
int winapi_GetFocus( lua_State *L );
int winapi_SwapMouseButton( lua_State *L );
int winapi_GetMessagePos( lua_State *L );
int winapi_GetMessageTime( lua_State *L );
int winapi_GetMessageExtraInfo( lua_State *L );
int winapi_SetMessageExtraInfo( lua_State *L );
int winapi_GetMessageW( lua_State *L );
int winapi_PostMessageW( lua_State *L );
int winapi_PostThreadMessageW( lua_State *L );
int winapi_SendMessageW( lua_State *L );
int winapi_PeekMessageW( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_WaitMessage( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_WaitForInputIdle( lua_State *L );
#endif
int winapi_TranslateMessage( lua_State *L );
int winapi_DispatchMessageW( lua_State *L );
int winapi_IsDialogMessageW( lua_State *L );
int winapi_CreateAcceleratorTableW( lua_State *L );
int winapi_TranslateAcceleratorW( lua_State *L );
int winapi_DefWindowProcW( lua_State *L );
int winapi_CallWindowProcW( lua_State *L );
int winapi_GetWindowLongW( lua_State *L );
int winapi_SetWindowLongW( lua_State *L );
int winapi_PostQuitMessage( lua_State *L );
int winapi_GetDC( lua_State *L );
int winapi_GetDCEx( lua_State *L );
int winapi_GetWindowDC( lua_State *L );
int winapi_ReleaseDC( lua_State *L );
int winapi_BeginPaint( lua_State *L );
int winapi_EndPaint( lua_State *L );
int winapi_InvalidateRect( lua_State *L );
int winapi_ValidateRect( lua_State *L );
int winapi_GetClientRect( lua_State *L );
int winapi_GetWindowRect( lua_State *L );
int winapi_ClientToScreen( lua_State *L );
int winapi_ScreenToClient( lua_State *L );
int winapi_MapWindowPoints( lua_State *L );
int winapi_GetCursorPos( lua_State *L );
int winapi_GetCapture( lua_State *L );
int winapi_SetCapture( lua_State *L );
int winapi_ReleaseCapture( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_AdjustWindowRect( lua_State *L );
#endif
int winapi_AdjustWindowRectEx( lua_State *L );
int winapi_MessageBoxW( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_MessageBoxExW( lua_State *L );
#endif
int winapi_MessageBeep( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_Beep( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetTopWindow( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetLastActivePopup( lua_State *L );
#endif
int winapi_GetWindow( lua_State *L );
int winapi_RegisterHotKey( lua_State *L );
int winapi_UnregisterHotKey( lua_State *L );
#if (defined(UNDER_CE))
int winapi_AllKeys( lua_State *L );
#endif
int winapi_GetSysColor( lua_State *L );
int winapi_GetSysColorBrush( lua_State *L );
int winapi_DrawFocusRect( lua_State *L );
int winapi_DrawEdge( lua_State *L );
int winapi_DrawFrameControl( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_DrawCaption( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_DrawAnimatedRects( lua_State *L );
#endif
int winapi_DrawTextW( lua_State *L );
int winapi_FillRect( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_FrameRect( lua_State *L );
#endif
int winapi_InvertRect( lua_State *L );
int winapi_LoadImageW( lua_State *L );
int winapi_LoadCursorW( lua_State *L );
int winapi_SetCursor( lua_State *L );
int winapi_DeleteObject( lua_State *L );
int winapi_GetObjectW( lua_State *L );
int winapi_GetObjectType( lua_State *L );
int winapi_GetStockObject( lua_State *L );
int winapi_SelectObject( lua_State *L );
int winapi_CreateCompatibleDC( lua_State *L );
int winapi_DeleteDC( lua_State *L );
int winapi_ExcludeClipRect( lua_State *L );
int winapi_IntersectClipRect( lua_State *L );
int winapi_GetCurrentObject( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_FrameRgn( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_InvertRgn( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_PaintRgn( lua_State *L );
#endif
int winapi_SetBkColor( lua_State *L );
int winapi_GetBkColor( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_SetDCBrushColor( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetDCBrushColor( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetDCPenColor( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_GetDCPenColor( lua_State *L );
#endif
int winapi_SetBkMode( lua_State *L );
int winapi_GetBkMode( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_SetMapMode( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetPolyFillMode( lua_State *L );
#endif
int winapi_SetTextColor( lua_State *L );
int winapi_SetTextAlign( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_SetTextJustification( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_PtVisible( lua_State *L );
#endif
int winapi_RectVisible( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_SetViewportExtEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetViewportOrgEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetWindowExtEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_SetWindowOrgEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_OffsetViewportOrgEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_OffsetWindowOrgEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_ScaleViewportExtEx( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_ScaleWindowExtEx( lua_State *L );
#endif
int winapi_CreatePen( lua_State *L );
int winapi_CreatePenIndirect( lua_State *L );
int winapi_CreatePatternBrush( lua_State *L );
int winapi_CreateSolidBrush( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_CreateHatchBrush( lua_State *L );
#endif
int winapi_CreateFontIndirectW( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_CreateFontW( lua_State *L );
#endif
int winapi_GetTextExtentExPointW( lua_State *L );
int winapi_GetTextExtentPoint32W( lua_State *L );
int winapi_CreateRectRgn( lua_State *L );
int winapi_CreateRectRgnIndirect( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_CreateRoundRectRgn( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_CreateEllipticRgn( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_CreateEllipticRgnIndirect( lua_State *L );
#endif
int winapi_EqualRgn( lua_State *L );
int winapi_CombineRgn( lua_State *L );
int winapi_OffsetRgn( lua_State *L );
int winapi_SetRectRgn( lua_State *L );
int winapi_PtInRegion( lua_State *L );
int winapi_RectInRegion( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_BeginPath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_CloseFigure( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_EndPath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_FillPath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_FlattenPath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_PathToRegion( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_StrokeAndFillPath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_StrokePath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_WidenPath( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_Arc( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_ArcTo( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_Chord( lua_State *L );
#endif
int winapi_LineTo( lua_State *L );
int winapi_MoveToEx( lua_State *L );
int winapi_Ellipse( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_Pie( lua_State *L );
#endif
int winapi_Rectangle( lua_State *L );
int winapi_RoundRect( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_ExtFloodFill( lua_State *L );
#endif
int winapi_FillRgn( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_FloodFill( lua_State *L );
#endif
int winapi_BitBlt( lua_State *L );
int winapi_PatBlt( lua_State *L );
int winapi_StretchBlt( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_TransparentBlt( lua_State *L );
#endif
#if (!defined(UNDER_CE))
int winapi_TextOutW( lua_State *L );
#endif
int winapi_ExtTextOutW( lua_State *L );
#if (defined(USE_OPENGL))
int winapi_wglCopyContext( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglCreateContext( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglCreateLayerContext( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglDeleteContext( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglGetCurrentContext( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglGetCurrentDC( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglMakeCurrent( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglShareLists( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglUseFontBitmapsA( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglUseFontBitmapsW( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_SwapBuffers( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglRealizeLayerPalette( lua_State *L );
#endif
#if (defined(USE_OPENGL))
int winapi_wglSwapLayerBuffers( lua_State *L );
#endif
int winapi_InitCommonControls( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_ImageList_LoadImageW( lua_State *L );
#endif
int winapi_ImageList_AddMasked( lua_State *L );
int winapi_GetOpenFileNameW( lua_State *L );
int winapi_GetSaveFileNameW( lua_State *L );
int winapi_ChooseColor( lua_State *L );
int winapi_CommDlgExtendedError( lua_State *L );
#if (!defined(UNDER_CE))
int winapi_PrintDlgW( lua_State *L );
#endif
int winapi_DrawXorBar( lua_State *L );
#if (defined(UNDER_CE))
int winapi_RequestPowerNotifications( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_StopPowerNotifications( lua_State *L );
#endif
#if (defined(USE_MSGQUEUE))
int winapi_CreateMsgQueue( lua_State *L );
#endif
#if (defined(USE_MSGQUEUE))
int winapi_OpenMsgQueue( lua_State *L );
#endif
#if (defined(USE_MSGQUEUE))
int winapi_ReadMsgQueue( lua_State *L );
#endif
#if (defined(USE_MSGQUEUE))
int winapi_WriteMsgQueue( lua_State *L );
#endif
#if (defined(USE_MSGQUEUE))
int winapi_GetMsgQueueInfo( lua_State *L );
#endif
#if (defined(USE_MSGQUEUE))
int winapi_CloseMsgQueue( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHInitExtraControls( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHInitDialog( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHCreateMenuBar( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHFindMenuBar( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHHandleWMActivate( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHHandleWMSettingChange( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHFullScreen( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHDoneButton( lua_State *L );
#endif
#if (defined(USE_AYGSHELL))
int winapi_SHSetAppKeyWndAssoc( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_Create( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_Show( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_AddBitmap( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_InsertComboBox( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_InsertMenubar( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_InsertMenubarEx( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_DrawMenuBar( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_GetMenu( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_AddAdornments( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_AlignAdornments( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_CommandBar_Height( lua_State *L );
#endif
#if (defined(USE_COMMANDBAR))
int winapi_IsCommandBarMessage( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrEstablishConnection( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrEstablishConnectionSync( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrConnectionStatus( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrReleaseConnection( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrSetConnectionPriority( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrMapURL( lua_State *L );
#endif
#if (defined(UNDER_CE))
int winapi_ConnMgrApiReadyEvent( lua_State *L );
#endif

LUA_API int luaopen_winapi(lua_State *L);
