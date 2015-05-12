//////////////////////////////////////////////////////////////////////////
/**

  luawinapi - winapi wrapper for Lua
  Copyright (C) 2011 Klaus Oberhofer. See copyright notice in
  LICENSE file
  
  !!! This file is generated by gen-w32api.lua  !!!

*/////////////////////////////////////////////////////////////////////////

#include <windows.h>

#ifdef USE_AYGSHELL
#include <aygshell.h>
#endif

#include "gen_abstractions.h"
#include "gen_structs.h"

// used to identify the type
const char* DC_Typename = "DC";

// push on stack
int lua_pushDC( lua_State *L, HDC hdl )
{
  if (NULL == hdl)
  {
    // return nil
    return 0;
  }

  // lookup handle in handle map
  luaL_getmetatable(L, DC_Typename);
  lua_pushstring(L, "$Handles");
  lua_rawget(L, -2);                      // stack: $Handles | metatable

  lua_pushlightuserdata(L, hdl);
  lua_rawget(L, -2);                      // stack: nil/object | $Handles | metatable

  if (lua_isnil(L, -1))
  {
    HDC* ud;
  
    // pop nil value
    lua_pop(L, 1);

    // push userdata
    ud = (HDC*)lua_newuserdata(L, sizeof(HDC));
    *ud = hdl;                              // stack: object | $Handles | metatable

    // set metatable
    lua_pushvalue(L, -3);
    lua_setmetatable(L, -2);

    // push key/value for lookup table
    lua_pushlightuserdata(L, hdl);
    lua_pushvalue(L, -2);                 // stack: object |  key  | object | $Handles | metatable

    // add item to lookup table
    lua_rawset(L, -4);                    // stack: object | $Handles | metatable
  }

  // cleanup stack (remove $Handles | metatable)
  lua_remove(L, -2);
  lua_remove(L, -2);

  return 1;
}

// get from stack
HDC lua_toDC( lua_State *L, int idx )
{
  HDC v = 0;
  switch (lua_type(L, idx))
  {
    case LUA_TNIL:
      {
      }
      break;
    case LUA_TLIGHTUSERDATA:
      {
        v = (HDC)lua_touserdata(L, idx);
      }
      break;
    case LUA_TNUMBER:
      {
        v = (HDC)lua_tointeger(L, idx);
      }
      break;
    case LUA_TUSERDATA:
      {
        HDC* ud  = (HDC*)luaL_checkudata(L, idx, DC_Typename);
        v = *ud;
      }
      break;
    default:
      {
        luaL_typerror(L, idx, "DC (handle)");
      }
      break;
  }
  return v;
}

// implements __index metamethod (for .handle attribute)
static int DC_index(lua_State *L)
{
  HDC* ud  = (HDC*)luaL_checkudata(L, 1, DC_Typename);

  const char* stridx = lua_tolstring(L, 2, NULL);

  // check for .handle
  if (0 == strcmp(stridx, "handle"))
  {
    lua_pushlightuserdata(L, *ud);
    return 1;
  }
  else
  {
    luaL_getmetafield(L, 1, stridx);
  }

  return 1;
}

// to wrap handle in an object
static int DC_wrap(lua_State *L)

{
  HDC handle;

  if (lua_isnil(L, -1))
  {
   lua_pushnil(L);
  }
  else if (lua_islightuserdata(L, -1))
  {
    HDC handle = 0;
    handle = (HDC)(lua_touserdata(L, -1));
    return lua_pushDC(L, handle);
  }
  else if (lua_isuserdata(L, -1))
  {
    HDC* ud  = (HDC*)luaL_checkudata(L, -1, DC_Typename);
    lua_pushvalue(L, -1);
    return 1;
  }
  
  handle = 0;
  if (lua_isnumber(L, -1))
  {
    handle = (HDC)lua_tointeger(L, -1);
  }
  
  return lua_pushDC(L, handle);
}


