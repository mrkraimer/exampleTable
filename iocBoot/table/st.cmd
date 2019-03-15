< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase("dbd/table.dbd")
table_registerRecordDeviceDriver(pdbbase)

## Load record instances


cd ${TOP}/iocBoot/${IOC}
iocInit()
tableCreateRecord table
