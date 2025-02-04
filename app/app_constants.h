#pragma once

namespace ctb::constants
{
   inline constexpr const char* CONFIG_PATH_SYNC                  = "/Preferences/DataSync";
   inline constexpr const char* CONFIG_VALUE_SYNC_ON_STARTUP      = "SyncOnStartup";
   inline constexpr const char* CONFIG_VALUE_DEFAULT_SYNC_TABLES  = "DefaultSyncTables";

   inline constexpr const char* FMT_STATUS_FILE_DOWNLOADING       = "Downloading file '{}'...";
   inline constexpr const char* FMT_STATUS_FILE_DOWNLOADED        = "Successfully downloaded file '{}'.";
   inline constexpr const char* STATUS_DOWNLOAD_COMPLETE          = "Download operation completed.";
   inline constexpr const char* STATUS_DOWNLOAD_CANCELED          = "Download operation canceled.";
   inline constexpr const char* STATUS_DOWNLOAD_FAILED            = "Download operation failed.";
   inline constexpr const char* INFO_MSG_NO_MATCHING_ROWS         = "No rows matched the search text.";


   inline constexpr const char* RES_NAME_MAINFRAME                = "MAINFRAME";
   inline constexpr const char* RES_NAME_ICON_PRODUCT             = "IDR_PRODUCT_ICON";
   inline constexpr const char* LBL_WINE                          = "Wine";
   inline constexpr const char* LBL_VARIETAL                      = "Varietal";
   inline constexpr const char* LBL_QTY                           = "Qty";
   inline constexpr const char* LBL_CT_SCORE                      = "CT Score";
   inline constexpr const char* LBL_MY_SCORE                      = "My Score";
   inline constexpr const char* LBL_MY_PRICE                      = "My Price";
   inline constexpr const char* LBL_DRINK_BY                      = "Drink By";
   inline constexpr const char* LBL_SEARCH                        = "&Search";
   inline constexpr const char* FMT_LBL_TOTAL_ROWS                = "Total Rows: {}";
   inline constexpr const char* FMT_LBL_FILTERED_ROWS             = "Filtered Rows: {}";

   inline constexpr const char* TITLE_DOWNLOAD_DATA               = "Download Data";
   inline constexpr const char* FMT_TITLE_TYPED_ERROR             = "Error ({})";

   inline constexpr const char* CMD_FILE_DOWNLOAD_DATA_LBL     = "&Download Data...";
   inline constexpr const char* CMD_FILE_DOWNLOAD_DATA_TIP     = "Download data from CellarTracker";
   inline constexpr const char* CMD_FILE_SETTINGS_LBL          = "&Settings...";
   inline constexpr const char* CMD_FILE_SETTINGS_TIP          = "Configure app settings";
   inline constexpr const char* MENU_VIEWS_LBL                 = "&Views";
   inline constexpr const char* CMD_VIEWS_WINE_LIST_LBL        = "&Wine List\tCtrl+W";
   inline constexpr const char* CMD_VIEWS_WINE_LIST_TIP        = "View Personal Wine List";

}  // namespace ctb::app::constants