static const struct luaL_reg DC_Methods[ ] = {
  { "__index", DC_index},
  { "wrap", DC_wrap },
  { "DrawFocusRect",  winapi_DrawFocusRect },
  { "DrawEdge",  winapi_DrawEdge },
  { "DrawFrameControl",  winapi_DrawFrameControl },
  { "DrawTextW",  winapi_DrawTextW },
  { "FillRect",  winapi_FillRect },
#if (!defined(UNDER_CE))
  { "FrameRect",  winapi_FrameRect },
#endif
  { "InvertRect",  winapi_InvertRect },
  { "SelectObject",  winapi_SelectObject },
  { "CreateCompatibleDC",  winapi_CreateCompatibleDC },
  { "DeleteDC",  winapi_DeleteDC },
  { "ExcludeClipRect",  winapi_ExcludeClipRect },
  { "IntersectClipRect",  winapi_IntersectClipRect },
  { "GetCurrentObject",  winapi_GetCurrentObject },
#if (!defined(UNDER_CE))
  { "FrameRgn",  winapi_FrameRgn },
#endif
#if (!defined(UNDER_CE))
  { "InvertRgn",  winapi_InvertRgn },
#endif
#if (!defined(UNDER_CE))
  { "PaintRgn",  winapi_PaintRgn },
#endif
  { "SetBkColor",  winapi_SetBkColor },
  { "GetBkColor",  winapi_GetBkColor },
#if (!defined(UNDER_CE))
  { "SetDCBrushColor",  winapi_SetDCBrushColor },
#endif
#if (!defined(UNDER_CE))
  { "GetDCBrushColor",  winapi_GetDCBrushColor },
#endif
#if (!defined(UNDER_CE))
  { "SetDCPenColor",  winapi_SetDCPenColor },
#endif
#if (!defined(UNDER_CE))
  { "GetDCPenColor",  winapi_GetDCPenColor },
#endif
  { "SetBkMode",  winapi_SetBkMode },
  { "GetBkMode",  winapi_GetBkMode },
#if (!defined(UNDER_CE))
  { "SetMapMode",  winapi_SetMapMode },
#endif
#if (!defined(UNDER_CE))
  { "SetPolyFillMode",  winapi_SetPolyFillMode },
#endif
  { "SetTextColor",  winapi_SetTextColor },
  { "SetTextAlign",  winapi_SetTextAlign },
#if (!defined(UNDER_CE))
  { "SetTextJustification",  winapi_SetTextJustification },
#endif
#if (!defined(UNDER_CE))
  { "PtVisible",  winapi_PtVisible },
#endif
  { "RectVisible",  winapi_RectVisible },
#if (!defined(UNDER_CE))
  { "SetViewportExtEx",  winapi_SetViewportExtEx },
#endif
#if (!defined(UNDER_CE))
  { "SetViewportOrgEx",  winapi_SetViewportOrgEx },
#endif
#if (!defined(UNDER_CE))
  { "SetWindowExtEx",  winapi_SetWindowExtEx },
#endif
#if (!defined(UNDER_CE))
  { "SetWindowOrgEx",  winapi_SetWindowOrgEx },
#endif
#if (!defined(UNDER_CE))
  { "OffsetViewportOrgEx",  winapi_OffsetViewportOrgEx },
#endif
#if (!defined(UNDER_CE))
  { "OffsetWindowOrgEx",  winapi_OffsetWindowOrgEx },
#endif
#if (!defined(UNDER_CE))
  { "ScaleViewportExtEx",  winapi_ScaleViewportExtEx },
#endif
#if (!defined(UNDER_CE))
  { "ScaleWindowExtEx",  winapi_ScaleWindowExtEx },
#endif
  { "GetTextExtentExPointW",  winapi_GetTextExtentExPointW },
  { "GetTextExtentPoint32W",  winapi_GetTextExtentPoint32W },
#if (!defined(UNDER_CE))
  { "BeginPath",  winapi_BeginPath },
#endif
#if (!defined(UNDER_CE))
  { "CloseFigure",  winapi_CloseFigure },
#endif
#if (!defined(UNDER_CE))
  { "EndPath",  winapi_EndPath },
#endif
#if (!defined(UNDER_CE))
  { "FillPath",  winapi_FillPath },
#endif
#if (!defined(UNDER_CE))
  { "FlattenPath",  winapi_FlattenPath },
#endif
#if (!defined(UNDER_CE))
  { "PathToRegion",  winapi_PathToRegion },
#endif
#if (!defined(UNDER_CE))
  { "StrokeAndFillPath",  winapi_StrokeAndFillPath },
#endif
#if (!defined(UNDER_CE))
  { "StrokePath",  winapi_StrokePath },
#endif
#if (!defined(UNDER_CE))
  { "WidenPath",  winapi_WidenPath },
#endif
#if (!defined(UNDER_CE))
  { "Arc",  winapi_Arc },
#endif
#if (!defined(UNDER_CE))
  { "ArcTo",  winapi_ArcTo },
#endif
#if (!defined(UNDER_CE))
  { "Chord",  winapi_Chord },
#endif
  { "LineTo",  winapi_LineTo },
  { "MoveToEx",  winapi_MoveToEx },
  { "Ellipse",  winapi_Ellipse },
#if (!defined(UNDER_CE))
  { "Pie",  winapi_Pie },
#endif
  { "Rectangle",  winapi_Rectangle },
  { "RoundRect",  winapi_RoundRect },
#if (!defined(UNDER_CE))
  { "ExtFloodFill",  winapi_ExtFloodFill },
#endif
  { "FillRgn",  winapi_FillRgn },
#if (!defined(UNDER_CE))
  { "FloodFill",  winapi_FloodFill },
#endif
  { "BitBlt",  winapi_BitBlt },
  { "PatBlt",  winapi_PatBlt },
  { "StretchBlt",  winapi_StretchBlt },
#if (!defined(UNDER_CE))
  { "TransparentBlt",  winapi_TransparentBlt },
#endif
#if (!defined(UNDER_CE))
  { "TextOutW",  winapi_TextOutW },
#endif
  { "ExtTextOutW",  winapi_ExtTextOutW },
#if (defined(USE_OPENGL))
  { "wglCreateContext",  winapi_wglCreateContext },
#endif
#if (defined(USE_OPENGL))
  { "wglCreateLayerContext",  winapi_wglCreateLayerContext },
#endif
#if (defined(USE_OPENGL))
  { "wglMakeCurrent",  winapi_wglMakeCurrent },
#endif
#if (defined(USE_OPENGL))
  { "wglUseFontBitmapsA",  winapi_wglUseFontBitmapsA },
#endif
#if (defined(USE_OPENGL))
  { "wglUseFontBitmapsW",  winapi_wglUseFontBitmapsW },
#endif
#if (defined(USE_OPENGL))
  { "SwapBuffers",  winapi_SwapBuffers },
#endif
#if (defined(USE_OPENGL))
  { "wglRealizeLayerPalette",  winapi_wglRealizeLayerPalette },
#endif
#if (defined(USE_OPENGL))
  { "wglSwapLayerBuffers",  winapi_wglSwapLayerBuffers },
#endif
  { "DrawXorBar",  winapi_DrawXorBar },
  { NULL, NULL }
};

