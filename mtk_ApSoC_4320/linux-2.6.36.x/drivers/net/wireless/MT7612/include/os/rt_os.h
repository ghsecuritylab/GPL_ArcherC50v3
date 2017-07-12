/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology	5th	Rd.
 * Science-based Industrial	Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved.	Ralink's source	code is	an unpublished work	and	the
 * use of a	copyright notice does not imply	otherwise. This	source code
 * contains	confidential trade secret material of Ralink Tech. Any attemp
 * or participation	in deciphering,	decoding, reverse engineering or in	any
 * way altering	the	source code	is stricitly prohibited, unless	the	prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:
	rt_os.h

	Abstract:
	Put all OS related definition/structure/MACRO here.

	Note:
	Used in UTIL/NETIF module.

	Revision History:
	Who			When			What
	--------	----------		----------------------------------------------
	Name		Date			Modification logs
*/

#ifndef _RT_OS_H_
#define _RT_OS_H_


#ifdef LINUX
#if WIRELESS_EXT <= 11
#ifndef SIOCDEVPRIVATE
#define SIOCDEVPRIVATE                              0x8BE0
#endif
#define SIOCIWFIRSTPRIV								SIOCDEVPRIVATE
#endif
#endif /* LINUX */


#ifdef CONFIG_STA_SUPPORT
#define RT_PRIV_IOCTL							(SIOCIWFIRSTPRIV + 0x01) /* Sync. with AP for wsc upnp daemon */
#define RTPRIV_IOCTL_SET							(SIOCIWFIRSTPRIV + 0x02)

#ifdef DBG
#define RTPRIV_IOCTL_BBP                            (SIOCIWFIRSTPRIV + 0x03)
#define RTPRIV_IOCTL_MAC                            (SIOCIWFIRSTPRIV + 0x05)

#ifdef RTMP_RF_RW_SUPPORT
#define RTPRIV_IOCTL_RF                             (SIOCIWFIRSTPRIV + 0x13)  /* edit by johnli, fix read rf register problem */
#endif /* RTMP_RF_RW_SUPPORT */
#define RTPRIV_IOCTL_E2P                            (SIOCIWFIRSTPRIV + 0x07)
#endif /* DBG */

#define RTPRIV_IOCTL_ATE							(SIOCIWFIRSTPRIV + 0x08)

#define RTPRIV_IOCTL_STATISTICS                     (SIOCIWFIRSTPRIV + 0x09)
#define RTPRIV_IOCTL_ADD_PMKID_CACHE                (SIOCIWFIRSTPRIV + 0x0A)
#define RTPRIV_IOCTL_RADIUS_DATA                    (SIOCIWFIRSTPRIV + 0x0C)
#define RTPRIV_IOCTL_GSITESURVEY					(SIOCIWFIRSTPRIV + 0x0D)
#define RT_PRIV_IOCTL_EXT							(SIOCIWFIRSTPRIV + 0x0E) /* Sync. with RT61 (for wpa_supplicant) */
#define RTPRIV_IOCTL_GET_MAC_TABLE					(SIOCIWFIRSTPRIV + 0x0F)
#define RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT					(SIOCIWFIRSTPRIV + 0x1F)	/* modified by Red@Ralink, 2009/09/30 */

#define RTPRIV_IOCTL_SHOW							(SIOCIWFIRSTPRIV + 0x11)


#ifdef WSC_STA_SUPPORT
#define RTPRIV_IOCTL_SET_WSC_PROFILE_U32_ITEM       (SIOCIWFIRSTPRIV + 0x14)
#define RTPRIV_IOCTL_SET_WSC_PROFILE_STRING_ITEM    (SIOCIWFIRSTPRIV + 0x16)
#endif /* WSC_STA_SUPPORT */
#endif /* CONFIG_STA_SUPPORT */

#ifdef CONFIG_AP_SUPPORT
/* Ralink defined OIDs */
#define RT_PRIV_IOCTL								(SIOCIWFIRSTPRIV + 0x01)
#define RTPRIV_IOCTL_SET							(SIOCIWFIRSTPRIV + 0x02)
#define RT_PRIV_IOCTL_EXT							(SIOCIWFIRSTPRIV + 0x0E) /* Sync. with RT61 (for wpa_supplicant) */				
#if defined(DBG) || defined(BB_SOC)
#define RTPRIV_IOCTL_BBP                            (SIOCIWFIRSTPRIV + 0x03)
#define RTPRIV_IOCTL_MAC                            (SIOCIWFIRSTPRIV + 0x05)

#ifdef RTMP_RF_RW_SUPPORT
#define RTPRIV_IOCTL_RF                             (SIOCIWFIRSTPRIV + 0x13)
#endif /* RTMP_RF_RW_SUPPORT */

#endif /* DBG */
#define RTPRIV_IOCTL_E2P                            (SIOCIWFIRSTPRIV + 0x07)

