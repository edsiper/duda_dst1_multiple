/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda I/O Examples", "Hello World");

void cb_aa(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "This is AA\n");
    response->end(dr, NULL);
}

int duda_main()
{
    map->static_add("/test", "cb_aa");
    return 0;
}
