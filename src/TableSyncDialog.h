/*********************************************************************
 * @file       TableSyncDialog.cpp
 *
 * @brief      Implementation for the class TableSyncDialog
 *
 * @copyright  Copyright © 2025 Jeff Kohn. All rights reserved.
 *********************************************************************/
#pragma once

#include "generated/TableSyncDlgBase.h"
#include "cts/CellarTrackerDownload.h"
#include "concepts.h"

#include <vector>

namespace cts
{
   class TableSyncDialog : public TableSyncDlgBase
   {
   public:
      /// @brief  ctor for two-phase window creation, requires manually calling Create()
      TableSyncDialog() {}

      // @brief ctor for implicit window creation, no need to call create.
      TableSyncDialog(wxWindow* parent);


      /// @brief create the window object
      ///
      /// this should only be called if this object was default-constructed
      bool Create(wxWindow* parent);


      /// @brief set the list of tables that should be selected for download.
      template <rng::input_range Rng>
      void selectTables(Rng&& values) requires std::is_same_v<rng::range_value_t<Rng>, data::TableId>
      {
         m_table_selection_val = values | vws::transform([] (data::TableId tbl)
                                                         {
                                                            return magic_enum::enum_index(tbl);
                                                         })
                                        | rng::to<wxArrayString>();
      }

      /// @brief retrieve the list of tables the user selected for download
      std::vector<data::TableId> selectedTables() const;

      /// @brief  indicates whether the user checked "Save as Default" in the dialog
      bool saveAsDefault() const noexcept { return m_save_default_val; }

      /// @brief indicates whether the user checked "Automatically Sync on Startup"
      bool syncOnStartup() const noexcept { return m_startup_sync_val; }

   protected:
      void onOkUpdateUI(wxUpdateUIEvent& event);
      void onOkClicked(wxCommandEvent& event);
   };

}
