﻿#include "App.h"
#include "grid/GridTableFilter.h"
#include "interfaces/GridTable.h"

namespace ctb::app
{
   StringSet GridTableFilter::getMatchValues(GridTable* grid_table) const
   {
      return grid_table->getFilterMatchValues(m_prop_index);
   }

} // ctb::app