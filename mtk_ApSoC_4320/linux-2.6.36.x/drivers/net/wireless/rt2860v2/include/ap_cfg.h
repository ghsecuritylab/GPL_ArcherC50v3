#ifndef __AP_CFG_H__
#define __AP_CFG_H__


#include "rt_config.h"

typedef struct _WLAN_BSS_INFO
{
	char ssid[33];			
	unsigned char bssid[6];	
	unsigned char securityEnable;	
	unsigned int channel;			
	unsigned int rssi;			
}WLAN_BSS_INFO;

typedef struct _WLAN_RATE_INFO
{
	unsigned int basicRateMask;
	unsigned int basicMcsMask;
	
	unsigned int operationalRateMask;
	unsigned int operationalMcsMask;
	
	unsigned int possibleRateMask;
	unsigned int possibleMcsMask;
}WLAN_RATE_INFO;


typedef struct _WLAN_STA_INFO
{
	unsigned char	addr[MAC_ADDR_LEN];
	unsigned int	tx_packets;
	unsigned int rx_packets;
	unsigned char hostName[16];
}WLAN_STA_INFO;

INT RTMPAPPrivIoctlSet(
	IN RTMP_ADAPTER *pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *pIoctlCmdStr);

INT RTMPAPPrivIoctlShow(
	IN RTMP_ADAPTER *pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *pIoctlCmdStr);

VOID RTMPAPGetAssoMacTable(
	IN RTMP_ADAPTER *pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *pIoctlCmdStr);

#ifdef INF_AR9
#ifdef AR9_MAPI_SUPPORT
INT RTMPAPPrivIoctlAR9Show(
	IN RTMP_ADAPTER *pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *pIoctlCmdStr);

VOID RTMPAR9IoctlGetMacTable(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlGetSTAT2(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlGetRadioDynInfo(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);
#endif /*AR9_MAPI_SUPPORT*/
#endif/* INF_AR9 */

INT RTMPAPSetInformation(
	IN	PRTMP_ADAPTER	pAd,
	IN	OUT	RTMP_IOCTL_INPUT_STRUCT	*rq,
	IN	INT				cmd);

INT RTMPAPQueryInformation(
	IN	PRTMP_ADAPTER       pAd,
	IN	OUT	RTMP_IOCTL_INPUT_STRUCT    *rq,
	IN	INT                 cmd);
	
VOID RTMPIoctlStatistics(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

#ifdef RTMP_RBUS_SUPPORT
/* +++ added by Red@Ralink, 2009/09/30 */
VOID RTMPIoctlGetMacTableStaInfo(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);
/* ++ end of addition */
#endif /* RTMP_RBUS_SUPPORT */

VOID RTMPIoctlGetMacTable(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);


VOID RTMPAPIoctlE2PROM(
    IN  PRTMP_ADAPTER   pAdapter,
    IN  RTMP_IOCTL_INPUT_STRUCT    *wrq);

#ifdef DBG
VOID RTMPAPIoctlBBP(
    IN  PRTMP_ADAPTER   pAdapter,
    IN  RTMP_IOCTL_INPUT_STRUCT    *wrq);

VOID RTMPAPIoctlMAC(
    IN  PRTMP_ADAPTER   pAdapter,
    IN  RTMP_IOCTL_INPUT_STRUCT    *wrq);

#ifdef RTMP_RF_RW_SUPPORT
VOID RTMPAPIoctlRF(
	IN	PRTMP_ADAPTER	pAdapter,
	IN	RTMP_IOCTL_INPUT_STRUCT	*wrq);
#endif /* RTMP_RF_RW_SUPPORT */

#endif /* DBG */

VOID RTMPIoctlGRATEINFO(
	IN PRTMP_ADAPTER pAd, 
	IN struct iwreq *wrq);

VOID RTMPIoctlGBSSINFO(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlGSTAINFO(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlGSCANBSSINFO(
	IN PRTMP_ADAPTER pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RtmpDrvMaxRateGet(
	IN	VOID					*pReserved,
/*	IN	PHTTRANSMIT_SETTING		pHtPhyMode, */
	IN	UINT8					MODE,
	IN	UINT8					ShortGI,
	IN	UINT8					BW,
	IN	UINT8					MCS,
	OUT	UINT32					*pRate);

#ifdef WSC_AP_SUPPORT
VOID RTMPIoctlWscProfile(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlWscProfile(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);
/*add by woody */
#ifdef INF_AR9
#ifdef AR9_MAPI_SUPPORT
VOID RTMPAR9IoctlWscProfile(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlWscPINCode(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);


VOID RTMPIoctlWscStatus(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlGetWscDynInfo(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);

VOID RTMPIoctlGetWscRegsDynInfo(
	IN PRTMP_ADAPTER pAdapter, 
	IN RTMP_IOCTL_INPUT_STRUCT *wrq);
#endif/*AR9_MAPI_SUPPORT*/
#endif/* INF_AR9 */
#endif /* WSC_AP_SUPPORT */

#ifdef DOT11_N_SUPPORT
VOID RTMPIoctlQueryBaTable(
	IN	PRTMP_ADAPTER	pAd, 
	IN	RTMP_IOCTL_INPUT_STRUCT	*wrq);
#endif /* DOT11_N_SUPPORT */

#ifdef DOT1X_SUPPORT
VOID RTMPIoctlStaticWepCopy(
	IN	PRTMP_ADAPTER	pAd, 
	IN	RTMP_IOCTL_INPUT_STRUCT	*wrq);

VOID RTMPIoctlRadiusData(
	IN PRTMP_ADAPTER	pAd, 
	IN RTMP_IOCTL_INPUT_STRUCT		*wrq);

VOID RTMPIoctlAddWPAKey(
	IN	PRTMP_ADAPTER	pAd, 
	IN	RTMP_IOCTL_INPUT_STRUCT	*wrq);

VOID RTMPIoctlAddPMKIDCache(
	IN	PRTMP_ADAPTER	pAd, 
	IN	RTMP_IOCTL_INPUT_STRUCT	*wrq);

VOID RTMPIoctlSetIdleTimeout(
	IN	PRTMP_ADAPTER	pAd, 
	IN	RTMP_IOCTL_INPUT_STRUCT	*wrq);
#endif /* DOT1X_SUPPORT */

INT	ApCfg_Set_AuthMode_Proc(
	IN	PRTMP_ADAPTER	pAd, 
	IN	INT				apidx,
	IN	PSTRING			arg);

INT	ApCfg_Set_MaxStaNum_Proc(
	IN PRTMP_ADAPTER 	pAd,
	IN INT				apidx,
	IN PSTRING 			arg);

INT	ApCfg_Set_IdleTimeout_Proc(
	IN	PRTMP_ADAPTER	pAd, 
	IN	PSTRING			arg);


#ifdef APCLI_SUPPORT
#ifdef APCLI_WPA_SUPPLICANT_SUPPORT
VOID RTMPApCliAddKey(
	IN	PRTMP_ADAPTER	    pAd, 
	IN 	INT				apidx,
	IN	PNDIS_APCLI_802_11_KEY    pApcliKey);
#endif /* APCLI_WPA_SUPPLICANT_SUPPORT */
#endif /* APCLI_SUPPORT */
#endif /* __AP_CFG_H__ */