static const struct luaL_reg DC_WrapMethods[ ] = {
  { "WrapDC", DC_wrap },
  { NULL, NULL }
};

// used to identify the type
const char* Window_Typename = "Window";

// push on stack
int lua_pushWindow( lua_State *L, HWND hdl )
{
  if (NULL == hdl)
  {
    // return nil
    return 0;
  }

  // lookup handle in handle map
  luaL_getmetatable(L, Window_Typename);
  lua_pushstring(L, "$Handles");
  lua_rawget(L, -2);                      // stack: $Handles | metatable

  lua_pushlightuserdata(L, hdl);
  lua_rawget(L, -2);                      // stack: nil/object | $Handles | metatable

  if (lua_isnil(L, -1))
  {
    HWND* ud;
  
    // pop nil value
    lua_pop(L, 1);

    // push userdata
    ud = (HWND*)lua_newuserdata(L, sizeof(HWND));
    *ud = hdl;                              // stack: object | $Handles | metatable

    // set metatable
    lua_pushvalue(L, -3);
    lua_setmetatable(L, -2);

    // push key/value for lookup table
    lua_pushlightuserdata(L, hdl);
    lua_pushvalue(L, -2);                 // stack: object |  key  | object | $Handles | metatable

    // add item to lookup table
    lua_rawset(L, -4);                    // stack: object | $Handles | metatable
  }

  // cleanup stack (remove $Handles | metatable)
  lua_remove(L, -2);
  lua_remove(L, -2);

  return 1;
}

