/*******************************************************************
 * @file GridTable.h
 *
 * @brief Header file for the GridTable base class
 * 
 * @copyright Copyright © 2025 Jeff Kohn. All rights reserved. 
 *******************************************************************/
#pragma once

#include "App.h"
#include "grid/GridTableFilter.h"

#include <wx/grid.h>

#include <set>
#include <memory>


namespace ctb::app
{


   /// @brief struct that contains name, index and direction of a sort option
   ///
   struct GridTableSortConfig
   {
      int               sort_index{};
      std::string_view  sort_name{};
      bool              ascending{ true };

      [[nodiscard]] std::strong_ordering operator<=>(const GridTableSortConfig&) const = default;
   };



   /// @brief our "data model", provides an base class interface for accessing CellarTracker data
   /// 
   /// users of this interface should gain access through 
   /// IGridTableEventSource::getTable() or using the ptr supplied when
   /// handling IGridTableEventSource::notify()
   /// 
   class GridTable : public wxGridStringTable
   {
   public:

      /// @brief Sets up the formatting options in the calling grid to match this grid table's fields
      ///
      virtual void configureGridColumns(wxGridCellAttrPtr default_attr) = 0;


      /// @brief filter does substring matching on ANY column in the table view
      ///
      /// returns true if filter was applied, false if there were no matches in which
      /// case the filter was not applied. triggers GridTableEvent::SubStringFilter
      ///
      virtual bool filterBySubstring(std::string_view substr) = 0;


      /// @brief sets filter that does substring matching on the specified column
      ///
      /// returns true if filter was applied, false if there were no matches in which
      /// case the filter was not applied. triggers GridTableEvent::SubStringFilter
      /// 
      virtual bool filterBySubstring(std::string_view substr, int col_idx) = 0;


      /// @brief clear the substring filter
      ///
      /// triggers GridTableEvent::SubStringFilter
      /// 
      virtual void clearSubStringFilter() = 0;


      /// @brief returns the total number of records in the underlying dataset
      ///
      virtual int totalRowCount() const = 0;


      /// @brief returns the number of records with filters applied.
      ///
      virtual int filteredRowCount() const  = 0;


      /// @brief retrieves list of available sortOptions, in order of display
      /// 
      /// the index in this vector corresponds to the index in the sort_index
      /// property.
      /// 
      virtual std::vector<GridTableSortConfig> availableSortConfigs() const = 0;


      /// @brief returns the currently active sort option
      ///
      virtual GridTableSortConfig activeSortConfig() const = 0;


      /// @brief specifies a new sort option, triggers GridTableEvent::Sort
      ///
      virtual void applySortConfig(const GridTableSortConfig& config) = 0;


      /// @brief retrieves a list of available filters for this table.
      ///
      virtual std::vector<GridTableFilter> availableFilters() const = 0;


      /// @brief get a list of values that can be used to filter on a column in the table
      ///
      virtual std::set<std::string> getFilterMatchValues(int prop_id) const = 0;


      /// @brief adds a match value filter for the specified column.
      ///
      /// a record must match at least one value for each property that 
      /// has a filter to be considered a match.
      /// 
      virtual void addFilter(int prop_id, std::string_view match_value) = 0;

      /// @brief destructor
      ///
      virtual ~GridTable()
      {}
   };


   /// @brief the smart-ptr-to-base that's used to work with the GridTable interface 
   ///
   using GridTablePtr = std::shared_ptr<GridTable>;


}  // namespace ctb::app