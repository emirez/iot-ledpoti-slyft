
// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

// endpoint implementation


    #include "Arduino.h"

#include "microcoap/coap.h"
#include "coapled_app.h"

#include "poti.h"
#include "led.h"
#include "bounds.h"




#define COAP_MAKERESPONSE_INTERNALSERVERERROR \
return coap_make_response(scratch, \
  outpkt, (uint8_t*)outbuf, 0, \
  id_hi, id_lo, \
  &inpkt->tok, \
  (coap_responsecode_t)MAKE_RSPCODE(5, 0), COAP_CONTENTTYPE_NONE \
  );

#define COAP_MAKERESPONSE_BADREQUEST \
return coap_make_response(scratch, \
  outpkt, (uint8_t*)outbuf, 0, \
  id_hi, id_lo, \
  &inpkt->tok, \
  COAP_RSPCODE_BAD_REQUEST, COAP_CONTENTTYPE_NONE \
  );

#define RSPCODE_CLASS(rsp)  (rsp >> 5)
#define RSPCODE_DETAIL(rsp) (rsp & 31)

extern const coap_endpoint_t endpoints[];

static char well_known_rsp[256] = "\0";


int TUTCI__coapled__handle_get_well_known_core(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo) {
    
    if (well_known_rsp[0] == '\0') {
        // set up response
        uint16_t len = sizeof(well_known_rsp);
        const coap_endpoint_t *ep = endpoints;
        char *rsp = well_known_rsp;
        int i;

        len--; // Null-terminated string

        while(NULL != ep->handler)
        {
          if (NULL == ep->core_attr) {
            ep++;
            continue;
          }

          if (0 < strlen(rsp)) {
            strncat(rsp, ",", len);
            len--;
          }

          strncat(rsp, "<", len);
          len--;

          for (i = 0; i < ep->path->count; i++) {
            strncat(rsp, "/", len);
            len--;

            strncat(rsp, ep->path->elems[i], len);
            len -= strlen(ep->path->elems[i]);
          }

          strncat(rsp, ">;", len);
          len -= 2;

          strncat(rsp, ep->core_attr, len);
          len -= strlen(ep->core_attr);

          ep++;
        }
    }


    int res = coap_make_response(scratch, outpkt, (const uint8_t *)well_known_rsp, strlen(well_known_rsp), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_APPLICATION_LINKFORMAT);


    return res;
}


// define coap handler functions

// Protocol-level handler for GET requests to /bounds
int TUTCI__coapled__handle_get___bounds(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo) {

    
    // processing
    uint8_t outbuf[512];
    mpack_memset(outbuf,0,sizeof(outbuf));
    size_t resp_len = 0;
    coap_responsecode_t  resp_code;
    coap_content_type_t  resp_content_type = COAP_CONTENTTYPE_NONE;

    struct TUTCI__coapled__get___bounds_req    req;
    struct TUTCI__coapled__get___bounds_resp   resp;


    TUTCI__bounds_init(&(resp.data.bounds_205));


    
    // forward req,resp structs to application handler
    bool handled = TUTCI__coapled__get___bounds(&req, &resp);
    

    if (handled) {
      // take response code from resp
      resp_code = resp.response_code;
      // form the response body
      if ( RSPCODE_CLASS(resp_code) == 2 && RSPCODE_DETAIL(resp_code) == 05) {
        
        // handle code 205, schema is bounds
        resp_len = resp.data.bounds_205.TUTCI__bounds_serialize(&(resp.data.bounds_205), outbuf, sizeof(outbuf));
        resp_content_type = COAP_CONTENTTYPE_APPLICATION_OCTECT_STREAM;
        
      }


      int res = coap_make_response(scratch,
        outpkt,
        (uint8_t*)outbuf, resp_len,
        id_hi, id_lo,
        &inpkt->tok,
        resp_code, resp_content_type
      );
      
      return res;
    } else {
      
      COAP_MAKERESPONSE_INTERNALSERVERERROR
    }

}