// get from stack
HWND lua_toWindow( lua_State *L, int idx )
{
  HWND v = 0;
  switch (lua_type(L, idx))
  {
    case LUA_TNIL:
      {
      }
      break;
    case LUA_TLIGHTUSERDATA:
      {
        v = (HWND)lua_touserdata(L, idx);
      }
      break;
    case LUA_TNUMBER:
      {
        v = (HWND)lua_tointeger(L, idx);
      }
      break;
    case LUA_TUSERDATA:
      {
        HWND* ud  = (HWND*)luaL_checkudata(L, idx, Window_Typename);
        v = *ud;
      }
      break;
    default:
      {
        luaL_typerror(L, idx, "Window (handle)");
      }
      break;
  }
  return v;
}

// implements __index metamethod (for .handle attribute)
static int Window_index(lua_State *L)
{
  HWND* ud  = (HWND*)luaL_checkudata(L, 1, Window_Typename);

  const char* stridx = lua_tolstring(L, 2, NULL);

  // check for .handle
  if (0 == strcmp(stridx, "handle"))
  {
    lua_pushlightuserdata(L, *ud);
    return 1;
  }
  else
  {
    luaL_getmetafield(L, 1, stridx);
  }

  return 1;
}

// to wrap handle in an object
static int Window_wrap(lua_State *L)

{
  HWND handle;

  if (lua_isnil(L, -1))
  {
   lua_pushnil(L);
  }
  else if (lua_islightuserdata(L, -1))
  {
    HWND handle = 0;
    handle = (HWND)(lua_touserdata(L, -1));
    return lua_pushWindow(L, handle);
  }
  else if (lua_isuserdata(L, -1))
  {
    HWND* ud  = (HWND*)luaL_checkudata(L, -1, Window_Typename);
    lua_pushvalue(L, -1);
    return 1;
  }
  
  handle = 0;
  if (lua_isnumber(L, -1))
  {
    handle = (HWND)lua_tointeger(L, -1);
  }
  
  return lua_pushWindow(L, handle);
}