#define RTPRIV_IOCTL_ATE							(SIOCIWFIRSTPRIV + 0x08)

#define RTPRIV_IOCTL_STATISTICS                     (SIOCIWFIRSTPRIV + 0x09)
#define RTPRIV_IOCTL_ADD_PMKID_CACHE                (SIOCIWFIRSTPRIV + 0x0A)
#define RTPRIV_IOCTL_RADIUS_DATA                    (SIOCIWFIRSTPRIV + 0x0C)
#define RTPRIV_IOCTL_GSITESURVEY					(SIOCIWFIRSTPRIV + 0x0D)
#define RTPRIV_IOCTL_ADD_WPA_KEY                    (SIOCIWFIRSTPRIV + 0x0E)
#define RTPRIV_IOCTL_GET_MAC_TABLE					(SIOCIWFIRSTPRIV + 0x0F)
#define RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT	(SIOCIWFIRSTPRIV + 0x1F)	/* modified by Red@Ralink, 2009/09/30 */
#define RTPRIV_IOCTL_STATIC_WEP_COPY                (SIOCIWFIRSTPRIV + 0x10)

#define RTPRIV_IOCTL_SHOW							(SIOCIWFIRSTPRIV + 0x11)
#define RTPRIV_IOCTL_WSC_PROFILE                    (SIOCIWFIRSTPRIV + 0x12)
#define RTPRIV_IOCTL_QUERY_BATABLE                  (SIOCIWFIRSTPRIV + 0x16)
#if defined(INF_AR9)  || defined(BB_SOC)
#define RTPRIV_IOCTL_GET_AR9_SHOW   (SIOCIWFIRSTPRIV + 0x17)
#endif/* INF_AR9 */
#define RTPRIV_IOCTL_SET_WSCOOB	(SIOCIWFIRSTPRIV + 0x19)
#define RTPRIV_IOCTL_WSC_CALLBACK	(SIOCIWFIRSTPRIV + 0x1A)
#endif /* CONFIG_AP_SUPPORT */

/* yanglx: port from MT7610 */
#define RTPRIV_IOCTL_GBSSINFO	(SIOCIWFIRSTPRIV + 0x1c)
#define RTPRIV_IOCTL_GRATEINFO	(SIOCIWFIRSTPRIV + 0x1d)
#define RTPRIV_IOCTL_GSTAINFO	(SIOCIWFIRSTPRIV + 0x1e)
#define RTPRIV_IOCTL_GSCANINFO	(SIOCIWFIRSTPRIV + 0x1a)

/* yanglx: port from MT7610 for MMT support */
#ifdef RALINK_ATE
#ifdef RALINK_QA
#define RTPRIV_IOCTL_ATE_SET						0x779
#define RTPRIV_IOCTL_ATE_EFUSE_WRITEBACK			0x765
#define RTPRIV_IOCTL_ATE_WRITECAL					0x766
#define RTPRIV_IOCTL_ATE_SET_DA						0x767
#define RTPRIV_IOCTL_ATE_SET_SA						0x768
#define RTPRIV_IOCTL_ATE_SET_BSSID					0x769
#define RTPRIV_IOCTL_ATE_SET_TX_ANT					0x76A
#define RTPRIV_IOCTL_ATE_SET_TX_CHANNEL				0x76B
#define RTPRIV_IOCTL_ATE_SET_TX_MODE				0x76C
#define RTPRIV_IOCTL_ATE_SET_TX_MCS					0x76D
#define RTPRIV_IOCTL_ATE_SET_TX_BW					0x76E
#define RTPRIV_IOCTL_ATE_SET_TX_GI					0x76F
#define RTPRIV_IOCTL_ATE_SET_TX_LENGTH				0x770
#define RTPRIV_IOCTL_ATE_SET_TX_POW0				0x771
#define RTPRIV_IOCTL_ATE_SET_TX_POW1				0x772
#define RTPRIV_IOCTL_ATE_SET_TX_COUNT				0x773
#define RTPRIV_IOCTL_ATE_SET_TX_FREQOFFSET			0x774
#define RTPRIV_IOCTL_ATE_SET_RX_ANT					0x775
#define RTPRIV_IOCTL_ATE_SET_RX_FER					0x776
#define RTPRIV_IOCTL_ATE_SET_RESETCOUNTER			0x777
#define RTPRIV_IOCTL_ATE_EFUSE_LOAD					0x778
#define RTPRIV_IOCTL_ATE_AUTO_ALC					0x77A
#define RTPRIV_IOCTL_ATE_VCO_CAL					0x77B
#define RTPRIV_IOCTL_ATE_IPG						0x77C
/* yanglx: add 2014-8-20 */
#define RTPRIV_IOCTL_ATE_SET_TX_POW_EVAL 			0x77D
#endif // RALINK_QA //
#endif // RALINK_ATE //
/* yanglx ended */

#endif /* _RT_OS_H_ */
