/*
** $Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/os/linux/include/gl_cfg80211.h#1 $
*/

/*! \file   gl_cfg80211.h
    \brief  This file is for Portable Driver linux cfg80211 support.
*/

/*******************************************************************************
* Copyright (c) 2007 MediaTek Inc.
*
* All rights reserved. Copying, compilation, modification, distribution
* or any other use whatsoever of this material is strictly prohibited
* except in accordance with a Software License Agreement with
* MediaTek Inc.
********************************************************************************
*/

/*******************************************************************************
* LEGAL DISCLAIMER
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
* AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK
* SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE
* PROVIDED TO BUYER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY
* DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE
* ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY
* WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK
* SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY
* WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE
* FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION OR TO
* CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL
* BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT
* ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY
* BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT
* OF LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING
* THEREOF AND RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN
* FRANCISCO, CA, UNDER THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE
* (ICC).
********************************************************************************
*/

/*
** $Log: gl_cfg80211.h $
** 
** 08 29 2012 chinglan.wang
** [ALPS00349655] [Need Patch] [Volunteer Patch] [ALPS.JB] Daily build warning on [mt6575_phone_mhl-eng]
** .
 *
*/

#ifndef _GL_CFG80211_H
#define _GL_CFG80211_H

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
#include <linux/kernel.h>
#include <linux/netdevice.h>
#include <linux/wireless.h>
#include <linux/ieee80211.h>
#include <net/cfg80211.h>

#include "gl_os.h"

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
/* cfg80211 hooks (station mode only; signatures follow current cfg80211_ops) */
int mtk_cfg80211_change_iface(struct wiphy *wiphy, struct net_device *ndev,
    enum nl80211_iftype type, struct vif_params *params);

int mtk_cfg80211_add_key(struct wiphy *wiphy, struct wireless_dev *wdev,
    int link_id, u8 key_index, bool pairwise, const u8 *mac_addr,
    struct key_params *params);

int mtk_cfg80211_get_key(struct wiphy *wiphy, struct wireless_dev *wdev,
    int link_id, u8 key_index, bool pairwise, const u8 *mac_addr,
    void *cookie, void (*callback)(void *cookie, struct key_params *));

int mtk_cfg80211_del_key(struct wiphy *wiphy, struct wireless_dev *wdev,
    int link_id, u8 key_index, bool pairwise, const u8 *mac_addr);

int mtk_cfg80211_get_station(struct wiphy *wiphy, struct wireless_dev *wdev,
    const u8 *mac, struct station_info *sinfo);

int mtk_cfg80211_scan(struct wiphy *wiphy,
    struct cfg80211_scan_request *request);

int mtk_cfg80211_connect(struct wiphy *wiphy, struct net_device *ndev,
    struct cfg80211_connect_params *sme);

int mtk_cfg80211_disconnect(struct wiphy *wiphy, struct net_device *ndev,
    u16 reason_code);

int mtk_cfg80211_join_ibss(struct wiphy *wiphy, struct net_device *ndev,
    struct cfg80211_ibss_params *params);

int mtk_cfg80211_leave_ibss(struct wiphy *wiphy, struct net_device *ndev);

int mtk_cfg80211_set_power_mgmt(struct wiphy *wiphy, struct net_device *ndev,
    bool enabled, int timeout);

int mtk_cfg80211_set_pmksa(struct wiphy *wiphy, struct net_device *ndev,
    struct cfg80211_pmksa *pmksa);

int mtk_cfg80211_del_pmksa(struct wiphy *wiphy, struct net_device *ndev,
    struct cfg80211_pmksa *pmksa);

int mtk_cfg80211_flush_pmksa(struct wiphy *wiphy, struct net_device *ndev);


/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif /* _GL_CFG80211_H */