static const struct luaL_reg Window_Methods[ ] = {
  { "__index", Window_index},
  { "wrap", Window_wrap },
  { "IsWindow",  winapi_IsWindow },
  { "IsWindowVisible",  winapi_IsWindowVisible },
  { "IsWindowEnabled",  winapi_IsWindowEnabled },
  { "IsChild",  winapi_IsChild },
  { "DestroyWindow",  winapi_DestroyWindow },
  { "ShowWindow",  winapi_ShowWindow },
  { "EnableWindow",  winapi_EnableWindow },
  { "UpdateWindow",  winapi_UpdateWindow },
  { "RedrawWindow",  winapi_RedrawWindow },
  { "SetParent",  winapi_SetParent },
  { "GetParent",  winapi_GetParent },
  { "SetActiveWindow",  winapi_SetActiveWindow },
  { "DrawMenuBar",  winapi_DrawMenuBar },
#if (!defined(UNDER_CE))
  { "CloseWindow",  winapi_CloseWindow },
#endif
  { "MoveWindow",  winapi_MoveWindow },
  { "SetWindowPos",  winapi_SetWindowPos },
#if (!defined(UNDER_CE))
  { "GetWindowPlacement",  winapi_GetWindowPlacement },
#endif
#if (!defined(UNDER_CE))
  { "SetWindowPlacement",  winapi_SetWindowPlacement },
#endif
  { "BringWindowToTop",  winapi_BringWindowToTop },
  { "SetForegroundWindow",  winapi_SetForegroundWindow },
  { "SetFocus",  winapi_SetFocus },
  { "PostMessageW",  winapi_PostMessageW },
  { "SendMessageW",  winapi_SendMessageW },
  { "IsDialogMessageW",  winapi_IsDialogMessageW },
  { "TranslateAcceleratorW",  winapi_TranslateAcceleratorW },
  { "DefWindowProcW",  winapi_DefWindowProcW },
  { "GetWindowLongW",  winapi_GetWindowLongW },
  { "SetWindowLongW",  winapi_SetWindowLongW },
  { "GetDC",  winapi_GetDC },
  { "GetDCEx",  winapi_GetDCEx },
  { "GetWindowDC",  winapi_GetWindowDC },
  { "ReleaseDC",  winapi_ReleaseDC },
  { "BeginPaint",  winapi_BeginPaint },
  { "EndPaint",  winapi_EndPaint },
  { "InvalidateRect",  winapi_InvalidateRect },
  { "ValidateRect",  winapi_ValidateRect },
  { "GetClientRect",  winapi_GetClientRect },
  { "GetWindowRect",  winapi_GetWindowRect },
  { "ClientToScreen",  winapi_ClientToScreen },
  { "ScreenToClient",  winapi_ScreenToClient },
  { "MapWindowPoints",  winapi_MapWindowPoints },
  { "SetCapture",  winapi_SetCapture },
#if (!defined(UNDER_CE))
  { "GetTopWindow",  winapi_GetTopWindow },
#endif
#if (!defined(UNDER_CE))
  { "GetLastActivePopup",  winapi_GetLastActivePopup },
#endif
  { "GetWindow",  winapi_GetWindow },
  { "RegisterHotKey",  winapi_RegisterHotKey },
  { "UnregisterHotKey",  winapi_UnregisterHotKey },
#if (!defined(UNDER_CE))
  { "DrawCaption",  winapi_DrawCaption },
#endif
#if (!defined(UNDER_CE))
  { "DrawAnimatedRects",  winapi_DrawAnimatedRects },
#endif
  { "EndDialog",  winapi_EndDialog },
  { "GetDlgItem",  winapi_GetDlgItem },
  { "SetDlgItemInt",  winapi_SetDlgItemInt },
  { "GetDlgItemInt",  winapi_GetDlgItemInt },
  { "SetDlgItemTextW",  winapi_SetDlgItemTextW },
  { "GetDlgItemTextW",  winapi_GetDlgItemTextW },
  { "CheckDlgButton",  winapi_CheckDlgButton },
  { "CheckRadioButton",  winapi_CheckRadioButton },
  { "IsDlgButtonChecked",  winapi_IsDlgButtonChecked },
  { "SendDlgItemMessageW",  winapi_SendDlgItemMessageW },
  { "GetNextDlgGroupItem",  winapi_GetNextDlgGroupItem },
  { "GetNextDlgTabItem",  winapi_GetNextDlgTabItem },
  { "GetDlgCtrlID",  winapi_GetDlgCtrlID },
  { "DefDlgProcW",  winapi_DefDlgProcW },
#if (defined(USE_AYGSHELL))
  { "SHFindMenuBar",  winapi_SHFindMenuBar },
#endif
#if (defined(USE_AYGSHELL))
  { "SHHandleWMActivate",  winapi_SHHandleWMActivate },
#endif
#if (defined(USE_AYGSHELL))
  { "SHHandleWMSettingChange",  winapi_SHHandleWMSettingChange },
#endif
#if (defined(USE_AYGSHELL))
  { "SHFullScreen",  winapi_SHFullScreen },
#endif
#if (defined(USE_AYGSHELL))
  { "SHDoneButton",  winapi_SHDoneButton },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_Show",  winapi_CommandBar_Show },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_AddBitmap",  winapi_CommandBar_AddBitmap },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_InsertComboBox",  winapi_CommandBar_InsertComboBox },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_InsertMenubar",  winapi_CommandBar_InsertMenubar },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_InsertMenubarEx",  winapi_CommandBar_InsertMenubarEx },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_DrawMenuBar",  winapi_CommandBar_DrawMenuBar },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_GetMenu",  winapi_CommandBar_GetMenu },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_AddAdornments",  winapi_CommandBar_AddAdornments },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_AlignAdornments",  winapi_CommandBar_AlignAdornments },
