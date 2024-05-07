/*
** Copyright 2022 bitValence, Inc.
** All Rights Reserved.
**
** This program is free software; you can modify and/or redistribute it
** under the terms of the GNU Affero General Public License
** as published by the Free Software Foundation; version 3 with
** attribution addendums as found in the LICENSE.txt.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Affero General Public License for more details.
**
** Purpose:
**   Define platform configurations for the JSON Gateway application
**
** Notes:
**   1. These macros can only be build with the application and can't
**      have a platform scope because the same app_cfg.h file name is used for
**      all applications following the object-based application design.
**
*/

#ifndef _app_cfg_
#define _app_cfg_

/*
** Includes
*/

#include "json_gw_eds_typedefs.h"
#include "json_gw_platform_cfg.h"
#include "app_c_fw.h"


/******************************************************************************
** Application Macros
*/

/*
** Versions:
**
** 0.9 - Prototype
*/

#define  JSON_GW_MAJOR_VER      0
#define  JSON_GW_MINOR_VER      9

/******************************************************************************
**  INI File
*/

#define  JSON_GW_INI_MAX_STRINGS 20

/******************************************************************************
** Init File declarations create:
**
**  typedef enum {
**     CMD_PIPE_DEPTH,
**     CMD_PIPE_NAME
**  } INITBL_ConfigEnum;
**    
**  typedef struct {
**     CMD_PIPE_DEPTH,
**     CMD_PIPE_NAME
**  } INITBL_ConfigStruct;
**
**   const char *GetConfigStr(value);
**   ConfigEnum GetConfigVal(const char *str);
**
** XX(name,type)
*/

#define CFG_APP_CFE_NAME       APP_CFE_NAME
#define CFG_APP_MAIN_PERF_ID   APP_MAIN_PERF_ID

#define CFG_JSON_GW_CMD_TOPICID         JSON_GW_CMD_TOPICID
#define CFG_SEND_STATUS_TLM_TOPICID     BC_SCH_2_SEC_TOPICID
#define CFG_JSON_GW_STATUS_TLM_TOPICID  JSON_GW_STATUS_TLM_TOPICID

#define CFG_CMD_PIPE_NAME   CMD_PIPE_NAME
#define CFG_CMD_PIPE_DEPTH  CMD_PIPE_DEPTH

#define CFG_RX_UDP_PORT          RX_UDP_PORT
#define CFG_RX_CHILD_NAME        RX_CHILD_NAME
#define CFG_RX_CHILD_STACK_SIZE  RX_CHILD_STACK_SIZE
#define CFG_RX_CHILD_PRIORITY    RX_CHILD_PRIORITY
#define CFG_RX_CHILD_PERF_ID     RX_CHILD_PERF_ID

#define CFG_TX_UDP_PORT          TX_UDP_PORT
#define CFG_TX_CHILD_NAME        TX_CHILD_NAME
#define CFG_TX_CHILD_STACK_SIZE  TX_CHILD_STACK_SIZE
#define CFG_TX_CHILD_PRIORITY    TX_CHILD_PRIORITY
#define CFG_TX_CHILD_PERF_ID     TX_CHILD_PERF_ID
#define CFG_TX_SB_PIPE_NAME      TX_SB_PIPE_NAME
#define CFG_TX_SB_PIPE_DEPTH     TX_SB_PIPE_DEPTH

#define CFG_MQTT_TOPIC_TBL_DEF_FILE  MQTT_TOPIC_TBL_DEF_FILE


#define APP_CONFIG(XX) \
   XX(APP_CFE_NAME,char*) \
   XX(APP_MAIN_PERF_ID,uint32) \
   XX(JSON_GW_CMD_TOPICID,uint32) \
   XX(BC_SCH_2_SEC_TOPICID,uint32) \
   XX(JSON_GW_STATUS_TLM_TOPICID,uint32) \
   XX(CMD_PIPE_NAME,char*) \
   XX(CMD_PIPE_DEPTH,uint32) \
   XX(RX_UDP_PORT,uint32) \
   XX(RX_CHILD_NAME,char*) \
   XX(RX_CHILD_STACK_SIZE,uint32) \
   XX(RX_CHILD_PRIORITY,uint32) \
   XX(RX_CHILD_PERF_ID,uint32) \
   XX(TX_UDP_PORT,uint32) \
   XX(TX_CHILD_NAME,char*) \
   XX(TX_CHILD_STACK_SIZE,uint32) \
   XX(TX_CHILD_PRIORITY,uint32) \
   XX(TX_CHILD_PERF_ID,uint32) \
   XX(TX_SB_PIPE_NAME,char*) \
   XX(TX_SB_PIPE_DEPTH,uint32) \
   XX(MQTT_TOPIC_TBL_DEF_FILE,char*)

DECLARE_ENUM(Config,APP_CONFIG)


/******************************************************************************
** Event Macros
**
** Define the base event message IDs used by each object/component used by the
** application. There are no automated checks to ensure an ID range is not
** exceeded so it is the developer's responsibility to verify the ranges. 
*/

#define JSON_GW_BASE_EID    (APP_C_FW_APP_BASE_EID +  0)
#define UDP_COMM_BASE_EID   (APP_C_FW_APP_BASE_EID + 20)
// Topic plugin macros are defined in mqtt_gw_topic_plugin.h and start at (APP_C_FW_APP_BASE_EID + 200)


/******************************************************************************
** UDP_COMM
**
*/

#define UDP_COMM_BUF_LEN   4096  /* Must accomodate Rx and Tx maximum message length */

#endif /* _app_cfg_ */
