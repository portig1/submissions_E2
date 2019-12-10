/******************************************************************************
 DO NOT EDIT - This file is generated by the SysConfig tool.
 @file ti_154stack_config.h

 @brief TI-15.4 Stack configuration parameters for Collector applications

 *****************************************************************************/
#ifndef TI_154STACK_CONFIG_H
#define TI_154STACK_CONFIG_H

/******************************************************************************
 Includes
 *****************************************************************************/
#include "api_mac.h"
#include "ti_154stack_features.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*! Setting for phy ID */
#define CONFIG_PHY_ID                   APIMAC_STD_US_915_PHY_1

/*! Setting for channel page */
#define CONFIG_CHANNEL_PAGE             APIMAC_CHANNEL_PAGE_9

/* ! Value for transmit power in dBm */
#define CONFIG_TRANSMIT_POWER           0

/*! Frequency hopping mode enabled */
#define CONFIG_FH_ENABLE                false

#define CONFIG_SECURE true     
#define CONFIG_PAN_ID 0xFFFF     
/* Unused CONFIG_SCAN_BACKOFF_INTERVAL generated for code compilation */
#define CONFIG_SCAN_BACKOFF_INTERVAL 5000     
/* Unused CONFIG_ORPHAN_BACKOFF_INTERVAL generated for code compilation */
#define CONFIG_ORPHAN_BACKOFF_INTERVAL 300000     
#define CONFIG_MIN_BE 3     
#define CONFIG_MAX_BE 5     
#define CONFIG_SCAN_DURATION 5     

#define KEY_TABLE_DEFAULT_KEY { 0x12,0x34,0x56,0x78,0x9A,0xBC,0xDE,0xF0, \
                   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }

#define CONFIG_CHANNEL_MASK    { 0x00,0x04,0x00,0x00,0x00,0x00, \
                          0x00,0x00,0x00,0x00,0x00,0x00, \
                         0x00,0x00,0x00,0x00,0x00 }

/* Unused CONFIG_FH_CHANNEL_MASK generated for code compilation */
#define CONFIG_FH_CHANNEL_MASK    { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                          0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                         0xFF,0xFF,0xFF,0xFF,0xFF }

/* Unused FH_ASYNC_CHANNEL_MASK generated for code compilation */
#define FH_ASYNC_CHANNEL_MASK    { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                          0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, \
                         0xFF,0xFF,0xFF,0xFF,0xFF }

#define CONFIG_POLLING_INTERVAL 2000     
#define CONFIG_REPORTING_INTERVAL 3000     
/* Unused CONFIG_FH_NETNAME generated for code compilation */
#define CONFIG_FH_NETNAME {"FHTest"}     
#define CONFIG_MAX_DEVICES 50     
#define CONFIG_MAC_BEACON_ORDER 15     
#define CONFIG_MAC_SUPERFRAME_ORDER 15     
#define TRACKING_DELAY_TIME 5000     
/* Unused FH_BROADCAST_INTERVAL generated for code compilation */
#define FH_BROADCAST_INTERVAL 10000     
/* Unused FH_BROADCAST_DWELL_TIME generated for code compilation */
#define FH_BROADCAST_DWELL_TIME 100     
#define CERTIFICATION_TEST_MODE false     



#ifdef __cplusplus
}
#endif

#endif /* TI_154STACK_CONFIG_H */