#endif
#if (defined(USE_COMMANDBAR))
  { "CommandBar_Height",  winapi_CommandBar_Height },
#endif
#if (defined(USE_COMMANDBAR))
  { "IsCommandBarMessage",  winapi_IsCommandBarMessage },
#endif
  { NULL, NULL }
};

static const struct luaL_reg Window_WrapMethods[ ] = {
  { "WrapWindow", Window_wrap },
  { NULL, NULL }
};

#if (defined(USE_MSGQUEUE))
// used to identify the type
const char* MsgQueue_Typename = "MsgQueue";

// push on stack
int lua_pushMsgQueue( lua_State *L, HMSGQUEUE hdl )
{
  if (NULL == hdl)
  {
    // return nil
    return 0;
  }

  // lookup handle in handle map
  luaL_getmetatable(L, MsgQueue_Typename);
  lua_pushstring(L, "$Handles");
  lua_rawget(L, -2);                      // stack: $Handles | metatable

  lua_pushlightuserdata(L, hdl);
  lua_rawget(L, -2);                      // stack: nil/object | $Handles | metatable

  if (lua_isnil(L, -1))
  {
    HMSGQUEUE* ud;
  
    // pop nil value
    lua_pop(L, 1);

    // push userdata
    ud = (HMSGQUEUE*)lua_newuserdata(L, sizeof(HMSGQUEUE));
    *ud = hdl;                              // stack: object | $Handles | metatable

    // set metatable
    lua_pushvalue(L, -3);
    lua_setmetatable(L, -2);

    // push key/value for lookup table
    lua_pushlightuserdata(L, hdl);
    lua_pushvalue(L, -2);                 // stack: object |  key  | object | $Handles | metatable

    // add item to lookup table
    lua_rawset(L, -4);                    // stack: object | $Handles | metatable
  }

  // cleanup stack (remove $Handles | metatable)
  lua_remove(L, -2);
  lua_remove(L, -2);

  return 1;
}

// get from stack
HMSGQUEUE lua_toMsgQueue( lua_State *L, int idx )
{
  HMSGQUEUE v = 0;
  switch (lua_type(L, idx))
  {
    case LUA_TNIL:
      {
      }
      break;
    case LUA_TLIGHTUSERDATA:
      {
        v = (HMSGQUEUE)lua_touserdata(L, idx);
      }
      break;
    case LUA_TNUMBER:
      {
        v = (HMSGQUEUE)lua_tointeger(L, idx);
      }
      break;
    case LUA_TUSERDATA:
      {
        HMSGQUEUE* ud  = (HMSGQUEUE*)luaL_checkudata(L, idx, MsgQueue_Typename);
        v = *ud;
      }
      break;
    default:
      {
        luaL_typerror(L, idx, "MsgQueue (handle)");
      }
      break;
  }
  return v;
}

// implements __index metamethod (for .handle attribute)
static int MsgQueue_index(lua_State *L)
{
  HMSGQUEUE* ud  = (HMSGQUEUE*)luaL_checkudata(L, 1, MsgQueue_Typename);

  const char* stridx = lua_tolstring(L, 2, NULL);

  // check for .handle
  if (0 == strcmp(stridx, "handle"))
  {
    lua_pushlightuserdata(L, *ud);
    return 1;
  }
  else
  {
    luaL_getmetafield(L, 1, stridx);
  }

  return 1;
}

