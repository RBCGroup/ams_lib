/*
 * ---------------------------------------------------------------------------------------------------------------------
 *
 * Copyright (C) 2018, Anton Synytsia
 *
 * ---------------------------------------------------------------------------------------------------------------------
 */

#include "ams_socket.h"


/*
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Variables
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

WSADATA* AMS::Socket::wsa_data = nullptr;


/*
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Helper Functions
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

bool AMS::Socket::c_init_socket() {
    int result;

    if (wsa_data != nullptr)
        return false;

    wsa_data = new WSADATA;

    // Initialize Winsock
    result = WSAStartup(MAKEWORD(2,2), wsa_data);
    if (result != 0) {
        delete wsa_data;
        wsa_data = nullptr;
        return false;
    }


    return true;
}

bool AMS::Socket::c_uninit_socket() {
    return false;
}


/*
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Ruby Functions
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/


/*
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Main
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

void AMS::Socket::init_ruby(VALUE mAMS) {
    // Initialize Winsock
    //c_init_socket();
}
