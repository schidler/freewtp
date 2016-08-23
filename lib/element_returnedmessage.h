#ifndef __CAPWAP_ELEMENT_RETURNEDMESSAGE_HEADER__
#define __CAPWAP_ELEMENT_RETURNEDMESSAGE_HEADER__

#define CAPWAP_ELEMENT_RETURNEDMESSAGE_VENDOR			0
#define CAPWAP_ELEMENT_RETURNEDMESSAGE_TYPE			34
#define CAPWAP_ELEMENT_RETURNEDMESSAGE				(struct capwap_message_element_id){ .vendor = CAPWAP_ELEMENT_RETURNEDMESSAGE_VENDOR, .type = CAPWAP_ELEMENT_RETURNEDMESSAGE_TYPE }


#define CAPWAP_RETURNED_MESSAGE_UNKNOWN_MESSAGE_ELEMENT						1
#define CAPWAP_RETURNED_MESSAGE_UNSUPPORTED_MESSAGE_ELEMENT					2
#define CAPWAP_RETURNED_MESSAGE_UNKNOWN_MESSAGE_ELEMENT_VALUE				3
#define CAPWAP_RETURNED_MESSAGE_UNSUPPORTED_MESSAGE_ELEMENT_VALUE			4

#define CAPWAP_RETURNED_MESSAGE_MAX_LENGTH						255

struct capwap_returnedmessage_element {
	uint8_t reason;
	uint8_t length;
	uint8_t* message;
};

extern const struct capwap_message_elements_ops capwap_element_returnedmessage_ops;

#endif /* __CAPWAP_ELEMENT_RETURNEDMESSAGE_HEADER__ */