#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "config.h"
#include "poppyNetwork.h"
#include "cmd.h"

#define TRUE 1
#define FALSE 0

typedef void (*DATA_CB) (volatile unsigned char *data);

typedef struct {
    unsigned char rx_error : 1;
    unsigned char unexpected_state : 1;
    unsigned char warning : 1;
} status_t;


typedef struct {
    // Callback pointers
        DATA_CB data_cb;    /*!< Data management callback. */
        RX_CB rx_cb;        /*!< User side slave RX callback. */

    // Module infomations
        unsigned short id;       /*!< Module ID. */
        unsigned char type;     /*!< Module type. */
        unsigned char alias[16];/*!< Module alias. */

    // Variables
        status_t status;    /*!< Status. */
        msg_t msg;          /*!< Message. */

        unsigned char max_multicast_target; /*!< Position pointer of the last multicast target. */
        unsigned short multicast_target_bank[256]; /*!< multicast target bank. */

        unsigned char max_virtual_target; /*!< Position pointer of the last virtual target. */
        unsigned short virtual_target_bank[256]; /*!< virtual target bank. */
    }context_t;

extern context_t ctx;

#endif /* _CONTEXT_H_ */