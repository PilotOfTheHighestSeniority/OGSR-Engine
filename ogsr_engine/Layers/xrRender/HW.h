// HW.h: interface for the CHW class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HW_H__0E25CF4A_FFEC_11D3_B4E3_4854E82A090D__INCLUDED_)
#define AFX_HW_H__0E25CF4A_FFEC_11D3_B4E3_4854E82A090D__INCLUDED_
#pragma once

#include <dxgi1_4.h>

#include "hwcaps.h"

#ifndef _MAYA_EXPORT
#include "stats_manager.h"
#endif

class CHW
    : public pureAppActivate,
      public pureAppDeactivate
{
    //	Functions section
public:
    CHW();
    ~CHW();

    void CreateD3D();
    void DestroyD3D();
    void CreateDevice(HWND hw);

    void DestroyDevice();

    void Reset(HWND hw);

    void selectResolution(u32& dwWidth, u32& dwHeight, BOOL bWindowed);
    D3DFORMAT selectDepthStencil(D3DFORMAT);
    u32 selectPresentInterval();
    u32 selectGPU();
    u32 selectRefresh(u32 dwWidth, u32 dwHeight, D3DFORMAT fmt);

    void updateWindowProps(HWND hw);
    BOOL support(D3DFORMAT fmt, DWORD type, DWORD usage);

    void Validate(void){};

    void DumpVideoMemoryUsage() const;

//	Variables section
public:
    ID3D11Device* pDevice = nullptr; // render device
    ID3D11RenderTargetView* pBaseRT = nullptr; // base render target
    ID3D11DepthStencilView* pBaseZB = nullptr; // base depth-stencil buffer

    IDXGIFactory4* pFactory = nullptr;
    IDXGIAdapter3* m_pAdapter = nullptr;
    ID3D11DeviceContext* pContext = nullptr;
    IDXGISwapChain* m_pSwapChain = nullptr;

    CHWCaps Caps;

    DXGI_SWAP_CHAIN_DESC m_ChainDesc; //	DevPP equivalent
    D3D_FEATURE_LEVEL FeatureLevel;


#ifndef _MAYA_EXPORT
    stats_manager stats_manager{};
#endif

    void UpdateViews();

    DXGI_RATIONAL selectRefresh(u32 dwWidth, u32 dwHeight, DXGI_FORMAT fmt);

    virtual void OnAppActivate();
    virtual void OnAppDeactivate();
};

extern ECORE_API CHW HW;

#endif // !defined(AFX_HW_H__0E25CF4A_FFEC_11D3_B4E3_4854E82A090D__INCLUDED_)
