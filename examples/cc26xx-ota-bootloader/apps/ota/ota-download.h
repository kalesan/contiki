/** @file   ota-download.h
 *  @brief  OTA Image Download Mechanism
 *  @author Mark Solters <msolters@gmail.com>
 */

#ifndef OTA_DOWNLOAD_H
#define OTA_DOWNLOAD_H

#include "contiki.h"
#include "contiki-lib.h"
#include "contiki-net.h"
#include "ip64-addr.h"
#include "er-coap-engine.h"

#include "ota.h"

static uip_ipaddr_t ota_server_ipaddr;
#define OTA_SERVER_IP() uip_ip6addr(&ota_server_ipaddr, 0xbbbb, 0, 0, 0, 0, 0, 0, 0x1)

/* OTA Download Thread */
extern int ota_download_th_p; // Pointer to OTA Download thread

//  OTA Download Events
typedef enum {
  OTA_HTTP_REQUEST_SUCCESS,
  OTA_HTTP_REQUEST_FAIL,
  OTA_HTTP_REQUEST_RETRY,
  OTA_PAGE_DOWNLOAD_COMPLETE,
  OTA_IMAGE_DOWNLOAD_COMPLETE
} ota_event_t;

static OTAMetadata_t new_firmware_metadata;
static int active_ota_download_slot;
static uint8_t page_buffer[ FLASH_PAGE_SIZE ];
static uint8_t page;
static bool metadata_received;
static uint32_t bytes_received;
static uint32_t img_req_position;

static bool ota_downloading_image;
#endif