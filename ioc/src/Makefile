TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library
#

DBD += table.dbd

#=============================
# build an ioc application

PROD_IOC += table


# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
table_SRCS += table_registerRecordDeviceDriver.cpp
table_SRCS_DEFAULT += tableMain.cpp
table_SRCS_vxWorks += -nil-


# The following adds support from base/src/vxWorks
table_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

table_LIBS += table
table_LIBS += pvDatabase qsrv pvAccessIOC pvAccess pvAccessCA nt pvData
table_LIBS += $(EPICS_BASE_IOC_LIBS)

PROD_SYS_LIBS_WIN32 += ws2_32

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

