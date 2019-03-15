TOP=..

include $(TOP)/configure/CONFIG

tableSRC = $(TOP)/src

EPICS_BASE_PVA_CORE_LIBS = pvaClient pvDatabase pvAccess pvAccessCA pvData ca Com

INC += pv/tableRecord.h

DBD += tableRegister.dbd

LIBRARY = table
LIBSRCS += tableRecord.cpp
LIBSRCS += tableRegister.cpp
table_LIBS += $(EPICS_BASE_PVA_CORE_LIBS)

# shared library ABI version.
SHRLIB_VERSION ?= 4.3.0

PROD_HOST += tableMain
tableMain_SRCS += tableMain.cpp
tableMain_LIBS += table
tableMain_LIBS += pvDatabase
tableMain_LIBS += $(EPICS_BASE_PVA_CORE_LIBS)

PROD_HOST += tableClient
tableClient_SRCS += tableClient.cpp
tableClient_LIBS += $(EPICS_BASE_PVA_CORE_LIBS)


PROD_SYS_LIBS_WIN32 += ws2_32


include $(TOP)/configure/RULES