// Protocol-level handler for POST requests to /bounds
int TUTCI__coapled__handle_post___bounds(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo) {

    
    // processing
    uint8_t outbuf[512];
    mpack_memset(outbuf,0,sizeof(outbuf));
    size_t resp_len = 0;
    coap_responsecode_t  resp_code;
    coap_content_type_t  resp_content_type = COAP_CONTENTTYPE_NONE;

    struct TUTCI__coapled__post___bounds_req    req;
    struct TUTCI__coapled__post___bounds_resp   resp;

    // handle input body
    TUTCI__bounds_init(&(req.data.bounds));
    int parse_res = req.data.bounds.TUTCI__bounds_parse(&(req.data.bounds),inpkt->payload.p, (uint32_t)inpkt->payload.len);
    if (parse_res != 0) {
        
        // get out here, unable to parse the request data
        COAP_MAKERESPONSE_BADREQUEST
    };
    



    
    // forward req,resp structs to application handler
    bool handled = TUTCI__coapled__post___bounds(&req, &resp);
    

    if (handled) {
      // take response code from resp
      resp_code = resp.response_code;
      // form the response body

      int res = coap_make_response(scratch,
        outpkt,
        (uint8_t*)outbuf, resp_len,
        id_hi, id_lo,
        &inpkt->tok,
        resp_code, resp_content_type
      );
      
      return res;
    } else {
      
      COAP_MAKERESPONSE_INTERNALSERVERERROR
    }

}

// Protocol-level handler for GET requests to /led
int TUTCI__coapled__handle_get___led(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo) {

    
    // processing
    uint8_t outbuf[512];
    mpack_memset(outbuf,0,sizeof(outbuf));
    size_t resp_len = 0;
    coap_responsecode_t  resp_code;
    coap_content_type_t  resp_content_type = COAP_CONTENTTYPE_NONE;

    struct TUTCI__coapled__get___led_req    req;
    struct TUTCI__coapled__get___led_resp   resp;


    TUTCI__led_init(&(resp.data.led_205));


    
    // forward req,resp structs to application handler
    bool handled = TUTCI__coapled__get___led(&req, &resp);
    

    if (handled) {
      // take response code from resp
      resp_code = resp.response_code;
      // form the response body
      if ( RSPCODE_CLASS(resp_code) == 2 && RSPCODE_DETAIL(resp_code) == 05) {
        
        // handle code 205, schema is led
        resp_len = resp.data.led_205.TUTCI__led_serialize(&(resp.data.led_205), outbuf, sizeof(outbuf));
        resp_content_type = COAP_CONTENTTYPE_APPLICATION_OCTECT_STREAM;
        
      }


      int res = coap_make_response(scratch,
        outpkt,
        (uint8_t*)outbuf, resp_len,
        id_hi, id_lo,
        &inpkt->tok,
        resp_code, resp_content_type
      );
      
      return res;
    } else {
      
      COAP_MAKERESPONSE_INTERNALSERVERERROR
    }

}

// Protocol-level handler for GET requests to /poti
int TUTCI__coapled__handle_get___poti(coap_rw_buffer_t *scratch,
    const coap_packet_t *inpkt, coap_packet_t *outpkt,
    uint8_t id_hi, uint8_t id_lo) {

    
    // processing
    uint8_t outbuf[512];
    mpack_memset(outbuf,0,sizeof(outbuf));
    size_t resp_len = 0;
    coap_responsecode_t  resp_code;
    coap_content_type_t  resp_content_type = COAP_CONTENTTYPE_NONE;

    struct TUTCI__coapled__get___poti_req    req;
    struct TUTCI__coapled__get___poti_resp   resp;


    TUTCI__poti_init(&(resp.data.poti_205));


    
    // forward req,resp structs to application handler
    bool handled = TUTCI__coapled__get___poti(&req, &resp);
    

    if (handled) {
      // take response code from resp
      resp_code = resp.response_code;
      // form the response body
      if ( RSPCODE_CLASS(resp_code) == 2 && RSPCODE_DETAIL(resp_code) == 05) {
        
        // handle code 205, schema is poti
        resp_len = resp.data.poti_205.TUTCI__poti_serialize(&(resp.data.poti_205), outbuf, sizeof(outbuf));
        resp_content_type = COAP_CONTENTTYPE_APPLICATION_OCTECT_STREAM;
        
      }


      int res = coap_make_response(scratch,
        outpkt,
        (uint8_t*)outbuf, resp_len,
        id_hi, id_lo,
        &inpkt->tok,
        resp_code, resp_content_type
      );
      
      return res;
    } else {
      
      COAP_MAKERESPONSE_INTERNALSERVERERROR
    }

}


