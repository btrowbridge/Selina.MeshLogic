#pragma once

//intern
#include <arpa/inet.h>
#include <errno.h>
#include <memory.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

//extern
	//boost
#include <boost/asio/ip/address.hpp>

//Utility
#include "Utility.hpp"

#define THROW(msg,...) fprintf(stderr, msg, ##__VA_ARGS__); exit(1);
