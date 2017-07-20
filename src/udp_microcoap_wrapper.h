// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

#ifndef __COAPPROCESSING_H
#define __COAPPROCESSING_H

#include "microcoap/coap.h"

typedef struct udp_microcoap_wrapper_s udp_microcoap_wrapper;
typedef struct udp_microcoap_wrapper_operations_s udp_microcoap_wrapper_operations;

struct udp_microcoap_wrapper_s {
    bool b_debug;
    // Pointer to UDP object
    void *p_udp;
    // Buffer for CoAP messages
    uint8_t packetbuf[2048];
    // Scratch Buffer to CoAP packet creation etc.
    uint8_t scratch_raw[32];
    coap_rw_buffer_t scratch_buf = {
            scratch_raw,
            sizeof(scratch_raw)
    };
    udp_microcoap_wrapper_operations *ops;
};

struct udp_microcoap_wrapper_operations_s {
    void (*handle_udp_coap_message)(udp_microcoap_wrapper *obj);

    void (*clear_packet_buf)(udp_microcoap_wrapper *obj);
};

// Initializes the coap processing struct
udp_microcoap_wrapper *udp_microcoap_wrapper_init(void *);

// Returns instance of udp_microcoap_wrapper struct
udp_microcoap_wrapper *udp_microcoap_wrapper_get();

// destroys a coap processing struct (empty, static mem)
void udp_microcoap_wrapper_destroy(udp_microcoap_wrapper *p);

#endif