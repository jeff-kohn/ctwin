///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include <wx/stockitem.h>

#include "MainFrameBase.h"

using namespace cts;

bool MainFrameBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{

    if (!wxFrame::Create(parent, id, title, pos, size, style, name))
        return false;

    m_toolBar = CreateToolBar();
    m_toolBar->Realize();

    m_menubar = new wxMenuBar();

    auto* menu_file = new wxMenu();
    auto* menu_sync_data = new wxMenuItem(menu_file, wxID_ANY, "&Sync Data...");
    menu_file->Append(menu_sync_data);
    menu_file->AppendSeparator();
    auto* menu_preferences = new wxMenuItem(menu_file, wxID_ANY, "&Preferences");
    menu_file->Append(menu_preferences);
    menu_file->AppendSeparator();
    auto* menu_quit = new wxMenuItem(menu_file, wxID_EXIT);
    menu_quit->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_QUIT, wxART_MENU));

    menu_file->Append(menu_quit);
    m_menubar->Append(menu_file, wxGetStockLabel(wxID_FILE));

    m_menu_data = new wxMenu();
    m_menubar->Append(m_menu_data, "&Data");

    SetMenuBar(m_menubar);

    m_statusBar = CreateStatusBar();

    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_MENU, &MainFrameBase::onMenuPreferences, this, menu_preferences->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::onMenuQuit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrameBase::onMenuSyncData, this, menu_sync_data->GetId());

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
