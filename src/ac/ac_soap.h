#ifndef __AC_SOAP_HEADER__
#define __AC_SOAP_HEADER__

#include <libxml/tree.h>
#include <libxml/parser.h>

/* */
#define SOAP_HTTP_PROTOCOL				1
#define SOAP_HTTPS_PROTOCOL				2

#define SOAP_HTTP_PORT					80
#define SOAP_HTTPS_PORT					443

/* */
struct ac_http_soap_server {
	int protocol;
	struct sockaddr_storage address;

	char* host;
	char* path;
};

/* */
struct ac_soap_request {
	xmlDocPtr xmlDocument;
	xmlNodePtr xmlRoot;
	xmlNodePtr xmlBody;
	xmlNodePtr xmlRequest;

	char* method;
};

/* */
struct ac_http_soap_request {
	struct ac_http_soap_server* server;
	struct ac_soap_request* request;

	int sock;

	/* Information for SOAP Response */
	int httpstate;
	int responsecode;
	int contentlength;
};

/* */
struct ac_soap_response {
	xmlDocPtr xmlDocument;
	xmlNodePtr xmlRoot;
	xmlNodePtr xmlBody;
	xmlNodePtr xmlResponse;
	xmlNodePtr xmlResponseReturn;
};

/* */
void ac_soapclient_init(void);
void ac_soapclient_free(void);

/* */
struct ac_http_soap_server* ac_soapclient_create_server(const char* url);
void ac_soapclient_free_server(struct ac_http_soap_server* server);

/* Request */
struct ac_soap_request* ac_soapclient_create_request(char* method, char* urinamespace);
int ac_soapclient_add_param(struct ac_soap_request* request, char* type, char* name, char* value);
char* ac_soapclient_get_request(struct ac_soap_request* request);
void ac_soapclient_free_request(struct ac_soap_request* request);

/* Transport Request */
struct ac_http_soap_request* ac_soapclient_prepare_request(struct ac_soap_request* request, struct ac_http_soap_server* server);
int ac_soapclient_send_request(struct ac_http_soap_request* httprequest, char* soapaction);
struct ac_soap_response* ac_soapclient_recv_response(struct ac_http_soap_request* httprequest);

void ac_soapclient_close_request(struct ac_http_soap_request* httprequest, int closerequest);

/* Response */
void ac_soapclient_free_response(struct ac_soap_response* response);

#endif /* __AC_SOAP_HEADER__ */