// to wrap handle in an object
static int MsgQueue_wrap(lua_State *L)

{
  HMSGQUEUE handle;

  if (lua_isnil(L, -1))
  {
   lua_pushnil(L);
  }
  else if (lua_islightuserdata(L, -1))
  {
    HMSGQUEUE handle = 0;
    handle = (HMSGQUEUE)(lua_touserdata(L, -1));
    return lua_pushMsgQueue(L, handle);
  }
  else if (lua_isuserdata(L, -1))
  {
    HMSGQUEUE* ud  = (HMSGQUEUE*)luaL_checkudata(L, -1, MsgQueue_Typename);
    lua_pushvalue(L, -1);
    return 1;
  }
  
  handle = 0;
  if (lua_isnumber(L, -1))
  {
    handle = (HMSGQUEUE)lua_tointeger(L, -1);
  }
  
  return lua_pushMsgQueue(L, handle);
}


static const struct luaL_reg MsgQueue_Methods[ ] = {
  { "__index", MsgQueue_index},
  { "wrap", MsgQueue_wrap },
#if (defined(USE_MSGQUEUE))
  { "ReadMsgQueue",  winapi_ReadMsgQueue },
#endif
#if (defined(USE_MSGQUEUE))
  { "WriteMsgQueue",  winapi_WriteMsgQueue },
#endif
#if (defined(USE_MSGQUEUE))
  { "GetMsgQueueInfo",  winapi_GetMsgQueueInfo },
#endif
#if (defined(USE_MSGQUEUE))
  { "CloseMsgQueue",  winapi_CloseMsgQueue },
#endif
  { NULL, NULL }
};

static const struct luaL_reg MsgQueue_WrapMethods[ ] = {
  { "WrapMsgQueue", MsgQueue_wrap },
  { NULL, NULL }
};

#endif
// used to identify the type
const char* Region_Typename = "Region";

// push on stack
int lua_pushRegion( lua_State *L, HRGN hdl )
{
  if (NULL == hdl)
  {
    // return nil
    return 0;
  }

  // lookup handle in handle map
  luaL_getmetatable(L, Region_Typename);
  lua_pushstring(L, "$Handles");
  lua_rawget(L, -2);                      // stack: $Handles | metatable

  lua_pushlightuserdata(L, hdl);
  lua_rawget(L, -2);                      // stack: nil/object | $Handles | metatable

  if (lua_isnil(L, -1))
  {
    HRGN* ud;
  
    // pop nil value
    lua_pop(L, 1);

    // push userdata
    ud = (HRGN*)lua_newuserdata(L, sizeof(HRGN));
    *ud = hdl;                              // stack: object | $Handles | metatable

    // set metatable
    lua_pushvalue(L, -3);
    lua_setmetatable(L, -2);

    // push key/value for lookup table
    lua_pushlightuserdata(L, hdl);
    lua_pushvalue(L, -2);                 // stack: object |  key  | object | $Handles | metatable

    // add item to lookup table
    lua_rawset(L, -4);                    // stack: object | $Handles | metatable
  }

  // cleanup stack (remove $Handles | metatable)
  lua_remove(L, -2);
  lua_remove(L, -2);

  return 1;
}

// get from stack
HRGN lua_toRegion( lua_State *L, int idx )
{
  HRGN v = 0;
  switch (lua_type(L, idx))
  {
    case LUA_TNIL:
      {
      }
      break;
    case LUA_TLIGHTUSERDATA:
      {
        v = (HRGN)lua_touserdata(L, idx);
      }
      break;
    case LUA_TNUMBER:
      {
        v = (HRGN)lua_tointeger(L, idx);
      }
      break;
    case LUA_TUSERDATA:
      {
        HRGN* ud  = (HRGN*)luaL_checkudata(L, idx, Region_Typename);
        v = *ud;
      }
      break;
    default:
      {
        luaL_typerror(L, idx, "Region (handle)");
      }
      break;
  }
  return v;
}

