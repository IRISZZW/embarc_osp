# Application name
APPL ?= freertos_net_httpserver

ifeq ($(BOARD), emsdp)
EXT_DEV_LIST += wifi/rs9113
else
EXT_DEV_LIST += wifi/mrf24g
endif

#
# root dir of embARC
#
EMBARC_ROOT = ../../../..

# Selected OS
OS_SEL ?= freertos
# Select Middleware Packages
MID_SEL = common lwip lwip-contrib
LWIP_CONTRIB_APPS ?= httpserver

# application source dirs
APPL_CSRC_DIR = .
APPL_ASMSRC_DIR = .

# application include dirs
APPL_INC_DIR = .

# include current project makefile
COMMON_COMPILE_PREREQUISITES += makefile

### Options above must be added before include options.mk ###
# include key embARC build system makefile
include $(EMBARC_ROOT)/options/options.mk
