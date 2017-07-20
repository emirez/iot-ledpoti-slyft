

// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

// slyftlet=c99-generic-msgpack

#ifndef tutci_POTI_H
#define tutci_POTI_H

#include "mpack/mpack.h"

struct TUTCI__poti {
  /* 0-1023 */
  int32_t	potval;

  /**
  * Wipes contents to \0
  * @param self      pointer to target struct TUTCI__poti
  */
  void (*TUTCI__poti_clean)(struct TUTCI__poti *self);

  /**
  * Given an input buffer and its size, this functions parses the elements
  * of struct TUTCI__poti
  * @param self          pointer to target struct TUTCI__poti
  * @param input_buf     input buffer
  * @param sz_input_buf  size of input buffer
  * @return 0=success, 1=error
  */
  int (*TUTCI__poti_parse)(struct TUTCI__poti *self, const uint8_t *input_buf, size_t sz_input_buf);

  /**
  * Given a msgpack reader, this functions parses the elements
  * of struct TUTCI__poti
  * @param self          pointer to target struct TUTCI__poti
  * @param reader        pointer to mpack reader struct
  */
  void (*TUTCI__poti_parse_mpack)(struct TUTCI__poti *self, mpack_reader_t *reader);

  /**
  * Given a struct TUTCI__poti, this function serializes it into given output buffer.
  * @param self              pointer to source struct TUTCI__poti
  * @param output_buf        output buffer
  * @param sz_output_buf     size of output buffer
  * @return Length of output buf (0=error)
  */
  size_t (*TUTCI__poti_serialize)(const struct TUTCI__poti *self, uint8_t *output_buf, size_t sz_output_buf);

  /**
  * Given a struct TUTCI__poti, this function serializes it into given mpack writer.
  * @param self              pointer to source struct TUTCI__poti
  * @param writer 	         pointer to mpack writer struct
  */
  void (*TUTCI__poti_serialize_mpack)(const struct TUTCI__poti *self, mpack_writer_t *writer);

};

/**
 * Initializes struct struct TUTCI__poti. empties fields, sets function pointers
 * @param self  struct TUTCI__poti
 */
void TUTCI__poti_init(struct TUTCI__poti *self);


/* ORIGINAL SCHEMA
{"$schema"=>"http://json-schema.org/draft-04/schema#", "id"=>"poti", "title"=>"Poti Value", "description"=>"Poti Value", "type"=>"object", "properties"=>{"potval"=>{"type"=>"integer", "description"=>"0-1023"}}, "additionalProperties"=>false, "required"=>["potval"], "minProperties"=>1}
 */
#endif		//tutci_POTI_H
