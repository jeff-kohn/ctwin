/*******************************************************************
 * @file GridTableWineList.h
 *
 * @brief Header file for the class GridTableWineList
 * 
 * @copyright Copyright © 2025 Jeff Kohn. All rights reserved. 
 *******************************************************************/
#pragma once

#include "ctb/data/DisplayColumn.h"
#include "ctb/data/WineListEntry.h"
#include "grids/GridTableBase.h"

#include <magic_enum/magic_enum.hpp>
#include <wx/grid.h>

#include <array>
#include <vector>


namespace ctb
{
   class GridTableWineList : public GridTableBase
   {
   public:
      /// @brief type used for describing how to display a column in the grid
      using DisplayColumn = data::DisplayColumn<data::WineListEntry>;

      explicit GridTableWineList(data::WineListData&& data) : 
         m_data{std::move(data)},
         m_display_columns(DefaultDisplayColumns.begin(), DefaultDisplayColumns.end())
      {}

      static inline const std::array DefaultDisplayColumns { 
         DisplayColumn{ data::WineListEntry::Prop::WineAndVintage,                              constants::LBL_WINE     },
         DisplayColumn{ data::WineListEntry::Prop::MasterVarietal,                              constants::LBL_VARIETAL },
         DisplayColumn{ data::WineListEntry::Prop::Country                                                              },
         DisplayColumn{ data::WineListEntry::Prop::Appellation                                                          },
         DisplayColumn{ data::WineListEntry::Prop::Quantity,   DisplayColumn::Format::Number,   constants::LBL_QTY      },
         DisplayColumn{ data::WineListEntry::Prop::Pending,    DisplayColumn::Format::Number                            },
         DisplayColumn{ data::WineListEntry::Prop::CTScore,    DisplayColumn::Format::Decimal,  constants::LBL_CT_SCORE },
         DisplayColumn{ data::WineListEntry::Prop::MYScore,    DisplayColumn::Format::Decimal,  constants::LBL_MY_SCORE },
         DisplayColumn{ data::WineListEntry::Prop::Price,      DisplayColumn::Format::Currency, constants::LBL_MY_PRICE },
         DisplayColumn{ data::WineListEntry::Prop::EndConsume, DisplayColumn::Format::Number,   constants::LBL_DRINK_BY }
      };


      /// @brief base class override that returns the number of rows/records in the table/grid
      int GetNumberRows() override { return std::ssize(m_data); }


      /// @brief base class override that returns the number of columns displayed in the table/grid
      int GetNumberCols() override { return std::ssize(m_display_columns); }


      /// @brief base class override to get the display name for column headers
      wxString GetColLabelValue(int col) override;


      /// @brief base class override to get the value for a given cell in the grid
      wxString GetValue(int row, int col) override;


      /// @brief this function will always throw an exception since the grid is read-only
      void SetValue(int row, int col, const wxString& value) override;


      /// @brief container alias used to hold the DisplayColumn's used for this grid
      using ColumnList = std::vector<DisplayColumn>;


      /// @brief  get a list of the columns that will be displayed in the grid
      /// 
      /// the columns are in the order they will be displayed.
      ColumnList getDisplayColumns() const { return m_display_columns; }


      /// @brief specify the columns to display in the grid
      template<rng::input_range Cols> requires std::is_same_v<rng::range_value_t<Cols>, ColumnList::value_type>
      void setDisplayColumns(Cols&& cols) 
      {
         ColumnList new_cols{std::forward<Cols>(cols)};
         m_display_columns.swap(new_cols);
      }


      /// @brief this method will configure the column alignment settings for the grid based on the
      ///        settings in the corresponding DisplayColumn objects.
      void configureGridColumns(wxGridCellAttrPtr default_attr_ptr) override;


      // object is move-only since copying would be expensive 
      // and we're going to store them in shared_ptr's anyway
      GridTableWineList(const GridTableWineList&) = delete;
      GridTableWineList& operator=(const GridTableWineList&) = delete;

   private:
      data::WineListData m_data{};
      ColumnList m_display_columns{};
   };


} // namespace ctb