// implements __index metamethod (for .handle attribute)
static int Region_index(lua_State *L)
{
  HRGN* ud  = (HRGN*)luaL_checkudata(L, 1, Region_Typename);

  const char* stridx = lua_tolstring(L, 2, NULL);

  // check for .handle
  if (0 == strcmp(stridx, "handle"))
  {
    lua_pushlightuserdata(L, *ud);
    return 1;
  }
  else
  {
    luaL_getmetafield(L, 1, stridx);
  }

  return 1;
}

// to wrap handle in an object
static int Region_wrap(lua_State *L)

{
  HRGN handle;

  if (lua_isnil(L, -1))
  {
   lua_pushnil(L);
  }
  else if (lua_islightuserdata(L, -1))
  {
    HRGN handle = 0;
    handle = (HRGN)(lua_touserdata(L, -1));
    return lua_pushRegion(L, handle);
  }
  else if (lua_isuserdata(L, -1))
  {
    HRGN* ud  = (HRGN*)luaL_checkudata(L, -1, Region_Typename);
    lua_pushvalue(L, -1);
    return 1;
  }
  
  handle = 0;
  if (lua_isnumber(L, -1))
  {
    handle = (HRGN)lua_tointeger(L, -1);
  }
  
  return lua_pushRegion(L, handle);
}


static const struct luaL_reg Region_Methods[ ] = {
  { "__index", Region_index},
  { "wrap", Region_wrap },
  { "EqualRgn",  winapi_EqualRgn },
  { "CombineRgn",  winapi_CombineRgn },
  { "OffsetRgn",  winapi_OffsetRgn },
  { "SetRectRgn",  winapi_SetRectRgn },
  { "PtInRegion",  winapi_PtInRegion },
  { "RectInRegion",  winapi_RectInRegion },
  { NULL, NULL }
};

static const struct luaL_reg Region_WrapMethods[ ] = {
  { "WrapRegion", Region_wrap },
  { NULL, NULL }
};


//////////////////////////////////////////////////////////////////////////
/**

  registers abstractions as Lua types

  @param[in]  L  pointer lua state

*/////////////////////////////////////////////////////////////////////////
void registerAbstractions(lua_State *L)
{
  // register package functions
  luaL_register( L, NULL, DC_WrapMethods );

  luaL_newmetatable(L, DC_Typename);
  lua_pushstring(L, "$Handles");
  lua_newtable(L);
  lua_rawset(L, -3);
//  lua_pushstring(L, "__index");
//  lua_newtable(L);
  luaL_register(L, NULL, DC_Methods);
//  lua_rawset(L, -3);
  lua_pop(L, 1);

  luaL_register( L, NULL, Window_WrapMethods );

  luaL_newmetatable(L, Window_Typename);
  lua_pushstring(L, "$Handles");
  lua_newtable(L);
  lua_rawset(L, -3);
//  lua_pushstring(L, "__index");
//  lua_newtable(L);
  luaL_register(L, NULL, Window_Methods);
//  lua_rawset(L, -3);
  lua_pop(L, 1);

#if (defined(USE_MSGQUEUE))
  luaL_register( L, NULL, MsgQueue_WrapMethods );

  luaL_newmetatable(L, MsgQueue_Typename);
  lua_pushstring(L, "$Handles");
  lua_newtable(L);
  lua_rawset(L, -3);
//  lua_pushstring(L, "__index");
//  lua_newtable(L);
  luaL_register(L, NULL, MsgQueue_Methods);
//  lua_rawset(L, -3);
  lua_pop(L, 1);

#endif
  luaL_register( L, NULL, Region_WrapMethods );

  luaL_newmetatable(L, Region_Typename);
  lua_pushstring(L, "$Handles");
  lua_newtable(L);
  lua_rawset(L, -3);
//  lua_pushstring(L, "__index");
//  lua_newtable(L);
  luaL_register(L, NULL, Region_Methods);
//  lua_rawset(L, -3);
  lua_pop(L, 1);

}

