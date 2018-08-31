#ifndef RS9113_ADAPTER_H_
#define	RS9113_ADAPTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dev_wnic.h"

#define WLAN_RSI		//If defined, Select RSI as WLAN module

#ifdef WLAN_RSI

#define RSI_91X			//This option enabes support for RSI 1x1 devices.
#define RSI_DEBUGFS		//This option creates debugfs entries
#define RSI_SDIO		//This option enables the SDIO bus support in rsi drivers.
#ifndef RSI_SDIO
#define RSI_USB			//This option enables the USB bus support in rsi drivers.
#endif
#define RSI_COEX		//This option enables the WLAN BT coex support in rsi drivers

#endif /* WLAN_RSI */

//! Wireless driver task priority
#define RSI_DRIVER_TASK_PRIORITY   5

//! Wireless driver task stack size
#define RSI_DRIVER_TASK_STACK_SIZE  500

typedef struct MACADDR_T
{
	union
	{
		uint8_t		u8[6];
		uint16_t	u16[3];
	};
} MACADDR;

#define MACBROADCAST	((MACADDR) {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF})	// RFC 894
#define MACNONE			((MACADDR) {0x00, 0x00, 0x00, 0x00, 0x00, 0x00})	// RFC 894

// WPA and WPA2 KEY, used for both
typedef struct
{
	uint8_t rgbKey[32];
} WPA2KEY;

typedef struct
{
	union
	{
		uint8_t		rgbKey[5];
		int8_t		asciiKey[5];
	} key[4];
} WEP40KEY;

typedef struct
{
	union
	{
		uint8_t		rgbKey[13];
		int8_t		asciiKey[13];
	} key[4];
} WEP104KEY;

extern int32_t rs9113_wnic_get_info(DEV_WNIC *rs9113_wnic, uint32_t cmd, void *rinfo);
extern int32_t rs9113_wnic_control(DEV_WNIC *rs9113_wnic, uint32_t ctrl_cmd, void *param);
extern int32_t rs9113_wnic_init(DEV_WNIC *rs9113_wnic, uint32_t network_type);
extern int32_t rs9113_poll_init_status(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_poll_busy_status(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_set_network_type(DEV_WNIC *rs9113_wnic, uint32_t type);
extern int32_t rs9113_set_macaddr(DEV_WNIC *rs9113_wnic, uint8_t *mac);
extern int32_t rs9113_get_macaddr(DEV_WNIC *rs9113_wnic, uint8_t *mac);
extern int32_t rs9113_start_scan(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_stop_scan(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_poll_scan_status(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_get_scan_result_cnt(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_get_scan_result(DEV_WNIC *rs9113_wnic, uint32_t index, WNIC_SCAN_RESULT *result);
extern int32_t rs9113_wnic_connect(DEV_WNIC *rs9113_wnic, uint32_t security, const uint8_t *ssid, WNIC_AUTH_KEY *key);
extern int32_t rs9113_poll_conn_status(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_wnic_disconnect(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_prepare_tx(DEV_WNIC *rs9113_wnic, uint32_t tx_len);
extern int32_t rs9113_add_tx_data(DEV_WNIC *rs9113_wnic, uint8_t *p_buf, uint32_t len);
extern int32_t rs9113_commit_tx(DEV_WNIC *rs9113_wnic, uint32_t len);
extern int32_t rs9113_prepare_rx(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_get_rx_data(DEV_WNIC *rs9113_wnic, uint8_t *p_buf, uint32_t len);
extern int32_t rs9113_accept_rx(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_config_power_mode(DEV_WNIC *rs9113_wnic, int32_t power_mode);
extern int32_t rs9113_poll_power_mode(DEV_WNIC *rs9113_wnic);
extern int32_t rs9113_wnic_reset(DEV_WNIC *rs9113_wnic);
extern void rs9113_period_process(DEV_WNIC *rs9113_wnic, void *ptr);

#ifdef __cplusplus
}
#endif

#endif	/* RS9113_ADAPTER_H_ */